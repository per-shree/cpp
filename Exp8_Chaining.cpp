
#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    int PRN;
    char name[30];
    float marks;
    node *next;
};

node *H[10];

class HashTable
{
public:
    HashTable()
    {
        for(int i = 0; i < 10; i++)
        {
            H[i] = NULL;
        }
    }

    int hashFunction(int PRN);
    void insert();
    void search();
    void deleteRecord();
    void display();
};

int HashTable :: hashFunction(int PRN)
{
    return PRN % 10;
}

// Insert Record
void HashTable :: insert()
{
    node *newnode = new node;

    cout << "Enter PRN: ";
    cin >> newnode->PRN;

    cout << "Enter Name: ";
    cin >> newnode->name;

    cout << "Enter Marks: ";
    cin >> newnode->marks;

    int h = hashFunction(newnode->PRN);

    newnode->next = H[h];
    H[h] = newnode;

    cout << "Record inserted successfully!" << endl;
}

// Search Record
void HashTable :: search()
{
    int PRN;

    cout << "Enter PRN to search: ";
    cin >> PRN;

    int h = hashFunction(PRN);
    node *temp = H[h];

    while(temp != NULL)
    {
        if(temp->PRN == PRN)
        {
            cout << "\nRecord found!" << endl;
            cout << "PRN: " << temp->PRN << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Marks: " << temp->marks << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Record not found!" << endl;
}

// Delete Record
void HashTable :: deleteRecord()
{
    int PRN;

    cout << "Enter PRN to delete: ";
    cin >> PRN;

    int h = hashFunction(PRN);

    node *temp = H[h];
    node *prev = NULL;

    while(temp != NULL)
    {
        if(temp->PRN == PRN)
        {
            if(prev == NULL)
            {
                H[h] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;

            cout << "Record deleted successfully!" << endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Record not found!" << endl;
}

// Display Hash Table
void HashTable :: display()
{
    cout << "\nHash Table Using Chaining\n";

    for(int i = 0; i < 10; i++)
    {
        cout << i << " -> ";

        node *temp = H[i];

        while(temp != NULL)
        {
            cout << "[PRN: " << temp->PRN
                 << ", Name: " << temp->name
                 << ", Marks: " << temp->marks << "] -> ";

            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

int main()
{
    HashTable ht;
    int ch;

    do
    {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                ht.insert();
                break;

            case 2:
                ht.search();
                break;

            case 3:
                ht.deleteRecord();
                break;

            case 4:
                ht.display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(ch != 5);

    return 0;
}
