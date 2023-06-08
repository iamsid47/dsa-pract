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

    def size(self, element):
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
        for element in self.elements:
            union_set.add(element)
        for element in other_set:
            union_set.add(element)

        return union_set

    def difference(self, other_set):
        diff_set = Set()
        for element in self.elements:
            if not other_set.contains(element):
                diff_set.add(element)

        return diff_set

    def subset(self, other_set):
        for element in self.elements:
            if not other_set.contains(element):
                return True

        return False


my_set = Set()
my_set.add(1)
my_set.add(2)
my_set.add(3)

my_set.contains(5)
