
#include <iostream>
#include <cstring>
using namespace std;

struct rec
{
    char name[10];
    int TeleNo;
};

rec H1[10];
rec H2[10];

class HashTable
{
public:
    HashTable()
    {
        for(int i = 0; i < 10; i++)
        {
            H1[i].name[0] = '\0';
            H1[i].TeleNo = -1;

            H2[i].name[0] = '\0';
            H2[i].TeleNo = -1;
        }
    }

    void create();
    void display();
    void search();
};

void HashTable :: create()
{
    int total = 0, TN;
    char NM[10];

    cout << "Enter name: ";
    cin >> NM;

    cout << "Enter TeleNo: ";
    cin >> TN;

    for(int i = 0; NM[i] != '\0'; i++)
    {
        total = total + int(NM[i]);
    }

    int h = total % 10;
    int inserted;

    // Linear Probing
    inserted = 0;

    for(int i = 0; i < 10; i++)
    {
        int nh = (h + i) % 10;

        if(H1[nh].TeleNo == -1)
        {
            strcpy(H1[nh].name, NM);
            H1[nh].TeleNo = TN;
            inserted = 1;
            break;
        }
    }

    if(!inserted)
        cout << "Linear Hash Table is full!" << endl;

    // Quadratic Probing
    inserted = 0;

    for(int i = 0; i < 10; i++)
    {
        int nh = (h + i * i) % 10;

        if(H2[nh].TeleNo == -1)
        {
            strcpy(H2[nh].name, NM);
            H2[nh].TeleNo = TN;
            inserted = 1;
            break;
        }
    }

    if(!inserted)
        cout << "Quadratic Hash Table insertion failed!" << endl;
}

void HashTable :: display()
{
    cout << "\nTelephone Directory using Linear Probing:\n";

    for(int i = 0; i < 10; i++)
    {
        if(H1[i].TeleNo != -1)
        {
            cout << i << "\t" << H1[i].name
                 << "\t" << H1[i].TeleNo << endl;
        }
    }

    cout << "\nTelephone Directory using Quadratic Probing:\n";

    for(int i = 0; i < 10; i++)
    {
        if(H2[i].TeleNo != -1)
        {
            cout << i << "\t" << H2[i].name
                 << "\t" << H2[i].TeleNo << endl;
        }
    }
}

void HashTable :: search()
{
    char NM[10];
    char ch;

    do
    {
        cout << "\nEnter name to search: ";
        cin >> NM;

        int LinComp = 0;
        int QudraComp = 0;
        int total = 0;

        for(int i = 0; NM[i] != '\0'; i++)
        {
            total = total + int(NM[i]);
        }

        int h = total % 10;
        int found = 0;

        // Linear Probing
        for(int i = 0; i < 10; i++)
        {
            int nh = (h + i) % 10;

            LinComp++;

            if(H1[nh].TeleNo == -1)
                break;

            if(strcmp(H1[nh].name, NM) == 0)
            {
                cout << "\nRecord found using Linear Probing\n";
                cout << "Index: " << nh << endl;
                cout << "Name: " << H1[nh].name << endl;
                cout << "TeleNo: " << H1[nh].TeleNo << endl;
                cout << "Comparisons: " << LinComp << endl;

                found = 1;
                break;
            }
        }

        if(!found)
            cout << "Record not found using Linear Probing\n";

        found = 0;

        // Quadratic Probing
        for(int i = 0; i < 10; i++)
        {
            int nh = (h + i * i) % 10;

            QudraComp++;

            if(H2[nh].TeleNo == -1)
                break;

            if(strcmp(H2[nh].name, NM) == 0)
            {
                cout << "\nRecord found using Quadratic Probing\n";
                cout << "Index: " << nh << endl;
                cout << "Name: " << H2[nh].name << endl;
                cout << "TeleNo: " << H2[nh].TeleNo << endl;
                cout << "Comparisons: " << QudraComp << endl;

                found = 1;
                break;
            }
        }

        if(!found)
            cout << "Record not found using Quadratic Probing\n";

        cout << "\nDo you want to search another element (Y/N): ";
        cin >> ch;

    } while(ch == 'Y' || ch == 'y');
}

int main()
{
    HashTable ht;
    int n;

    cout << "Enter the No of users you want to add: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        ht.create();
    }

    ht.display();
    ht.search();

    return 0;
}
