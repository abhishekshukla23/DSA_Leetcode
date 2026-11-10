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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev1=head;
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev2=nullptr;
        ListNode* curr=head->next;
        while(curr){
            while( curr && prev1->val==curr->val){
                prev1=curr;
                curr=curr->next;
            }
            if(prev2==NULL) {
                prev2=prev1;
                head=prev2;
            }
            else prev2->next=prev1;
            prev2=prev1;
            prev1=curr;
            if(curr)
            curr=curr->next;
        }
        return head;

    }
};