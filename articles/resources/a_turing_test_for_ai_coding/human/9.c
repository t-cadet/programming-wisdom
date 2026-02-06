// https://github.com/TheAlgorithms/C/blob/master/searching/linear_search.c
int linearsearch(int *arr, int size, int val) {
  int i;
  for (i = 0; i < size; i++) {
    if (arr[i] == val) return 1;
  }
  return 0;
}

