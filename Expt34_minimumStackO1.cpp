#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }

    void displayStack() {
        cout << "Stack Elements: ";
        stack<int> tempStack = mainStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);

    minStack.displayStack(); // Display the stack elements

    cout << "Minimum: " << minStack.getMin() << endl;
    cout << "Top: " << minStack.top() << endl;


    return 0;
}
