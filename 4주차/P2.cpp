#include <iostream>
#include <string>
using namespace std;

class Queue{
	public:
		int *arr;
		int f=0;
		int r=-1;
		int cnt=0;
		int max_cnt;

	Queue(int x){
		arr=new int[x];
		cnt=0;
		max_cnt=x;
		for(int i=0; i<x; i++){
			arr[i]=0;
		}
	}

	void size(){
		cout<< (r-f+1+max_cnt)%max_cnt<<"\n";
	}

	void isEmpty(){
		if(f==(r+1)%max_cnt){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
	}

	void enqueue(int x){
		if((r-f+1+max_cnt)%max_cnt==max_cnt-1){
			cout<<"Full\n";
			return;
		}
		r=(r+1)%max_cnt;
		arr[r]=x;
	}

	void dequeue(){
		if(f==(r+1)%max_cnt){
			cout<<"Empty\n";
			return;
		}
		else{
			cout<<arr[f]<<"\n";
			arr[f]=0;
			f = (f+1)%max_cnt;
		}
	}

	void front(){
		if(f==(r+1)%max_cnt){
			cout<<"Empty\n";
		}
		else{
			cout<<arr[f]<<"\n";
		}
	}

	void rear(){
		if(f==(r+1)%max_cnt){
			cout<<"Empty\n";
		}
		else{
			cout<<arr[r]<<"\n";
		}
	}
};

int main(){
	int n;
	cin >>n;
	Queue q(n+1);
	int t;
	cin >>t;

	while(t--){
		string str;
		cin >>str;
		if(str=="isEmpty"){
			q.isEmpty();
		}
		if(str=="size"){
			q.size();
		}
		if(str=="front"){
			q.front();
		}
		if(str=="rear"){
			q.rear();
		}
		if(str=="enqueue"){
			int x;
			cin >>x;
			q.enqueue(x);
		}
		if(str=="dequeue"){
			q.dequeue();
		}
	}

}