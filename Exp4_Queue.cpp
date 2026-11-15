#include <iostream>
using namespace std;

class JobQueue
{
public:
    int front;
    int rear;
    int max;
    int queue[5];

    JobQueue()
    {
        front = 0;
        rear = -1;
        max = 5;
    }

    int isEmpty();
    int isFull();
    void addJob();
    void deleteJob();
    void display();
};

int JobQueue::isEmpty()
{
    if (front > rear)
        return 1;
    else
        return 0;
}

int JobQueue::isFull()
{
    if (rear == max - 1)
        return 1;
    else
        return 0;
}

void JobQueue::addJob()
{
    if (!isFull())
    {
        int job;
        cout << "Enter Job Number: ";
        cin >> job;

        rear++;
        queue[rear] = job;

        cout << "Job added successfully." << endl;
    }
    else
    {
        cout << "Queue is full." << endl;
    }
}

void JobQueue::deleteJob()
{
    if (!isEmpty())
    {
        cout << "Deleted Job: " << queue[front] << endl;
        front++;
    }
    else
    {
        cout << "Queue is empty." << endl;
    }
}

void JobQueue::display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Jobs in Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    JobQueue jobQueue;
    int choice;
    char ch;

    do
    {
        cout << "\nJOB QUEUE";
        cout << "\n1. Add Job";
        cout << "\n2. Delete Job";
        cout << "\n3. Display Job";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                jobQueue.addJob();
                break;

            case 2:
                jobQueue.deleteJob();
                break;

            case 3:
                jobQueue.display();
                break;

            default:
                cout << "Invalid choice.";
        }

        cout << "\nDo you want to continue (Y/N): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}