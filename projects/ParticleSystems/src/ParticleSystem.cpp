#include <ParticleSystem.hpp>

#include <ofVec2f.h>
#include <ofVec3f.h>

namespace ParticleSystem {

  tempate<class V>
  ParticleSystem<V>::ParticleSystem(unsigned int minN) :
    minN(minN) {
    //
  }

  tempate<class V>
  ParticleSystem<V>::~ParticleSystem() {
    //
  }

  tempate<class V>
  void ParticleSystem<V>::step() {
    //
  }

  tempate<class V>
  void ParticleSystem<V>::spawn(unsigned int n) {
    //
  }

  tempate<class V>
  const std::vector<Particle<V>>& ParticleSystem<V>::getParticles() const {
    return particles;
  }

  template class ParticleSystem<ofVec2f>;
  template class ParticleSystem<ofVec3f>;
}
