class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_begin(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def insert_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

    def delete_begin(self):
        if self.head is None:
            print("List is empty")
        else:
            if self.head.next is None:
                self.head = None
            else:
                self.head = self.head.next
                self.head.prev = None

    def delete_end(self):
        if self.head is None:
            print("List is empty")
        else:
            if self.head.next is None:
                self.head = None
            else:
                temp = self.head
                while temp.next:
                    temp = temp.next
                temp.prev.next = None

    def display(self):
        if self.head is None:
            print("List is empty")
        else:
            temp = self.head
            while temp:
                print(temp.data, end=" ")
                temp = temp.next
            print()

# Example usage:
dll = DoublyLinkedList()
dll.insert_begin(10)
dll.insert_end(20)
dll.insert_begin(5)
dll.display()  # Output: 5 10 20
dll.delete_begin()
dll.display()  # Output: 10 20
dll.delete_end()
dll.display()  # Output: 10