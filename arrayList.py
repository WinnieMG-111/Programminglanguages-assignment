MAX = 10

class arrayList:
    def __init__(self):
        self.data = [0] * MAX   # fixed-size array
        self.size = 0           # number of elements

    def insert(self, pos, value):
        if self.size == MAX:
            print("List is full")
            return
        if pos < 0 or pos > self.size:
            print("Invalid position")
            return
        # Shift elements to the right
        for i in range(self.size, pos, -1):
            self.data[i] = self.data[i - 1]

        self.data[pos] = value
        self.size += 1

    def delete(self, pos):
        if pos < 0 or pos >= self.size:
            print("Invalid position")
            return
        # Shift elements to the left
        for i in range(pos, self.size - 1):
            self.data[i] = self.data[i + 1]

        self.size -= 1

    def display(self):
        if self.size == 0:
            print("List is empty")
            return

        for i in range(self.size):
            print(self.data[i], end=" ")
        print()
# main part that runs
L = arrayList()

L.insert(0, 10)
L.insert(1, 20)
L.insert(2, 30)
L.display()

L.delete(1)
L.display()