#include<map>
#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertnode(node* &head,node* &tail, int data)
{
    if(head == NULL)
    {
        node* newnode = new node(data);
        newnode->next = head;
        head = newnode;
        tail = newnode;
        return;
    }
    node* newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

void detect_cycle(node* &head)
{
    if(head==NULL)
    {
        return;
    }
    node* ptr = head;
    map<node*,bool> visited;
    
    while(ptr)
    {
        if(visited[ptr]==1)
        {
            cout << "cycle Detected" <<endl;
            return;
        }
        visited[ptr] = 1;
        ptr = ptr->next;
    }
    cout << "cycle not detected"<<endl;
}

void print(node* head)
{
    if(head==NULL)
    {
        return;
    }
    node* temp = head;
    while(temp)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}

int main()
{
    node* head;
    node* tail;
    insertnode(head,tail,10);
    insertnode(head,tail,20);
    insertnode(head,tail,30);
    insertnode(head,tail,40);
    insertnode(head,tail,50);
    insertnode(head,tail,60);
    tail->next = head->next->next;
    
    detect_cycle(head);
   // print(head);
   cout << head->data <<" ";
   cout << tail->data<<" ";
    return 0;
}


