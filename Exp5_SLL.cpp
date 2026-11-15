#include <iostream>
using namespace std;

struct node
{
    int PRN;
    char name[10];
    node *next;
};

node *temp, *temp1, *nn;

class Club
{
public:
    node *pres;
    node *sect;

    Club() {
        pres = sect = NULL;
    }

    void create();
    void display();
    void count();
    void concat(Club c1, Club c2);
    void add();
    void delet();
};

void Club::create()
{
    int n;
    cout << "Enter no of members you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        nn = new node;
        nn->next = NULL;
        cout << "Enter PRN of student: ";
        cin >> nn->PRN;
        cout << "Enter name of student: ";
        cin >> nn->name;

        if (pres == NULL)
        {
            pres = sect = nn;
        }
        else
        {
            sect->next = nn;
            sect = nn;
        }
    }
}

void Club::concat(Club c1, Club c2)
{
    cout << "\nEnter member of Div B: ";
    c2.create();
    cout << "\n Div A: ";
    c1.display();
    cout << "\n Div B: ";
    c2.display();

    if (c1.pres == NULL)
    {
        c1.pres = c2.pres;
        c1.sect = c2.sect;
    }
    else
    {
        c1.sect->next = c2.pres;
        c1.sect = c2.sect;
    }
    cout << "\n After concatenation: ";
    c1.display();
}

void Club::display()
{
    if (pres == NULL)
    {
        cout << "\n Club is empty.";
    }
    else
    {
        temp = pres;
        cout << "\n students are: " << endl;
        while (temp != NULL)
        {
            cout << temp->PRN << " ";
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
}

void Club::count()
{
    int count = 0;
    temp = pres;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "\n Total Members are: " << count;
}

void Club::add()
{
    nn = new node;
    nn->next = NULL;
    cout << "Enter PRN: ";
    cin >> nn->PRN;
    cout << "Enter name: ";
    cin >> nn->name;

    int choice;
    cout << "\n 1. Add President";
    cout << "\n 2. Add Secretary";
    cout << "\n 3. Add Member";
    cout << "\n Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        nn->next = pres;
        pres = nn;
        if (sect == NULL)
            sect = nn;
        break;

    case 2:
        if (pres == NULL)
        {
            pres = sect = nn;
        }
        else
        {
            sect->next = nn;
            sect = nn;
        }
        break;

    case 3:
        if (pres == NULL || pres->next == NULL)
        {
            cout << "\n Add President and secretary first.";
            delete nn;
            break;
        }
        int afterPRN;
        cout << "\n Enter PRN after which member is to be added: ";
        cin >> afterPRN;
        temp = pres;
        while (temp != NULL && temp->PRN != afterPRN)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "\n PRN not found";
            delete nn;
        }
        else
        {
            nn->next = temp->next;
            temp->next = nn;
        }
        break;

    default:
        cout << "\n Invalid choice";
    }
}

void Club::delet()
{
    if (pres == NULL)
    {
        cout << "\n Club is empty";
        return;
    }
    cout << "\n 1. Delete President";
    cout << "\n 2. Delete Secretary";
    cout << "\n 3. Delete member";
    cout << "\n Enter which element you want to delete: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        temp = pres;
        pres = pres->next;
        delete temp;
        if (pres == NULL)
            sect = NULL;
        break;

    case 2:
        if (pres == sect)
        {
            delete pres;
            pres = sect = NULL;
        }
        else
        {
            temp = pres;
            while (temp->next != sect)
            {
                temp = temp->next;
            }
            delete sect;
            sect = temp;
            sect->next = NULL;
        }
        break;

    case 3:
        int key;
        cout << "\n Enter PRN No of member to delete: ";
        cin >> key;
        if (pres->PRN == key)
        {
            cout << "\n Use delete president option";
            break;
        }
        temp = pres;
        while (temp->next != NULL && temp->next->PRN != key)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "\n Member not found";
        }
        else
        {
            temp1 = temp->next;
            if (temp1 == sect)
                sect = temp;
            temp->next = temp1->next;
            delete temp1;
        }
        break;

    default:
        cout << "\n Invalid choice";
    }
}

int main()
{
    Club c1, c2;
    char ch;
    c1.create();
    c1.display();

    do
    {
        int choice;
        cout << "\n 1. Add";
        cout << "\n 2. Delete";
        cout << "\n 3. Count";
        cout << "\n 4. Display";
        cout << "\n 5. Concatenate";
        cout << "\n Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c1.add();
            c1.display();
            break;

        case 2:
            c1.delet();
            c1.display();
            break;

        case 3:
            c1.count();
            break;

        case 4:
            c1.display();
            break;

        case 5:
            c1.concat(c1, c2);
            break;

        default:
            cout << "\n Invalid choice";
        }

        cout << "\n Do you want to continue (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}