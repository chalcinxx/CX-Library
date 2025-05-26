#ifndef CX_GRID_HPP
#define CX_GRID_HPP

#include "CX/UIElement/UIElement.hpp"

namespace cx
{
   /// @brief Place elements in an organized manner.
   struct Grid
   {
      /// @brief Element placement in cells.
      enum class Alignment : char
      {
         default_,      ///< @brief Default position.
         corner,        ///< @brief Top-left corner.
         bottom_corner, ///< @brief Bottom-right corner.
         top,           ///< @brief Top center.
         center,        ///< @brief Center.
         bottom,        ///< @brief Bottom center.
         left,          ///< @brief Left center.
         right          ///< @brief Right center.
      };

      // Constructors

      /// @brief Create a default grid.
      Grid() = default;
      ~Grid() = default;

      /// @brief Create a new grid.
      /// @param size Size of the grid.
      /// @param columns Column count 1 to 127.
      /// @param rows Row count 1 to 127.
      /// @param position Center position of the grid.
      /// @param alignment Alignment of elements.
      constexpr Grid(const Vec2f& size,
                     char columns,
                     char rows,
                     const Vec2f& position = Vec2f(),
                     Alignment alignment = Alignment::corner)
         : grid_pos(position), grid_size(size), column_count(columns), row_count(rows), grid_alignment(alignment)
      {
         if (column_count <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (row_count <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         grid_pos += grid_size * -.5f;
         grid_scale = Vec2f(1.f);
      }

      // Constructors after creation

      /// @brief Create a new grid.
      /// @param size Size of the grid.
      /// @param columns Column count 1 to 127.
      /// @param rows Row count 1 to 127.
      /// @param position Center position of the grid.
      /// @param alignment Alignment of elements.
      constexpr void create(const Vec2f& size,
                            char columns,
                            char rows,
                            const Vec2f& position = Vec2f(),
                            Alignment alignment = Alignment::corner)
      {
         if (column_count <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (row_count <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         grid_size = size;
         grid_pos = position + grid_size * -.5f;
         grid_scale = Vec2f(1.f);
         column_count = columns;
         row_count = rows;
         grid_alignment = alignment;
      }

      /// @brief Create a grid from boundaries.
      /// @param bounds Boundaries.
      constexpr void from_bounds(const Vec4f& bounds)
      {
         grid_pos = bounds.get_top_left();
         grid_size = bounds.get_size();
         grid_scale = Vec2f(1.f);
      }

      /// @brief Create a grid from boundaries.
      /// @param bounds Boundaries.
      constexpr void from_bounds(const Vec5f& bounds)
      {
         from_bounds(bounds.un_rotated());
      }

      // Setter functions

      /// @brief Change center position of the grid.
      /// @param position New position.
      constexpr void set_center(const Vec2f& position)
      {
         grid_pos = position + grid_size * -.5f * grid_scale;
      }

      /// @brief Change center position of the grid.
      /// @param center_x New X position.
      /// @param center_y New Y position.
      constexpr void set_center(float center_x, float center_y)
      {
         set_center(Vec2f(center_x, center_y));
      }

      /// @brief Change center position of the grid.
      /// @param position New position.
      constexpr void set_center(float position)
      {
         set_center(Vec2f(position));
      }

      /// @brief Change top-left position of the grid.
      /// @param position New position.
      constexpr void set_top_left(const Vec2f& position)
      {
         grid_pos = position;
      }

      /// @brief Change top-left position of the grid.
      /// @param left New X position.
      /// @param top New Y position.
      constexpr void set_top_left(float left, float top)
      {
         set_top_left(Vec2f(left, top));
      }

      /// @brief Change top-left position of the grid.
      /// @param position New position.
      constexpr void set_top_left(float position)
      {
         set_top_left(Vec2f(position));
      }

      /// @brief Change bottom-right position of the grid.
      /// @param position New position.
      constexpr void set_bottom_right(const Vec2f& position)
      {
         grid_pos = position + grid_size * grid_scale;
      }

      /// @brief Change bottom-right position of the grid.
      /// @param right New right position.
      /// @param bottom New bottom position.
      constexpr void set_bottom_right(float right, float bottom)
      {
         set_bottom_right(Vec2f(right, bottom));
      }

      /// @brief Change bottom-right position of the grid.
      /// @param position New position.
      constexpr void set_bottom_right(float position)
      { 
         set_bottom_right(Vec2f(position));
      }

      /// @brief Change size of the grid.
      /// @param size New size.
      constexpr void set_size(const Vec2f& size)
      {
         const Vec2f center (grid_pos + grid_size * .5f * grid_scale);
         grid_size = size;
         grid_pos = center + grid_size * -.5f * grid_scale;
      }

      /// @brief Change size of the grid.
      /// @param width New X size.
      /// @param height New Y size.
      constexpr void set_size(float width, float height)
      {
         set_size(Vec2f(width, height));
      }

      /// @brief Change size of the grid.
      /// @param size New size.
      constexpr void set_size(float size)
      {
         set_size(Vec2f(size));
      }

      /// @brief Change width of the grid.
      /// @param width New width.
      constexpr void set_width(float width)
      {
         set_size(Vec2f(width, grid_size.y));
      }

      /// @brief Change height of the grid.
      /// @param height New height.
      constexpr void set_height(float height)
      {
         set_size(Vec2f(grid_size.x, height));
      }

      /// @brief Change scale of the grid.
      /// @param scale New scale.
      constexpr void set_scale(const Vec2f& scale)
      {
         const Vec2f center (grid_pos + grid_size * .5f * grid_scale);
         grid_scale = scale;
         grid_pos = center + grid_size * -.5f * grid_scale;
      }

      /// @brief Change scale of the grid.
      /// @param scale_x New X scale.
      /// @param scale_y New Y scale.
      constexpr void set_scale(float scale_x, float scale_y)
      {
         set_scale(Vec2f(scale_x, scale_y));
      }

      /// @brief Change scale of the grid.
      /// @param scale New scale.
      constexpr void set_scale(float scale)
      {
         set_scale(Vec2f(scale));
      }

      /// @brief Change column and row count of the grid.
      /// @param columns New count 1 to 127.
      /// @param rows New count 1 to 127.
      constexpr void set_cell_count(char columns, char rows)
      {
         if (columns <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (rows <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         column_count = columns;
         row_count = rows;
      }

      /// @brief Change column and row count of the grid.
      /// @param count New count 1 to 127.
      constexpr void set_cell_count(char count)
      {
         if (count <= 0)
            throw std::runtime_error(errors::grid::invalid_count);
         column_count = row_count = count;
      }

      /// @brief Change column count of the grid.
      /// @param columns New count 1 to 127.
      constexpr void set_column_count(char columns)
      {
         if (columns <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);
         column_count = columns;
      }

      /// @brief Change row count of the grid.
      /// @param rows New count 1 to 127.
      constexpr void set_row_count(char rows) 
      {
         if (rows <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);
         row_count = rows;
      }

      /// @brief Change element alignment of the grid.
      /// @param alignment New alignment.
      constexpr void set_alignment(Alignment alignment)
      {
         grid_alignment = alignment;
      }

      // Getter functions

      /// @brief Get grid center.
      /// @return Center.
      constexpr Vec2f get_center() const
      {
         return grid_pos + grid_size * .5f * grid_scale;
      }

      /// @brief Get grid top-left position.
      /// @return Position.
      constexpr const Vec2f& get_top_left() const
      {
         return grid_pos;
      }

      /// @brief Get grid bottom-right position.
      /// @return Position.
      constexpr Vec2f get_bottom_right() const
      {
         return grid_pos + grid_size * grid_scale;
      }

      /// @brief Get grid size.
      /// @return Size.
      constexpr const Vec2f& get_size() const
      {
         return grid_size;
      }

      /// @brief Get grid scale.
      /// @return Scale.
      constexpr const Vec2f& get_scale() const
      {
         return grid_scale;
      }

      /// @brief Get grid global boundaries.
      /// @return Global boundaries.
      constexpr Vec5f get_bounds() const
      {
         return Vec5f(grid_pos, grid_size * grid_scale.abs(), 0.f);
      }

      /// @brief Get grid local boundaries.
      /// @return Local boundaries.
      constexpr Vec5f get_local_bounds() const
      {
         return Vec5f(grid_pos, grid_size, 0.f);
      }

      /// @brief Get grid global boundaries without rotation.
      /// @return Simple boundaries.
      constexpr Vec4f get_simple_bounds() const
      {
         return Vec4f(grid_pos, grid_size * grid_scale.abs());
      }

      /// @brief Get grid width.
      /// @return Width.
      constexpr float get_width() const
      {
         return grid_size.x;
      }

      /// @brief Get grid height.
      /// @return Height.
      constexpr float get_height() const
      {
         return grid_size.y;
      }

      /// @brief Get grid X center.
      /// @return X center.
      constexpr float get_center_x() const
      {
         return grid_pos.x + grid_size.x * .5f * grid_scale.x;
      }

      /// @brief Get grid Y center.
      /// @return Y center.
      constexpr float get_center_y() const
      {
         return grid_pos.y + grid_size.y * .5f * grid_scale.y;
      }

      /// @brief Get X position.
      /// @return X position.
      constexpr float get_left() const
      {
         return grid_pos.x;
      }

      /// @brief Get Y position.
      /// @return Y position.
      constexpr float get_top() const
      {
         return grid_pos.y;
      }

      /// @brief Get right position.
      /// @return Right position.
      constexpr float get_right() const
      {
         return grid_pos.x + grid_size.x * grid_scale.x; 
      }

      /// @brief Get bottom position.
      /// @return Bottom position.
      constexpr float get_bottom() const
      {
         return grid_pos.y + grid_size.y * grid_scale.y;
      }

      /// @brief Get grid column count.
      /// @return Column count.
      constexpr char get_column_count() const
      {
         return column_count;
      }

      /// @brief Get grid row count.
      /// @return Row count.
      constexpr char get_row_count() const
      {
         return row_count;
      }

      /// @brief Get grid alignment type.
      /// @return Alignment.
      constexpr Alignment get_alignment() const
      {
         return grid_alignment;
      }

      // Update grid

      /// @brief Move the grid.
      /// @param offset Amount to move by.
      constexpr void move(const Vec2f& offset)
      {
         grid_pos += offset;
      }

      /// @brief Move the grid.
      /// @param offset_x Amount to move by horizontally.
      /// @param offset_y Amount to move by vertically.
      constexpr void move(float offset_x, float offset_y)
      {
         grid_pos += Vec2f(offset_x, offset_y);
      }

      /// @brief Move the grid.
      /// @param offset Amount to move by.
      constexpr void move(float offset)
      {
         grid_pos += Vec2f(offset);
      }

      /// @brief Scale the grid.
      /// @param scale Amount to scale by.
      constexpr void scale(const Vec2f& scale)
      {
         set_scale(grid_scale * scale);
      }

      /// @brief Scale the grid.
      /// @param scale_x Amount to scale by horizontally.
      /// @param scale_y Amount to scale by vertically.
      constexpr void scale(float scale_x, float scale_y)
      {
         set_scale(grid_scale * Vec2f(scale_x, scale_y));
      }

      /// @brief Scale the grid.
      /// @param scale Amount to scale by.
      constexpr void scale(float scale)
      {
         set_scale(grid_scale * scale);
      }

      // Math functions

      /// @brief Get cell size.
      /// @return Cell size.
      constexpr Vec2f get_cell_size() const
      {
         const Vec2f size (grid_size * grid_scale);
         return Vec2f(size.x / column_count, size.y / row_count);
      }

      /// @brief Get cell width.
      /// @return Cell width.
      constexpr float get_cell_width() const
      {
         return grid_size.x * grid_scale.x / column_count;
      }

      /// @brief Get cell height.
      /// @return Cell height.
      constexpr float get_cell_height() const
      {
         return grid_size.y * grid_scale.y / row_count;
      }

      /// @brief Get column and row from position.
      /// @param position Position.
      /// @return Column and row if inside grid, [-1, -1] if outside.
      constexpr Vec2<char> get_grid_cell(const Vec2f& position) const
      {
         if (column_count <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (row_count <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         if (!get_bounds().contains(position))
            return Vec2<char>(-1);

         const Vec2f scaled (position - grid_pos);
         return Vec2<char>(
            std::min<char>(static_cast<char>(scaled.x / get_cell_width()), column_count - 1),
            std::min<char>(static_cast<char>(scaled.y / get_cell_height()), row_count - 1)
         );
      }

      /// @brief Get cell position from row and column.
      /// @param column Column index.
      /// @param row Row index.
      /// @param alignment Alignment type.
      constexpr Vec2f get_cell_position(char column,
                                        char row,
                                        Alignment alignment = Alignment::default_) const
      {
         if (column_count <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (row_count <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         if (column > column_count || column < 0)
            throw std::runtime_error(errors::grid::invalid_column_pos);

         if (row > row_count || row < 0)
            throw std::runtime_error(errors::grid::invalid_row_pos);

         const auto offset = get_offset(alignment);
         return Vec2f(
            (grid_size.x * grid_scale.x / column_count) * (column + offset.x) + grid_pos.x,
            (grid_size.y * grid_scale.y / row_count) * (row + offset.y) + grid_pos.y
         );
      }

      /// @brief Snap position to closest cell.
      /// @param position Position to snap.
      /// @return Snapped position.
      constexpr Vec2f snap(const Vec2f& position) const
      {
         const Vec2<char> pos = get_grid_cell(position);

         if (pos.x < 0 || pos.y < 0)
            return position;
         return get_cell_position(pos.x, pos.y);
      }

      /// @brief Position an element.
      /// @param element Element to position.
      /// @param column Column index.
      /// @param row Row index.
      /// @param alignment Alignment type.
      constexpr void place(UIElement& element,
                           char column,
                           char row,
                           Alignment alignment = Alignment::default_) const
      {
         if (column_count <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (row_count <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         if (column > column_count || column < 0)
            throw std::runtime_error(errors::grid::invalid_column_pos);

         if (row > row_count || row < 0)
            throw std::runtime_error(errors::grid::invalid_row_pos);

         const auto offset = get_offset(alignment);
         element.set_center(Vec2f(
            (grid_size.x * grid_scale.x / column_count) * (column + offset.x) + grid_pos.x,
            (grid_size.y * grid_scale.y / row_count) * (row + offset.y) + grid_pos.y
         ));
      }

      /// @brief Position a grid.
      /// @param grid Grid to position.
      /// @param column Column index.
      /// @param row Row index.
      /// @param alignment Alignment type.
      constexpr void place(Grid& grid,
                           char column,
                           char row,
                           Alignment alignment = Alignment::default_) const
      {
         if (column_count <= 0)
            throw std::runtime_error(errors::grid::invalid_columns);

         if (row_count <= 0)
            throw std::runtime_error(errors::grid::invalid_rows);

         if (column > column_count || column < 0)
            throw std::runtime_error(errors::grid::invalid_column_pos);

         if (row > row_count || row < 0)
            throw std::runtime_error(errors::grid::invalid_row_pos);

         const auto offset = get_offset(alignment);
         grid.set_center(Vec2f(
            (grid_size.x * grid_scale.x / column_count) * (column + offset.x) + grid_pos.x,
            (grid_size.y * grid_scale.y / row_count) * (row + offset.y) + grid_pos.y
         ));
      }

   private:
      Vec2f grid_pos;
      Vec2f grid_size;
      char column_count = 1;
      char row_count = 1;
      Alignment grid_alignment = Alignment::corner;
      Vec2f grid_scale;

      /// @brief Get offset based on grid alignment.
      /// @param alignment Grid alignment.
      /// @return Offset.
      constexpr Vec2f get_offset(Alignment alignment) const
      {
         switch ((alignment == Alignment::default_ ? grid_alignment : alignment))
         {
         case Alignment::default_:
         case Alignment::corner:
            return {};
         case Alignment::bottom_corner:
            return {1.f};
         case Alignment::center:
            return {.5f};
         case Alignment::bottom:
            return {.5f, 1.f};
         case Alignment::left:
            return {0.f, .5f};
         case Alignment::right:
            return {1.f, .5f};
         case Alignment::top:
            return {.5f, 0.f};
         }
      }
   };
}

#endif
