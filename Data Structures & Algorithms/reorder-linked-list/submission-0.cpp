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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;  // save before cutting!
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2!=nullptr){
            ListNode* l1next = l1->next;  
            ListNode* l2next = l2->next;  

            l1->next = l2;
            l2->next = l1next;

            l1 = l1next;
            l2 = l2next;
        }
    }
};
