#pragma once

#include "my_list.h"

template <typename T>
class MySet {
private:
    MyList<T> elements;

public:
    void insert(const T& value) {
        if (!contains(value)) {
            elements.push_back(value);
        }
    }

    bool contains(const T& value) const {
        typename MyList<T>::ListNode* current = elements.getBegin();
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};