#pragma once

#include "decomp.h"

class DefaultElist;

template <typename T, typename D = DefaultElist> class NuEListNode {
  public:
    NuEListNode<T, D> *prev;
    NuEListNode<T, D> *next;
    T *data;
};

template <typename T, typename D = DefaultElist> class NuEList {
  public:
    NuEListNode<T, D> *head;
    NuEListNode<T, D> *tail;

    NuEListNode<T, D> **head_ptr;
    NuEListNode<T, D> **tail_ptr;

    usize length;

    NuEList() {
        head = nullptr;
        tail = nullptr;
        head_ptr = &head;
        tail_ptr = &tail;
        length = 0;
    }

    ~NuEList() {
        for (auto *node = head; node != nullptr;) {
            auto *next = node->next;
            delete node;
            node = next;
        }
    }
};
