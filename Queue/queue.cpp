#include <iostream>
#include <stdlib.h>
using namespace std;
#define N 100

class Queue
{
    int front,rear,queue[N];
    public:
        Queue()
        {
            front=rear=-1;
        }
        void enQueue(int data)
        {
            if(rear==N-1)
            {
                cout<<"Queue if Full (Queue Overflow)\n";
                return;
            }
            if(rear==-1)
                front=rear=0;
            else
                rear++;
            queue[rear] = data;
        }
        void deQueue()
        {
            if(front==-1)
             {
                 cout<<"Queue is Empty (Queue Underflow)\n";
                 return;
             }
             cout<<"Deleted element from queue is: "<<queue[front]<<endl;
             if(front==rear)
                front=rear=-1;
             else
                front++;
        }
        void traversal()
        {
            if(front==-1)
             {
                 cout<<"Queue is Empty (Queue Underflow)\n";
                 return;
             }
            cout<<"The elements present in the queue: \n";
            for(int i=front;i<=rear;i++)
                cout<<queue[i]<<" ";
            cout<<endl;
        }
};

int main()
{
    Queue q;
    int x,data;
    do
    {
        cout<<"\nChoose the operation you want to perform: \n";
        cout<<"1. Insertion to Queue \n";
        cout<<"2. Deletion from Queue \n";
        cout<<"3. Traversal of Queue \n";
        cout<<"4. Quit \n";
        cout<<"Enter your choice(1-4): ";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Enter the data to be stored: ";
                    cin>>data;
                    q.enQueue(data);
                    break;
            case 2: q.deQueue();
                    break;
            case 3: q.traversal();
                    break;
            case 4: exit(0);
            default: cout<<"Invalid Choice Entered\n";
        }
    }
    while(true);
    return 0;
}
