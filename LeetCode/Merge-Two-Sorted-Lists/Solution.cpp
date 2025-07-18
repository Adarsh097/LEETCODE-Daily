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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
                temp->next = NULL;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }
        if(temp1){
            temp->next = temp1;
        }
        if(temp2){
            temp->next = temp2;
        }
        return ans->next;
    }
};