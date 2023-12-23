def selectionSort(arr, n):
    for i in range(n-1):
        minidx = i
        for j in range(n):
            if arr[j]>arr[minidx]:
                minidx = j
        if minidx!=i:
            arr[minidx], arr[i] = arr[i], arr[minidx]


if __name__ == '__main__':
    n = int(input("Enter the number of elements in array:  "))
    a = []
    for i in range(n):
        a.append(int(input(f"Enter element {i}: ")))
    print("Array before Sorting: ",a)
    selectionSort(a, n)
    print("Array after Sorting: ",a)