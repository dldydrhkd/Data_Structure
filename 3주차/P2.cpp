#include <iostream>
#include <string>
using namespace std;

struct node{
	int data;
	node *next;

	node(int x){
		data = x;
		next = NULL;
	}
};

class LinkedList{
	public:
		node *head;
		node *tail;
		int cnt;
	LinkedList(){
		head=NULL;
		tail=NULL;
		cnt = 0;
	}

	void empty(){
		if(cnt==0){
			cout<<"1\n";
		}
		else{
			cout<<"0\n";
		}
	}

	void top(){
		if(cnt==0){
			cout<<"-1\n";
			return;
		}
		cout<<head->data<<"\n";
	}

	void push(int x){
		node *temp = new node(x);
		if(head==NULL){
			temp->next = tail;
			head = temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
		cnt++;
	}

	void pop(){
		if(cnt==0){
			cout<<"-1\n";
			return;
		}
		else{
			cout<<head->data<<"\n";
			node *temp=head;
			head = head->next;
			delete temp;
			cnt--;
		}
	}

	void size(){
		cout<<cnt<<"\n";
	}
};

int main(){
	int n;
	cin >>n;
	LinkedList li;
	while(n--){
		string str;
		cin>>str;
		if(str=="empty"){
			li.empty();
		}
		if(str=="top"){
			li.top();
		}
		if(str=="pop"){
			li.pop();
		}
		if(str=="push"){
			int x;
			cin >>x;
			li.push(x);
		}
		if(str=="size"){
			li.size();
		}
	}
}