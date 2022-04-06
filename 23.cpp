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


//You are given an array of k linked - lists lists, each linked - list is sorted in ascending order.

//Merge all the linked - lists into one sorted linked - list and return it.

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};



ListNode* mergeKLists(vector<ListNode*>& lists) {

    ListNode* node = new ListNode(0);
    ListNode* node1 = node; 
    int n = lists.size();

    while (1) {
        int minimal = 1000000;
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (lists[i] != NULL && lists[i]->val < minimal) {
                minimal = lists[i]->val;
                index = i;
            }
        }
        if (index == -1) {
            break;
        }
        node1->next = new ListNode(minimal); 
        node1 = node1->next; 
        
        lists[index] = lists[index]->next; 
    }

    return node->next;
}