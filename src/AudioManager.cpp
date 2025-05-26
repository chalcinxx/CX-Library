#include "CX/AudioManager.hpp"

#include <SFML/Audio/Sound.hpp>
#include "CX/Errors.hpp"
#include "CX/Math/Math.hpp"
#include "CX/Math/Random.hpp"

namespace cx
{
   static std::mutex soundMutex;

   // Constructors

   AudioManager::AudioManager(AssetManager& assetManager)
      : asset(assetManager) {}

   // Update function

   void AudioManager::update()
   {
      // Update sounds
      {
         std::lock_guard<std::mutex> lock(soundMutex);

         active_sounds.erase(std::remove_if(active_sounds.begin(), active_sounds.end(), [](const auto& sound)
         {
            return sound->getStatus() == sf::Sound::Stopped;
         }), active_sounds.end());
      }

      // Update the music
      if (current_song.getStatus() != sf::Music::Stopped || song_pool.empty())
         return;

      if (shuffle_music)
         music_index += randiu(0, 50);

      music_index = music_index % song_pool.size();
      const std::string& identifier {song_pool.at(music_index)};
      ++music_index;

      if (!current_song.openFromFile(*asset.get_song(identifier)))
         throw std::runtime_error(
            std::format(errors::audio::song_cannot_be_played, identifier));

      current_song.setVolume(music_volume);
      current_song.play();
   }

   // Sound functions

   void AudioManager::save_sound(const std::string& identifier,
                                 const std::string& song_identifier,
                                 unsigned char max_duplicates,
                                 float min_pitch,
                                 float max_pitch)
   {
      saved_sounds[std::move(identifier)] = AudioManagerSound{
         {std::move(song_identifier)},
         max_duplicates,
         min_pitch,
         max_pitch
      };
   }

   void AudioManager::save_sound(const std::string& identifier,
                                 const std::vector<std::string>& song_identifiers,
                                 unsigned char max_duplicates,
                                 float min_pitch,
                                 float max_pitch)
   {
      saved_sounds[std::move(identifier)] = AudioManagerSound{
         std::move(song_identifiers),
         max_duplicates,
         min_pitch,
         max_pitch
      };
   }

   void AudioManager::play_saved_sound(const std::string& identifier)
   {
      if (!saved_sounds.contains(identifier))
         throw std::runtime_error(
            std::format(errors::audio::sound_is_not_saved, identifier));

      const AudioManagerSound& sound {saved_sounds.at(identifier)};

      if (sound.identifiers.empty())
         return;

      const std::string& soundIdentifier {
         (sound.identifiers.size() == 1 ? sound.identifiers.at(0) : 
         sound.identifiers.at(randiu(size_t(0), sound.identifiers.size() - 1)))
      };

      if (!asset.find_sound(soundIdentifier))
         throw std::runtime_error(std::format(
            errors::audio::sound_doesnot_exist, soundIdentifier));
      
      std::lock_guard<std::mutex> lock(soundMutex);

      // Check for duplicates
      unsigned char total {};

      for (const auto& sound : active_sounds)
         if (sound->getBuffer() == asset.get_sound(soundIdentifier).get())
            ++total;
      
      if (sound.duplicate_count <= total)
         return;
      
      // Create a new sound
      auto newSound {std::make_shared<sf::Sound>()};
      newSound->setBuffer(*asset.get_sound(soundIdentifier));
      newSound->setVolume(sound_volume);

      if (sound.min_pitch == sound.max_pitch)
         newSound->setPitch(sound.min_pitch);
      else
         newSound->setPitch(randfu(min(sound.min_pitch, sound.max_pitch),
            max(sound.min_pitch, sound.max_pitch)));

      newSound->play();

      active_sounds.push_back(newSound);
   }

   void AudioManager::play_sound(const std::string& identifier,
                                 unsigned char max_duplicates,
                                 float min_pitch,
                                 float max_pitch)
   {
      if (!asset.find_sound(identifier))
         throw std::runtime_error(std::format(
            errors::audio::sound_doesnot_exist, identifier));
      
      std::lock_guard<std::mutex> lock(soundMutex);

      // Check for duplicates
      unsigned char total {};

      for (const auto& sound : active_sounds)
         if (sound->getBuffer() == asset.get_sound(identifier).get())
            ++total;
      
      if (max_duplicates <= total)
         return;
      
      // Create a new sound
      auto sound {std::make_shared<sf::Sound>()};
      sound->setBuffer(*asset.get_sound(identifier));
      sound->setVolume(sound_volume);

      if (min_pitch == max_pitch)
         sound->setPitch(min_pitch);
      else
         sound->setPitch(randfu(min(min_pitch, max_pitch),
            max(min_pitch, max_pitch)));

      sound->play();

      active_sounds.push_back(sound);
   }

   void
   AudioManager::play_random_sound(const std::vector<std::string>& identifiers, 
                                   unsigned char max_duplicates,
                                   float min_pitch,
                                   float max_pitch)
   {
      if (identifiers.empty())
         return;

      const std::string& identifier {identifiers.at(randiu(size_t(0),
         identifiers.size() - 1))};

      if (!asset.find_sound(identifier))
         throw std::runtime_error(std::format(
            errors::audio::sound_doesnot_exist, identifier));
      
      std::lock_guard<std::mutex> lock(soundMutex);

      // Check for duplicates
      unsigned char total {};

      for (const auto& sound : active_sounds)
         if (sound->getBuffer() == asset.get_sound(identifier).get())
            ++total;
      
      if (max_duplicates <= total)
         return;
      
      // Create a new sound
      auto sound {std::make_shared<sf::Sound>()};
      sound->setBuffer(*asset.get_sound(identifier));
      sound->setVolume(sound_volume);

      if (min_pitch == max_pitch)
         sound->setPitch(min_pitch);
      else
         sound->setPitch(randfu(min(min_pitch, max_pitch),
            max(min_pitch, max_pitch)));

      sound->play();

      active_sounds.push_back(sound);
   }

   void AudioManager::toggle_paused_sounds()
   {
      std::lock_guard<std::mutex> lock(soundMutex);

      if (active_sounds.size() == 0)
         return;

      const bool pause {active_sounds.front()->getStatus()
         == sf::Music::Playing};

      for (auto& sound : active_sounds)
         if (pause && sound->getStatus() == sf::Music::Playing)
            sound->pause();
         else if (!pause && sound->getStatus() == sf::Music::Paused)
            sound->play();
   }

   void AudioManager::pause_sounds()
   {
      std::lock_guard<std::mutex> lock(soundMutex);

      for (auto& sound : active_sounds)
         if (sound->getStatus() == sf::Sound::Playing)
            sound->pause();
   }

   void AudioManager::resume_sounds()
   {
      std::lock_guard<std::mutex> lock(soundMutex);

      for (auto& sound : active_sounds)
         if (sound->getStatus() == sf::Sound::Paused)
            sound->play();
   }

   void AudioManager::stop_sounds()
   {
      std::lock_guard<std::mutex> lock(soundMutex);

      for (auto& sound : active_sounds)
      {
         sound->stop();
         sound->resetBuffer();
      }
   }

   void AudioManager::set_sound_volume(float volume)
   {
      std::lock_guard<std::mutex> lock(soundMutex);

      sound_volume = (volume > 100.f ? 100.f : (volume < 0.f ? 0.f : volume));
      
      for (auto& sound : active_sounds)
         sound->setVolume(sound_volume);
   }

   float AudioManager::get_sound_volume() const
   {
      return sound_volume;
   }

   // Music functions
   
   void AudioManager::play_music(const std::string& identifier, bool looping)
   {
      if (current_song.getStatus() == sf::Music::Playing)
         current_song.stop();

      if (!current_song.openFromFile(*asset.get_song(identifier)))
         throw std::runtime_error(std::format(
            errors::audio::song_cannot_be_played, identifier));

      current_song.setVolume(music_volume);
      current_song.setLoop(looping);
      current_song.play();
   }

   void AudioManager::set_music_pool(const std::vector<std::string>& identifiers, 
                                     bool shuffle)
   {
      if (identifiers == song_pool)
         return;

      music_index = 0;
      shuffle_music = shuffle;
      song_pool = std::move(identifiers);

      if (current_song.getStatus() == sf::Music::Playing)
         current_song.stop();
      current_song.setLoop(false);
   }

   void AudioManager::toggle_paused_music()
   {
      if (current_song.getStatus() == sf::Music::Playing)
         current_song.pause();
      else if (current_song.getStatus() == sf::Music::Paused)
         current_song.play();
   }

   void AudioManager::pause_music()
   {
      if (current_song.getStatus() == sf::Music::Playing)
         current_song.pause();
   }

   void AudioManager::resume_music()
   {
      if (current_song.getStatus() == sf::Music::Paused)
         current_song.play();
   }

   void AudioManager::restart_music()
   {
      current_song.stop();
      current_song.play();
   }

   void AudioManager::stop_music()
   {
      song_pool.clear();
      current_song.stop();
   }

   void AudioManager::set_music_volume(float volume)
   {
      music_volume = (volume > 100.f ? 100.f : (volume < 0.f ? 0.f : volume));
      current_song.setVolume(music_volume);
   }

   bool AudioManager::is_music_paused() const
   {
      return current_song.getStatus() == sf::Music::Paused;
   }

   bool AudioManager::is_music_playing() const
   {
      return current_song.getStatus() == sf::Music::Playing;
   }

   bool AudioManager::is_music_finished() const
   {
      return current_song.getStatus() == sf::Music::Stopped;
   }

   float AudioManager::get_music_volume() const
   {
      return music_volume;
   }

   // Contains functions

   bool AudioManager::contains_saved_sound(const std::string& name) const
   {
      return saved_sounds.contains(name);
   }

   bool AudioManager::contains_music(const std::string& name) const
   {
      for (const auto& song : song_pool)
         if (song == name)
            return true;
      return false;
   }
}
