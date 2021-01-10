#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap{
   private:
      vector<int> v;
      int heap_size;
      int root_idx;
   public:
      Heap(){
         v.push_back(0);
         this->heap_size=0;
         this->root_idx=1;
      }
      ~Heap(){};

      void swap(int idx1, int idx2){
         v[0]=v[idx1];
         v[idx1]=v[idx2];
         v[idx2]=v[0];
      }

      void upHeap(int idx){
         if(idx == root_idx){
            return;
         }
         else{
            int parent = idx/2;
            if(v[parent]>v[idx]){
               swap(parent,idx);
               upHeap(parent);
            }
         }
      }

      void downHeap(int idx){
         int left = idx*2;
         int right = idx*2+1;
         if(right<=heap_size){
            if(v[left]<=v[right]){
               if(v[left]<v[idx]){
                  swap(idx,left);
                  downHeap(left);
               }
               else{
                  return;
               }
            }
            else{
               if(v[right]<v[idx]){
                  swap(idx,right);
                  downHeap(right);
               }
               else{
                  return;
               }
            }
         }
         if(left<=heap_size){
            if(v[left]<v[idx]){
               swap(idx, left);
               downHeap(left);
            }
            else{
               return;
            }
         }
         else{
            return;
         }
      }

      bool isEmpty(){
         if(heap_size==0){
            return true;
         }
         return false;
      }

      void insert(int value){
         v.push_back(value);
         heap_size++;
         upHeap(heap_size);
      }

      int size(){
         return heap_size;
      }

      int pop(){
         if(isEmpty()){
            return -1;
         }
         int top = v[root_idx];
         v[root_idx]=v[heap_size];
         heap_size--;
         v.pop_back();
         downHeap(root_idx);
         return -top;
      }

      int top(){
         if(isEmpty()){
            return -1;
         }
         return -v[root_idx];
      }

      void print(){
         if(isEmpty()){
            cout<<"-1";
         }
         else{
            for(int i=root_idx; i<heap_size; i++){
               cout<<-v[i]<<" ";
            }
            cout<<-v[heap_size];
         }
      }
};

int main(){
   int n;
   cin >>n;
   Heap h;
   while(n--){
      string str;
      cin >>str;
      if(str=="isEmpty"){
         cout<<h.isEmpty();
         cout<<"\n";
      }
      if(str=="insert"){
         int e;
         cin >>e;
         h.insert(-e);
      }
      if(str=="size"){
         cout<<h.size();
         cout<<"\n";
      }
      if(str=="pop"){
         cout<<h.pop();
         cout<<"\n";
      }
      if(str=="top"){
         cout<<h.top();
         cout<<"\n";
      }
      if(str=="print"){
         h.print();
         cout<<"\n";
      }
   }
   return 0;
}
