#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

// Define the structure of the index record
struct IndexRecord
{
    char key[10];
    long offset;
};

// Define the size of the index record
const int RECORD_SIZE = sizeof(IndexRecord);

// Function to add a new index record
void addRecord(fstream &indexFile)
{
    IndexRecord record;

    cout << "Enter the key: ";
    cin >> record.key;
    cout << "Enter the offset: ";
    cin >> record.offset;

    // Write the record to the end of the file
    indexFile.seekp(0, ios::end);
    indexFile.write(reinterpret_cast<char *>(&record), RECORD_SIZE);
}

// Function to search for an index record
void searchRecord(fstream &indexFile)
{
    char key[10];
    IndexRecord record;

    cout << "Enter the key to search for: ";
    cin >> key;

    // Search the file for the record with the matching key
    indexFile.seekg(0, ios::beg);
    while (indexFile.read(reinterpret_cast<char *>(&record), RECORD_SIZE))
    {
        if (strcmp(record.key, key) == 0)
        {
            cout << "Record found:" << endl;
            cout << "Key: " << record.key << endl;
            cout << "Offset: " << record.offset << endl;
            return;
        }
    }

    // If the key is not found, print an error message
    cout << "Record not found." << endl;
}

// Function to print all index records
void printRecords(fstream &indexFile)
{
    IndexRecord record;

    cout << setw(10) << "Key" << setw(10) << "Offset" << endl;
    cout << "-----------------------" << endl;

    // Read each record and print its key and offset
    indexFile.seekg(0, ios::beg);
    while (indexFile.read(reinterpret_cast<char *>(&record), RECORD_SIZE))
    {
        cout << setw(10) << record.key << setw(10) << record.offset << endl;
    }
}

int main()
{
    fstream indexFile("index.dat", ios::in | ios::out | ios::binary);

    // If the index file does not exist, create it
    if (!indexFile)
    {
        indexFile.open("index.dat", ios::out | ios::binary);
        indexFile.close();
        indexFile.open("index.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do
    {
        cout << endl;
        cout << "1. Add a new record" << endl;
        cout << "2. Search for a record" << endl;
        cout << "3. Print all records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord(indexFile);
            break;
        case 2:
            searchRecord(indexFile);
            break;
        case 3:
            printRecords(indexFile);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    indexFile.close();
    return 0;
}