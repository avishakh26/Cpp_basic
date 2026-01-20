#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class SinglyLinkedList {
private:
    Node* head;  // Pointer to the first node

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (head->next == nullptr) {  // If only one node
            cout << head->data << " deleted from the end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << temp->next->data << " deleted from the end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function for user interaction
int main() {
    SinglyLinkedList list;
    int choice, value;

    while (true) {
        cout << "\nSingly Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                list.deleteFromBeginning();
                break;
            case 4:
                list.deleteFromEnd();
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}




