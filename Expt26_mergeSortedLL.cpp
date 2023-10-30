#include <iostream>

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

    static LinkedList mergeSortedLists(LinkedList& list1, LinkedList& list2) {
        LinkedList mergedList;
        Node* current1 = list1.head;
        Node* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data < current2->data) {
                mergedList.insert(current1->data);
                current1 = current1->next;
            } else {
                mergedList.insert(current2->data);
                current2 = current2->next;
            }
        }

        while (current1 != nullptr) {
            mergedList.insert(current1->data);
            current1 = current1->next;
        }

        while (current2 != nullptr) {
            mergedList.insert(current2->data);
            current2 = current2->next;
        }

        return mergedList;
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
    LinkedList list1;
    list1.insert(1);
    list1.insert(3);
    list1.insert(5);

    LinkedList list2;
    list2.insert(2);
    list2.insert(4);
    list2.insert(6);

    cout << "Linked List 1: ";
    list1.display();

    cout << "Linked List 2: ";
    list2.display();

    LinkedList mergedList = LinkedList::mergeSortedLists(list1, list2);

    cout << "Merged Sorted List: ";
    mergedList.display();

    return 0;
}
