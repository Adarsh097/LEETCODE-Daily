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
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* right = curr->next;
            curr->next = prev;
            prev = curr;
            curr = right;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        int n = 0;
        int ans = 0;
        ListNode* temp = head;
        while(temp){
            ans += (pow(2,n)*temp->val);
            n++;
            temp = temp->next;
        }
        return ans;
    }
};