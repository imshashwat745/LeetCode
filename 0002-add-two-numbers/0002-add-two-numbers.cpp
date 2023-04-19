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
        return addTwoNumbersHelper(l1,l2,0);
    }
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2,int carry) {
        if(l1==NULL&&l2==NULL&&carry==0)
            return NULL;
        if(l1!=NULL&&l2!=NULL){
        ListNode* x=addTwoNumbersHelper(l1->next,l2->next,(l1->val+l2->val+carry)/10);
        ListNode* newNode=new ListNode((l1->val+l2->val+carry)%10);
        newNode->next=x;
        return newNode;
        }
        else if(l1!=NULL){
        ListNode* x=addTwoNumbersHelper(l1->next,l2,(l1->val+carry)/10);
        ListNode* newNode=new ListNode((l1->val+carry)%10);
        newNode->next=x;
        return newNode;
        }
        else if(l2!=NULL){
        ListNode* x=addTwoNumbersHelper(l1,l2->next,(l2->val+carry)/10);
        ListNode* newNode=new ListNode((l2->val+carry)%10);
        newNode->next=x;
        return newNode;
        }
        else{
        ListNode* x=addTwoNumbersHelper(l1,l2,carry/10);
        ListNode* newNode=new ListNode((carry)%10);
        newNode->next=x;
        return newNode;
        }
    }
};