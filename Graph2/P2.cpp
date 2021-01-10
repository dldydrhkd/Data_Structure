#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,a;
int node_info[20001];
int node[1001];
vector<int> v[1001];
bool visited[1001];
bool mat[1001][1001];

int main(){
	cin >>n>>m>>a;
	for(int i=1; i<=n; i++){
		int temp;
		cin >>temp;
		node_info[temp]=i;
		node[i]=temp;
	}
	for(int i=0; i<m; i++){
		int s,d;
		cin >>s>>d;
		s = node_info[s];
		d = node_info[d];
		if(mat[s][d] || mat[d][s]){
			cout<<"-1\n";
		}
		else{
			v[s].push_back(d);
			v[d].push_back(s);
			mat[s][d]=true;
			mat[d][s]=true;
		}
	}
	a = node_info[a];
	visited[a]=true;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int size=q.size();
		while(size--){
			int front = q.front();
			cout<<node[front]<<" ";
			q.pop();
			for(int i=0; i<v[front].size(); i++){
				if(!visited[v[front][i]]){
					visited[v[front][i]]=true;
					q.push(v[front][i]);
				}
			}
		}
	}
}