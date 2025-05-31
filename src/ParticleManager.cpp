#include "CX/ParticleManager.hpp"

#include "CX/Math/Math.hpp"
#include "CX/Math/Random.hpp"

namespace cx
{
   // Constructors

   ParticleManager::ParticleManager(const Vec2f& spawn_position,
                                    const Vec2f& particle_size,
                                    size_t particle_count,
                                    float lifetime,
                                    float spawn_rate)
   {
      position = spawn_position;
      size_min = size_max = particle_size;
      this->particle_count = particle_count;
      lifetime_min = lifetime_max = lifetime;
      this->spawn_rate = spawn_rate;
      spawn_rate_fraction = 1.f / spawn_rate;
   }

   // Constructors after creation

   void ParticleManager::create(const Vec2f& spawn_position,
                                const Vec2f& particle_size,
                                size_t particle_count,
                                float lifetime,
                                float spawn_rate)
   {
      position = spawn_position;
      size_min = size_max = particle_size;
      this->particle_count = particle_count;
      lifetime_min = lifetime_max = lifetime;
      this->spawn_rate = spawn_rate;
      spawn_rate_fraction = 1.f / spawn_rate;
   }

   // Setter functions

   void ParticleManager::set_position_properties(const Vec2f& position, float spawn_radius)
   {
      this->position = position;
      set_spawn_radius(spawn_radius);
   }

   void ParticleManager::set_position_properties(const Vec2f& position,
                                                 float spawn_radius_min,
                                                 float spawn_radius_max)
   {
      this->position = position;
      set_spawn_radius(spawn_radius_min, spawn_radius_max);
   }

   void ParticleManager::set_position(const Vec2f& position)
   {
      this->position = position;
   }

   void ParticleManager::set_spawn_radius(float spawn_radius)
   {
      spawn_radius_max = spawn_radius_min = spawn_radius;
   }

   void ParticleManager::set_spawn_radius(float spawn_radius_min, float spawn_radius_max)
   {
      this->spawn_radius_min = min(spawn_radius_min, spawn_radius_max);
      this->spawn_radius_max = max(spawn_radius_min, spawn_radius_max);
   }

   void ParticleManager::set_velocity_properties(const Vec2f& velocity,
                                                 const Vec2f& acceleration,
                                                 float friction)
   {
      set_velocity(velocity);
      set_acceleration(acceleration);
      set_friction(friction);
   }

   void ParticleManager::set_velocity_properties(const Vec2f& velocity_min,
                                                 const Vec2f& velocity_max,
                                                 const Vec2f& acceleration_min,
                                                 const Vec2f& acceleration_max,
                                                 float friction_min,
                                                 float friction_max)
   {
      set_velocity(velocity_min, velocity_max);
      set_acceleration(acceleration_min, acceleration_max);
      set_friction(friction_min, friction_max);
   }

   void ParticleManager::set_velocity(const Vec2f& velocity)
   {
      velocity_min = velocity_max = velocity;
   }

   void ParticleManager::set_velocity(const Vec2f& velocity_min, const Vec2f& velocity_max)
   {
      this->velocity_min = Vec2f(min(velocity_min.x, velocity_max.x), min(velocity_min.y, velocity_max.y));
      this->velocity_max = Vec2f(max(velocity_min.x, velocity_max.x), max(velocity_min.y, velocity_max.y));
   }

   void ParticleManager::set_acceleration(const Vec2f& acceleration)
   {
      acceleration_min = acceleration_max = acceleration;
   }

   void ParticleManager::set_acceleration(const Vec2f& acceleration_min, const Vec2f& acceleration_max)
   {
      this->acceleration_min = Vec2f(min(acceleration_min.x, acceleration_max.x), min(acceleration_min.y, acceleration_max.y));
      this->acceleration_max = Vec2f(max(acceleration_min.x, acceleration_max.x), max(acceleration_min.y, acceleration_max.y));
   }

   void ParticleManager::set_friction(float friction)
   {
      friction_min = friction_max = friction;
   }

   void ParticleManager::set_friction(float friction_min, float friction_max)
   {
      this->friction_min = min(friction_min, friction_max);
      this->friction_max = max(friction_min, friction_max);
   }

   void ParticleManager::set_size_properties(const Vec2f& size,
                                             const Vec2f& scale,
                                             const Vec2f& scale_velocity)
   {
      set_size(size);
      set_scale(scale);
      set_scale_velocity(scale_velocity);
   }

   void ParticleManager::set_size_properties(const Vec2f& size_min,
                                             const Vec2f& size_max,
                                             const Vec2f& scale_min,
                                             const Vec2f& scale_max,
                                             const Vec2f& scale_velocity_min,
                                             const Vec2f& scale_velocity_max)
   {
      set_size(size_min, size_max);
      set_scale(scale_min, scale_max);
      set_scale_velocity(scale_velocity_min, scale_velocity_max);
   }

   void ParticleManager::set_size(const Vec2f& size)
   {
      size_min = size_max = size;
   }

   void ParticleManager::set_size(const Vec2f& size_min, const Vec2f& size_max)
   {
      this->size_min = Vec2f(min(size_min.x, size_max.x), min(size_min.y, size_max.y));
      this->size_max = Vec2f(max(size_min.x, size_max.x), max(size_min.y, size_max.y));
   }

   void ParticleManager::set_scale(const Vec2f& scale)
   {
      scale_min = scale_max = scale;
   }

   void ParticleManager::set_scale(const Vec2f& scale_min, const Vec2f& scale_max)
   {
      this->scale_min = Vec2f(min(scale_min.x, scale_max.y), min(scale_min.y, scale_max.y));
      this->scale_max = Vec2f(max(scale_min.x, scale_max.y), max(scale_min.y, scale_max.y));
   }

   void ParticleManager::set_scale_velocity(const Vec2f& scale_velocity)
   {
      scale_velocity_min = scale_velocity_max = scale_velocity;
   }

   void ParticleManager::set_scale_velocity(const Vec2f& scale_velocity_min,
                                            const Vec2f& scale_velocity_max)
   {
      this->scale_velocity_min = Vec2f(min(scale_velocity_min.x, scale_velocity_max.x), min(scale_velocity_min.y, scale_velocity_max.y));
      this->scale_velocity_max = Vec2f(max(scale_velocity_min.x, scale_velocity_max.x), max(scale_velocity_min.y, scale_velocity_max.y));
   }

   void ParticleManager::set_rotation_properties(float rotation, float rot_velocity)
   {
      set_rotation(rotation);
      set_rot_velocity(rot_velocity);
   }

   void ParticleManager::set_rotation_properties(float rotation_min,
                                                 float rotation_max,
                                                 float rot_velocity_min,
                                                 float rot_velocity_max)
   {
      set_rotation(rotation_min, rotation_max);
      set_rot_velocity(rot_velocity_min, rot_velocity_max);
   }

   void ParticleManager::set_rotation(float rotation)
   {
      rotation_min = rotation_max = rotation;
   }

   void ParticleManager::set_rotation(float rotation_min, float rotation_max)
   {
      this->rotation_min = min(rotation_min, rotation_max);
      this->rotation_max = max(rotation_min, rotation_max);
   }

   void ParticleManager::set_rot_velocity(float rot_velocity)
   {
      rot_velocity_min = rot_velocity_max = rot_velocity;
   }

   void ParticleManager::set_rot_velocity(float rot_velocity_min, float rot_velocity_max)
   {
      this->rot_velocity_min = min(rot_velocity_min, rot_velocity_max);
      this->rot_velocity_max = max(rot_velocity_min, rot_velocity_max);
   }

   void ParticleManager::set_texture_properties(const sf::Texture* texture,
                                                const Vec4i& texture_rect,
                                                size_t pieces)
   {
      set_texture(texture);
      set_texture_rect(texture_rect);
      set_texture_pieces(pieces);
   }

   void ParticleManager::set_texture(const sf::Texture* texture)
   {
      this->texture = texture;
   }

   void ParticleManager::set_texture_rect(const Vec4i& texture_rect)
   {
      this->texture_rect = texture_rect;
   }

   void ParticleManager::set_texture_pieces(size_t pieces)
   {
      this->pieces = pieces;
      piece_size = texture->getSize() / unsigned(pieces);
   }

   void ParticleManager::set_color(const Color& color)
   {
      color_start = color_end = color;
   }

   void ParticleManager::setColor(const Color& start_color, const Color& end_color)
   {
      color_start = start_color;
      color_end = end_color;
   }

   void ParticleManager::set_properties(float lifetime,
                                        float spawn_rate,
                                        size_t particle_count,
                                        bool explosive,
                                        bool spawn_once,
                                        bool can_spawn)
   {
      set_lifetime(lifetime);
      set_spawn_rate(spawn_rate);
      set_particle_count(particle_count);
      set_explosive(explosive);
      set_spawn_once(spawn_once);
      set_can_spawn(can_spawn);
   }

   void ParticleManager::set_properties(float lifetime_min,
                                        float lifetime_max,
                                        float spawn_rate,
                                        size_t particle_count,
                                        bool explosive,
                                        bool spawn_once,
                                        bool can_spawn)
   {
      set_lifetime(lifetime_min, lifetime_max);
      set_spawn_rate(spawn_rate);
      set_particle_count(particle_count);
      set_explosive(explosive);
      set_spawn_once(spawn_once);
      set_can_spawn(can_spawn);
   }

   void ParticleManager::set_lifetime(float lifetime)
   {
      lifetime_min = lifetime_max = lifetime;
   }

   void ParticleManager::set_lifetime(float lifetime_min, float lifetime_max)
   {
      this->lifetime_min = min(lifetime_min, lifetime_max);
      this->lifetime_max = max(lifetime_min, lifetime_max);
   }

   void ParticleManager::set_spawn_rate(float spawn_rate)
   {
      this->spawn_rate = spawn_rate;
      spawn_rate_fraction = 1.f / spawn_rate;
   }

   void ParticleManager::set_particle_count(size_t particle_count)
   {
      this->particle_count = particle_count;
      spawned_count = 0u;
   }

   void ParticleManager::set_explosive(bool explosive)
   {
      this->explosive = explosive;
   }

   void ParticleManager::set_spawn_once(bool spawn_once)
   {
      this->spawn_once = spawn_once;
      spawned_count = 0u;
   }

   void ParticleManager::set_can_spawn(bool can_spawn)
   {
      this->can_spawn = can_spawn;
   }

   // Getter functions

   std::vector<std::shared_ptr<Particle>>& ParticleManager::get_particles()
   {
      return particles;
   }

   const std::vector<std::shared_ptr<Particle>>& ParticleManager::get_particles() const
   {
      return particles;
   }

   size_t ParticleManager::size() const
   {
      return particles.size();
   }

   const sf::Texture* ParticleManager::get_texture() const
   {
      return texture;
   }

   const Vec4i& ParticleManager::get_texture_rect() const
   {
      return texture_rect;
   }

   size_t ParticleManager::get_texture_pieces() const
   {
      return pieces;
   }

   const Vec2f& ParticleManager::get_position() const
   {
      return position;
   }

   float ParticleManager::get_spawn_radius_min() const
   {
      return spawn_radius_min;
   }

   float ParticleManager::get_spawn_radius_max() const
   {
      return spawn_radius_max;
   }

   const Vec2f& ParticleManager::get_velocity_min() const
   {
      return velocity_min;
   }

   const Vec2f& ParticleManager::get_velocity_max() const
   {
      return velocity_max;
   }

   const Vec2f& ParticleManager::get_acceleration_min() const
   {
      return acceleration_min;
   }

   const Vec2f& ParticleManager::get_acceleration_max() const
   {
      return acceleration_max;
   }

   float ParticleManager::get_friction_min() const
   {
      return friction_min;
   }

   float ParticleManager::get_friction_max() const
   {
      return friction_max;
   }

   const Vec2f& ParticleManager::get_size_min() const
   {
      return size_min;
   }

   const Vec2f& ParticleManager::get_size_max() const
   {
      return size_max;
   }

   const Vec2f& ParticleManager::get_scale_min() const
   {
      return scale_min;
   }

   const Vec2f& ParticleManager::get_scale_max() const
   {
      return scale_max;
   }

   const Vec2f& ParticleManager::get_scale_velocity_min() const
   {
      return scale_velocity_min;
   } 

   const Vec2f& ParticleManager::get_scale_velocity_max() const
   {
      return scale_velocity_max;
   }

   float ParticleManager::get_rotation_min() const
   {
      return rotation_min;
   }

   float ParticleManager::get_rotation_max() const
   {
      return rotation_max;
   }

   float ParticleManager::get_rot_velocity_min() const
   {
      return rot_velocity_min;
   }

   float ParticleManager::get_rot_velocity_max() const
   {
      return rot_velocity_max;
   }

   const Color& ParticleManager::get_starting_color() const
   {
      return color_start;
   }

   const Color& ParticleManager::get_end_color() const
   {
      return color_end;
   }

   float ParticleManager::get_lifetime_min() const
   {
      return lifetime_min;
   }

   float ParticleManager::get_lifetime_max() const
   {
      return lifetime_max;
   }

   float ParticleManager::get_spawn_rate() const
   {
      return spawn_rate;
   }

   size_t ParticleManager::get_particle_count() const
   {
      return particle_count;
   }

   bool ParticleManager::is_explosive() const
   {
      return explosive;
   }

   bool ParticleManager::get_spawn_once() const
   {
      return spawn_once;
   }

   bool ParticleManager::get_can_spawn() const
   {
      return can_spawn;
   }

   // Update functions

   void ParticleManager::clear()
   {
      particles.clear();
   }

   void ParticleManager::spawn()
   {
      for (size_t i = 0; i < particle_count - particles.size(); ++i)
         create_particle();
   }

   void ParticleManager::update(float dt)
   {
      // Spawn logic
      if ((!spawn_once || (spawn_once && spawned_count < particle_count)) && can_spawn)
      {
         if (explosive && particles.size() == 0u)
         {
            for (size_t i = 0; i < particle_count; ++i)
               create_particle();
         }
         else if (!explosive)
         {
            spawn_timer -= dt;

            if (spawn_timer <= 0.f && particle_count > particles.size())
            {
               create_particle();
               spawn_timer += spawn_rate_fraction;
            }
         }
      }

      // Update particles
      for (const auto& particle : particles)
      {
         particle->age += dt;

         if (!particle->velocity.empty())
            particle->particle.move(particle->velocity * dt);

         if (!particle->acceleration.empty())
            particle->velocity = particle->velocity + particle->acceleration * dt;
         
         if (particle->friction != 0.f)
            particle->velocity = particle->velocity * (1.f - particle->friction * dt);

         if (particle->rot_velocity != 0.f)
            particle->particle.rotate(particle->rot_velocity * dt);

         if (!particle->scale_velocity.empty())
            particle->particle.setScale(particle->scale_velocity * dt + particle->particle.getScale());

         if (color_start != color_end)
            particle->particle.setFillColor(color_start.blend(color_end, particle->age / particle->lifetime));
      }

      particles.erase(
         std::remove_if(particles.begin(), particles.end(), [](const auto& p)
         {return p->age >= p->lifetime;}), particles.end());
   }

   // Render functions

   void ParticleManager::render(sf::RenderWindow& window) const
   {
      for (const auto& particle : particles)
         window.draw(particle->particle);
   }

   void ParticleManager::render(sf::RenderWindow& window, const sf::Shader* shader) const
   {
      for (const auto& particle : particles)
         window.draw(particle->particle, shader);
   }

   // Private functions

   void ParticleManager::create_particle()
   {
      ++spawned_count;

      auto particle = std::make_shared<Particle>();
      particle->particle.setSize(rand_v(size_min, size_max));
      particle->particle.setOrigin(particle->particle.getSize() * .5f);

      particle->particle.setScale(rand_v(scale_min, scale_max));
      particle->particle.setRotation(rand_f(rotation_min, rotation_max));
   
      if (spawn_radius_min == 0.f && spawn_radius_max == 0.f)
         particle->particle.setPosition(position);
      else
      {
         const float angle  = rand_f(0.f, Constants<float>::two_pi);
         const float radius = std::sqrt(rand_f(spawn_radius_min * spawn_radius_min, spawn_radius_max * spawn_radius_max));
         const Vec2f offset (cos(angle) * radius, sin(angle) * radius);
         particle->particle.setPosition(position + offset);
      }

      particle->particle.setTexture(texture);
      particle->particle.setFillColor(color_start);

      if (!texture_rect.empty())
         particle->particle.setTextureRect(texture_rect);

      if (pieces != 0u)
      {
         const size_t index_x = randiu<size_t>(0, pieces - 1);
         const size_t index_y = randiu<size_t>(0, pieces - 1);

         particle->particle.setTextureRect(Vec4i(piece_size.x * index_x, piece_size.y * index_y, piece_size.x, piece_size.y));
      }

      particle->acceleration = rand_v(acceleration_min, acceleration_max);
      particle->velocity = rand_v(velocity_min, velocity_max);
      particle->scale_velocity = rand_v(scale_velocity_min, scale_velocity_max);
      particle->rot_velocity = rand_f(rot_velocity_min, rot_velocity_max);
      particle->friction = rand_f(friction_min, friction_max);
      particle->lifetime = rand_f(lifetime_min, lifetime_max);

      particles.push_back(std::move(particle));
   }

   float ParticleManager::rand_f(float min, float max)
   {
      return (min == max ? min : randfu(min, max));
   }

   Vec2f ParticleManager::rand_v(const Vec2f& min, const Vec2f& max)
   {
      return (min != max ? Vec2f::random(min, max) : min);
   }
}
