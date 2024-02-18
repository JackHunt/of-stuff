#pragma once

template<class V>
class Particle {
protected:
  V pos;
  const float mass;
  const float accel;

public:
  Particle(const V& startPos, float mass, float accel = 0.05);
  virtual ~Particle();

  const V& step();
  const V& getPos();
};
