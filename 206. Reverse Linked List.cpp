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
    ListNode* reverseList(ListNode* head) {
        ListNode* father = nullptr;
        auto son = head;
        while(son != nullptr){
            ListNode* x =  son->next;
            son->next = father; 
            father = son; 
            son = x;
        }
        return father;
    }
};
