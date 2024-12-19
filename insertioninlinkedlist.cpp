#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insertion at the start (head)
void insertAtHead(node*& head, int data) {
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

// Insertion at the end (tail)
void insertAtEnd(node*& head, int data) {
    node* temp = new node(data);
    if (head == NULL) {
        head = temp;  // If the list is empty, make the new node the head
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;  // Traverse to the last node
    }
    current->next = temp;  // Link the new node to the last node
}

// Insertion at nth position
void insertAtNthPosition(node*& head, int data, int n) {
    if (n <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    node* temp = new node(data);
    if (n == 1) {
        insertAtHead(head, data);  // If the position is 1, insert at the start
        return;
    }
    node* current = head;
    for (int i = 1; i < n - 1 && current != NULL; i++) {
        current = current->next;  // Traverse to the (n-1)th node
    }
    if (current == NULL) {
        cout << "Position is out of bounds!" << endl;
        delete temp;  // Clean up if position is invalid
        return;
    }
    temp->next = current->next;
    current->next = temp;  // Insert the new node at position n
}

// Print the linked list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = NULL;
    
    // Insertion at the head (start)
    insertAtHead(head, 12);
    insertAtHead(head, 67);
    insertAtHead(head, 14);
    insertAtHead(head, 25);
    
    cout << "List after inserting at the start:" << endl;
    printList(head);
    
    // Insertion at the end (tail)
    insertAtEnd(head, 99);
    cout << "List after inserting at the end:" << endl;
    printList(head);
    
    // Insertion at the nth position
    insertAtNthPosition(head, 45, 3); // Inserting at the 3rd position
    cout << "List after inserting at the 3rd position:" << endl;
    printList(head);
    
    return 0;
}
