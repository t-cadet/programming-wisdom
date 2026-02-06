// https://github.com/TheAlgorithms/C/blob/master/geometry/vectors_3d.c
double get_angle(const vec_3d *a, const vec_3d *b) {
  double alpha, cos_alpha;
  float norm_a = vector_norm(a);
  float norm_b = vector_norm(b);
  if (fabsf(norm_a) < EPSILON || fabsf(norm_b) < EPSILON) {
    return NAN;
  }

  cos_alpha = dot_prod(a, b) / (norm_a * norm_b);
  alpha = acos(cos_alpha);
  return alpha;
}

