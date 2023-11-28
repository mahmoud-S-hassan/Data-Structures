#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};

template <typename T>
class linkedList {
private:
    Node<T>* head;

public:
    linkedList()
        : head(nullptr)
    {
    }

    void insertNode(T val)
    {
        Node<T>* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    };

    void deleteNode(T val)
    {
        if (head == nullptr) {
            std::cout << " lest is empty.!\n";
            return;
        }
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        if (temp->next == nullptr && temp->data == val) {
            head = temp->next;
            delete temp;
            temp = nullptr;
            return;
        }

        while (temp != nullptr && temp->data != val) {

            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;

        if (temp == nullptr) {
            std::cout << "Element not found\n";
            return;
        }
    }

    void traversList() const
    {
        Node<T>* temp = head;

        while (temp->next != nullptr) {

            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main(int argc, char* argv[])
{
    linkedList<int> Linkedlist;

    Linkedlist.insertNode(30);
    Linkedlist.insertNode(50);
    Linkedlist.insertNode(5);
    Linkedlist.insertNode(20);
    Linkedlist.insertNode(70);
    Linkedlist.insertNode(10);

    std::cout << "original list💡: ";
    Linkedlist.traversList();

    // 1. ❌ Delete element 20 from the linked list
    Linkedlist.deleteNode(20);
    // 2. 🏃 Traversing The List

    std::cout << "List after Deleting: ";
    Linkedlist.traversList();
    return 0;
}
