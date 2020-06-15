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
    ListNode* appendList(ListNode* p, int val) {
        ListNode* q = new ListNode(val);
        p->next = q;
        return q;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode* head = new ListNode();
        ListNode* end = head;
        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val < p2->val) {
                end = appendList(end, p1->val);
                p1 = p1->next;
            } else {
                end = appendList(end, p2->val);
                p2 = p2->next;
            }
        }
        
        while(p1 != nullptr) {
            end = appendList(end, p1->val);
            p1 = p1->next;
        }
        while(p2 != nullptr) {
            end = appendList(end, p2->val);
            p2 = p2->next;
        }
        head = head->next;
        
        return head;
    }
};