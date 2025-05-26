#include "CX/AssetManager.hpp"

#include "CX/Errors.hpp"
#include <iostream>
#include <thread>

namespace cx
{
   using Callback = std::function<void(bool)>;

   // Constructors

   AssetManager::AssetManager(const fs::path& root_directory)
      : root(root_directory)
   {
      if (!fs::exists(root_directory))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, root_directory.string()));

      if (!fs::is_directory(root_directory))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, root_directory.string()));
   }

   // File functions

   bool AssetManager::is_path_valid(const fs::path& path, bool relative_to_root) const
   {
      const fs::path full_path ((relative_to_root ? root / path : path));
      return fs::exists(full_path);
   }

   bool AssetManager::file_exists(const fs::path& path, bool relative_to_root) const
   {
      const fs::path full_path ((relative_to_root ? root / path : path));
      return fs::exists(full_path) && fs::is_regular_file(full_path);
   }

   bool AssetManager::dir_exists(const fs::path& path, bool relative_to_root) const
   {
      const fs::path full_path ((relative_to_root ? root / path : path));
      return fs::exists(full_path) && fs::is_directory(full_path);
   }

   // Root directory functions

   void AssetManager::set_root_directory(const fs::path& root_directory)
   {
      if (!fs::exists(root_directory))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, root_directory.string()));

      if (!fs::is_directory(root_directory))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, root_directory.string()));

      root = root_directory;
   }

   const fs::path& AssetManager::get_root_directory() const
   {
      return root;
   }

   // Load functions

   const AssetManager::texture_t& AssetManager::load_texture(const std::string& identifier,
                                                             const fs::path& path,
                                                             bool relative_to_root)
   {
      if (textures.contains(identifier))
         return textures[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      sf::Texture texture;

      if (!texture.loadFromFile(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      textures.insert({identifier, std::make_shared<sf::Texture>(std::move(texture))});
      return textures[identifier];
   }

   const AssetManager::sound_t& AssetManager::load_sound(const std::string& identifier,
                                                         const fs::path& path,
                                                         bool relative_to_root)
   {
      if (sounds.contains(identifier))
         return sounds[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      sf::SoundBuffer sound;

      if (!sound.loadFromFile(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      sounds.insert({identifier, std::make_shared<sf::SoundBuffer>(std::move(sound))});
      return sounds[identifier];
   }

   const AssetManager::music_t& AssetManager::load_song(const std::string& identifier,
                                                        const fs::path& path,
                                                        bool relative_to_root)
   {
      if (music.contains(identifier))
         return music[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_regular_file(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      if (!music_extensions.contains(full_path.extension().string()))
         throw std::runtime_error(std::format(errors::asset::invalid_extension, full_path.string(), full_path.extension().string()));

      music.insert({identifier, std::make_shared<fs::path>(std::move(full_path))});
      return music[identifier];
   }

   const AssetManager::font_t& AssetManager::load_font(const std::string& identifier,
                                                       const fs::path& path,
                                                       bool relative_to_root)
   {
      if (fonts.contains(identifier))
         return fonts[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      sf::Font font;

      if (!font.loadFromFile(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      fonts.insert({identifier, std::make_shared<sf::Font>(std::move(font))});
      return fonts[identifier];
   }

   const AssetManager::texture_t& AssetManager::load_texture(const fs::path& path, bool relative_to_root)
   {
      const std::string& identifier {path.stem().string()};

      if (textures.contains(identifier))
         return textures[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      sf::Texture texture;

      if (!texture.loadFromFile(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      textures.insert({identifier, std::make_shared<sf::Texture>(std::move(texture))});
      return textures[identifier];
   }

   const AssetManager::sound_t& AssetManager::load_sound(const fs::path& path, bool relative_to_root)
   {
      const std::string& identifier {path.stem().string()};
      
      if (sounds.contains(identifier))
         return sounds[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(
            errors::asset::path_does_not_exist, full_path.string()));

      sf::SoundBuffer sound;

      if (!sound.loadFromFile(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      sounds.insert({identifier, std::make_shared<sf::SoundBuffer>(std::move(sound))});
      return sounds[identifier];
   }

   const AssetManager::music_t& AssetManager::load_song(const fs::path& path, bool relative_to_root)
   {
      const std::string& identifier {path.stem().string()};

      if (music.contains(identifier))
         return music[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_regular_file(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      if (!music_extensions.contains(full_path.extension().string()))
         throw std::runtime_error(std::format(errors::asset::invalid_extension, full_path.string(), full_path.extension().string()));

      music.insert({identifier, std::make_shared<fs::path>(std::move(full_path))});
      return music[identifier];
   }

   const AssetManager::font_t& AssetManager::load_font(const fs::path& path, bool relative_to_root)
   {
      const std::string& identifier {path.stem().string()};

      if (fonts.contains(identifier))
         return fonts[identifier];

      const fs::path full_path ((relative_to_root ? root / path : path));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      sf::Font font;

      if (!font.loadFromFile(full_path))
         throw std::runtime_error(std::format(errors::asset::cannot_load_asset, full_path.string()));

      fonts.insert({identifier, std::make_shared<sf::Font>(std::move(font))});
      return fonts[identifier];
   }

   void AssetManager::load_texture_dir(const fs::path& directory,
                                       bool relative_to_root,
                                       bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      for (const auto& file : fs::directory_iterator(full_path))
      {
         if (file.is_directory() && recursive)
            load_texture_dir(file.path(), false);

         if (!file.is_regular_file() || !texture_extensions.contains(file.path().extension()))
            continue;

         sf::Texture texture;

         if (!texture.loadFromFile(file.path()))
            throw std::runtime_error(std::format(errors::asset::cannot_load_asset, file.path().string()));

         if (!textures.contains(file.path().stem()))
            textures.insert({file.path().stem(), std::make_shared<sf::Texture>(std::move(texture))});
      }
   }

   void AssetManager::load_sound_dir(const fs::path& directory,
                                     bool relative_to_root,
                                     bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory: directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      for (const auto& file : fs::directory_iterator(full_path))
      {
         if (file.is_directory() && recursive)
            load_sound_dir(file.path(), false);

         if (!file.is_regular_file() || !sound_extensions.contains(file.path().extension()))
            continue;

         sf::SoundBuffer sound;

         if (!sound.loadFromFile(file.path()))
            throw std::runtime_error(std::format(errors::asset::cannot_load_asset, file.path().string()));

         if (!sounds.contains(file.path().stem()))
            sounds.insert({file.path().stem(), std::make_shared<sf::SoundBuffer>(std::move(sound))});
      }
   }

   void AssetManager::load_song_dir(const fs::path& directory,
                                    bool relative_to_root,
                                    bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      for (const auto& file : fs::directory_iterator(full_path))
      {
         if (file.is_directory() && recursive)
            load_song_dir(file.path(), false);

         if (!file.is_regular_file() || !music_extensions.contains(file.path().extension()))
            continue;

         if (!music.contains(file.path().stem()))
            music.insert({file.path().stem(), std::make_shared<fs::path>(file.path())});
      }
   }

   void AssetManager::load_font_dir(const fs::path& directory,
                                    bool relative_to_root,
                                    bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      for (const auto& file : fs::directory_iterator(full_path))
      {
         if (file.is_directory() && recursive)
            load_font_dir(file.path(), false);

         if (!file.is_regular_file() || !font_extensions.contains(file.path().extension()))
            continue;

         sf::Font font;

         if (!font.loadFromFile(file.path()))
            throw std::runtime_error(std::format(errors::asset::cannot_load_asset, file.path().string()));

         if (!fonts.contains(file.path().stem()))
            fonts.insert({file.path().stem(), std::make_shared<sf::Font>(std::move(font))});
      }
   }

   void AssetManager::load_texture_dir_async(const Callback& on_finished,
                                             const fs::path& directory,
                                             bool relative_to_root,
                                             bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      std::thread([=, this]()
      {
         try
         {
            std::function<void(const fs::path&, bool)> load_files = [&](const fs::path& dir, bool rec)
            {
               for (const auto& file : fs::directory_iterator(dir))
               {
                  if (file.is_directory() && rec)
                     load_files(file.path(), false);

                  // Skip files with other extensions
                  if (!file.is_regular_file() || !texture_extensions.contains(file.path().extension()))
                     continue;

                  sf::Texture texture;

                  if (!texture.loadFromFile(file.path()))
                     throw std::runtime_error(std::format(errors::asset::cannot_load_asset, file.path().string()));

                  std::lock_guard<std::mutex> lock(texture_mutex);

                  if (!textures.contains(file.path().stem()))
                     textures.insert({file.path().stem(), std::make_shared<sf::Texture>(std::move(texture))});
               }
            };

            load_files(full_path, recursive);

            if (on_finished)
               on_finished(true);
         }
         catch (const std::exception& e)
         {
            std::cerr << "Error in 'AssetManager::load_texture_dir_async': " << e.what() << std::endl;
            if (on_finished)
               on_finished(false);
         }
      }).detach();
   }

   void AssetManager::load_sound_dir_async(const Callback& on_finished,
                                           const fs::path& directory,
                                           bool relative_to_root,
                                           bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      std::thread([=, this]()
      {
         try
         {
            std::function<void(const fs::path&, bool)> load_files = [&](const fs::path& dir, bool rec)
            {
               for (const auto& file : fs::directory_iterator(dir))
               {
                  if (file.is_directory() && rec)
                     load_files(file.path(), false);

                  if (!file.is_regular_file() || !sound_extensions.contains(file.path().extension()))
                     continue;

                  sf::SoundBuffer sound;

                  if (!sound.loadFromFile(file.path()))
                     throw std::runtime_error(std::format(errors::asset::cannot_load_asset, file.path().string()));

                  std::lock_guard<std::mutex> lock(sound_mutex);

                  if (!sounds.contains(file.path().stem()))
                     sounds.insert({file.path().stem(), std::make_shared<sf::SoundBuffer>(std::move(sound))});
               }
            };

            load_files(full_path, recursive);

            if (on_finished)
               on_finished(true);
         }
         catch (const std::exception& e)
         {
            std::cerr << "Error in 'AssetManager::loadDirtAsync': " << e.what() << std::endl;
            if (on_finished)
               on_finished(false);
         }
      }).detach();
   }

   void AssetManager::load_song_dir_async(const Callback& on_finished,
                                          const fs::path& directory,
                                          bool relative_to_root,
                                          bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      std::thread([=, this]()
      {
         try
         {
            std::function<void(const fs::path&, bool)> load_files = [&](const fs::path& dir, bool rec)
            {
               for (const auto& file : fs::directory_iterator(dir))
               {
                  if (file.is_directory() && rec)
                     load_files(file.path(), false);

                  if (!file.is_regular_file() || !music_extensions.contains(file.path().extension()))
                     continue;

                  std::lock_guard<std::mutex> lock(music_mutex);

                  if (!music.contains(file.path().stem()))
                     music.insert({file.path().stem(), std::make_shared<fs::path>(std::move(file.path()))});
               }
            };

            load_files(full_path, recursive);

            if (on_finished)
               on_finished(true);
         }
         catch (const std::exception& e)
         {
            std::cerr << "Error in 'AssetManager::loadDirtAsync': " << e.what() << std::endl;
            if (on_finished)
               on_finished(false);
         }
      }).detach();
   }

   void AssetManager::load_font_dir_async(const Callback& on_finished,
                                          const fs::path& directory,
                                          bool relative_to_root,
                                          bool recursive)
   {
      const fs::path full_path ((relative_to_root ? root / directory : directory));

      if (!fs::exists(full_path))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, full_path.string()));

      if (!fs::is_directory(full_path))
         throw std::runtime_error(std::format(errors::asset::path_not_dir, full_path.string()));

      std::thread([=, this]()
      {
         try
         {
            std::function<void(const fs::path&, bool)> load_files = [&](const fs::path& dir, bool rec)
            {
               for (const auto& file : fs::directory_iterator(dir))
               {
                  if (file.is_directory() && rec)
                     load_files(file.path(), false);

                  if (!file.is_regular_file() || !font_extensions.contains(file.path().extension()))
                     continue;

                  sf::Font font;

                  if (!font.loadFromFile(file.path()))
                     throw std::runtime_error(std::format(errors::asset::cannot_load_asset, file.path().string()));

                  std::lock_guard<std::mutex> lock(font_mutex);

                  if (!fonts.contains(file.path().stem()))
                     fonts.insert({file.path().stem(), std::make_shared<sf::Font>(std::move(font))});
               }
            };

            load_files(full_path, recursive);

            if (on_finished)
               on_finished(true);
         }
         catch (const std::exception& e)
         {
            std::cerr << "Error in 'AssetManager::loadDirtAsync': " << e.what() << std::endl;
            if (on_finished)
               on_finished(false);
         }
      }).detach();
   }

   // Insert functions

   const AssetManager::texture_t& AssetManager::insert_texture(const std::string& identifier,
                                                               const sf::Texture& texture)
   {
      if (!textures.contains(identifier))
         textures.insert({identifier, std::make_shared<sf::Texture>(std::move(texture))});
      return textures[identifier];
   }

   const AssetManager::sound_t& AssetManager::insert_sound(const std::string& identifier,
                                                           const sf::SoundBuffer& sound)
   {
      if (!sounds.contains(identifier))
         sounds.insert({identifier, std::make_shared<sf::SoundBuffer>(std::move(sound))});
      return sounds[identifier];
   }

   const AssetManager::music_t& AssetManager::insert_song(const std::string& identifier,
                                                          const fs::path& song)
   {
      if (music.contains(identifier))
         return music[identifier];

      if (!fs::exists(song))
         throw std::runtime_error(std::format( errors::asset::path_does_not_exist, song.string()));

      if (!fs::is_regular_file(song))
         throw std::runtime_error(std::format( errors::asset::path_not_file, song.string()));

      if (!music_extensions.contains(song.extension()))
         throw std::runtime_error(std::format(errors::asset::invalid_extension, identifier, song.extension().string()));

      music.insert({identifier, std::make_shared<fs::path>(std::move(song))});
      return music[identifier];
   }

   const AssetManager::font_t& AssetManager::insert_font(const std::string& identifier,
                                                         const sf::Font& font)
   {
      if (!fonts.contains(identifier))
         fonts.insert({identifier, std::make_shared<sf::Font>(std::move(font))});
      return fonts[identifier];
   }

   // Get functions

   const AssetManager::texture_t& AssetManager::get_texture(const std::string& identifier)
   {
      if (!textures.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));
      return textures[identifier];
   }

   const AssetManager::sound_t& AssetManager::get_sound(const std::string& identifier)
   {
      if (!sounds.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));
      return sounds[identifier];
   }

   const AssetManager::music_t& AssetManager::get_song(const std::string& identifier)
   {
      if (!music.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));
      return music[identifier];
   }

   const AssetManager::font_t& AssetManager::get_font(const std::string& identifier)
   {
      if (!fonts.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));
      return fonts[identifier];
   }

   // Update functions

   const AssetManager::texture_t& AssetManager::update_texture(const std::string& identifier,
                                                               const sf::Texture& texture)
   {
      if (!textures.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));

      textures[identifier] = std::make_shared<sf::Texture>(std::move(texture));
      return textures[identifier];
   }

   const AssetManager::sound_t& AssetManager::update_sound(const std::string& identifier,
                                                           const sf::SoundBuffer& sound)
   {
      if (!sounds.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));

      sounds[identifier] = std::make_shared<sf::SoundBuffer>(std::move(sound));
      return sounds[identifier];
   }

   const AssetManager::music_t& AssetManager::update_song(const std::string& identifier,
                                                          const fs::path& song)
   {
      if (!music.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));

      if (!fs::exists(song))
         throw std::runtime_error(std::format(errors::asset::path_does_not_exist, song.string()));

      if (!fs::is_regular_file(song))
         throw std::runtime_error(std::format(errors::asset::path_not_file, song.string()));

      if (!music_extensions.contains(song.extension()))
         throw std::runtime_error(std::format(errors::asset::invalid_extension, identifier, song.extension().string()));

      music[identifier] = std::make_shared<fs::path>(std::move(song));
      return music[identifier];
   }

   const AssetManager::font_t& AssetManager::update_font(const std::string& identifier,
                                                         const sf::Font& font)
   {
      if (!fonts.contains(identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, identifier));

      fonts[identifier] = std::make_shared<sf::Font>(std::move(font));
      return fonts[identifier];
   }

   // Rename functions

   void AssetManager::rename_texture(const std::string& old_identifier,
                                     const std::string& new_identifier)
   {
      if (!textures.contains(old_identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, old_identifier));

      if (textures.contains(new_identifier))
         throw std::runtime_error(std::format(errors::asset::cannot_rename_asset, old_identifier, new_identifier));

      const auto& oldValue {textures[old_identifier]};
      textures.insert({new_identifier, std::move(oldValue)});
      textures.erase(old_identifier);
   }

   void AssetManager::rename_sound(const std::string& old_identifier,
                                   const std::string& new_identifier)
   {
      if (!sounds.contains(old_identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, old_identifier));

      if (sounds.contains(new_identifier))
         throw std::runtime_error(std::format(errors::asset::cannot_rename_asset, old_identifier, new_identifier));

      const auto& oldValue {sounds[old_identifier]};
      sounds.insert({new_identifier, std::move(oldValue)});
      sounds.erase(old_identifier);
   }

   void AssetManager::rename_song(const std::string& old_identifier,
                                  const std::string& new_identifier)
   {
      if (!music.contains(old_identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, old_identifier));

      if (music.contains(new_identifier))
         throw std::runtime_error(std::format(errors::asset::cannot_rename_asset, old_identifier, new_identifier));

      const auto& oldValue {music[old_identifier]};
      music.insert({new_identifier, std::move(oldValue)});
      music.erase(old_identifier);
   }

   void AssetManager::rename_font(const std::string& old_identifier,
                                  const std::string& new_identifier)
   {
      if (!fonts.contains(old_identifier))
         throw std::runtime_error(std::format(errors::asset::asset_does_not_exist, old_identifier));

      if (fonts.contains(new_identifier))
         throw std::runtime_error(std::format(errors::asset::cannot_rename_asset, old_identifier, new_identifier));

      const auto& oldValue {fonts[old_identifier]};
      fonts.insert({new_identifier, std::move(oldValue)});
      fonts.erase(old_identifier);
   }

   // Find functions

   bool AssetManager::find_texture(const std::string& identifier) const
   {
      return textures.contains(identifier);
   }

   bool AssetManager::find_sound(const std::string& identifier) const
   {
      return sounds.contains(identifier);
   }

   bool AssetManager::find_song(const std::string& identifier) const
   {
      return music.contains(identifier);
   }

   bool AssetManager::find_font(const std::string& identifier) const
   {
      return fonts.contains(identifier);
   }

   // Unload functions

   void AssetManager::unload_texture(const std::string& identifier)
   {
      textures.erase(identifier);
   }

   void AssetManager::unload_sound(const std::string& identifier)
   {
      sounds.erase(identifier);
   }

   void AssetManager::unload_song(const std::string& identifier)
   {
      music.erase(identifier);
   }

   void AssetManager::unload_font(const std::string& identifier)
   {
      fonts.erase(identifier);
   }

   void AssetManager::unload_textures()
   {
      textures.clear();
   }

   void AssetManager::unload_sounds()
   {
      sounds.clear();
   }

   void AssetManager::unload_music()
   {
      music.clear();
   }

   void AssetManager::unload_fonts()
   {
      fonts.clear();
   }

   void AssetManager::unload_everything()
   {
      textures.clear();
      sounds.clear();
      music.clear();
      fonts.clear();
   }
}
