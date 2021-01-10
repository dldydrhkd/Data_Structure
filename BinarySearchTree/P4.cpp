#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* leftChild;
		Node* rightChild;
		Node* parent;

		Node(){
			this->leftChild = NULL;
			this->rightChild = NULL;
			this->parent = NULL;
		}

		Node(int data){
			this->data = data;
			this->leftChild = NULL;
			this->rightChild = NULL;
			this->parent = NULL;
		}
};

class binarySearchTree{
	private:
		Node* root;
	public:
		binarySearchTree(){this->root = NULL;}

		void insert(int inputData){
			Node* newNode = new Node(inputData);
			Node* saveNode = NULL;

			if(root == NULL){root = newNode;}
			else{
				Node* curNode = root;
				while(curNode!=NULL){
					saveNode = curNode;
					if(curNode->data == inputData){
						cout<<"Duplication\n";
						return;
					}
					else if(curNode->data>inputData){
						curNode = curNode->leftChild;
					}
					else{
						curNode = curNode->rightChild;
					}
				}
				if(saveNode->data>inputData){
					newNode->parent = saveNode;
					saveNode->leftChild = newNode;
				}
				else{
					newNode->parent = saveNode;
					saveNode->rightChild = newNode;
				}
			}
		}

		Node* find(int inputData){
			Node* curNode = root;

			while(curNode != NULL){
				if(curNode->data == inputData){
					return curNode;
				}
				else if(curNode->data > inputData){
					curNode=curNode->leftChild;
				}
				else{
					curNode = curNode->rightChild;
				}
			}
			return NULL;
		}

		Node* min_findNode(Node* _Node){
			Node* curNode = _Node;
			Node* saveNode = NULL;

			while(curNode != NULL){
				saveNode = curNode;
				curNode = curNode->leftChild;
			}

			return saveNode;
		}

		Node* max_findNode(Node* _Node){
			Node* curNode = _Node;
			Node* saveNode = NULL;
			
			while(curNode != NULL){
				saveNode = curNode;
				curNode = curNode->rightChild;
			}
			return saveNode;
		}

		void erase(int data){
			Node* curNode = find(data);
			int numOfchild = bool(curNode->leftChild)+bool(curNode->rightChild);

			if(numOfchild==0){
				if(curNode == root){
					root = NULL;
				}
				else{
					if(curNode->parent->data > curNode->data){
						curNode->parent->leftChild=NULL;
					}
					else{
						curNode->parent->rightChild = NULL;
					}
				}
				delete curNode;
			}
			else if(numOfchild==2){
				Node *minNode = min_findNode(curNode->rightChild);
				int data = minNode->data;
				erase(minNode->data);
				curNode->data = data;
			}
			else if(numOfchild == 1){
				if(curNode == root){
					if(curNode->leftChild != NULL){
						root = curNode->leftChild;
					}
					else{
						root = curNode->rightChild;
					}
				}
				else{
					Node* curParent = curNode->parent;
					Node* child = (curNode->leftChild) ? curNode->leftChild : curNode->rightChild;

					if(curParent->data > child->data){
						curParent->leftChild = child;
						child->parent = curParent;
					}
					else{
						curParent->rightChild = child;
						child->parent = curParent;
					}
				}
				delete curNode;
			}
		}

      void postorderPrint(Node* curNode){
         if(curNode != NULL){
            postorderPrint(curNode->leftChild);
            postorderPrint(curNode->rightChild);
            cout<<curNode->data<<" ";
         }
      }

      void postorder(){
         if(root==NULL){
				cout<<"Empty\n";
				return;
			}
         postorderPrint(root);
         cout<<"\n";
      }

		void preorderPrint(Node* curNode){
			if(curNode != NULL){
				cout<<curNode->data<<" ";
				preorderPrint(curNode->leftChild);
				preorderPrint(curNode->rightChild);
			}
		}

		void preorder(){
         if(root==NULL){
				cout<<"Empty\n";
				return;
			}
			preorderPrint(root);
			cout<<"\n";
		}

		void inorderPrint(Node* curNode){
			if(curNode->leftChild != NULL){
				inorderPrint(curNode->leftChild);
			}
			cout<<curNode->data<<" ";
			if(curNode->rightChild != NULL){
				inorderPrint(curNode->rightChild);
			}
		}

		void inorder(){
			if(root==NULL){
				cout<<"Empty\n";
				return;
			}
			inorderPrint(root);
			cout<<"\n";
		}
};


int main(){

	int t;
	cin >>t;
	while(t--){
		binarySearchTree bst;
		int p;
		cin >>p;
		while(p--){
			int n;
			cin >>n;
			bst.insert(n);
		}
		int q;
		cin >>q;
		while(q--){
			int n;
			cin >>n;
			bst.erase(n);
		}
		bst.postorder();
	}
}
