1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* swapPairs(ListNode* head) {
14        if(!head)return head;
15        ListNode* temp1 = new ListNode(0);
16      
17        ListNode* temp2 = new ListNode(0);
18             ListNode* new1 = temp1;
19           ListNode* new2 = temp2;
20
21        bool flag = true;
22        ListNode* temp = head;
23        while(temp){
24            if(flag){
25                temp1 ->next = temp;
26                temp1 = temp1->next;
27                temp = temp->next;
28                temp1->next = NULL;
29                flag = !flag;
30            }else{
31                temp2 ->next = temp;
32                temp2 = temp2 ->next;
33                temp = temp->next;
34                temp2->next = NULL;
35                flag = !flag;
36            }
37            
38        }
39
40        ListNode* ansNode = new ListNode(0);
41        head = ansNode;
42
43
44        new1 = new1->next;
45        new2 = new2->next;
46            
47        
48        while(new1 && new2){
49            ansNode->next = new2;
50            new2 = new2->next;
51            ansNode = ansNode->next;
52            ansNode->next = new1;
53             ansNode = ansNode->next;
54            new1 = new1->next;
55        }
56
57        if(new1)ansNode->next = new1;
58        if(new2)ansNode->next = new2;
59        return head->next;
60    }
61};