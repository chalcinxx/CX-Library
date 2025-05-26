#ifndef CX_AUDIO_MANAGER_HPP
#define CX_AUDIO_MANAGER_HPP

#include "CX/AssetManager.hpp"

namespace cx
{
   /// @brief Play sounds and music.
   class AudioManager
   {
   public:
      // Constructors

      /// @brief Create a default audio manager.
      /// @param asset_manager Asset manager.
      AudioManager(cx::AssetManager& asset_manager);
      ~AudioManager() = default;

      // Update functions

      /// @brief Handle music and clear finished sounds.
      void update();

      // Sound functions

      /// @brief Save or update a sound.
      /// @param identifier New identifier.
      /// @param sound_identifier Asset identifier.
      /// @param max_duplicates Maximum amount of identical sounds.
      /// @param min_pitch Minimum pitch and playback speed.
      /// @param max_pitch Maximum pitch and playback speed.
      void save_sound(const std::string& identifier,
                      const std::string& songIdentifier,
                      unsigned char max_duplicates = 255,
                      float min_pitch = 1.f,
                      float max_pitch = 1.f);

      /// @brief Save or update a sound.
      /// @param identifier New identifier.
      /// @param sound_identifiers Asset identifiers.
      /// @param max_duplicates Maximum amount of identical sounds.
      /// @param min_pitch Minimum pitch and playback speed.
      /// @param max_pitch Maximum pitch and playback speed.
      void save_sound(const std::string& identifier,
                      const std::vector<std::string>& songIdentifiers,
                      unsigned char max_duplicates = 255,
                      float min_pitch = 1.f,
                      float max_pitch = 1.f);
      
      /// @brief Play a saved sound.
      /// @param identifier Saved sound identifier.
      void play_saved_sound(const std::string& identifier);

      /// @brief Play a sound.
      /// @param identifier Asset identifier.
      /// @param max_duplicates Maximum amount of identical sounds.
      /// @param min_pitch Minimum pitch and playback speed.
      /// @param max_pitch Maximum pitch and playback speed.
      void play_sound(const std::string& identifier,
                      unsigned char max_duplicates = 255,
                      float min_pitch = 1.f,
                      float max_pitch = 1.f);

      /// @brief Play a random sound.
      /// @param identifier Asset identifiers.
      /// @param max_duplicates Maximum amount of identical sounds.
      /// @param min_pitch Minimum pitch and playback speed.
      /// @param max_pitch Maximum pitch and playback speed.
      void play_random_sound(const std::vector<std::string>& identifiers,
                             unsigned char max_duplicates = 255,
                             float min_pitch = 1.f,
                             float max_pitch = 1.f);

      /// @brief Toggle paused for all sounds based on oldest sound.
      void toggle_paused_sounds();

      /// @brief Pause all sounds.
      void pause_sounds();

      /// @brief Unpause all sounds.
      void resume_sounds();

      /// @brief Stop all sounds.
      void stop_sounds();
      
      /// @brief Set sound volume.
      /// @param volume New volume.
      void set_sound_volume(float volume);

      /// @brief Get sound volume.
      /// @return Volume.
      float get_sound_volume() const;

      // Music functions

      /// @brief Play a song.
      /// @param identifier Asset identifier.
      /// @param looping Should the song loop.
      void play_music(const std::string& identifier, bool looping = false);

      /// @brief Play songs from the pool.
      /// @param identifiers Asset identifiers.
      /// @param shuffle Should random music be picked.
      void set_music_pool(const std::vector<std::string>& identifiers,
                          bool shuffle = true);

      /// @brief Toggle paused for current song.
      void toggle_paused_music();

      /// @brief Pause current song.
      void pause_music();

      /// @brief Unpause current song.
      void resume_music();

      /// @brief Restart current song.
      void restart_music();

      /// @brief Stop current song.
      void stop_music();

      /// @brief Set music volume.
      /// @param volume New volume.
      void set_music_volume(float volume);

      /// @brief Get music volume.
      /// @return Volume.
      float get_music_volume() const;

      /// @brief Check if current song is paused.
      /// @return True if paused.
      bool is_music_paused() const;

      /// @brief Check if current song is playing.
      /// @return True if playing.
      bool is_music_playing() const;

      /// @brief Check if current song is finished.
      /// @return True if finished.
      bool is_music_finished() const;

      // Contains functions

      /// @brief Check if a saved sound exists.
      /// @param name Name of the sound.
      /// @return True if exists.
      bool contains_saved_sound(const std::string& name) const;

      /// @brief Check if the music pool contains a song.
      /// @param name Name of the song.
      /// @return True if contains.
      bool contains_music(const std::string& name) const;

   private:
      /// @brief Save sounds.
      struct AudioManagerSound
      {
         std::vector<std::string> identifiers;
         unsigned char duplicate_count {255};
         float min_pitch {1.f};
         float max_pitch {1.f};
      };

      cx::AssetManager& asset;
      sf::Music current_song;
      std::vector<std::string> song_pool;
      std::vector<std::shared_ptr<sf::Sound>> active_sounds;
      std::unordered_map<std::string, AudioManagerSound> saved_sounds;

      bool shuffle_music {};
      float sound_volume {100.f};
      float music_volume {100.f};
      size_t music_index {0};
   };
}

#endif
