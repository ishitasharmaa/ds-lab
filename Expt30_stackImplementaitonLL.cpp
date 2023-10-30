#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class stack{
    private:

    Node*top;
    int size;

    public:
    stack(){
        top=NULL;
        size=0;
    }

    void push(int val){
        Node*temp=new Node(val);
        temp->next=top;
        top=temp;
        size++;
    }
    void pop(){
        if(top==NULL){
            cout<<"stack is overflow "<<endl;
        }
        else{
            Node*temp=top->next;
            top->next=NULL;
            delete top;
            top=temp;
            size--;
        }
    }

    bool empty(){
        return   top==NULL ? true:false;
    }
    int peek(){
        return top!=NULL ? top->data : -1;
    }
    int Size(){
        return size;
    }
};
int main(){
    
    stack st;
    int ct=0;
    while(ct!=10){
        int x;
        cin>>x;
        st.push(x);
        cout<<"size of curr stack is "<<st.Size()<<endl;
        ct++;
    }
    while(!st.empty()){

        cout<<st.peek()<<" ";
        st.pop();

    }
    
}
