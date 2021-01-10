#include <iostream>
#include <vector>
#include <string>
using namespace std;
int arr[2001][2001];
int exist[20001];

int main(){
   int n,m,k;
   cin >>n>>m>>k;
   int vertex=0;
   for(int i=0; i<n; i++){
      int a;
      cin >>a;
      exist[a]=true;
      vertex++;
   }
   int cnt = 0;
   for(int i=0; i<m; i++){
      int a,b;
      cin >>a>>b;
      if(arr[a][b] || arr[b][a] || !exist[a] || !exist[b]){
         cout<<"-1\n";
      }
      else{
         arr[a][b]=1;
         arr[b][a]=1;
         cnt++;
      }
   }
   cout<<vertex<<" "<<cnt<<"\n";
   for(int i=0; i<k; i++){
      int a,b;
      cin >>a>>b;
      if(!exist[a] || !exist[b]){
         cout<<"-1\n";
      }
      else if(arr[a][b] || arr[b][a]){
         cout<<"1\n";
      }
      else{
         cout<<"0\n";
      }
   }
}