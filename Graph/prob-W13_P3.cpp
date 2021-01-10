#include <iostream>
#include <vector>
#include <string>
using namespace std;
int exist[2001];
bool arr[2001][2001];
vector<pair<int,string>> v[2001];
vector<pair<pair<int,int>,string>> order;


int main(){
   int n,m,k;
   cin >>n>>m>>k;
   int vertex = 0;
   int edge = 0;
   for(int i=0; i<n; i++){
      int a;
      cin >>a;
      exist[a]=true;
      vertex++;
   }
   for(int i=0; i<m; i++){
      int a,b;
      cin >>a>>b;
      string str;
      cin >>str;
      if(!exist[a] || !exist[b]){
         cout<<"-1\n";
      }
      else if(arr[a][b] || arr[b][a]){
         cout<<"-1\n";
      }
      else{
         arr[a][b]=true;
         arr[b][a]=true;
         v[a].push_back({b,str});
         v[b].push_back({a,str});
         order.push_back({{a,b},str});
         edge++;
      }
   }
   cout<<vertex<<" "<<edge<<"\n";
   for(int i=0; i<k; i++){
      int a;
      cin >>a;
      if(!exist[a] || vertex == 0){
         cout<<"-1\n";
      }
      else{
         for(int i=0; i<v[a].size(); i++){
            vector<pair<int, string>> :: iterator it;
            int next = v[a][i].first;
            it = v[next].begin();
            for(int j=0; j<v[next].size(); j++){
               if(v[next][j].first==a){
                  vector<pair<pair<int,int>,string>> :: iterator s = order.begin();
                  for(int p = 0; p<order.size(); p++){
                     int edge1 = order[p].first.first;
                     int edge2 = order[p].first.second;
                     if((a == edge1 && next == edge2) || (a == edge2 && next == edge1)){
                        order.erase(s+p);
                        break;
                     }
                  }
                  v[v[a][i].first].erase(it+j);
                  edge--;
                  break;
               }
            }
         }
         vertex--;
         v[a].clear();
         exist[a]=false;
         cout<<edge<<" ";
         for(int i=0; i<edge; i++){
            cout<<order[i].second<<" ";
         }
         cout<<"\n";
      }
   }
}