class Node: # Node class
    def __init__(self, value):
        self.data = value
        self.next = None

class linkedList: # class of the actual list
    def __init__(self):
        self.head = None
    # insert at the front
    def insert_front(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node # moves head to the new node
    # delete at the front
    def delete_front(self): # removes the first node
        if self.head is None: # checks if list is empty
            print("List is empty")
            return

        self.head = self.head.next
    # Display the list
    def display(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL")
# Main code
LL = linkedList()

LL.insert_front(10)
LL.insert_front(20)
LL.insert_front(30)
LL.display()

LL.delete_front()
LL.display()

