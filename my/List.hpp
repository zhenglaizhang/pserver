//
// Created by darinzh on 10/28/2015.
//

#ifndef CXX_LIST_HPP
#define CXX_LIST_HPP

#include <bits/stl_pair.h>

// http://www.geeksforgeeks.org/merge-sort-for-linked-list/


template<typename T>
struct ListNode {
    T data;
    ListNode *next;
};


// Merge 2 sorted list recersively
ListNode *SortedMerge(ListNode *lhs, ListNode *rhs) {
    if (lhs == nullptr) return rhs;
    if (rhs == nullptr) return lhs;

    ListNode *res = nullptr;

    if (lhs->data <= rhs->data) {
        res = lhs;
        res->next = SortedMerge(lhs->next, rhs);
    } else {
        res = rhs;
        res->next = SortedMerge(lhs, rhs->next);
    }

    return res;
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.
     If the length is odd, the extra node should go in the front list.
     Uses the fast/slow pointer strategy.  */
std::pair<ListNode *, ListNode *> SplitList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return std::make_pair(head, nullptr);
    }

    auto slow = head;
    auto fast = head->next;
    while (fast != nullptr) {
        fast = fast->next;              // move fast extra step firstly!
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // slow is before the mid point of the list
    auto res = std::make_pair(head, slow->next);
    slow->next = nullptr;   // split/cut the list as
    return res;
};

void MergeSort(ListNode **head) {
    if (head == nullptr || (*head)->next == nullptr)
        return;

    auto split = SplitList(*head);
    auto left = split.first;
    auto right = split.second;
    MergeSort(&left);
    MergeSort(&right);
    *head = SortedMerge(left, right);
}

template<typename T>
void PushNode(ListNode<T> **head_ref, T data) {
    auto new_node = new ListNode<T>;
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

#endif //CXX_LIST_HPP
