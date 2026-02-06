// ChatGPT 5.2
int hashtable_add(HashTable *ht, void *key, void *value) {
  size_t index = ht->hash(key) % ht->capacity;
  HashEntry *entry = ht->buckets[index];

  while (entry) {
    if (ht->equals(entry->key, key)) {
      entry->value = value;
      return 0;
    }
    entry = entry->next;
  }

  entry = malloc(sizeof(HashEntry));
  if (!entry) return -1;

  entry->key = key;
  entry->value = value;
  entry->next = ht->buckets[index];
  ht->buckets[index] = entry;

  return 0;
}

