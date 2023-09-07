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
    int len(ListNode* head){
        if(head==NULL)
            return 0;
        return 1+len(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int l=len(head);
        int sz=l/k;
        int extra=l%k;
        ListNode* t=head;
        int c=1;
        while(t){
            if((v.size()<extra&&c==(sz+1))||(v.size()>=extra&&c==sz)){
                ListNode* temp=head;
                head=t->next;
                t->next=NULL;
                t=head;
                v.push_back(temp);
                c=1;
            }
            else{
                t=t->next;
                ++c;
            }
        }
        int i;l=v.size();
        for(i=0;i<(k-l);++i)
            v.push_back(NULL);
        return v;
    }
};