#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;

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
        int i, j;
        char ch = 'y';
        fstream seqFile;
        fstream indexFile;
        i = 0;
        indexFile.open("IND.DAT", ios::in | ios::out | ios::binary);
        seqFile.open("EMP.DAT", ios::in | ios::out | ios::binary);

        do
        {
            cout << "Enter name : ";
            cin.getline(Records.name, 10);
            cout << "Enter Employee id : ";
            cin >> Records.emp_id;
            cout << "Enter Salary : ";
            cin >> Records.salary;
            cout << "Enter designation : ";
            cin.getline(Records.designation, 10);

            seqFile.write((char *)&Records, sizeof(Records)) << flush;
            Ind_Records.emp_id = Records.emp_id;
            Ind_Records.position = i;
            indexFile.write((char *)&Ind_Records, sizeof(Ind_Records)) << flush;

            cout << "DO you want to add more records? : ";
            cin >> ch;
        } while (ch == 'y');
    }
    // void Display();
    // void Update();
    // void Delete();
    // void Append();
    // void Search();
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
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.Create();
            break;
        // case 2:
        //     list.Display();
        //     break;
        // case 3:
        //     list.Update();
        //     break;
        // case 4:
        //     list.Delete();
        //     break;
        // case 5:
        //     list.Append();
        //     break;
        // case 6:
        //     list.Search();
        //     break;
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