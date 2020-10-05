#include <iostream>
#include <stdlib.h>
#define N 100
using namespace std;

class Stack
{
    int top, stack[N];
    public:
        Stack()
        {
            top = -1;
        }
        void push(int data)
        {
            if(top==N-1)
            {
                cout<<"Stack is Full (Stack Overflow) \n";
                return;
            }
            stack[++top] = data;
        }
        void pop()
        {
            if(top==-1)
            {
                cout<<"Stack is Empty, thus cannot pop an element (Stack Underflow) \n";
                return;
            }
            cout<<"The popped item from the stack is: "<<stack[top--]<<endl;
        }
        void StackTop()
        {
            if(top==-1)
            {
                cout<<"Stack is Empty, thus no TOP Element present \n";
                return;
            }
            cout<<"The top element present in the stack is: "<<stack[top]<<endl;
        }
        void traversal()
        {
            if(top==-1)
            {
                cout<<"Stack is Empty, thus cannot traverse the stack \n";
                return;
            }
            cout<<"The elements present in the Stack are: \n";
            for(int i=top;i>=0;i--)
                cout<<stack[i]<<" ";
            cout<<endl;
        }
        int stackSize()
        {
            cout<<"Size of the Stack: "<<top+1<<endl;
        }
};

int main()
{
    Stack s;
    int x, data;
    do
    {
        cout<<"\nMain Menu \n";
        cout<<"1. Insertion to Stack (Push Operation) \n";
        cout<<"2. Deletion from Stack (Pop Operation) \n";
        cout<<"3. Return Top Element from Stack \n";
        cout<<"4. Traversal of the elements of the Stack \n";
        cout<<"5. Size of Stack\n";
        cout<<"6. Quit \n";
        cout<<"Enter your choice (1-6): ";
        cin>>x;
        switch(x)
        {
            case 1: cout<<"Enter the value to be inserted in Stack: ";
                    cin>>data;
                    s.push(data);
                    break;
            case 2: s.pop();
                    break;
            case 3: s.StackTop();
                    break;
            case 4: s.traversal();
                    break;
            case 5: s.stackSize();
                    break;
            case 6: exit(0);
            default: cout<<"Invalid Choice Entered\n";
        }
    }
    while(true);
    return 0;
}
