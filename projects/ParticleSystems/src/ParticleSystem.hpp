#pragma once

#include <vector>

#include <Particle.hpp>

namespace ParticleSystem {

  template<class V>
  class ParticleSystem {
  protected:
    const unsigned int minN;

    std::vector<Particle<V>> particles;

  public:
    ParticleSystem(unsigned int minN);
    virtual ~ParticleSystem();

    void step();
    void spawn(unsigned int n);
    const std::vector<Particle<V>>& getParticles() const;
  };

}
