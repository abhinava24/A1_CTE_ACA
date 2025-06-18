#include <stdio.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *next;
};

// Reverse list
struct Node* rev(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* cur = head;
    while (cur) {
        struct Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// Check palindrome
bool isPal(struct Node* head) {
    if (!head || !head->next) return true;

    // Find mid
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct Node* sec = rev(slow);
    struct Node* tmp = sec;

    // Compare halves
    while (sec) {
        if (head->val != sec->val) {
            rev(tmp); // Restore list
            return false;
        }
        head = head->next;
        sec = sec->next;
    }

    // Restore list
    rev(tmp);

    return true;
}