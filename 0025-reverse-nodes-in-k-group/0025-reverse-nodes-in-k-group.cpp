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

void reverse(ListNode* head , int times){
    ListNode* curr = head;
    ListNode* prev = NULL;

    while(times--){
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return ;
}


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        int size = k;

        while(true){
            right = left;
            for(int i=0; i<size-1; i++){
                if(right == NULL){
                    break;
                }
                right = right->next;
            }

            if(right){
                ListNode* nextleft = right->next;
                reverse(left , size);

                if(res == NULL){
                    res = right;
                }

                if(prevleft){
                    prevleft->next = right;
                }

                prevleft = left;

                left = nextleft;
            }

            else{
                if(prevleft){
                    prevleft->next = left;
                }

                if(res == NULL){
                    res = left;
                }

                break;
            }
        }

        return res;
    }
};