#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class GeneralTree;

template <typename T>
class Node{
private:
   T data;
   int depth;
   Node *par;
   vector<Node*> chi;
public:
   Node(){
      this->data = NULL;
      this->par = NULL;
      this->depth = 0;
   }
   Node(T data){
      this->data = data;
      this->par = NULL;
   }
   ~Node(){}
   void setParent(Node *par){
      this->par=par;
      return;
   }
   void insertChild(Node* chi){
      this->chi.push_back(chi);
      return;
   }
   void delChild(Node *chi){
      for(int i=0; i<this->chi.size(); i++){
         if(this->chi[i]==chi){
            this->chi.erase(this->chi.begin()+i);
         }
      }
      return;
   }
   friend GeneralTree<T>;
};

template<typename T>
class GeneralTree{
public:
   Node<T>* root;
   vector<Node<T>*> node_list;
   int tree_size=0;
public:
   GeneralTree(){
      root=NULL;
   }
   GeneralTree(T data){
      root = new Node<T>(data);
      node_list.push_back(root);
   }
   ~GeneralTree(){}
   void insertNode(T parent_data, T data){
      Node<T>* par;
      for(auto &i: this->node_list){
         if(i->data == parent_data){
            par=i;
            Node<T>* newnode = new Node<T>(data);
            newnode->depth = par->depth+1;
            par->insertChild(newnode);
            newnode->setParent(par);
            node_list.push_back(newnode);
            return ;
         }
      }
      return ;
   }


   void dfs(Node<T> *data){
      for (auto &i : data->chi){
         dfs(i);
      }
	  cout<<data->data<<" ";
   }

   
};


int main(){
   int n;
   cin >>n;
   while(n--){
      int m;
      cin >>m;
      GeneralTree<int> *t = new GeneralTree<int>(1);
      for(int i=0; i<m; i++){
         int par, data;
         cin >>par>>data;
         t->insertNode(par,data);
      }
      t->dfs(t->root);
      cout<<"\n";
   }
}
