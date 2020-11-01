#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class SequenceList;

struct Node{
	int e;
	Node *prev;
	Node *next;

	Node(){
		prev = NULL;
		next = NULL;
	}

	Node(int x){
		prev = NULL;
		next = NULL;
		e = x;
	}
};

class Iterator{
	private:
		Node *v;
	public:
		Iterator(Node *u){
			v = u;
			
		}
		int& operator*(){
			return v->e;
		}
		bool operator==(const Iterator& p) const{
			return v==p.v;
		}
		bool operator!=(const Iterator& p) const{
			return v!=p.v;
		}
		Iterator& operator++(){
			v=v->next;
			return *this;
		}
		Iterator& operator--(){
			v=v->prev;
			return *this;
		}
	friend SequenceList;
};


class SequenceList{
	private:
		int n;
		Node* header;
		Node* trailer;
	
	public:
		SequenceList(){
			n = 0;
			header=new Node;
			trailer = new Node;
			header->next = trailer;
			trailer->prev = header;
		}
		int size() const{
			return n;
		}
		bool empty() const{
			return (n==0);
		}
		Iterator begin() const{
			return Iterator(header->next);
		}
		Iterator end() const{
			return Iterator(trailer);
		}
		void insert(const Iterator& p, const int& e){
			Node* w = p.v;
			Node* u = w->prev;
			Node* v = new Node;
			v->e = e;
			v->next = w;
			w->prev = v;
			v->prev = u;
			u->next = v;
			this->n++;
		}
		void insertFront(const int& e){
			insert(begin(),e);
		}
		void insertBack(const int& e){
			insert(end(),e);
		}
		void erase(const Iterator& p){
			if(n==0){
				cout<<"Empty\n";
				return;
			}
			Node* v = p.v;
			Node* w = v->next;
			Node* u = v->prev;
			u->next = w;
			w->prev = u;
			delete v;
			this->n--;
		}
		void eraseFront(){
			erase(begin());
		}
		void eraseBack(){
			erase(--end());
		}
		Iterator atIndex(int i) const{
			Iterator p = begin();
			for(int j=0; j<i; j++){
				++p;
			}
			return p;
		}
		int indexOf(Iterator& p) const{
			Iterator q = begin();
			int j=0;
			while(q!=p){
				++q;
				++j;
			}
			return j;
		}
		void reversePrint(){
			if(header->next==trailer){
				cout<<"Empty";
			}
			else{
				Node *temp = trailer->prev;
				while(temp!=header){
					cout<<temp->e<<" ";
					temp=temp->prev;
				}
			}
		}
};

int main(){
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		SequenceList sl;
		Iterator iter=sl.begin();
		for(int i=0; i<n; i++){
			int x;
			cin >>x;
			sl.insert(iter,x);
		}
		iter = sl.begin();
		int min_value=1000;
		int sum=0;
		for(int i=0; i<n; i++){
			sum+=*iter;
			if(min_value>*iter){
				min_value=*iter;
			}
			iter.operator++();
		}

		cout<<sum/n<<" "<<min_value<<"\n";
	}
	
}