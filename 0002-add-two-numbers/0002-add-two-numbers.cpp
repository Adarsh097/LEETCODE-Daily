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
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        int rem = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + rem;
            int digit = sum%10;
            rem = sum/10;
            temp->next = new ListNode(digit);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val  + rem;
            int digit = sum%10;
            rem = sum/10;
            temp->next = new ListNode(digit);
            temp = temp->next;
            l1 = l1->next;
        }
         while(l2){
            int sum =  l2->val + rem;
            int digit = sum%10;
            rem = sum/10;
            temp->next = new ListNode(digit);
            temp = temp->next;
            
            l2 = l2->next;
        }
        if(rem>0){
            temp->next = new ListNode(rem);
        }
        return ans->next;
    }
};