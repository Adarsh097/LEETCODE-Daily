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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==nullptr)return head;
        ListNode* ansNode = head->next;

        ListNode* temp = swapPairs(ansNode->next);
        head->next = temp;
        ansNode->next = head;
        return ansNode;
    }
};