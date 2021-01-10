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
         while(arr[(key%p+cnt)%p]!=-1 && cnt<=p){
            cnt++;
         }
         if(cnt!=p){
            arr[(key%p+cnt)%p]=key;
         }
      }
      int r;
      cin >>r;
      for(int i=0; i<r; i++){
         int find;
         cin >>find;
         int probing = 0;
         bool check = false;
         while(arr[(find%p+probing)%p]!=-1 && probing<=p){
            if(arr[(find%p+probing)%p]==find){
               check = true;
               probing++;
               break;
            }
            probing++;
         }
         if(check){
            cout<<"True ";
            cout<<probing<<"\n";
         }
         else{
            cout<<"False ";
            cout<<probing+1<<"\n";
         }
      }
   }
}