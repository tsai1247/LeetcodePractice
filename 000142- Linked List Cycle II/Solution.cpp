#include<bits/stdc++.h>
#include "../ListNode.h"
using namespace std;

// Time complexity: O(n) (at most n*2 times of loop)
// Space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
        The List: 
        1  ->  2  ->  3  ->  4  ->  5  ->   6
                             ↑              ↓
                             9  <-  8  <-   7
        Assume that fast == slow at value 6, set L1 = Length of (1~4), L2 = Length of (4~6), L3 = Length of (6~4)
        Because fast == slow and fast is 2x speed of slow, L1 + L2 + (L2+L3)*n_loop = 2*( L1 + L2 )
        => L1 = L3 + (L2+L3)*(n-1)

        Set entry = head. when entry walks L1 steps, the slow will walks `L3 + (L2+L3)*(n-1)` steps at the same time.
        In other words, slow will walk L3 steps, reach the entrypoint (the 4 in example), and then walk n-1 loops to meet entry.
    */
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)  return NULL;
        ListNode* slow=head, *fast=head;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
            slow = slow->next;
            if(slow == fast)
            {
                ListNode* entry = head;
                while(entry!=slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }

    void test() {
        ListNode* head;
        
        head = make_ListNode(*(new vector<int>( {3,2,0,-4} )));
        addCycle(head, 0, 3);
        assert(detectCycle(head)->val == 3);

        head = make_ListNode(*(new vector<int>( {3,2,0,-4} )));
        addCycle(head, 1, 3);
        assert(detectCycle(head)->val == 2);

        head = make_ListNode(*(new vector<int>( {3,2,0,-4} )));
        addCycle(head, 2, 3);
        assert(detectCycle(head)->val == 0);

        head = make_ListNode(*(new vector<int>( {3,2,0,-4} )));
        addCycle(head, 3, 3);
        assert(detectCycle(head)->val == -4);

        head = make_ListNode(*(new vector<int>( {3} )));
        addCycle(head, 0, 0);
        assert(detectCycle(head)->val == 3);

        head = make_ListNode(*(new vector<int>( {} )));
        assert(detectCycle(head) == NULL);

        head = make_ListNode(*(new vector<int>( {1, 2, 3} )));
        addCycle(head, 0, 2);
        assert(detectCycle(head)->val == 1);
        
        head = make_ListNode(*(new vector<int>( {1, 2, 3} )));
        addCycle(head, 1, 2);
        assert(detectCycle(head)->val == 2);
        
        head = make_ListNode(*(new vector<int>( {1, 2, 3} )));
        addCycle(head, 2, 2);
        assert(detectCycle(head)->val == 3);

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}