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

    def delete(self, key):
        hash_value = self._hash(key)
        chain = self.table[hash_value]

        for i, (k, v) in enumerate(chain):
            if k == key:
                del chain[i]
                return True

        return False

    def find(self, key):
        hash_value = self._hash(key)
        chain = self.table[hash_value]

        for k, v in chain:
            if k == key:
                return v

        return None


def display(dictionary):
    for chain in dictionary.table:
        for key, value in chain:
            print(f"Key - {key}, Value - {value}")


dictio = HashDictionary(10)

dictio.insert("apple", 100)
dictio.insert("banana", 200)
dictio.insert("grapes", 300)

display(dictio)

print(dictio.find("banana"))

dictio.delete("banana")

display(dictio)
