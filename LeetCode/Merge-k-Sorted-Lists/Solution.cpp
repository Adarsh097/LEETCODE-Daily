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

class Compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;

       for(int i=0;i<lists.size();i++){
        if(lists[i]){
            pq.push(lists[i]);
        }
       }

        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            temp->next = node;
            temp = node;
            if(temp->next!=NULL){
                pq.push(temp->next);
            }
        }
        return ans->next;
    }
};