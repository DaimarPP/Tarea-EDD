#include <iostream>
#include <string>

template<typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(T val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; // Circular link
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    ~CircularLinkedList() {
        if (!head) return;
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(T val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    CircularLinkedList<std::string> circularList;
    DoublyLinkedList<std::string> doublyList;

    // Insertar datos desordenadamente
    circularList.insert("Alice");
    circularList.insert("Bob");
    circularList.insert("Charlie");

    doublyList.insert("David");
    doublyList.insert("Eva");
    doublyList.insert("Frank");

    // Mostrar las listas
    std::cout << "Lista Circular Simple: ";
    circularList.display();

    std::cout << "Lista Doblemente Enlazada: ";
    doublyList.display();

    return 0;
}
