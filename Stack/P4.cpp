#include <iostream>
#include <string>
using namespace std;

struct Node{
	char data;
	Node *next;
	Node(char data){
		this->data=data;
		next=NULL;
	}
};

class Stack{
	public:
		Node *head;
		Node *tail;
		int cnt;
	
	Stack(){
		head = NULL;
		tail = NULL;
		cnt=0;
	}

	void push(char data){
		Node *temp = new Node(data);
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
		Node *temp=head;
		head = head->next;
		delete(temp);
		cnt--;
	}

	char top(){
		return head->data;
	}

	bool empty(){
		return cnt==0;
	}
};


int main(){
	int n;
	cin >>n;
	while(n--){
		string str;
		string ans = "";
		cin >>str;
		Stack st;
		for(int i=0; i<str.size(); i++){
			if(str[i]-'0'>=1 && str[i]-'0'<=9){
				ans+=str[i];
			}
			else{
				switch(str[i]){
					case '(':
						st.push(str[i]);
						break;
					case '*':
						while(!st.empty() && st.top()=='*'){
							ans+=st.top();
							st.pop();
						}
						st.push(str[i]);
						break;
					case '+':
					case '-':
						while(!st.empty() && st.top()!='('){
							ans+=st.top();
							st.pop();
						}
						st.push(str[i]);
						break;
					case ')':
						while(!st.empty() && st.top()!='('){
							ans+=st.top();
							st.pop();
						}
						st.pop();
						break;
				}
			}
		}
		while(!st.empty()){
			ans+=st.top();
			st.pop();
		}
		cout<<ans<<"\n";
	}
}