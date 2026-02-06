// Claude 4.5 Sonnet
void rot13(char *s) {
  while (*s) {
    if (*s >= 'a' && *s <= 'z') {
      *s = 'a' + (*s - 'a' + 13) % 26;
    } else if (*s >= 'A' && *s <= 'Z') {
      *s = 'A' + (*s - 'A' + 13) % 26;
    }
    s++;
  }
}

