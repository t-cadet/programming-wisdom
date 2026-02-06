// Claude 4.5 Sonnet
vec_3d vector_prod(const vec_3d *a, const vec_3d *b) {
  vec_3d result;
  result.x = a->y * b->z - a->z * b->y;
  result.y = a->z * b->x - a->x * b->z;
  result.z = a->x * b->y - a->y * b->x;
  return result;
}

