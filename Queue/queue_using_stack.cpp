#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;
    // Add an item to the queue
    void enQueue(int x)
    {
        // Push item into the first stack (s1)
        s1.push(x);
    }
    // Remove an item from the queue
    int deQueue()
    {
        // If both stacks are empty, then exit
        if (s1.empty() && s2.empty()){
            cout << "Queue is Empty, thus deletion cannot be performed\n";
            return -1;
        }

        // If second stack (s2) is empty, move elements from first stack (s1) to second stack (s2)
        if (s2.empty()) {
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        // Return the top item from second stack (s2)
        int x = s2.top();
        s2.pop();
        return x;
    }
    void sizeQueue()
    {
        cout<<"Size of the Queue: "<<s1.size()+s2.size()<<endl;
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
