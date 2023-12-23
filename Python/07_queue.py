
def s_dequeue(arr):
    if (not len(arr)):
        print('Queue Underflow')
        return
    arr.pop(0)

def s_display(arr):
    if (not len(arr)):
        print('Queue Underflow')
        return
    print("Stack : ", a)

if __name__ == '__main__':
    a = []
    
    while True:
        print('----Queue Operations------')
        print('1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n')
        c = int(input("Enter your choice: "))
        if(c==1):
            val = int(input("Enter the data to be pushed:   "))
            a.append(val)
        elif(c==2):
            s_dequeue(a)
        
        elif(c==3):
            s_display(a)
        elif c==4:
            break
        else:
            print("Invalid Choice")