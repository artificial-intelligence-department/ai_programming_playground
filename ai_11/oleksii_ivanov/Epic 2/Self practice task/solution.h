#ifndef SELF_PRACTICE_TASK_SOLUTION_H
#define SELF_PRACTICE_TASK_SOLUTION_H

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // holding linked list pointer and current node of it
        ListNode* new_list = new ListNode, *new_node = new_list;
        // holding remainder of addition
        int remainder = 0;

        // writing current node if any of lists have any members
        while (l1 != nullptr || l2 != nullptr) {
            // summing everything up
            int sum = remainder;
            if (l1 != nullptr) sum += l1->val;
            if (l2 != nullptr) sum += l2->val;

            // writing last digit as value
            new_node->val = sum % 10;
            // evaluating remainder
            remainder = sum / 10;

            // if there is next value in any of lists,
            if (
                    (l1 != nullptr && l1->next != nullptr) ||
                    (l2 != nullptr && l2->next != nullptr)
                    ) {
                // next node is needed
                new_node->next = new ListNode;
            }
                // or if there is no elements, but remainder isn't equal to 0
            else if (remainder != 0) {
                new_node->next = new ListNode(remainder);
            }

            // moving iterating pointers to next positions
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
            new_node = new_node->next;
        }

        // returning resulting list
        return new_list;
    }
};

#endif //SELF_PRACTICE_TASK_SOLUTION_H
