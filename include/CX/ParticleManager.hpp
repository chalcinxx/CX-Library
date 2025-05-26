#ifndef CX_PARTICLE_MANAGER_HPP
#define CX_PARTICLE_MANAGER_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "CX/Color.hpp"
#include "CX/Vector/Vec4.hpp"
#include <memory>

namespace cx
{
   /// @brief Particle struct used in particle manager.
   struct Particle
   {
      sf::RectangleShape particle; ///< @brief Particle.
      Vec2f velocity;              ///< @brief Amount to move the particle by each second.
      Vec2f acceleration;          ///< @brief Acceleration of velocity.
      Vec2f scale_velocity;        ///< @brief Amount to change scale by each second.
      float rot_velocity = 0.f;    ///< @brief Amount to rotate by each second.
      float friction = 0.f;        ///< @brief Amount to slow velocity by.
      float lifetime = 0.f;        ///< @brief Lifetime of the particle.
      float age = 0.f;             ///< @brief Age of the particle.
   };

   /// @brief Handle particles.
   class ParticleManager
   {
   public:
      // Constructors

      /// @brief Create a default particle manager.
      ParticleManager() = default;

      /// @brief Create a new particle manager.
      /// @param spawn_position Spawn position of the particles.
      /// @param particle_size Size of the particles.
      /// @param particle_count Maximum count of particles at once.
      /// @param life_time Life time of particles in seconds.
      /// @param spawn_rate Spawn rate of particles per second.
      ParticleManager(const Vec2f& spawn_position,
                      const Vec2f& particle_size,
                      size_t particle_count = 5,
                      float life_time = 5.f,
                      float spawn_rate = 5.f);
      ~ParticleManager() = default;

      // Constructors after creation

      /// @brief Create a new particle manager.
      /// @param spawn_position Spawn position of the particles.
      /// @param particle_size Size of the particles.
      /// @param particle_count Maximum count of particles at once.
      /// @param life_time Life time of particles in seconds.
      /// @param spawn_rate Spawn rate of particles per second.
      void create(const Vec2f& spawn_position,
                  const Vec2f& particle_size,
                  size_t particle_count = 5,
                  float lifetime = 5.f,
                  float spawn_rate = 5.f);

      // Setter functions

      /// @brief Set position based properties.
      /// @param position Spawn position.
      /// @param spawn_radius Spawn radius.
      void set_position_properties(const Vec2f& position, float spawn_radius);

      /// @brief Set position based properties.
      /// @param position Spawn position.
      /// @param spawn_radius_min Minimum spawn radius.
      /// @param spawn_radius_max Maximum spawn radius.
      void set_position_properties(const Vec2f& position,
                                   float spawn_radius_min,
                                   float spawn_radius_max);
      
      /// @brief Set particle spawn position.
      /// @param position Spawn position.
      void set_position(const Vec2f& position);

      /// @brief Set spawn radius.
      /// @param spawn_radius Spawn radius.
      void set_spawn_radius(float spawn_radius);

      /// @brief Set spawn radius.
      /// @param spawn_radius_min Minimum spawn radius.
      /// @param spawn_radius_max Maximum spawn radius.
      void set_spawn_radius(float spawn_radius_min, float spawn_radius_max);

      /// @brief Set velocity based properties.
      /// @param velocity Particle velocity.
      /// @param acceleration Particle acceleration.
      /// @param friction Particle friction.
      void set_velocity_properties(const Vec2f& velocity,
                                   const Vec2f& acceleration,
                                   float friction);

      /// @brief Set velocity based properties.
      /// @param velocity_min Minimum particle velocity.
      /// @param velocity_max Maximum particle velocity.
      /// @param acceleration_min Minimum particle acceleration.
      /// @param acceleration_max Maximum particle acceleration.
      /// @param friction_min Minimum particle friction.
      /// @param friction_max Maximum particle friction.
      void set_velocity_properties(const Vec2f& velocity_min,
                                   const Vec2f& velocity_max,
                                   const Vec2f& acceleration_min,
                                   const Vec2f& acceleration_max,
                                   float friction_min,
                                   float friction_max);

      /// @brief Set particle velocity.
      /// @param velocity Particle velocity.
      void set_velocity(const Vec2f& velocity);

      /// @brief Set particle velocity.
      /// @param velocity_min Minimum particle velocity.
      /// @param velocity_max Maximum particle velocity.
      void set_velocity(const Vec2f& velocity_min, const Vec2f& velocity_max);

      /// @brief Set particle acceleration.
      /// @param acceleration Particle acceleration.
      void set_acceleration(const Vec2f& acceleration);

      /// @brief Set particle acceleration.
      /// @param acceleration_min Minimum particle acceleration.
      /// @param acceleration_max Maximum particle acceleration.
      void set_acceleration(const Vec2f& acceleration_min, const Vec2f& acceleration_max);

      /// @brief Set particle friction.
      /// @param friction Particle friction.
      void set_friction(float friction);

      /// @brief Set particle friction.
      /// @param friction_min Minimum particle friction.
      /// @param friction_max Maximum particle friction.
      void set_friction(float friction_min, float friction_max);

      /// @brief Set particle size based properties.
      /// @param size Particle size.
      /// @param scale Particle scale.
      /// @param scale_velocity Particle scale velocity.
      void set_size_properties(const Vec2f& size,
                               const Vec2f& scale,
                               const Vec2f& scale_velocity);

      /// @brief Set particle size based properties.
      /// @param size_min Minimum particle size.
      /// @param size_max Maximum particle size.
      /// @param scale_min Minimum particle scale.
      /// @param scale_max Maximum particle scale.
      /// @param scale_velocity_min Minimum particle scale velocity.
      /// @param scale_velocity_max Maximum particle scale velocity.
      void set_size_properties(const Vec2f& size_min,
                               const Vec2f& size_max,
                               const Vec2f& scale_min,
                               const Vec2f& scale_max,
                               const Vec2f& scale_velocity_min,
                               const Vec2f& scale_velocity_max);

      /// @brief Set particle size.
      /// @param size Particle size.
      void set_size(const Vec2f& size);

      /// @brief Set particle size.
      /// @param size_min Minimum particle size.
      /// @param size_max Maximum particle size.
      void set_size(const Vec2f& size_min, const Vec2f& size_max);

      /// @brief Set particle scale.
      /// @param scale Particle scale.
      void set_scale(const Vec2f& scale);

      /// @brief Set particle scale.
      /// @param scale_min Minimum particle scale.
      /// @param scale_max Maximum particle scale.
      void set_scale(const Vec2f& scale_min, const Vec2f& scale_max);

      /// @brief Set particle scale velocity.
      /// @param scaleVelocity Particle scale velocity.
      void set_scale_velocity(const Vec2f& scale_velocity);

      /// @brief Set particle scale velocity.
      /// @param scale_velocity_min Minimum particle scale velocity.
      /// @param scale_velocity_max Maximum particle scale velocity.
      void set_scale_velocity(const Vec2f& scale_velocity_min,
                              const Vec2f& scale_velocity_max);

      /// @brief Set particle rotation based properties.
      /// @param rotation Particle rotation.
      /// @param rot_velocity Particle rotation velocity.
      void set_rotation_properties(float rotation, float rot_velocity);

      /// @brief Set particle rotation based properties.
      /// @param rotation_min Minimum particle rotation.
      /// @param rotation_max Maximum particle rotation.
      /// @param rot_velocity_min Minimum particle rotation velocity.
      /// @param rot_velocity_max Maximum particle rotation velocity.
      void set_rotation_properties(float rotation_min,
                                   float rotation_max,
                                   float rot_velocity_min,
                                   float rot_velocity_max);
      
      /// @brief Set particle rotation.
      /// @param rotation Particle rotation.
      void set_rotation(float rotation);

      /// @brief Set particle rotation.
      /// @param rotation_min Minimum particle rotation.
      /// @param rotation_max Maximum particle rotation.
      void set_rotation(float rotation_min, float rotation_max);

      /// @brief Set particle rotation velocity.
      /// @param rot_velocity Particle rotation velocity.
      void set_rot_velocity(float rot_velocity);

      /// @brief Set particle rotation velocity.
      /// @param rot_velocity_min Minimum particle rotation velocity.
      /// @param rot_velocity_max Maximum particle rotation velocity.
      void set_rot_velocity(float rot_velocity_min, float rot_velocity_max);

      /// @brief Set particle texture based properties.
      /// @param texture Particle texture.
      /// @param pieces How many pieces should it be divided in each axis.
      void set_texture_properties(const sf::Texture* texture,
                                  const Vec4i& texture_rect,
                                  size_t pieces);

      /// @brief Set particle texture.
      /// @param texture Particle texture.
      void set_texture(const sf::Texture* texture);

      /// @brief Set texture rectangle.
      /// @param texture_rect Texture rectangle.
      void set_texture_rect(const Vec4i& texture_rect);

      /// @brief Set texture pieces.
      /// @param pieces How many pieces should it be divided in each axis.
      void set_texture_pieces(size_t pieces);

      /// @brief Set particle color.
      /// @param color Particle color.
      void set_color(const Color& color);

      /// @brief Set particle color.
      /// @param start_color Particle starting color.
      /// @param end_color Color at the end of particle lifetime.
      void setColor(const Color& start_color, const Color& end_color);

      /// @brief Set particle properties.
      /// @param lifetime Particle lifetime in seconds.
      /// @param spawn_rate Particle spawn rate per second.
      /// @param particle_count Maximum particle count at once.
      /// @param explosive Should particles only spawn once.
      void set_properties(float lifetime,
                          float spawn_rate,
                          size_t particle_count,
                          bool explosive,
                          bool spawn_once,
                          bool can_spawn);

      /// @brief Set particle properties.
      /// @param lifetime_min Minimum particle lifetime.
      /// @param lifetime_max Maximum particle lifetime.
      /// @param spawn_rate Particle spawn rate per second.
      /// @param particle_count Maximum particle count at once.
      /// @param explosive Should particles only spawn once.
      void set_properties(float lifetime_min,
                          float lifetime_max,
                          float spawn_rate,
                          size_t particle_count,
                          bool explosive,
                          bool spawn_once,
                          bool can_spawn);

      /// @brief Set particle lifetime.
      /// @param lifetime Particle lifetime in seconds.
      void set_lifetime(float lifetime);

      /// @brief Set particle lifetime.
      /// @param lifetime_min Minimum particle lifetime.
      /// @param lifetime_max Maximum particle lifetime.
      void set_lifetime(float lifetime_min, float lifetime_max);

      /// @brief Set particle spawn rate.
      /// @param spawn_rate Particle spawn rate per second.
      void set_spawn_rate(float spawn_rate);

      /// @brief Set particle count.
      /// @param particle_count Maximum particle count at once.
      void set_particle_count(size_t particle_count);

      /// @brief Set explosive property.
      /// @param explosive Should particles only spawn once.
      void set_explosive(bool explosive);

      /// @brief Set spawn once property.
      /// @param spawn_once Should particles be spawned once.
      void set_spawn_once(bool spawn_once);

      /// @brief Set can spawn property.
      /// @param can_spawn Can the particles spawn by themselves.
      void set_can_spawn(bool can_spawn);

      // Getter functions

      /// @brief Get all particles.
      /// @return List of particles.
      std::vector<std::shared_ptr<Particle>>& get_particles();

      /// @brief Get all particles.
      /// @return List of particles.
      const std::vector<std::shared_ptr<Particle>>& get_particles() const;

      /// @brief Get particle count.
      /// @return Particle count.
      size_t size() const;

      /// @brief Get particle texture.
      /// @return Texture.
      const sf::Texture* get_texture() const;

      /// @brief Get texture rectangle.
      /// @return Texture rectangle.
      const Vec4i& get_texture_rect() const;

      /// @brief Get texture pieces.
      /// @return Texture pieces.
      size_t get_texture_pieces() const;

      /// @brief Get particle spawn position.
      /// @return Position.
      const Vec2f& get_position() const;

      /// @brief Get minimum spawn radius.
      /// @return Minimum spawn radius.
      float get_spawn_radius_min() const;

      /// @brief Get maximum spawn radius.
      /// @return Maximum spawn radius.
      float get_spawn_radius_max() const;

      /// @brief Get minimum particle velocity.
      /// @return Minimum velocity.
      const Vec2f& get_velocity_min() const;

      /// @brief Get maximum particle velocity.
      /// @return Maximum velocity.
      const Vec2f& get_velocity_max() const;

      /// @brief Get minimum particle acceleration.
      /// @return Minimum acceleration.
      const Vec2f& get_acceleration_min() const;

      /// @brief Get maximum particle acceleration.
      /// @return Maximum acceleration.
      const Vec2f& get_acceleration_max() const;

      /// @brief Get minimum particle friction.
      /// @return Minimum friction.
      float get_friction_min() const;

      /// @brief Get maximum particle friction.
      /// @return Maximum friction.
      float get_friction_max() const;

      /// @brief Get minimum particle size.
      /// @return Minimum size.
      const Vec2f& get_size_min() const;

      /// @brief Get maximum particle size.
      /// @return Maximum size.
      const Vec2f& get_size_max() const;

      /// @brief Get minimum particle scale.
      /// @return Minimum scale.
      const Vec2f& get_scale_min() const;

      /// @brief Get maximum particle scale.
      /// @return Maximum scale.
      const Vec2f& get_scale_max() const;

      /// @brief Get minimum scale velocity.
      /// @return Minimum scale velocity.
      const Vec2f& get_scale_velocity_min() const;

      /// @brief Get maximum scale velocity.
      /// @return Maximum scale velocity.
      const Vec2f& get_scale_velocity_max() const;

      /// @brief Get minimum particle rotation.
      /// @return Minimum rotation.
      float get_rotation_min() const;

      /// @brief Get maximum particle rotation.
      /// @return Maximum rotation.
      float get_rotation_max() const;

      /// @brief Get minimum particle rotation velocity.
      /// @return Minimum rotation velocity.
      float get_rot_velocity_min() const;

      /// @brief Get maximum particle rotation velocity.
      /// @return Maximum rotation velocity.
      float get_rot_velocity_max() const;

      /// @brief Get particle starting color.
      /// @return Starting color.
      const Color& get_starting_color() const;

      /// @brief Get particle end color.
      /// @return End color.
      const Color& get_end_color() const;

      /// @brief Get minimum particle lifetime.
      /// @return Minimum lifetime.
      float get_lifetime_min() const;

      /// @brief Get maximum particle lifetime.
      /// @return Maximum lifetime.
      float get_lifetime_max() const;

      /// @brief Get particle spawn rate.
      /// @return Spawn rate.
      float get_spawn_rate() const;

      /// @brief Get maximum particle count.
      /// @return Particle count.
      size_t get_particle_count() const;

      /// @brief Get explosive property.
      /// @return True if explosive.
      bool is_explosive() const;

      /// @brief Get spawn once property.
      /// @return True if spawn once.
      bool get_spawn_once() const;

      /// @brief Get can spawn property.
      /// @return True if can spawn.
      bool get_can_spawn() const;

      // Update functions

      /// @brief Clear all particles.
      void clear();

      /// @brief Spawn all particles that can be spawned.
      void spawn();

      /// @brief Spawn and update particles.
      /// @param dt Delta time.
      void update(float dt);

      // Render functions

      /// @brief Render particles to the screen.
      /// @param window Window to draw to.
      void render(sf::RenderWindow& window) const;

      /// @brief Render particles to the screen.
      /// @param window Window to draw to.
      /// @param shader Shader.
      void render(sf::RenderWindow& window,
                  const sf::Shader* shader) const;

   private:
      std::vector<std::shared_ptr<Particle>> particles;

      // Particle position and spawn
      Vec2f position;
      float spawn_radius_min = 0.f;
      float spawn_radius_max = 0.f;

      // Particle velocity
      Vec2f velocity_min;
      Vec2f velocity_max;
      Vec2f acceleration_min;
      Vec2f acceleration_max;
      float friction_min = 0.f;
      float friction_max = 0.f;

      // Particle size
      Vec2f size_min;
      Vec2f size_max;
      Vec2f scale_min = Vec2f(1.f);
      Vec2f scale_max = Vec2f(1.f);
      Vec2f scale_velocity_min;
      Vec2f scale_velocity_max;

      // Particle rotation
      float rotation_min  = 0.f;
      float rotation_max  = 0.f;
      float rot_velocity_min = 0.f;
      float rot_velocity_max = 0.f;

      // Particle texture
      const sf::Texture* texture;
      Vec4i texture_rect;
      size_t pieces = 0u;
      Vec2f piece_size;

      // Particle color
      Color color_start = Color(255);
      Color color_end   = Color(255);

      // Particle lifetime and misc
      float lifetime_min    = 5.f;
      float lifetime_max    = 5.f;
      float spawn_rate      = 1.f;
      size_t particle_count = 10u;
      bool explosive       = false;
      bool spawn_once       = false;
      bool can_spawn        = true;

      size_t spawned_count      = 0u;
      float spawn_timer         = 0.f;
      float spawn_rate_fraction = 1.f;

      /// @brief Create a new particle.
      void create_particle();

      /// @brief Optimized randfu function.
      /// @param min Minimum value.
      /// @param max Maximum value.
      float rand_f(float min, float max);
      
      /// @brief Optimized random vector function.
      /// @param min Minimum value.
      /// @param max Maximum value.
      Vec2f rand_v(const Vec2f& min, const Vec2f& max);
   };
}

#endif
