#include <iostream>
#define MAX 5  // Maximum size of the stack

using namespace std;

class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the top element

public:
    Stack() { top = -1; }  // Constructor initializes stack as empty

    // Push an element onto the stack
    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    // Peek: Get the top element without removing it
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Display the stack elements
    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function with user input
int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}




