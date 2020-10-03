#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;

    node(int num){
        data=num;
        next=NULL;
    }
};

class LinkedList{
    public:
        node *head;
        node *tail;

    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    void addFront(int x){
        node *temp = new node(x);
        if(head==NULL){
            temp->next=tail;
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }

    void removeFront(){
        if(head==NULL){
            cout<<"-1\n";
        }
        else{
            node *temp = head;
            head=head->next;
            cout<<temp->data<<"\n";
            delete temp;
        }
    }

    void front(){
        if(head==NULL){
            cout<<"-1\n";
        }
        else{
            cout<<head->data<<"\n";
        }
    }

    void empty(){
        if(head==NULL){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList list;
    while(n--){
        string str;
        cin >>str;
        if(str=="empty"){
            list.empty();
        }
        else if(str=="front"){
            list.front();
        }
        else if(str=="removeFront"){
            list.removeFront();
        }
        else if(str=="addFront"){
            int x;
            cin >>x;
            list.addFront(x);
        }
    }
}