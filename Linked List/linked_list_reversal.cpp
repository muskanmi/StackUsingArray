#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    void reverse()
    {
        Node* current = head;
        Node *prev = NULL, *temp = NULL;
        while (current != NULL)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void display()
    {
        struct Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    int n, data;
    LinkedList ll;
    cout<<"Enter the number of elements to be added in Linked List: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the data item "<<i+1<<": ";
        cin>>data;
        ll.push(data);
    }
    cout << "The Linked List is:\n";
    ll.display();
    cout<<"The Reversed Linked List is:\n";
    ll.reverse();
    ll.display();
    return 0;
}
