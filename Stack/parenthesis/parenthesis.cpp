#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Stack {
private:
    T* A;
    int size;
    int top;

public:
    Stack() {
        size = 10;
        top = -1;
        A = new T[size];
    }

    Stack(int size) {
        this->size = size;
        top = -1;
        A = new T[this->size];
    }

    void push(T x) {
        if (isFull()) {
            cout << "Stack Overflow";
        } else {
            top++;
            A[top] = x;
        }
    }

    T pop() {
        T x = static_cast<T>(-1);
        if (isEmpty()) {
            cout << "Stack Underflow";
        } else {
            x = A[top];
            top--;
        }
        return x;
    }

    T peek(int index) {
        T x = static_cast<T>(-1);
        if (top - index + 1 < 0) {
            cout << "Invalid index" << endl;
        } else {
            x = A[top - index + 1];
        }
        return x;
    }

    T stacktop() {
        if (isEmpty()) {
            return static_cast<T>(-1);
        }
        return A[top];
    }

    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void Display() {
        for (int i = top; i >= 0; i--) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    // Add your implementation for isBalanced function
   
bool isBalanced(char *exp) {
    Stack<char> st; // Declare an object of the Stack class
    
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            st.push(exp[i]);
        } else if (exp[i] == ')') {
            if (st.isEmpty()) {
                return false;
            }
            st.pop();
        }
    }

    return st.isEmpty();
}
};

int main() {
 char exp[]="(a + b) * (c - d)";
  int size = strlen(exp);
  Stack<char> st(size);

  cout<<st.isBalanced(exp);


    return 0;
}