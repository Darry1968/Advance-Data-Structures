#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef struct EMPLOYEE
{
    char name[10];
    int emp_id;
    char designation[10];
    int salary;
} Rec;

int main()
{
    Rec Records;
    fstream seqfile;
    seqfile.open("Temp.dat", ios::in | ios::out | ios::binary);
    while (seqfile.read(reinterpret_cast<char *>(&Records), sizeof(Records)))
    {
        cout << setw(10) << Records.name << setw(10) << Records.emp_id << setw(20) << Records.designation << setw(15) << Records.salary << endl;
    }

    return 0;
}