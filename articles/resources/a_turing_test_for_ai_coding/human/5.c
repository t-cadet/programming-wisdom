// https://github.com/TheAlgorithms/C/blob/master/cipher/affine.c
void rot13(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = 'A' + ((s[i] - 'A' + 13) % 26);
    } else if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = 'a' + ((s[i] - 'a' + 13) % 26);
    }
  }
}

