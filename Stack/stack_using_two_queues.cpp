#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // Initailize objects of two in-built queues.
    queue<int> q1, q2;
    // To maintain current size of stack
    int curr_size;

    public:
        Stack()
        {
            curr_size = 0;
        }

        void push(int x)
        {
            q1.push(x);
            curr_size++;
        }

        void pop(){
            if (q1.empty())
            {
                cout << "Stack is Empty, thus deletion cannot be performed\n";
                return;
            }
            // Leave one element in q1 and push all other elements in second queue (q2).
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            // Pop the only left element from first queue (q1)
            cout<<"The popped element is: "<<q1.front()<<endl;
            q1.pop();
            curr_size--;
            // Swap the names of two queues
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
            return;
        }

        void top()
        {
            if (q1.empty())
            {
                cout<<"Stack is Empty\n";
                return;
            }
            while( q1.size() != 1 )
            {
               q2.push(q1.front());
               q1.pop();
            }
            // Last pushed element to Stack
            int temp = q1.front();
            cout<<"The Top Element of Stack is: "<<temp<<endl;
            // To empty the auxiliary queue after last operation
            q1.pop();
            // Push last element to second queue (q2)
            q2.push(temp);
            // Swap the names of the two queues
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
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
