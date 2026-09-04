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
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Har linked list ka first node
        for(auto list : lists) {
            if(list != nullptr) {
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = curr;

            // Current list ka next node
            if(curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};