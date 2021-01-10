#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Heap{
   private:
      vector<int> v;
      int heap_size;
      int root_idx;
      int cnt;
   public:
      Heap(){
         v.push_back(-1);
         heap_size = 0;
         root_idx = 1;
         cnt = 0;
      }
      ~Heap(){}

      void swap(int idx1, int idx2){
         v[0]=v[idx1];
         v[idx1]=v[idx2];
         v[idx2]=v[0];
      }

      void upHeap(int idx){
         cnt++;
         if(idx == root_idx){
            return ;
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
         int right = idx*2 + 1;
         if(right<=heap_size){
            if(v[left]<v[right]){
               if(v[left]<v[idx]){
                  swap(left,idx);
                  downHeap(left);
               }
               else return;
            }
            else{
               if(v[right]<v[idx]){
                  swap(right, idx);
                  downHeap(right);
               }
               else return;
            }
         }
         if(left<=heap_size){
            if(v[left]<v[idx]){
               swap(left,idx);
               downHeap(left);
            }
            else return;
         }
         else return;
      }

      bool isEmpty(){
         return heap_size==0;
      }

      void insert(int e){
         v.push_back(e);
         heap_size++;
         upHeap(heap_size);
      }

      void size(){
         cout<<heap_size<<"\n";
      }

      int pop(){
         if(isEmpty()){
            return -1;
         }
         else{
            int top = v[root_idx];
            v[root_idx] = v[heap_size];
            v.pop_back();
            heap_size--;
            downHeap(root_idx);
            return top;
         }
      }

      void top(){
         if(isEmpty()){
            cout<<"-1\n";
         }
         else{
            cout<<v[root_idx]<<"\n";
         }
      }

      void print(){
         if(isEmpty()){
            cout<<"-1\n";
         }
         else{
            for(int i=1; i<=heap_size; i++){
               cout<<v[i];
               if(i!=heap_size){
                  cout<<" ";
               }
            }
            cout<<"\n";
         }
      }
      void printAt(int a){
         cout<<v[a]<<"\n";
      }

      int get_cnt(){
         return cnt;
      }
};

int main(){
   int t;
   cin >>t;
   int ans = 0;
   while(t--){
      Heap pq;
      int n,p;
      cin >>n>>p;
      for(int i=0; i<n; i++){
         int a;
         cin >>a;
         pq.insert(a);
      }
      pq.print();
      pq.printAt(p);
      for(int i=0; i<p; i++){
         if(i==p-1){
            cout<<pq.pop()<<"\n";
         }
         else{
            pq.pop();
         }
      }
      ans+=pq.get_cnt();
      cout<<ans<<"\n";
   }
}