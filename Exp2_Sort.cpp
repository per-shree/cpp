
#include <iostream>
using namespace std;

void BubbleSort(int n, float A[])
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                float temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }

        cout << "\nFor pass " << i+1 << ":";

        for(int k = 0; k < n; k++)
        {
            cout << A[k] << " ";
        }
    }

    cout << "\nTop 3 students percentages are:";

    for(int k = n-1; k > n-4; k--)
    {
        cout << A[k] << " ";
    }
}

void SelectionSort(int n, float A[])
{
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;

        for(int j = i+1; j < n; j++)
        {
            if(A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }

        float temp = A[minIndex];
        A[minIndex] = A[i];
        A[i] = temp;

        cout << "\nFor pass " << i+1 << ":";

        for(int k = 0; k < n; k++)
        {
            cout << A[k] << " ";
        }
    }

    cout << "\nTop 3 students percentages are:";

    for(int k = n-1; k > n-4; k--)
    {
        cout << A[k] << " ";
    }
}

int main()
{
    int n;
    float A[65];
    int choice;
    char ch;

    cout << "Enter number of students: ";
    cin >> n;

    do
    {
        cout << "\nEnter percentages of students:";

        for(int i = 0; i < n; i++)
        {
            cout << "\nStudent " << i+1 << ":";
            cin >> A[i];
        }

        cout << "\n1. Bubble Sort";
        cout << "\n2. Selection Sort";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                BubbleSort(n, A);
                break;

            case 2:
                SelectionSort(n, A);
                break;

            default:
                cout << "Invalid choice";
        }

        cout << "\nThe total percentages are:";

        for(int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }

        cout << "\nDo you want to continue (Y/N): ";
        cin >> ch;

    } while(ch == 'Y' || ch == 'y');

    cout << "\nYour service is completed.";

    return 0;
}