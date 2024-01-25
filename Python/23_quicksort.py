
def quickSort(a):
    if len(a) <=1:
        return a
    pivot = a[len(a)//2]
    l = [x for x in a if x< pivot]
    middle = [x for x in a if x==pivot]
    r = [x for x in a if x>pivot]

    return quickSort(l)+middle+quickSort(r)
    

a = eval(input("Enter the array:   "))
a = quickSort(a)
print(a)
