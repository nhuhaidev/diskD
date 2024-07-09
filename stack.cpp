#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];           
    int top;         
public:
    Stack() : top(-1) {}
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == MAX_SIZE - 1;
   }
    void push(int value) {
        if (isFull()) {
            throw overflow_error("Stack overflow: Cannot push, stack is full.");
        }
        arr[++top] = value;
    }

 
    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: Cannot pop, stack is empty.");
        }
        return arr[top--];
    }

  
    int peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty: Cannot peek.");
        }
        return arr[top];
    }

   
    void printStack() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Thêm phần tử vào stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // In các phần tử của stack
    cout << "Stack elements: ";
    stack.printStack();

    // Lấy phần tử từ stack
    cout << "Popped element: " << stack.pop() << endl;

    // Xem phần tử trên cùng
    cout << "Top element: " << stack.peek() << endl;

    return 0;
}