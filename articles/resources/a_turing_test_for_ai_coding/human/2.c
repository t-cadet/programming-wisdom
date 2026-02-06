// https://github.com/justin-lathrop/c/blob/master/HashTable/HashTable.c
void *hashtable_get(HashTable *ht, void *key) {
  size_t hash = ht->hf(key);
  Item *next = ht->table[hash % ht->size];

  while (next) {
    if (ht->eq(next->key, key)) {
      return (next->value);
    } else {
      next = next->next;
    }
  }

  return ((void *)0);
}

