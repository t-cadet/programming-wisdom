// ChatGPT 5.2
void *hashtable_get(HashTable *ht, void *key) {
  size_t index = ht->hash(key) % ht->capacity;
  HashEntry *entry = ht->buckets[index];

  while (entry) {
    if (ht->equals(entry->key, key)) return entry->value;
    entry = entry->next;
  }

  return NULL;
}

