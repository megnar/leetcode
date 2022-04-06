#define _CRT_SECURE_NO_WARNING

#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_set>
#include <cmath>
#include <string>
#include <sstream>
#include <numeric>
#include <list>
#include <thread>
#include <functional>
#include <cstdio>
using namespace std;




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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int x = 0;
    int sum = 0;
    ListNode* node = NULL;
    ListNode** node1 = &node;
    int flag1 = 0;
    int flag2 = 0;
    while (1) {

        sum = x;

        if (flag1 == 0) {
            sum += l1->val;
        }

        if (flag2 == 0) {
            sum += l2->val;
        }

        if (sum == 0 && flag1 == 1 && flag2 == 1) {
            break;
        }
        (*node1) = new ListNode(0);
        (*node1)->val = sum % 10;
        x = sum / 10;

        if (l1->next == nullptr)
            flag1 = 1;
        else
            l1 = l1->next;
        if (l2->next == nullptr)
            flag2 = 1;
        else
            l2 = l2->next;
        node1 = &((*node1)->next);

    }

    return node;
}

