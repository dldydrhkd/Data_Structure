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
         head=head->next;
         delete temp;
         total_size--;
      }
   }

   int front(){
      return (head->value);
   }
};

int main(){
   int t;
   cin >>t;
   while(t--){
      int n;
      cin >>n;
      LinkedList list1(n);
      LinkedList list2(n);

      for(int i=0; i<n; i++){
         int a;
         cin >>a;
         list1.enqueue(a);
      }
      for(int i=0; i<n; i++){
         int b;
         cin >>b;
         list2.enqueue(b);
      }
      int cnt1=0;
      int cnt2=0;
      int a=1;
      int b=1;
      while(n--){
         int p1=a-1+list1.front();
         int p2=b-1+list2.front();
         if(p1>p2){
            cnt1++;
            a=p1-p2;
            b=1;
         }
         else if(p1<p2){
            cnt2++;
            b=p2-p1;
            a=1;
         }
         else{
            a=1;
            b=1;
         }
         list1.dequeue();
         list2.dequeue();
      }
      if(cnt1>cnt2){
         cout<<"1\n";
      }
      else if(cnt2>cnt1){
         cout<<"2\n";
      }
      else{
         cout<<"0\n";
      }
   }
}