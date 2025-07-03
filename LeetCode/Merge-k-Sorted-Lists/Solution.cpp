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
    class Compare{
        public:
        bool operator()(ListNode* &a, ListNode* &b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        priority_queue<ListNode*, vector<ListNode*>,Compare>pq;
        for(auto &list : lists){
            if(list)pq.push(list);
        }

        ListNode* ansList = new ListNode();
        ListNode* temp = ansList;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            temp->next = it;
            temp = it;
            if(temp->next)pq.push(temp->next);
        }
        return ansList->next;
    }
};