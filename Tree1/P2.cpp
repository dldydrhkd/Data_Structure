#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class GeneralTree;

template <typename T>
class Node{
private:
   T data;
   Node *par;
   vector<Node*> chi;
public:
   Node(){
      this->data = NULL;
      this->par = NULL;
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
private:
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
            par->insertChild(newnode);
            newnode->setParent(par);
            node_list.push_back(newnode);
            return ;
         }
      }
      return ;
   }
   void delNode(T data){
      Node<T> *nownode;
      Node<T> *par;
      for(int i=0; i<this->node_list.size(); i++){
         if(this->node_list[i]->data == data){
            nownode=node_list[i];
            par=nownode->par;
            for(auto *child : nownode->chi){
               par->insertChild(child);
               child->setParent(par);
            }
            par->delChild(nownode);
            this->node_list.erase(this->node_list.begin()+i);
            delete nownode;
         }
      }
      return ;
   }

   void printSibling(T data){
      for (auto &i : this->node_list){
         if(i->data == data){
            if(i == root){
                cout<<data<<"\n";
                return;
            } 
            for(auto &child : i->par->chi){
               cout<<child->data<<" ";
            }
            cout<<"\n";
            return;
         }
      }
      cout<<"0\n";
      return;
   }
};


int main(){
   int n;
   string str;
   cin >>n;
   GeneralTree<int> t = GeneralTree<int>(1);
   for(int i=0; i<n; i++){
      cin >>str;
      if(str=="insert"){
         int par,data;
         cin >>par>>data;
         t.insertNode(par,data);
      }
      else if(str=="delete"){
         int data;
         cin >>data;
         t.delNode(data);
      }
      else if(str=="print"){
         int data;
         cin >>data;
         t.printSibling(data);
      }
   }
}