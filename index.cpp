#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

int i = 0;
typedef struct EMPLOYEE
{
    char name[10];
    int emp_id;
    char designation[10];
    int salary;
} Rec;

typedef struct INDEX
{
    int emp_id;
    int position;
} Ind_rec;

const int emp_size = sizeof(EMPLOYEE);

class EMP_class
{
    Rec Records;
    Ind_rec Ind_Records;

public:
    EMP_class()
    {
        strcpy(Records.name, "");
        strcpy(Records.designation, "");
        Records.emp_id = -1;
        Records.salary = 0;
    }

    void Create()
    {
        char ch = 'y';
        fstream seqFile;
        fstream indexFile;
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary);
        seqFile.open("EMP.DAT", ios::in | ios::out | ios::binary);

        do
        {
            cout << "Enter Employee id : ";
            cin >> Records.emp_id;
            cin.ignore();
            cout << "Enter name : ";
            cin.getline(Records.name, 10);
            cout << "Enter Salary : ";
            cin >> Records.salary;
            cin.ignore();
            cout << "Enter designation : ";
            cin.getline(Records.designation, 10);

            seqFile.write((char *)&Records, sizeof(Records)) << flush;
            Ind_Records.emp_id = Records.emp_id;
            Ind_Records.position = i;
            i++;
            indexFile.write((char *)&Ind_Records, sizeof(Ind_Records)) << flush;

            cout << "DO you want to add more records?(y/n) : ";
            cin >> ch;
        } while (ch == 'y');
        indexFile.close();
        seqFile.close();
    }
    void Display()
    {
        fstream seqFile;
        fstream indexFile;
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary);
        seqFile.open("EMP.DAT", ios::in | ios::out | ios::binary);

        cout << setw(10) << "Name" << setw(15) << "Employee id" << setw(15) << "Designation" << setw(15) << "Salary" << endl;
        cout << "---------------------------------------------------------" << endl;

        seqFile.seekg(0, ios::beg);
        while (seqFile.read(reinterpret_cast<char *>(&Records), emp_size))
        {
            cout << setw(10) << Records.name << setw(10) << Records.emp_id << setw(20) << Records.designation << setw(15) << Records.salary << endl;
        }
    }
    void Update()
    {
        fstream seqFile;
        fstream indexFile;
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary);
        seqFile.open("EMP.DAT", ios::in | ios::out | ios::binary);
        int id, flag = 0;

        char n[10], d[10];
        int Id, s;

        cout << "Enter employee id whose data you want to update : ";
        cin >> id;

        while (indexFile.read(reinterpret_cast<char *>(&Ind_Records), sizeof(Ind_Records)))
        {
            if (Ind_Records.emp_id == id)
            {
                flag = 1;
                cout << "Enter new name : ";
                cin.ignore();
                cin.getline(Records.name, 10);

                cout << "Enter new id : ";
                cin >> Records.emp_id;

                cout << "Enter new designation : ";
                cin.ignore();
                cin.getline(Records.designation, 10);

                cout << "Enter new salary : ";
                cin >> Records.salary;

                int location = Ind_Records.position * sizeof(Records);
                // cout << "Location : " << location << endl;
                seqFile.seekp(location);

                seqFile.write(reinterpret_cast<char *>(&Records), sizeof(Records));
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Employee not found" << endl;
        }
        seqFile.close();
        indexFile.close();
    }
    void Delete()
    {
        fstream seqFile, testfile;
        fstream indexFile, testindex;
        int id, flag = 0;

        seqFile.open("EMP.DAT", ios::in | ios::out | ios::binary);
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary);
        testfile.open("Temp.dat", ios::out | ios::binary);
        testindex.open("TempIndex.dat", ios::out | ios::binary);

        cout << "Enter Employee id whose data you want to delete : ";
        cin >> id;

        while (seqFile.read(reinterpret_cast<char *>(&Records), sizeof(Records)))
        {
            if (Records.emp_id != id)
            {
                testfile.write(reinterpret_cast<char *>(&Records), sizeof(Records));
            }
            else
            {
                flag = 1;
            }
        }

        while (indexFile.read(reinterpret_cast<char *>(&Ind_Records), sizeof(Ind_Records)))
        {
            if (Ind_Records.emp_id != id)
            {
                testindex.write(reinterpret_cast<char *>(&Ind_Records), sizeof(Ind_Records));
            }
        }

        if (flag == 0)
        {
            cout << "Employee not found!!" << endl;
        }
        else
        {
            cout << "Employee deleted" << endl;
        }

        seqFile.close();
        indexFile.close();
        testfile.close();
        testindex.close();

        remove("EMP.DAT");
        rename("Temp.dat", "EMP.DAT");

        remove("IND.DAT");
        rename("TempIndex.dat", "IND.DAT");
    }
    void Append()
    {
        fstream seqFile;
        fstream indexFile;
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary | ios::app);
        seqFile.open("EMP.DAT", ios::in | ios::out | ios::binary | ios_base::app);

        cout << "Enter new Employee id : ";
        cin >> Records.emp_id;
        cin.ignore();
        cout << "Enter new Employee name : ";
        cin.getline(Records.name, 10);
        cout << "Enter new Employee's Salary : ";
        cin >> Records.salary;
        cin.ignore();
        cout << "Enter new Employee's designation : ";
        cin.getline(Records.designation, 10);

        Ind_Records.emp_id = Records.emp_id;
        Ind_Records.position = i;
        i++;
        indexFile.write((char *)&Ind_Records, sizeof(Ind_Records)) << flush;

        seqFile.seekp(0, ios::end);
        seqFile.write(reinterpret_cast<char *>(&Records), sizeof(Records));

        seqFile.close();
        indexFile.close();
    }
    void Search()
    {
        fstream indexFile;
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary | ios::app);

        int id, flag = 0;
        cout << "Enter employee id to search : ";
        cin >> id;
        while (indexFile.read(reinterpret_cast<char *>(&Ind_Records), sizeof(Ind_Records)))
        {
            if (Ind_Records.emp_id == id)
            {
                flag = 1;
                cout << "Position : " << Ind_Records.position << endl;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Record is not found" << endl;
        }
        else
            cout << "record is found";
    }
};

int main()
{
    EMP_class list;
    char ans = 'y';
    int choice, key;
    do
    {
        cout << "\n\t\tMain Menu\t\t" << endl;
        cout << "\n1. Create";
        cout << "\n2. Display";
        cout << "\n3. Update";
        cout << "\n4. Delete";
        cout << "\n5. Append";
        cout << "\n6. Search";
        cout << "\n7. Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.Create();
            break;
        case 2:
            list.Display();
            break;
        case 3:
            list.Update();
            break;
        case 4:
            list.Delete();
            break;
        case 5:
            list.Append();
            break;
        case 6:
            list.Search();
            break;
        case 7:
            exit(0);
            break;

        default:
            cout << "Wrong choice try again";
            break;
        }
    } while (ans == 'y');

    return 0;
}

/*
    You have to create both files EMP.DAT and IND.DAT code is not designed in the way to create files automatically
*/