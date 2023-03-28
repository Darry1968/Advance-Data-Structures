def acc_set(A):
    n = int(input("Enter the size of hash table : "))
    A.clear()
    for i in range(n):
        A.append(0)
    for i in range(n):
        x = int(input("Enter value : "))
        p = hashfn(x,n)

        if A[p] == 0:
            A[p] = x
        else:
            tmp = (p+1)%n
            while tmp != p:
                if A[tmp] == 0:
                    A[tmp] = x
                    break
                    
def display_set(A):
    n = len(A)
    if n == 0:
        print("Hash table is empty")
    else:
        for i in range(n):
            print(A[i])

def hashfn(x,n):
    p = x%n
    return p

def main():
    A = []
    while True:
        print("1. Accept\n2. Display\n3.Exit\n")
        ch = int(input("Enter your choice : "))
        if ch == 1:
            acc_set(A)
        elif ch == 2:
            display_set(A)
        elif ch == 3:
            print("End of the program")
            break
        else:
            print("Wrong choice try again")

if __name__ == '__main__':
    main()