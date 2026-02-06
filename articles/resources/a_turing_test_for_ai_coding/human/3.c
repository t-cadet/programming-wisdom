// https://github.com/justin-lathrop/c/blob/master/HashTable/HashTable.c
int hashtable_add(HashTable *ht, void *key, void *value) {
  size_t hash = ht->hf(key);
  Item *next = ht->table[hash % ht->size];
  size_t i = 0;

  while (next) {
    if (ht->eq(next->key, key)) {
      next->value = value;
      return (1);
    }

    next = next->next;
    i++;
  }

  next = (Item *)malloc(sizeof(Item));

  if (next == NULL) {
    printf("\nERROR: Insufficient memory. Terminating....");
    exit(EXIT_FAILURE);
  }

  next->key = key;
  next->value = value;
  next->next = ht->table[hash % ht->size];
  ht->table[hash % ht->size] = next;

  if (i >= ht->maxCollisions) {
    hashtable_resize(ht, ht->size + ht->growthFactor);
  }

  return (1);
}

