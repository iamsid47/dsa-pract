class Set:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, other_set):
        intersection_set = Set()
        for element in self.elements:
            if other_set.contains(element):
                intersection_set.add(element)
        return intersection_set

    def union(self, other_set):
        union_set = Set()
        union_set.elements = self.elements.copy()
        for element in other_set.elements:
            if not union_set.contains(element):
                union_set.add(element)
        return union_set

    def difference(self, other_set):
        difference_set = Set()
        for element in self.elements:
            if not other_set.contains(element):
                difference_set.add(element)
        return difference_set

    def subset(self, other_set):
        for element in self.elements:
            if not other_set.contains(element):
                return False
        return True


my_set = Set()
my_set.add(1)
my_set.add(2)
my_set.add(3)
print(my_set.contains(2))  # Output: True
my_set.remove(3)
print(my_set.size())  # Output: 2

other_set = Set()
other_set.add(2)
other_set.add(4)

intersection_set = my_set.intersection(other_set)
print(list(intersection_set.iterator()))  # Output: [2]

union_set = my_set.union(other_set)
print(list(union_set.iterator()))  # Output: [1, 2, 4]

difference_set = my_set.difference(other_set)
print(list(difference_set.iterator()))  # Output: [1]

print(my_set.subset(union_set))  # Output: True
print(other_set.subset(my_set))  # Output: False
