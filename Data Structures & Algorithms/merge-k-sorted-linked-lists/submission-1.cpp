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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;

        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        if(pq.empty()) return nullptr;

        auto top_pair = pq.top(); pq.pop();
        ListNode* top = top_pair.second;
        ListNode* ans = top;
        if(top->next)
            pq.push({top->next->val, top->next});

        while(!pq.empty())
        {
            auto curr = pq.top(); pq.pop();

            if(curr.second->next) pq.push({curr.second->next->val, curr.second->next});

            top->next = curr.second;
            top = top->next;
        }

        return ans;
    }
};
