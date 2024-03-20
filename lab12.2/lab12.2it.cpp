#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Додавання елемента в кінець списку
void append(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Виведення значень елементів списку на екран
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Формування списків L1 та L2 з додатних та від'ємних значень відповідно
void splitList(Node* head, Node*& positiveList, Node*& negativeList) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data > 0) {
            append(positiveList, temp->data);
        }
        else if (temp->data < 0) {
            append(negativeList, temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    // Формування початкового списку
    Node* L = nullptr;
    append(L, 1);
    append(L, -2);
    append(L, 3);
    append(L, -4);
    append(L, 5);

    // Виведення початкового списку на екран
    cout << "Initial List: ";
    printList(L);

    // Формування списків L1 та L2
    Node* L1 = nullptr; // Список для додатних значень
    Node* L2 = nullptr; // Список для від'ємних значень
    splitList(L, L1, L2);

    // Виведення списків L1 та L2 на екран
    cout << "List with positive values (L1): ";
    printList(L1);
    cout << "List with negative values (L2): ";
    printList(L2);

    return 0;
}
