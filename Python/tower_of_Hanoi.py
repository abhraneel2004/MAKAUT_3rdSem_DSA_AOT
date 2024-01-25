def towerOfHanoi(n, from_, to, aux):
    if n==1:
        print(from_,"------>", to)
        return
    towerOfHanoi(n-1, from_, aux, to)
    print(from_,"------>", to)
    towerOfHanoi(n-1, aux, to, from_)

n = int(input("Enter the number of disks:  "))
towerOfHanoi(n, "A", "B", "C")