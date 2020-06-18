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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = (int)lists.size();
        priority_queue<pair<int, int> > pq;
        for(int i = 0; i < size; ++i) {
            if(lists[i] != nullptr) {
                pq.push({-lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(!pq.empty()) {
            int val = -pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            ListNode* l = new ListNode(val);
            l->next = tail->next;
            tail->next = l;
            tail = l;
            
            if(lists[idx] == nullptr)
                continue;
            pq.push({-lists[idx]->val, idx});
            lists[idx] = lists[idx]->next;
        }
        
        return head->next;
    }
};