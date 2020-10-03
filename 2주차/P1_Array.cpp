#include <iostream>
using namespace std;
int arr[10010];

int main(){
    int size=0;
    int m;
    cin >>m;
    for(int i=0; i<m; i++){
        string str;
        cin >>str;
        if(str=="at"){
            int index;
            cin >>index;
            if(index<size){
                cout<<arr[index]<<"\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(str=="add"){
            int index;
            int x;
            cin >>index>>x;
            if(size==10000) continue;
            if(size-1<index){
                arr[size]=x;
                size++;
            }
            else{
                for(int j=size-1; j>=index; j--){
                    arr[j+1]=arr[j];
                }
                arr[index]=x;
                size++;
            }
        }
        else if(str=="set"){
            int index;
            int x;
            cin >>index>>x;
            if(index<size){
                arr[index]=x;
            }
            else{
                cout<<"0\n";
            }
        }
    }
}