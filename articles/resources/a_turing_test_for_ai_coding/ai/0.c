// Gemini 3 Pro
void calculateCentroid(observation observations[], size_t size, cluster* centroid) {
  if (size == 0) return;

  for (int i = 0; i < centroid->dimension; i++) {
    centroid->values[i] = 0.0;
  }

  for (size_t i = 0; i < size; i++) {
    for (int j = 0; j < centroid->dimension; j++) {
      centroid->values[j] += observations[i].values[j];
    }
  }

  for (int i = 0; i < centroid->dimension; i++) {
    centroid->values[i] /= (double)size;
  }
}

