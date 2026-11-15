#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int max;
    char st[10];

    Stack()
    {
        top = -1;
        max = 10;
    }

    int IsEmpty();
    int IsFull();
    void push(char c);
    char pop();
    char getTop();
    void check();
};

int Stack::IsEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack::IsFull()
{
    if(top == max - 1)
        return 1;
    else
        return 0;
}

void Stack::push(char c)
{
    if(!IsFull())
    {
        st[++top] = c;
    }
    else
    {
        cout << "Stack Overflow";
    }
}

char Stack::pop()
{
    if(!IsEmpty())
        return st[top--];
    else
        return 'u';
}

char Stack::getTop()
{
    if(!IsEmpty())
    {
        return st[top];
    }
    else
    {
        return 0;
    }
}

void Stack::check()
{
    char Exp[20];
    char ch, ch1;

    cout << "Enter Expression: ";
    cin >> Exp;

    int i = 0;
    int flag = 0;

    while(Exp[i] != '\0')
    {
        ch = Exp[i];

        if(ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        else
        {
            switch(ch)
            {
                case ')':
                    ch1 = pop();

                    if(ch1 != '(')
                    {
                        flag = 1;
                    }
                    break;

                case ']':
                    ch1 = pop();

                    if(ch1 != '[')
                    {
                        flag = 1;
                    }
                    break;

                case '}':
                    ch1 = pop();

                    if(ch1 != '{')
                    {
                        flag = 1;
                    }
                    break;
            }
        }

        if(flag == 1)
            break;

        i++;
    }

    if(IsEmpty() && flag == 0)
    {
        cout << "Expression is well parenthesized.";
    }
    else
    {
        cout << "Expression is not well parenthesized";
    }
}

int main()
{
    char c;

    do
    {
        Stack Exp;
        Exp.check();

        cout << "\nDo you want to continue (Y/N): ";
        cin >> c;

    } while(c == 'Y' || c == 'y');

    cout << "Your service is completed!";
    return 0;
}