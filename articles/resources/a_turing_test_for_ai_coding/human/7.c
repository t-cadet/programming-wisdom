// https://github.com/TheAlgorithms/C/blob/master/geometry/vectors_3d.c
vec_3d vector_prod(const vec_3d *a, const vec_3d *b) {
  vec_3d out;

  out.x = a->y * b->z - a->z * b->y;
  out.y = -a->x * b->z + a->z * b->x;
  out.z = a->x * b->y - a->y * b->x;

  return out;
}

