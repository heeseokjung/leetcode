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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ret = nullptr, *p = nullptr;
        while(l1 || l2) {
            int tmp = carry;
            if(l1 != nullptr)
                tmp += l1->val;
            if(l2 != nullptr)
                tmp += l2->val;
            carry = tmp / 10;
            tmp %= 10;
            if(ret == nullptr) {
                ret = new ListNode(tmp);
                p = ret;
            } else {
                p->next = new ListNode(tmp);
                p = p->next;
            }
            
            l1 = (l1 != nullptr ? l1->next : l1);
            l2 = (l2 != nullptr ? l2->next : l2);
        }
        
        if(carry != 0)
            p->next = new ListNode(carry);
        
        return ret;
    }
};