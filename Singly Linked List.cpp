#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;

    Node(int data){
        this->value = data;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node *head;
    Node *tail;

    LinkedList(){
        head=NULL;
        tail=NULL;
    }

    void addFront(int value){
        if(head==NULL){
            Node *temp = new Node(value);
            temp->next=tail;
            head = temp;
        }
        else{
            Node *temp = new Node(value);
            temp->next=head;
            head = temp;
        }
    }

    void removeFront(){
        if(head==NULL){
            cout<<"-1\n";
        }
        else{
            cout<<head->value<<"\n";
            Node *temp=head;
            head=head->next;
            delete temp;
        }
    }
    void front(){
        if(head==NULL){
            cout<<"-1\n";
        }
        else{
            cout<<head->value<<"\n";
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
    LinkedList list;
    int n;
    cin >>n;
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
            int a;
            cin >> a;
            list.addFront(a);
        }
    }
}