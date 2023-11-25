#pragma once
#include "framework.h"

struct ChessNode {
    int x, y, dist;

    ChessNode(int x, int y, int dist = 0) : x(x), y(y), dist(dist) {}

    bool operator==(const ChessNode& other) const {
        return x == other.x && y == other.y && dist == other.dist;
    }

    bool operator<(const ChessNode& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

template <typename T>
class MyList {
public:
    class ListNode {
    public:
        T data;
        ListNode* next;

        ListNode(const T& value) : data(value), next(nullptr) {}

        bool operator==(const ListNode& other) const {
            return data == other.data;
        }
    };

private:
    ListNode* head;
    size_t size;

public:
    MyList();
    void push_back(const T& value);
    size_t get_size() const;
    ListNode* at(size_t index);
    void push_front(const T& value);
    void insert_after(ListNode* node, const T& value);
    ListNode* begin();
    ListNode* end();
    ListNode* getBegin() const;
    void print();
    void copy_from(const MyList& otherList);
    ~MyList();
};
