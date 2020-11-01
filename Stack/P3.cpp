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

class Stack{
	public:
		node *head;
		node *tail;
		int cnt;
	
	Stack(){
		head = NULL;
		tail = NULL;
		cnt = 0;
	}

	int top(){
		if(cnt==0){
			return 0;
		}
		else{
			return head->data;
		}
	}

	void push(int x){
		node *temp = new node(x);
		if(head==NULL){
			temp->next = tail;
			head =temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
		cnt++;
	}

	bool empty(){
		return cnt==0;
	}

	int pop(){
		node *temp = head;
		int a = head->data;
		head = head->next;
		delete temp;
		cnt--;
		return a;
	}
};

bool is_number(char a){
	if(a>='1' && a<='9'){
		return true;
	}
	return false;
}

int main(){
	int n;
	cin >>n;
	while(n--){
		string str;
		cin >>str;
		Stack st;
		for(int i=0; i<str.size(); i++){
			if(is_number(str[i])){
				st.push(str[i]-'0');
			}
			else{
				int a = st.pop();
				int b = st.pop();
				int temp;
				if(str[i]=='+'){
					temp = a + b;
				}
				if(str[i]=='-'){
					temp = b - a;
				}
				if(str[i]=='*'){
					temp = a * b;
				}
				st.push(temp);
			}
		}
		cout<<st.top()<<"\n";
	}
}