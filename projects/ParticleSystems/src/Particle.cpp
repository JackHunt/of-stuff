#include <Particle.hpp>

template<class V>
Particle<V>::Particle(const V& startPos, float mass, float accel) :
  pos(startPos),
  mass(mass),
  accel(accel){
  //
}

template<class V>
Particle<V>::~Particle() {
  //
}

template<class V>
const V& Particle<V>::step() {
  // Do update
  return getPos();
}

template<class V>
const V& Particle<V>::getPos() {
  return pos;
}
