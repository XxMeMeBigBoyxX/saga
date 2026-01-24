#include "nu2api.saga/nucore/nulist.h"

void NuLinkedListAppend(NULISTHDR *list, NULISTLNK *node) {
    node->next = NULL;
    node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = node;
    }

    list->tail = node;

    if (list->head == NULL) {
        list->head = node;
    }
}

void NuLinkedListInsert(NULISTHDR *list, NULISTLNK *node) {
    node->next = list->head;
    node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = node;
    }

    if (list->tail == NULL) {
        list->tail = node;
    }

    list->head = node;
}

void NuLinkedListRemove(NULISTHDR *list, NULISTLNK *node) {
    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
}

NULISTLNK *NuLinkedListGetHead(NULISTHDR *list) {
    return list->head;
}

NULISTLNK *NuLinkedListGetTail(NULISTHDR *list) {
    return list->tail;
}

NULISTLNK *NuLinkedListGetPrev(NULISTHDR *list, NULISTLNK *node) {
    if (node != NULL) {
        return node->prev;
    } else {
        return list->tail;
    }
}

NULISTLNK *NuLinkedListGetNext(NULISTHDR *list, NULISTLNK *node) {
    if (node != NULL) {
        return node->next;
    } else {
        return list->head;
    }
}
