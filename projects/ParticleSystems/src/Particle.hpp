#pragma once

#include <Decay.hpp>

enum class DecayType {
  LINEAR,
  EXPONENTIAL,
  NONE
};

namespace ParticleSystem {

  template<class V>
  class Particle {
  protected:
    V pos;
    const float mass;
    const float accel;
    const DecayType decayType;
    const float decayRate;

  public:
    Particle(const V& startPos,
             float mass = 1.0,
             float accel = 0.05,
             DecayType decayType = DecayType::LINEAR,
             float decayRate = 0.05);
    virtual ~Particle();

    const V& step(float dt);
    const V& getPos();
  };

}
