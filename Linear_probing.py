def acc_set(A):
    n = int(input("Enter the size of hash table : "))
    no = int(input("Enter number of elements : "))
    A.clear()
    for i in range(n):
        A.append(0)
    for i in range(no):
        x = int(input("Enter value of key : "))
        p = hashfn(x,n)
        if A[p] == 0:
            A[p] = x
        else:
            tmp = (p+1)%n
            while tmp != p:
                print(f"Trying for {x}")
                if A[tmp] == 0:
                    A[tmp] = x
                    break
                tmp = (tmp + 1) % n
                    
def display_set(A):
    n = len(A)
    if n == 0:
        print("Hash table is empty")
    else:
        for i in range(n):
            print(A[i],end=" | ")
    print()

def hashfn(x,n):
    p = x%n
    return p

def main():
    A = []
    while True:
        print("1. Accept\n2. Display\n3. Exit\n")
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

'''
    Input and output
    1. Accept
    2. Display
    3. Exit

    Enter your choice : 1
    Enter the size of hash table : 10
    Enter number of elements : 6
    Enter value of key : 11
    Enter value of key : 22
    Enter value of key : 32
    Trying for 32
    Enter value of key : 44
    Enter value of key : 24
    Trying for 24
    Enter value of key : 55
    Trying for 55
    1. Accept
    2. Display
    3. Exit

    Enter your choice : 2
    0 | 11 | 22 | 32 | 44 | 24 | 55 | 0 | 0 | 0 |
    1. Accept
    2. Display
    3. Exit

    Enter your choice : 3
    End of the program
'''