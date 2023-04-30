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
            obj = pickle.load(file)
            print(f"Name\tEmployee id\tDesignation\tSalary")
            print("-------------------------------------------------")
            print(f"{obj.name:<10}{obj.emp_id:<15}{obj.designation:<15}{obj.salary}")

f= File()

f.create()
f.Display()