#include <iostream>
using namespace std;
int arr[10002];

int main(){
   int t;
   cin >>t;
   while(t--){
      int p;
      cin >>p;
      for(int i=0; i<=p; i++){
         arr[i]=-1;
      }
      int q;
      cin >>q;
      for(int i=0; i<q; i++){
         int key;
         cin >>key;
         int cnt = 0;
         while(arr[(key%p+cnt*(17-(key)%17))%p]!=-1 && cnt<=p){
            cnt++;
         }
         if(cnt!=p){
            arr[(key%p+cnt*(17-key%17))%p]=key;
         }
      }
      for(int i=0; i<p; i++){
         cout<<arr[i]<<" ";
      }
      cout<<"\n";
   }
}