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
        vector<ListNode*> v;
        ListNode* p = head;
        while(p != nullptr) {
            v.push_back(p);
            p = p->next;
        }
        
        int size = (int)v.size();
        ListNode* target = v[size-n];
        if(size - n == 0) {
            head = target->next;
        } else {
            ListNode* prev = v[size-n-1];
            prev->next = target->next;
        }
        
        return head;
    }
};