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
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;

        
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        while(head1!=NULL && head2!=NULL){
            if(head1->val < head2->val){
                temp -> next = head1;
                head1 = head1->next;
            }else{
                temp -> next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if(head1!=NULL){
            temp->next = head1;
        }
         if(head2!=NULL){
             temp->next = head2;
         }
         ListNode* result = head ->next;
         head->next = NULL;
         delete head;
         return result;
    }
    ListNode* Sort(ListNode* head, ListNode* tail){
        if(head==NULL || head==tail){
            if(head!=NULL)
            head -> next = NULL;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL){
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        ListNode* l1 = Sort(head,slow);
        ListNode* l2 = Sort(head2,tail);
        ListNode* merged = merge(l1,l2);
        return merged;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL)return head;
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        return Sort(head,tail);
    }
};