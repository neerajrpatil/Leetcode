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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        pair<int,int>maxi={-1,-1};
        int posi=1;
        ListNode* cur=head->next;
        int prev=-1;
        int mini=1e6;
        int a=head->val,b=cur->val,c;
        while(cur->next!=NULL){
            c=cur->next->val;
            b=cur->val;
            if(b>a&&b>c || b<a&&b<c){
                if(maxi.first==-1){
                    maxi.first=posi;
                    maxi.second=posi;
                    prev=posi;
                }
                else{
                    mini=min(mini,posi-prev);
                    maxi.second=posi;
                    prev=posi;
                }
            }
            a=b;
            cur=cur->next;
            posi++;
        }
        if(maxi.first==maxi.second)return {-1,-1};
        return {mini==1e6?-1:mini,maxi.second-maxi.first};
    }
};