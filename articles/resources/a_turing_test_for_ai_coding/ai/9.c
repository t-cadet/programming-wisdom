// Gemini 3 Pro
int linearsearch(int *arr, int size, int val) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == val) {
      return i;
    }
  }
  return -1;
}

