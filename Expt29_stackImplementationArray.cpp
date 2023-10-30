#include <iostream>
using namespace std;

// stack class
class stack
{
    // private data members
private:
    int top;
    int *arr;
    int size;

    // public member functions
public:
    // constructor
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // push operation
    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "stack is overflow " << endl;
        }
    }

    // pop operation
    void pop()
    {
        if (top == -1)
        {
            cout << "stack is overflow " << endl;
        }
        else
        {
            top--;
        }
    }

    // isempty
    bool empty()
    {
        return top == -1 ? true : false;
    }
    // get peek element
    int peek()
    {
        return top != -1 ? arr[top] : -1;
    }
};
int main()
{

    stack st(5);
    st.push(1);
    st.push(2);
    cout << "stack elements are : ";
   
    while (!st.empty())
    {
        cout << st.peek() << " ";
        st.pop();
    }
    return 0;
}
