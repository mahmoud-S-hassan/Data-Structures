/**
 * @brief Array based stack
 *
 * @tparam T Data type
 * @return Operation on stack
 */

#include <iomanip>
#include <iostream>
#include <string>
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val)
        : data(val)
        , next(nullptr)
    {
    }
};
template <typename T>
class Stack {
    Node<T>* top;

public:
    Stack()
        : top(nullptr)
    {
    }

    ~Stack()
    {
        while (!isEmpty()) {
            pop();
        }
    }
    bool isEmpty() { return top == nullptr; }

    void push(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
    }
    T pop()
    {
        if (top == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        Node<T>* temp = top;
        top = top->next;
        T val = temp->data;
        delete temp;
        return val;
    }
    T Top()
    {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        return top->data;
    }
};

template <typename T, int size>
class arrayStack {
public:
    arrayStack()
        : top(-1)
    {
        stackArray = new T[size];
    }
    ~arrayStack() { delete[] stackArray; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == size - 1; }
    T Top()
    {
        if (isEmpty()) {
            std::cout << "Stack is empty.";
            return T(); // default constructor
        }
        return stackArray[top];
    }

    void push(T val)
    {
        if (isFull()) {
            std::cout << "Stack overflow!\n";
            return;
        }
        stackArray[++top] = val;
    }
    T pop()
    {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return T();
        }

        return stackArray[top--];
    }
    void display()
    {
        if (isEmpty()) {
            std::cout << "stack is empty." << std::endl;
            return;
        }
        int tempTop = top;

        while (tempTop != -1) {
            std::cout << stackArray[tempTop] << " ";
            --tempTop;
        }
        std::cout << std::endl;
    }

private:
    T* stackArray;
    int top;
};

std::string reverseWord(const std::string& word)
{
    Stack<char> charStack;

    for (char c : word) {
        charStack.push(c);
    }
    std::string reversedWord;
    while (!charStack.isEmpty()) {

        reversedWord.push_back(charStack.pop());
    }
    return reversedWord;
}

bool checkBalancedPrantheses(const std::string& opject)
{
    Stack<char> charStack;
    for (char c : opject) {
        if (c == '(' || c == '{' || c == '[') {
            charStack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (charStack.isEmpty()) {
                return false;
            }

            char top = charStack.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return charStack.isEmpty();
}

int main(int argc, char* argv[])
{
    int c;
    std::cout << "    tasks \n\t1. array Stack\n\t2. linked Stack\n " << std::endl;
    std::cin >> c;
    if (c == 1) {

        arrayStack<int, 5> arrayStack;
        // push elements
        arrayStack.push(2);
        arrayStack.push(10);
        arrayStack.push(5);

        // pop elements
        arrayStack.pop();

        // push another elements
        arrayStack.push(7);
        std::cout << arrayStack.Top() << std::endl;
        std::cout << (arrayStack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << std::endl;
        arrayStack.display();
        return 0;
    } else if (c == 2) {
        std::string reversedWord = reverseWord("DATA STRUCTURE");
        std::cout << "reversed Word: " << reversedWord << std::endl;

        //
        std::cout << "Balanced Prantheses (A+B)     " << std::setw(5) << (checkBalancedPrantheses("(A+B)") ? "Yes" : "No") << std::endl;
        std::cout << "Balanced Prantheses [2+3]+(A)}" << std::setw(5) << (checkBalancedPrantheses("[2+3]+(A)}") ? "Yes" : "No") << std::endl;
        std::cout << "Balanced Prantheses )(        " << std::setw(5) << (checkBalancedPrantheses(")(") ? "Yes" : "No") << std::endl;
        std::cout << "Balanced Prantheses {(A+Z}    " << std::setw(5) << (checkBalancedPrantheses("{(A+Z}") ? "Yes" : "No") << std::endl;
    }
    return 0;
}
