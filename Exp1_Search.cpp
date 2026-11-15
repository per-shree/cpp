#include <algorithm>
#include <iostream>
using namespace std;

void LinearSearch(int n, int A[], int key)
{
    int found = 0;
    int comparisons = 0;

    for(int i = 0; i < n; i++)
    {
        comparisons++;

        if(A[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        cout << "\nStudent is absent";
    }
    else
    {
        cout << "\nStudent is present";
    }

    cout << "\nTotal number of comparisons in Linear Search "
         << comparisons;
}

void BinarySearch(int n, int A[], int key)
{
    sort(A, A + n);

    int start = 0, end = n - 1;
    int comparisons = 0;
    int found = 0;

    while(start <= end)
    {
        int mid = (start + end) / 2;
        comparisons++;

        if(A[mid] == key)
        {
            found = 1;
            break;
        }
        else if(A[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if(found == 1)
    {
        cout << "\nStudent is present";
    }
    else
    {
        cout << "\nStudent is absent";
    }

    cout << "\nTotal number of comparisons in Binary Search "
         << comparisons;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int A[100];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter roll No: ";
        cin >> A[i];
    }

    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    int choice;
    char ch;
    int key;

    do
    {
        cout << "\n1. Linear Search";
        cout << "\n2. Binary Search";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter roll No to search: ";
                cin >> key;
                LinearSearch(n, A, key);
                break;

            case 2:
                cout << "\nEnter roll No to search: ";
                cin >> key;
                BinarySearch(n, A, key);
                break;

            case 3:
                cout << "Exiting the program";
                break;

            default:
                cout << "Invalid choice";
        }

        cout << "\nDo you want to continue (Y/N)? ";
        cin >> ch;

    } while(ch == 'Y' || ch == 'y');

    cout << "\nYour service is completed.";

    return 0;
}
