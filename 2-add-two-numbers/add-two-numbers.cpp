/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t = l1;
        ListNode* t2 = l2;
        int n = 0, m = 0;
        while (t) {
            n++;
            t = t->next;
        }
        while (t2) {
            m++;
            t2 = t2->next;
        }
        t = l1;
        t2 = l2;
        while (t || t2) {
            int s = 0;
            if (t && t2) s = t->val + t2->val;
            else if (t) s = t->val;
            else s = t2->val;
            int cry = s / 10;
            int digi = s % 10;
            if (cry) {
                if (n > m) {
                    if (t->next != nullptr)
                        t->next->val = t->next->val + cry;
                    else {
                        ListNode* newNode = new ListNode(cry);
                        t->next = newNode;
                    }
                } else {
                    if (t2->next != nullptr)
                        t2->next->val = t2->next->val + cry;
                    else {
                        ListNode* newNode = new ListNode(cry);
                        t2->next = newNode;
                    }
                }
            }
            if (n > m) t->val = digi;
            else t2->val = digi;
            if (t) t = t->next;
            if (t2) t2 = t2->next;
        }
        if (n > m) return l1;
        return l2;
    }
};