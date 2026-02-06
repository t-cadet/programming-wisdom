// https://github.com/TheAlgorithms/C/blob/master/geometry/quaternions.c
void calculateCentroid(observation observations[], size_t size, cluster* centroid) {
  size_t i = 0;
  centroid->x = 0;
  centroid->y = 0;
  centroid->count = size;
  for (; i < size; i++) {
    centroid->x += observations[i].x;
    centroid->y += observations[i].y;
    observations[i].group = 0;
  }
  centroid->x /= centroid->count;
  centroid->y /= centroid->count;
}

