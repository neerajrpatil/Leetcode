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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy =new ListNode();
        ListNode* ansPtr=dummy;
        ListNode* ptr=head->next;
        while(ptr){
            int sum=0;
           while(ptr->val!=0){
                sum+=ptr->val;
                ptr=ptr->next;
            } 
            ansPtr->next=new ListNode(sum);
            ansPtr=ansPtr->next;
            ptr=ptr->next;
        }
        return dummy->next;
    }
};