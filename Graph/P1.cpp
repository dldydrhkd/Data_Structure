#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define MappingSize 501

class vertex{
	public:
		vertex *prev;
		vertex *next;
		int degree;
		int data;
		vertex(int data){
			this->degree = 0;
			this->data = data;
		}
		void increase_degree(){
			this->degree++;
		}
		void decrease_degree(){
			this->degree--;
		}
};

class edge{
	public:
		edge *prev;
		edge *next;
		vertex *source;
		vertex *destination;
		edge(vertex *a, vertex *b){
			this->source = a;
			this->destination = b;
		}
};

class DoublyVertexLinkedList{
	public:
		vertex *head;
		vertex *tail;
		DoublyVertexLinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		void insert(vertex *insertVertex){
			if(this->head == NULL){
				head = insertVertex;
				tail = insertVertex;
			}
			else{
				tail->next = insertVertex;
				insertVertex->prev = tail;
				tail = insertVertex;
			}
		}
		void remove(vertex *delVertex){
			if(delVertex == head || delVertex == tail){
				if(delVertex == head && delVertex != tail){
					vertex *temp = head;
					head = head->next;
					head->prev = NULL;
					delete temp;
				}
				else if(delVertex == tail && delVertex != head){
					vertex *temp = tail;
					tail = tail->prev;
					tail->next = NULL;
					delete temp;
				}
				else{
					head = tail = NULL;
				}
			}
			else {
				delVertex->prev->next = delVertex->next;
				delVertex->next->prev = delVertex->prev;
				delete delVertex;
			}
		}
};

class DoublyEdgeLinkedList{
	public:
		edge *head;
		edge *tail;
		DoublyEdgeLinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		void insert(edge *insertEdge){
			if(this->head == NULL){
				head = insertEdge;
				tail = insertEdge;
			}
			else{
				tail->next = insertEdge;
				insertEdge->prev = tail;
				tail = insertEdge;
			}
		}
		void remove(edge *delEdge){
			if(delEdge == head || delEdge == tail){
				if(delEdge == head && delEdge != tail){
					edge *temp = head;
					head = head->next;
					head->prev = NULL;
					delete temp;
				}
				else if (delEdge == tail && delEdge != head){
					edge *temp = tail;
					tail = tail->prev;
					tail->next = NULL;
					delete temp;
				}
				else{
					head = tail = NULL;
				}
			}
			else{
				delEdge->prev->next = delEdge->next;
				delEdge->next->prev = delEdge->prev;
				delete delEdge;
			}
		}
};

class graph{
	public:
		edge ***edgeMatrix;
		DoublyVertexLinkedList *VertexList;
		DoublyEdgeLinkedList *EdgeList;
		int vertexSize;
		int edgeSize;
		int mappingTable[MappingSize];

		graph(){
			this->VertexList = new DoublyVertexLinkedList();
			this->EdgeList = new DoublyEdgeLinkedList();
			this->vertexSize = 0;
			this->edgeSize = 0;
			for(int i=0; i<MappingSize; i++){
				mappingTable[i] = -1;
			}
			this->edgeMatrix = new edge**[1];
			this->edgeMatrix[0] = new edge*[1];
			this->edgeMatrix[0][0] = NULL;
		}
		bool isfindVertex(int n){
			bool flag = false;
			vertex *temp = VertexList->head;
			while(temp != NULL){
				if (temp->data == n){
					flag = true;
					break;
				}
				temp = temp->next;
			}
			return flag;
		}
		vertex *findVertex(int n){
			vertex *temp = VertexList->head;
			while(temp!=NULL){
				if(temp->data == n){
					break;
				}
				temp = temp->next;
			}
			return temp;
		}
		void insert_vertex(int n){
			if(isfindVertex(n) == true){
				return;
			}
			else{
				edge ***tempMatrix = new edge**[vertexSize + 1];
				for (int i=0; i<vertexSize + 1; i++){
					tempMatrix[i]=new edge*[vertexSize + 1];
					for(int j=0; j<vertexSize + 1; j++){
						tempMatrix[i][j] = NULL;
					}
				}

				for(int i=0; i<vertexSize; i++){
					for(int j=0; j<vertexSize; j++){
						tempMatrix[i][j] = this->edgeMatrix[i][j];
					}
				}

				this->edgeMatrix = tempMatrix;

				vertex *newVertex = new vertex(n);
				VertexList->insert(newVertex);
				this->vertexSize++;
				mappingTable[vertexSize - 1]=n;
			}
		}

		void erase_vertex(int n){
			if(isfindVertex(n) == false || vertexSize == 0){
				return ;
			}
			else{
				edge ***tempMatrix = new edge**[vertexSize -1];
				for (int i=0; i<vertexSize-1; i++){
					tempMatrix[i] = new edge*[vertexSize-1];
					for(int j=0; j<vertexSize-1; j++){
						tempMatrix[i][j]=NULL;
					}
				}

				int middleIdx = 0;
				for(int i=0; i<vertexSize; i++){
					if(mappingTable[i]== n){
						middleIdx = i;
					}
				}
				for(int i=middleIdx; i<vertexSize; i++){
					mappingTable[i]=mappingTable[i+1];
				}

				for(int i=0; i<vertexSize; i++){
					if(this->edgeMatrix[middleIdx][i] != NULL){
						EdgeList->remove(this->edgeMatrix[middleIdx][i]);
					}
				}

				for(int i=0; i<vertexSize; i++){
					for(int j=0; j<vertexSize; j++){
						if(i<middleIdx && j<middleIdx){
							tempMatrix[i][j]=this->edgeMatrix[i][j];
						}
						else if(i>middleIdx && j>middleIdx){
							tempMatrix[i-1][j-1] = this->edgeMatrix[i][j];
						}
						else if(j>middleIdx){
							tempMatrix[i][j-1] = this->edgeMatrix[i][j];
						}
						else if(i>middleIdx){
							tempMatrix[i-1][j] = this->edgeMatrix[i][j];
						}
					}
				}
				this->edgeMatrix = tempMatrix;
				VertexList->remove(findVertex(n));
				this->vertexSize--;
			}
		}

		void insert_edge(int indirectSource, int IndirectDestination){
			if(isfindVertex(indirectSource) == false || isfindVertex(IndirectDestination) == false){
				cout<<-1<<"\n";
				return;
			}

			int destination = -1;
			int source = -1;
			for(int i=0; i<= vertexSize; i++){
				if(mappingTable[i] == IndirectDestination){
					destination = i;
				}
				if(mappingTable[i] == indirectSource){
					source = i;
				}
				if(source != -1 && destination != -1){
					break;
				}
			}

			if(edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL){
				cout<<-1<<"\n";
				return;
			}

			edge *newEdge = new edge(findVertex(indirectSource), findVertex(IndirectDestination));
			edgeMatrix[source][destination] = newEdge;
			edgeMatrix[destination][source] = newEdge;

			findVertex(indirectSource)->increase_degree();
			findVertex(IndirectDestination)->increase_degree();

			EdgeList->insert(newEdge);
			edgeSize++;
		}

		void erase_edge(int indirectSource, int IndirectDestination){
			int destination = -1;
			int source = -1;
			for(int i=0; i<=vertexSize; i++){
				if(mappingTable[i]==IndirectDestination){
					destination = i;
				}
				if(mappingTable[i] == indirectSource){
					source = i;
				}
				if(source != -1 && destination != -1){
					break;
				}
			}

			if(edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL){
				return ;
			}
			findVertex(indirectSource)->decrease_degree();
			findVertex(IndirectDestination)->decrease_degree();

			edge *delEdge = edgeMatrix[source][destination];
			EdgeList->remove(delEdge);
			edgeSize--;

			edgeMatrix[source][destination] = NULL;
			edgeMatrix[destination][source] = NULL;
		}
};

int main(){
	int n,m;
	cin >>n>>m;
	graph g;
	for(int i=0; i<n; i++){
		int num;
		cin >>num;
		g.insert_vertex(num);
	}
	for(int i=0; i<m; i++){
		int from,to;
		cin >>from>>to;
		g.insert_edge(from, to);
	}
	cout<<g.vertexSize<<" "<<g.edgeSize;
	
}