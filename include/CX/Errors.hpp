#ifndef CX_ERRORS_HPP
#define CX_ERRORS_HPP

namespace cx::errors
{
   namespace vector
   {
      static constexpr const char* division_by_zero2 = "'Vec2' attempted to divide by zero.";
      static constexpr const char* division_by_zero4 = "'Vec4' attempted to divide by zero.";
      static constexpr const char* division_by_zero5 = "'Vec5' attempted to divide by zero.";
      static constexpr const char* out_of_bounds2    = "'Vec2' index out of bounds at '[]' operator or 'at' function. Index 0 - 'x', index 1 - 'y'.";
      static constexpr const char* out_of_bounds4    = "'Vec4' index out of bounds at '[]' operator or 'at' function. Index 0 - 'x', index 1 - 'y', index 2 - 'w', index 3 - 'h'.";
      static constexpr const char* out_of_bounds5    = "'Vec5' index out of bounds at '[]' operator or 'at' function. Index 0 - 'x', index 1 - 'y', index 2 - 'w', index 3 - 'h', index 4 - 'r'.";
   }

   namespace color
   {
      static constexpr const char* out_of_bounds = "'Color' index out of bounds at '[]' operator or 'at' function. Index 0 - 'r', index 1 - 'g', index 2 - 'b', index 3 - 'a'.";
   }

   namespace grid
   {
      static constexpr const char* invalid_count      = "'Grid' cannot have less than 1 column and row. Source: 'set_cell_count'.";
      static constexpr const char* invalid_columns    = "'Grid' cannot have less than 1 column. Sources: 'Grid', 'set_column_count', 'get_grid_cell', 'get_cell_position', 'place', 'snap' or 'debug_render'.";
      static constexpr const char* invalid_rows       = "'Grid' cannot have less than 1 row. Sources: 'Grid', 'set_row_count', 'get_grid_cell', 'get_cell_position', 'place', 'snap' or 'debug_render'.";
      static constexpr const char* invalid_column_pos = "'Grid' invalid column position. Source: 'place', 'snap' or 'get_cell_position'.";
      static constexpr const char* invalid_row_pos    = "'Grid' invalid row position. Source: 'place', 'snap' or 'get_cell_position'.";
   }

   namespace text
   {
      static constexpr const char* invalid_font = "'Text'/'Button' uninitialized font. Sources: 'Text', 'Button' or 'set_font'.";
   }

   namespace slider
   {
      static constexpr const char* could_not_load_shader = "'Slider' Could not load clipping_shader.frag. Source: 'Slider'.";
   }

   namespace asset
   {
      static constexpr const char* path_does_not_exist  = "'AssetManager' path '{}' does not exist. Sources: 'asset_manager', 'set_root_directory', 'load' or 'load_dir'.";
      static constexpr const char* path_not_dir         = "'AssetManager' path '{}' is not a directory. Sources: 'asset_manager', 'set_root_directory' or 'load_dir'.";
      static constexpr const char* path_not_file        = "'AssetManager' path '{}' is not a file. Sources: 'insert' or 'update'.";
      static constexpr const char* asset_does_not_exist = "'AssetManager' could not get asset '{}' as it does not exist. Sources: 'get', 'update' or 'rename'.";
      static constexpr const char* cannot_load_asset    = "'AssetManager' could not load asset '{}'. Source: 'load'.";
      static constexpr const char* cannot_rename_asset  = "'AssetManager' could not rename asset '{}' to '{}' as an asset with the same name already exists. Source: 'rename'.";
      static constexpr const char* invalid_extension    = "'AssetManager' could not update asset '{}' as it has an invalid extension '{}'. Sources: 'insert', 'load' or 'update'.";
   }

   namespace audio
   {
      static constexpr const char* sound_doesnot_exist   = "'AudioManager' could not play sound '{}' as it does not exist. Sources: 'play_saved_sound', 'play_sound' or 'play_random_sound'.";
      static constexpr const char* sound_is_not_saved    = "'AudioManager' could not play saved sound '{}' as it doesn't exist. Source: 'play_saved_sound'.";
      static constexpr const char* song_cannot_be_played = "'AudioManager' could not play song '{}' as file cannot be opened. Sources: 'play_music', 'set_music_pool' or 'update'.";
   }

   namespace navigation
   {
      static constexpr const char* index_taken   = "'NavigationManager' could not add element as index '{}' is taken. Source: 'add_element'.";
      static constexpr const char* invalid_index = "'NavigationManager' could not get element as index '{}' was not found. Source: 'get_element'.";
      static constexpr const char* no_selection  = "'NavigationManager' could not get selected element as there is no selection. Source 'get_selected_element'.";
   }
}

#endif
