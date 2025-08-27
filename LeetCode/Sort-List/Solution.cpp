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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(head1 && head2){
            if(head1->val <= head2->val){
                temp->next = head1;
                head1 = head1->next;
            }else{
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1){
            temp->next = head1;
        }else{
            temp->next = head2;
        }
        return dummy->next;
    }
    ListNode* mid(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode* midNode = mid(head);
        ListNode* right = midNode->next;
        midNode->next = NULL;
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(right);
        return merge(list1,list2);
    }
};