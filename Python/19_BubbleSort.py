
def bubbleSort(arr, n):
    
    for i in range(n-1):
        c = 0
        for j in range(n-i-1):
            if arr[j]> arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                c+=1
        if not c:
            break

if __name__ == '__main__':
    n = int(input("Enter the number of elements in array:  "))
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i}: ")))
    print("Array before Sorting: ",a)
    bubbleSort(a, n)
    print("Array after Sorting: ",a)