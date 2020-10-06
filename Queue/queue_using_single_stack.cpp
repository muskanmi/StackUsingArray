#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s;
    // Add an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }
    // Remove an item from the queue
    int deQueue()
    {

         if (s.empty()) {
            cout << "Queue is Empty, thus deletion cannot be performed\n";
            return -1;
        }

        // Pop an item from the stack
        int x = s.top();
        s.pop();

        // If the stack becomes empty, then return the popped item
        if (s.empty())
            return x;

        // Recursive call of Dequeue Function
        int item = deQueue();

        // Push popped item back to the stack
        s.push(x);

        // Return the result of deQueue() function call
        return item;
    }
    void sizeQueue()
    {
        cout<<"Size of the Queue: "<<s.size()<<endl;
    }
};

int main()
{
    Queue q;
    int x, data;
    do
    {
        cout<<"\nMain Menu: \n";
        cout<<"1. Insertion to Queue \n";
        cout<<"2. Deletion from Queue \n";
        cout<<"3. Size of Queue\n";
        cout<<"4. Quit\n";
        cout<<"Enter your choice (1-4): ";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Enter the value to be inserted in Queue: ";
                    cin>>data;
                    q.enQueue(data);
                    break;
            case 2: data = q.deQueue();
                    if(data!=-1)
                        cout<<"The deleted element is: "<<data<<endl;
                    break;
            case 3: q.sizeQueue();
                    break;
            case 4: exit(0);
            default: cout<<"Invalid Choice Entered\n";
        }
    }
    while(true);
    return 0;
}
