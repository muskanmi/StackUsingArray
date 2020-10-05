#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // Initailize objects of two in-built queues.
    queue<int>q;
    // To maintain current size of stack
    int curr_size;

    public:
        Stack()
        {
            curr_size = 0;
        }

        // Add an element to the Stack
        void push(int x)
        {
            // Get previous size of queue
            int s = q.size();
            // Push current element to queue
            q.push(x);
            // Dequeue all previous elements and Enqueue them after current element
            for (int i=0; i<s; i++)
            {
                // This will add element at front into rear of the queue
                q.push(q.front());
                // This will delete element at front of the queue
                q.pop();
            }
            curr_size++;
        }

        // Remove an element from the Stack
        void pop(){
            if (q.empty())
            {
                cout << "Stack is Empty, thus deletion cannot be performed\n";
                return;
            }
            cout<<"The popped element is: "<<q.front()<<endl;
            q.pop();
            curr_size--;
            return;
        }

        void top()
        {
            if (q.empty())
            {
                cout<<"Stack is Empty\n";
                return;
            }
            cout<<"The Top Element of Stack is: "<<q.front()<<endl;
            return;
        }

        int sizeStack()
        {
            cout<<"Size of the Stack: "<<curr_size<<endl;
        }
};

int main()
{
    Stack s;
    int x, data;
    do
    {
        cout<<"Main Menu \n";
        cout<<"1. Insertion to Stack (Push Operation) \n";
        cout<<"2. Deletion from Stack (Pop Operation) \n";
        cout<<"3. Return Top Element from Stack \n";
        cout<<"4. Size of Stack\n";
        cout<<"5. Quit \n";
        cout<<"Enter your choice (1-5): ";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Enter the value to be inserted in Stack: ";
                    cin>>data;
                    s.push(data);
                    break;
            case 2: s.pop();
                    break;
            case 3: s.top();
                    break;
            case 4: s.sizeStack();
                    break;
            case 5: exit(0);
            default: cout<<"Invalid Choice Entered\n";
        }
    }
    while(true);
    return 0;
}
