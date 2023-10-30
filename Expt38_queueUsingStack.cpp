#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> input;
    stack<int> output;

public:
    void enqueue(int val) {
        input.push(val);
        cout << "Enqueue: " << val << endl;
    }

    int dequeue() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (!output.empty()) {
            int val = output.top();
            output.pop();
            cout << "Dequeue: " << val << endl;
            return val;
        }
        return -1; // Queue is empty
    }

    bool isEmpty() {
        return input.empty() && output.empty();
    }

    int front() {
        if (!output.empty()) {
            return output.top();
        }
        if (input.empty()) {
            return -1; // Queue is empty
        }
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    void displayQueue() {
        stack<int> temp;
        while (!output.empty()) {
            temp.push(output.top());
            output.pop();
        }
        while (!temp.empty()) {
            cout << temp.top() << endl;
            output.push(temp.top());
            temp.pop();
        }
        stack<int> reversed;
        while (!input.empty()) {
            temp.push(input.top());
            reversed.push(input.top());
            input.pop();
            temp.pop();
        }
        while (!reversed.empty()) {
            output.push(reversed.top());
            reversed.pop();
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Queue elements:" << endl;
    queue.displayQueue();

    queue.dequeue();
    queue.enqueue(4);

    cout << "\nQueue elements after dequeuing and enqueuing:" << endl;
    queue.displayQueue();

    return 0;
}
