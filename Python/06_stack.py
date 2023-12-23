
def s_pop(arr):
    if (not len(arr)):
        print('Stack Underflow')
        return
    arr.pop()

def s_display(arr):
    if (not len(arr)):
        print('Stack Underflow')
        return
    print("Stack : ", a[::-1])

if __name__ == '__main__':
    a = []
    
    while True:
        print('----Stack Operations------')
        print('1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n')
        c = int(input("Enter your choice: "))
        if(c==1):
            val = int(input("Enter the data to be pushed:   "))
            a.append(val)
        elif(c==2):
            s_pop(a)
        elif(c==3):
            print("Stack Top: ", a[-1])
        elif(c==4):
            s_display(a)
        elif c==5:
            break
        else:
            print("Invalid Choice")