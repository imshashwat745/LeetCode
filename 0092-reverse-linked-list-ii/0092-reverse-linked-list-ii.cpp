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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* first=NULL;
        ListNode* lft=NULL;
        ListNode* nxt=NULL;
        int i=1;
        while(i<=right&&curr){
            nxt=curr->next;
            if(i==left-1){
                first=curr;
            }
            else if(i==left){
                lft=curr;
            }
            else if(i>left&&i<=right){
                curr->next=prev;
            }
            prev=curr;
            curr=nxt;
            ++i;
        }
        lft->next=curr;
        if(first)first->next=prev;
        else head=prev;
        return head;

    }
};