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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        int jump = len - n;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        head = dummy;
        
        temp = head;
        while(jump--){
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        delete del;
        return head->next;
    }
};