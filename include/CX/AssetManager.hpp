#ifndef CX_ASSET_MANAGER_HPP
#define CX_ASSET_MANAGER_HPP

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>
#include <functional>
#include <mutex>
#include <unordered_map>
#include <unordered_set>

namespace fs = std::filesystem;

namespace cx
{
   /// @brief Load, unload and retrieve assets.
   class AssetManager
   {
   public:
      // Type aliases

      using texture_t = std::shared_ptr<sf::Texture>;
      using sound_t   = std::shared_ptr<sf::SoundBuffer>;
      using music_t   = std::shared_ptr<fs::path>;
      using font_t    = std::shared_ptr<sf::Font>;

      // Constructors
   
      /// @brief Create a default asset manager.
      AssetManager() = default;
      ~AssetManager() = default;

      /// @brief Create a new asset manager.
      /// @param root_directory Root directory.
      AssetManager(const fs::path& root_directory);

      // File functions

      /// @brief Check if path is valid.
      /// @param path Path.
      /// @param relative_to_root Is path relative to root.
      /// @return True if path is valid.
      bool is_path_valid(const fs::path& path, bool relative_to_root = true) const;

      /// @brief Check if path is a file.
      /// @param path Path.
      /// @param relative_to_root Is path relative to root.
      /// @return True if path is a file.
      bool file_exists(const fs::path& path, bool relative_to_root = true) const;

      /// @brief Check if path is a directory.
      /// @param path Path.
      /// @param relative_to_root Is path relative to root.
      /// @return True if path is a directory.
      bool dir_exists(const fs::path& path, bool relative_to_root = true) const;

      // Root directory functions

      /// @brief Set root directory.
      /// @param root_directory Root directory.
      void set_root_directory(const fs::path& root_directory);

      /// @brief Get root directory.
      /// @return Root directory.
      const fs::path& get_root_directory() const;

      // Load functions

      /// @brief Load or retrieve a texture.
      /// @param identifier New identifier.
      /// @param path Path to texture.
      /// @param relative_to_root Is path relative to root.
      /// @return Texture.
      const texture_t& load_texture(const std::string& identifier,
                                    const fs::path& path,
                                    bool relative_to_root = true);

      /// @brief Load or retrieve a sound.
      /// @param identifier New identifier.
      /// @param path Path to sound.
      /// @param relative_to_root Is path relative to root.
      /// @return Sound.
      const sound_t& load_sound(const std::string& identifier,
                                const fs::path& path,
                                bool relative_to_root = true);

      /// @brief Load or retrieve a song.
      /// @param identifier New identifier.
      /// @param path Path to song.
      /// @param relative_to_root Is path relative to root.
      /// @return Song.
      const music_t& load_song(const std::string& identifier,
                               const fs::path& path,
                               bool relative_to_root = true);

      /// @brief Load or retrieve a font.
      /// @param identifier New identifier.
      /// @param path Path to font.
      /// @param relative_to_root Is path relative to root.
      /// @return Font.
      const font_t& load_font(const std::string& identifier,
                              const fs::path& path,
                              bool relative_to_root = true);

      /// @brief Load or retrieve texture. Gives same identifier as file name.
      /// @param path Path to texture.
      /// @param relative_to_root Is path relative to root.
      /// @return Texture.
      const texture_t& load_texture(const fs::path& path, bool relative_to_root = true);

      /// @brief Load or retrieve a sound. Gives same identifier as file name.
      /// @param path Path to sound.
      /// @param relative_to_root Is path relative to root.
      /// @return Sound.
      const sound_t& load_sound(const fs::path& path, bool relative_to_root = true);

      /// @brief Load or retrieve a song. Gives same identifier as file name.
      /// @param path Path to song.
      /// @param relative_to_root Is path relative to root.
      /// @return Song.
      const music_t& load_song(const fs::path& path, bool relative_to_root = true);

      /// @brief Load or retrieve a font. Gives same identifier as file name.
      /// @param path Path to font.
      /// @param relative_to_root Is path relative to root.
      /// @return Font.
      const font_t& load_font(const fs::path& path, bool relative_to_root = true);

      // Load directory functions

      /// @brief Load all textures in a directory.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_texture_dir(const fs::path& directory = "",
                            bool relative_to_root = true,
                            bool recursive = true);

      /// @brief Load all sounds in a directory.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_sound_dir(const fs::path& directory = "",
                          bool relative_to_root = true,
                          bool recursive = true);

      /// @brief Load all songs in a directory.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_song_dir(const fs::path& directory = "",
                         bool relative_to_root = true,
                         bool recursive = true);

      /// @brief Load all fonts in a directory.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_font_dir(const fs::path& directory = "",
                         bool relative_to_root = true,
                         bool recursive = true);

      // Load directory async functions

      /// @brief Load all textures in a directory in the background.
      /// @param on_finished Called when finished.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_texture_dir_async(const std::function<void(bool)>& on_finished,
                                  const fs::path& directory = "",
                                  bool relative_to_root = true,
                                  bool recursive = true);

      /// @brief Load all sounds in a directory in the background.
      /// @param on_finished Called when finished.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_sound_dir_async(const std::function<void(bool)>& on_finished,
                                  const fs::path& directory = "",
                                  bool relative_to_root = true,
                                  bool recursive = true);

      /// @brief Load all songs in a directory in the background.
      /// @param on_finished Called when finished.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_song_dir_async(const std::function<void(bool)>& on_finished,
                            const fs::path& directory = "",
                            bool relative_to_root = true,
                            bool recursive = true);

      /// @brief Load all fonts in a directory in the background.
      /// @param on_finished Called when finished.
      /// @param directory Directory.
      /// @param relative_to_root Is directory relative to root.
      /// @param recursive Should subdirectories be loaded.
      void load_font_dir_async(const std::function<void(bool)>& on_finished,
                                  const fs::path& directory = "",
                                  bool relative_to_root = true,
                                  bool recursive = true);

      // Insert functions

      /// @brief Insert or retrieve a texture.
      /// @param identifier Identifier.
      /// @param texture Texture.
      /// @return Texture.
      const texture_t& insert_texture(const std::string& identifier, const sf::Texture& texture);

      /// @brief Insert or retrieve a sound.
      /// @param identifier Identifier.
      /// @param sound Sound.
      /// @return Sound.
      const sound_t& insert_sound(const std::string& identifier, const sf::SoundBuffer& sound);

      /// @brief Insert or retrieve a song.
      /// @param identifier Identifier.
      /// @param song Song.
      /// @return Song.
      const music_t& insert_song(const std::string& identifier, const fs::path& song);

      /// @brief Insert or retrieve a font.
      /// @param identifier Identifier.
      /// @param font Font.
      /// @return Font.
      const font_t& insert_font(const std::string& identifier, const sf::Font& font);

      // Get functions

      /// @brief Get texture or throw error.
      /// @param identifier Identifier.
      /// @return Texture.
      const texture_t& get_texture(const std::string& identifier);

      /// @brief Get sound or throw error.
      /// @param identifier Identifier.
      /// @return Sound.
      const sound_t& get_sound(const std::string& identifier);

      /// @brief Get song or throw error.
      /// @param identifier Identifier.
      /// @return Song.
      const music_t& get_song(const std::string& identifier);

      /// @brief Get font or throw error.
      /// @param identifier Identifier.
      /// @return Font.
      const font_t& get_font(const std::string& identifier);

      // Update functions

      /// @brief Update a texture.
      /// @param identifier Identifier.
      /// @param texture New texture.
      /// @return Texture.
      const texture_t& update_texture(const std::string& identifier, const sf::Texture& texture);

      /// @brief Update a sound.
      /// @param identifier Identifier.
      /// @param sound New sound.
      /// @return Sound.
      const sound_t& update_sound(const std::string& identifier, const sf::SoundBuffer& sound);

      /// @brief Update a song.
      /// @param identifier Identifier.
      /// @param song New song.
      /// @return Song.
      const music_t& update_song(const std::string& identifier, const fs::path& song);

      /// @brief Update a font.
      /// @param identifier Identifier.
      /// @param font New font.
      /// @return Font.
      const font_t& update_font(const std::string& identifier, const sf::Font& font);

      // Rename functions

      /// @brief Rename a texture.
      /// @param old_identifier Identifier.
      /// @param new_identifier New identifier.
      void rename_texture(const std::string& old_identifier, const std::string& new_identifier);
      
      /// @brief Rename a sound.
      /// @param old_identifier Identifier.
      /// @param new_identifier New identifier.
      void rename_sound(const std::string& old_identifier, const std::string& new_identifier);

      /// @brief Rename a song.
      /// @param old_identifier Identifier.
      /// @param new_identifier New identifier.
      void rename_song(const std::string& old_identifier, const std::string& new_identifier);

      /// @brief Rename a font.
      /// @param old_identifier Identifier.
      /// @param new_identifier New identifier.
      void rename_font(const std::string& old_identifier, const std::string& new_identifier);

      // Find functions

      /// @brief Check if texture exists.
      /// @param identifier Identifier.
      /// @return True if exists.
      bool find_texture(const std::string& identifier) const;

      /// @brief Check if sound exists.
      /// @param identifier Identifier.
      /// @return True if exists.
      bool find_sound(const std::string& identifier) const;

      /// @brief Check if song exists.
      /// @param identifier Identifier.
      /// @return True if exists.
      bool find_song(const std::string& identifier) const;

      /// @brief Check if font exists.
      /// @param identifier Identifier.
      /// @return True if exists.
      bool find_font(const std::string& identifier) const;

      // Unload functions

      /// @brief Unload a texture.
      /// @param identifier Identifier.
      void unload_texture(const std::string& identifier);

      /// @brief Unload a sound.
      /// @param identifier Identifier.
      void unload_sound(const std::string& identifier);

      /// @brief Unload a song.
      /// @param identifier Identifier.
      void unload_song(const std::string& identifier);

      /// @brief Unload a font.
      /// @param identifier Identifier.
      void unload_font(const std::string& identifier); 

      /// @brief Unload all textures.
      void unload_textures();

      /// @brief Unload all sounds.
      void unload_sounds();

      /// @brief Unload all music.
      void unload_music();

      /// @brief Unload all fonts.
      void unload_fonts();

      /// @brief Unload all assets.
      void unload_everything();

   private:
      /// @brief Texture extensions.
      inline static const std::unordered_set<std::string> texture_extensions
      {".bmp", ".dds", ".jpg", ".jpeg", ".png", ".tga", ".psd", ".gif", ".hdr", ".pic"};

      /// @brief Sound extensions.
      inline static const std::unordered_set<std::string> sound_extensions
      {".wav", ".ogg", ".flac", ".aiff", ".aif"};

      /// @brief Music extensions.
      inline static const std::unordered_set<std::string> music_extensions
      {".wav", ".ogg", ".flac", ".mid", ".midi"};

      /// @brief Font extensions.
      inline static const std::unordered_set<std::string> font_extensions
      {".ttf", ".otf", ".pfa", ".pfb", ".bmf"};

      fs::path root;

      std::unordered_map<std::string, texture_t> textures;
      std::unordered_map<std::string, sound_t>   sounds;
      std::unordered_map<std::string, music_t>   music;
      std::unordered_map<std::string, font_t>    fonts;

      std::mutex texture_mutex;
      std::mutex sound_mutex;
      std::mutex music_mutex;
      std::mutex font_mutex;
   };
}

#endif
