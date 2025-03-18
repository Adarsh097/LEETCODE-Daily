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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)return head;
        
        ListNode* temp1 = head;
        while(k>1){
            temp1 = temp1->next;
            k--;
        }
        ListNode* temp2 = head;
        ListNode* temp = temp1;
        while(temp->next){
            temp = temp->next;
            temp2 = temp2->next;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};