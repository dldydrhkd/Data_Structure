#include <iostream>
#include <string>
using namespace std;
int s=-1;
int arr[10001];

void empty(){
    if(s==-1){
        cout<<"1\n";
    }
    else{
        cout<<"0\n";
    }
}

void top(){
    if(s==-1){
        cout<<"-1\n";
    }
    else{
        cout<<arr[s]<<"\n";
    }
}

void push(int x){
    arr[s+1]=x;
    s++;
}

void pop(){
    if(s==-1){
        cout<<"-1\n";
    }
    else{
        cout<<arr[s]<<"\n";
        arr[s]=0;
        s--;
    }
}

void size(){
    cout<<s+1<<"\n";
}

int main(){
    int n;
    cin >>n;
    while(n--){
        string str;
        cin >>str;
        if(str=="empty"){
            empty();
        }
        else if(str=="push"){
            int x;
            cin >>x;
            push(x);
        }
        else if(str=="size"){
            size();
        }
        else if(str=="pop"){
            pop();
        }
        else if(str=="top"){
            top();
        }
    }
}