#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum direction { MIN = 1, MAX = -1};

class Heap {
	private:
		vector<int> v;
		int heap_size;
		int root_index;
		int direction;
		int cnt;
	public:
		Heap(int direction){
			v.push_back(-1);
			this->heap_size=0;
			this->root_index=1;
			this->direction=direction;
			int cnt=0;
		}
		~Heap(){};
		void swap(int idx1, int idx2){
			v[0]=v[idx1];
			v[idx1]=v[idx2];
			v[idx2]=v[0];
		}
		int get_cnt(){
			return cnt;
		}
		void upHeap(int idx){
			cnt++;
			if(idx==root_index){
				return;
			}
			else{
				int parent = idx/2;
				if(v[parent]*direction>v[idx]*direction){
					swap(parent,idx);
					upHeap(parent);
				}
			}
		}
		void downHeap(int idx){
			int left = idx*2;
			int right = idx*2 + 1;
			if(right <= heap_size){
				if(v[left]*direction <= v[right]*direction){
					if(v[left]*direction < v[idx]*direction){
						swap(left, idx);
						downHeap(left);
					}
					else return;
				}
				else{
					if(v[right]*direction < v[idx] * direction){
						swap(right, idx);
						downHeap(right);
					}
					else return;
				}
			}
			else if(left <= heap_size){
				if(v[left]*direction < v[idx]*direction){
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else return;
		}

		bool isEmpty(){
			if(heap_size==0) return true;
			else return false;
		}

		void insert (int e){
			v.push_back(e);
			heap_size++;
			upHeap(heap_size);
		}

		int pop(){
			if(isEmpty()){
				return -1;
			}
			int top = v[root_index];
			v[root_index] = v[heap_size];
			heap_size--;
			v.pop_back();
			downHeap(root_index);
			return top;
		}
		int top(){
			if(isEmpty()){
				return -1;
			}
			return v[root_index];
		}
		int size(){
			return heap_size;
		}

		void print(){
			if(isEmpty() == false){
				for(int i=root_index; i < heap_size; i++){
					cout<<v[i]<<" ";
				}
				cout<<v[heap_size]<<"\n";
			}
			else {
				cout<<"-1\n";
			}
		}
		int find(int x){
			if(isEmpty()==false) return v.at(x);
			else return 0;
		}
		void print_at(int x){
			cout<<v[x]<<"\n";
		}
};

int main(){
	int t;
	cin >>t;
	while(t--){
		int n,p;
		cin >>n>>p;
		Heap pq(MIN);
		for(int i=0; i<n; i++){
			int x;
			cin >>x;
			pq.insert(x);
		}
		pq.print();
		pq.print_at(p);
		int up = pq.get_cnt();
		int temp = 0;
		for(int i=0; i<p; i++){
			temp = pq.pop();
		}
		cout<<temp<<"\n";
		cout<<up<<"\n";
	}
}