import pickle

class Employee:
    def __init__(self,name,id,designation,salary):
        self.name = name
        self.emp_id = id
        self.designation = designation
        self.salary = salary

class File:
    e = Employee("",0,"",0)

    def create(self):
        ch = 'y'
        while ch == 'y':
            self.e.name = input("Enter employee name : ")
            self.e.emp_id = int(input("Enter the employee id : "))
            self.e.designation = input("Enter the employee's designation : ")
            self.e.salary = int(input("Enter the salary of employee : "))

            with open("seq.dat","wb") as file:
                pickle.dump(self.e,file)
            
            ch = input("Do you want to add more employee?(y/n) : ")

    def Display(self):
        with open("seq.dat","rb") as file:
            print(f"Name\tEmployee id\tDesignation\tSalary")
            print("-------------------------------------------------")
            while True:
                try:
                    obj = pickle.load(file)
                    print(f"{obj.name:<10}{obj.emp_id:<15}{obj.designation:<15}{obj.salary}")
                except EOFError:
                    break

    def Append(self):
        self.e.name = input("Enter new employee name : ")
        self.e.emp_id = int(input("Enter new employee id : "))
        self.e.designation = input("Enter new employee's designation : ")
        self.e.salary = int(input("Enter new salary of employee : "))

        with open('seq.dat','ab') as file:
            pickle.dump(self.e,file)

    def Delete(self):
        pass

    def Update(self):
        pass

if __name__ == '__main__':
    f= File()
    while True:
        print("\n1. Create\n2. Display\n3. Delete\n4. Append\n5. Update\n6. Exit")
        
        ch = int(input("\nEnter your choice : "))
        if ch == 1:
            f.create()
        elif ch == 2:
            f.Display()
        elif ch == 3:
            f.Delete()
        elif ch == 4:
            f.Append()
        elif ch == 5:
            f.Update()
        elif ch == 6:
            exit()
        else:
            print("Wrong choice enter again!!")




