
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
    
    def insertBegin(self, data):
        curr = Node(data)
        curr.next = self.head
        self.head = curr
    
    def insertEnd(self, data):
        if self.head==None:
            curr = Node(data)
            curr.next = self.head
            self.head = curr
        
        else:
            last_node = self.head
            while last_node.next != None:
                last_node = last_node.next
            curr = Node(data)
            last_node.next = curr
    
    def delBegin(self):
        if self.head == None:
            print('List is empty')
            return
        self.head = self.head.next
    
    def delEnd(self):
        if self.head==None:
            print("List is Empty")
            return
        second_last = self.head
        while second_last.next.next:
            second_last = second_last.next
        second_last.next = None
    
    def printList(self):
        if self.head==None:
            print("List is Empty")
            return
        curr = self.head
        while curr:
            print(curr.data,"->", end = " ")
            curr = curr.next
        print("None")

if __name__ == "__main__":
    sll = SinglyLinkedList()
    c=1
    while c!=6:
        print("-----Single Linked List--------")
        print("1. Insert at Begin")
        print('2. Insert at End')
        print("3. Delete from Begin")
        print("4. Delete from end")
        print("5. Display list")
        print("6. Exit")
        
        try:
            c = int(input("Enter your choice (1-6): "))
        except Exception as e:
            print("Illegal Input")
            continue
        if c==1:
            sll.insertBegin(int(input("Enter the data: ")))
        elif c==2:
            sll.insertEnd(int(input("Enter the data: ")))
        elif c==3:
            sll.delBegin()
        elif c==4:
            sll.delEnd()
        elif c==5:
            sll.printList()
        elif c==6:
            break
        else:
            print("Invalid Choice")
        