#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool isPalindrome() {
        if (head == nullptr)
            return false;

        stack<int> s;
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            s.push(slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the linked list has an odd number of elements, skip the middle element.
        if (fast != nullptr) {
            slow = slow->next;
        }

        while (slow != nullptr) {
            int top = s.top();
            s.pop();
            if (top != slow->data) {
                return false;
            }
            slow = slow->next;
        }

        return true;
    }
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Linked List: ";
    list.display();

    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
