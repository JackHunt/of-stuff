#include <Particle.hpp>

#include <ofVec2f.h>
#include <ofVec3f.h>

namespace ParticleSystem {

  template<class V>
  Particle<V>::Particle(const V& startPos,
                        float mass,
                        float accel,
                        DecayType decayType,
                        float decayRate) :
    pos(startPos),
    mass(mass),
    accel(accel),
    decayType(decayType),
    decayRate(decayRate) {
    //
  }

  template<class V>
  Particle<V>::~Particle() {
    //
  }

  template<class V>
  const V& Particle<V>::step(float dt) {
    // Do update
    return getPos();
  }

  template<class V>
  const V& Particle<V>::getPos() {
    return pos;
  }

  template class Particle<ofVec2f>;
  template class Particle<ofVec3f>;

}
