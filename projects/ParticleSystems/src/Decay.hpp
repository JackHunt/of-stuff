#pragma once

inline float linearDecay(float x, float alpha = 0.05) {
  return x * (1 - alpha);
}

inline float exponentialDecay(float x) {
  return x;
}
