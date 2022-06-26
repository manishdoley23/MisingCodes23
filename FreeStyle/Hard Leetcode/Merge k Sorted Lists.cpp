/* Definition for singly-linked list.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(int i=0; i<lists.size(); ++i){
            while(lists[i] != NULL){
                pq.push(lists[i]-> val);
                lists[i] = lists[i]-> next;
            }
        }
        if(pq.empty()) return NULL;
        ListNode* head = new ListNode(pq.top());
        ListNode* tail = head;
        pq.pop();
        while(pq.size()){
            ListNode* newNode = new ListNode(pq.top());
            pq.pop();
            tail-> next = newNode;
            tail = newNode;
        }
        return head;
    }
};
