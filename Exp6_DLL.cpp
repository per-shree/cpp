#include <iostream>
using namespace std;

struct node
{
    int bit;
    node *prev;
    node *next;
};
node *temp, *nn;

class Binary
{
public:
    node *MSB;
    node *LSB;

    Binary()
    {
        MSB = LSB = NULL;
    }

    void create();
    void display();
    void onesComplement();
    void twosComplement();
    void addition(Binary b1, Binary b2);
};

void Binary::create()
{
    int n;
    cout << "\n Enter no of bits : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        nn = new node;
        nn->next = nn->prev = NULL;
        cout << "Enter bit : ";
        cin >> nn->bit;
        if (MSB == NULL)
        {
            MSB = LSB = nn;
        }
        else
        {
            LSB->next = nn;
            nn->prev = LSB;
            LSB = nn;
        }
    }
}

void Binary::display()
{
    temp = MSB;
    while (temp != NULL)
    {
        cout << temp->bit;
        temp = temp->next;
    }
    cout << endl;
}

void Binary::onesComplement()
{
    temp = MSB;
    while (temp != NULL)
    {
        if (temp->bit == 0)
        {
            temp->bit = 1;
        }
        else
        {
            temp->bit = 0;
        }
        temp = temp->next;
    }
}

void Binary::twosComplement()
{
    int flag = 0;
    temp = LSB;
    while (temp != NULL)
    {
        if (flag == 0)
        {
            if (temp->bit == 1)
            {
                flag = 1;
            }
        }
        else
        {
            if (temp->bit == 0)
            {
                temp->bit = 1;
            }
            else
            {
                temp->bit = 0;
            }
        }
        temp = temp->prev;
    }
}

void Binary::addition(Binary b1, Binary b2)
{
    MSB = LSB = NULL;
    node *temp1 = b1.LSB;
    node *temp2 = b2.LSB;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        nn = new node;
        nn->prev = nn->next = NULL;
        if (temp1->bit == 0 && temp2->bit == 0 && carry == 0)
        {
            nn->bit = 0;
            carry = 0;
        }
        else if (temp1->bit == 0 && temp2->bit == 0 && carry == 1)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp1->bit == 0 && temp2->bit == 1 && carry == 0)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp1->bit == 0 && temp2->bit == 1 && carry == 1)
        {
            nn->bit = 0;
            carry = 1;
        }
        else if (temp1->bit == 1 && temp2->bit == 0 && carry == 0)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp1->bit == 1 && temp2->bit == 0 && carry == 1)
        {
            nn->bit = 0;
            carry = 1;
        }
        else if (temp1->bit == 1 && temp2->bit == 1 && carry == 0)
        {
            nn->bit = 0;
            carry = 1;
        }
        else if (temp1->bit == 1 && temp2->bit == 1 && carry == 1)
        {
            nn->bit = 1;
            carry = 1;
        }
        
        if (MSB == NULL)
        {
            MSB = LSB = nn;
        }
        else
        {
            nn->next = MSB;
            MSB->prev = nn;
            MSB = nn;
        }
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    while (temp1 != NULL)
    {
        nn = new node;
        nn->prev = nn->next = NULL;
        if (temp1->bit == 0 && carry == 0)
        {
            nn->bit = 0;
            carry = 0;
        }
        else if (temp1->bit == 0 && carry == 1)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp1->bit == 1 && carry == 0)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp1->bit == 1 && carry == 1)
        {
            nn->bit = 0;
            carry = 1;
        }

        nn->next = MSB;
        if (MSB != NULL)
        {
            MSB->prev = nn;
        }
        else
        {
            LSB = nn;
        }
        MSB = nn;
        temp1 = temp1->prev;
    }

    while (temp2 != NULL)
    {
        nn = new node;
        nn->prev = nn->next = NULL;
        if (temp2->bit == 0 && carry == 0)
        {
            nn->bit = 0;
            carry = 0;
        }
        else if (temp2->bit == 0 && carry == 1)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp2->bit == 1 && carry == 0)
        {
            nn->bit = 1;
            carry = 0;
        }
        else if (temp2->bit == 1 && carry == 1)
        {
            nn->bit = 0;
            carry = 1;
        }

        nn->next = MSB;
        if (MSB != NULL)
        {
            MSB->prev = nn;
        }
        else
        {
            LSB = nn;
        }
        MSB = nn;
        temp2 = temp2->prev;
    }
    if (carry == 1)
    {
        nn = new node;
        nn->bit = 1;
        nn->prev = NULL;
        nn->next = MSB;
        if (MSB != NULL)
        {
            MSB->prev = nn;
        }
        else
        {
            LSB = nn;
        }
        MSB = nn;
    }
}
int main()
{
    Binary b1, b2, b3, result;
    b1.create();
    cout << "\n Original binary number : ";
    b1.display();

    cout << "\n Ones Complement : ";
    b1.onesComplement();
    b1.display();

    cout << "\n In Twos Complement : ";
    b1.onesComplement();
    b1.twosComplement();
    b1.display();

    cout << "\n Enter first binary number for addition : ";
    b2.create();
    cout << "\n Enter second binary number for addition : ";
    b3.create();

    cout << "\n First binary no : ";
    b2.display();
    cout << "\n Second binary no : ";
    b3.display();

    result.addition(b2, b3);
    cout << "\n Addition is : ";
    result.display();

    return 0;
}