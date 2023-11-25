#include "framework.h"

template <typename T>
class MyQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    MyQueue() : front(nullptr), rear(nullptr) {}

    ~MyQueue() {
        while (!empty()) {
            dequeue();
        }
    }

    void enqueue(T data) {
        Node* newNode = new Node(data);
        if (empty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (empty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    T peek() const {
        if (empty()) {
            cerr << "Queue is empty." << endl;
            exit(EXIT_FAILURE);
        }
        return front->data;
    }

    bool empty() const {
        return front == nullptr;
    }
};