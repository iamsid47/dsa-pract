class HashDictionary:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        hash_value = self._hash(key)
        chain = self.table[hash_value]

        for i, (k, v) in enumerate(chain):
            if k == key:
                chain[i] = (key, value)
                return

        chain.append((key, value))

    def find(self, key):
        hash_value = self._hash(key)
        chain = self.table[hash_value]

        for k, v in chain:
            if k == key:
                return v

        return None

    def delete(self, key):
        hash_value = self._hash(key)
        chain = self.table[hash_value]

        for i, (k, v) in enumerate(chain):
            if k == key:
                del chain[i]
                return True

        return False


dictionary = HashDictionary(10)


def display(dictionary):
    for chain in dictionary.table:
        for key, value in chain:
            print(f"Key: {key}, Value: {value}")


# Inserting key-value pairs
dictionary.insert("apple", 5)
dictionary.insert("banana", 7)
dictionary.insert("orange", 9)

display(dictionary)  # Output: {'banana': 7, 'apple': 5, 'orange': 9}

# Finding values by keys
print(dictionary.find("banana"))  # Output: 7
print(dictionary.find("apple"))  # Output: 5
print(dictionary.find("grape"))  # Output: None (key not found)

# Deleting key-value pairs
dictionary.delete("banana")
display(dictionary)
