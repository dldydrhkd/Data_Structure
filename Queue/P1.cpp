#include <iostream>
#include <string>
using namespace std;

struct Node{
   int value;
   Node *next;

   Node(int value){
      this->value=value;
      this->next=NULL;
   }
};

class LinkedList{
public:
   Node *head;
   Node *tail;
   int total_size;
   int max_size;

   LinkedList(int s){
      head=NULL;
      tail=NULL;
      max_size=s;
      total_size=0;
   }

   void enqueue(int value){
      if(total_size==max_size){
         cout<<"Full\n";
         return ;
      }
      Node *temp = new Node(value);
      if(head==NULL){
         head=tail=temp;
         total_size++;
      }
      else{
         tail->next = temp;
         tail=temp;
         total_size++;
      }
   }

   void dequeue(){
      if(total_size){
         Node *temp=head;
         cout<<head->value<<"\n";
         head=head->next;
         delete temp;
         total_size--;
      }
      else{
         cout<<"Empty\n";
      }
   }

   void size(){
      cout<<total_size<<"\n";
   }

   void isEmpty(){
      if(total_size){
         cout<<"0\n";
      }
      else{
         cout<<"1\n";
      }
   }

   void front(){
      if(total_size){
         cout<<head->value<<"\n";
      }
      else{
         cout<<"Empty\n";
      }
   }

   void rear(){
      if(total_size){
         cout<<tail->value<<"\n";
      }
      else{
         cout<<"Empty\n";
      }
   }
};

int main(){
   int s;
   cin >>s;
   int n;
   cin >>n;
   LinkedList list(s);
   for(int i=0; i<n; i++){
      string str;
      cin >>str;
      if(str=="isEmpty"){
         list.isEmpty();
      }
      else if(str=="size"){
         list.size();
      }
      else if(str=="enqueue"){
         int a;
         cin >>a;
         list.enqueue(a);
      }
      else if(str=="front"){
         list.front();
      }
      else if(str=="rear"){
         list.rear();
      }
      else if(str=="dequeue"){
         list.dequeue();
      }
   }
}