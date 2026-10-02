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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* prev_p2 = nullptr;

        while(n--) p1 = p1->next;

        while(p1){
            p1 = p1->next;
            prev_p2 = p2;
            p2 = p2->next;
        }

        if(prev_p2==nullptr) return head->next;

        prev_p2->next = p2->next;

        return head;
    }
};
