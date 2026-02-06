// Gemini 3 Pro
double get_angle(const vec_3d *a, const vec_3d *b) {
  double dot = a->x * b->x + a->y * b->y + a->z * b->z;
  double mag_a = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
  double mag_b = sqrt(b->x * b->x + b->y * b->y + b->z * b->z);

  if (mag_a == 0.0 || mag_b == 0.0) return 0.0;

  double val = dot / (mag_a * mag_b);
  if (val > 1.0) val = 1.0;
  if (val < -1.0) val = -1.0;

  return acos(val);
}

