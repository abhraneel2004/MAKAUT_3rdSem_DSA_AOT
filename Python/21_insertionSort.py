
def insertionSort(arr, n):
    for i in range(n-1):
        key = arr[i]
        j = i-1
        while (j >= 0 and arr[j] > key):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key


if __name__ == '__main__':
    n = int(input("Enter the number of elements in array:  "))
    a = []

    for i in range(n):
        a.append(int(input(f"Enter element {i}: ")))
    # a = [2,1,4,3]
    # n = len(a)
    print("Array before Sorting: ", a)
    insertionSort(a, n)
    print("Array after Sorting: ", a)
