#include<bits/stdc++.h>
#include "../../ListNode.h"
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
// The solution fits the follow-up.
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
        ListNode* cur=head, *n_far_node=head;
        for(int i=0; i<n; i++)
        {
            n_far_node = n_far_node->next;
        }
        
        if(n_far_node == NULL)
            return head->next;
        while(n_far_node->next != NULL)
        {
            n_far_node = n_far_node->next;
            cur = cur->next;
        }
        
        // now, cur->next is the target.
        cur->next = cur->next->next;
        
        return head;
    }

    void test() {
        assert(
            Equals(
                removeNthFromEnd( make_ListNode(*(new vector<int>( {1} ))), 1 ),
                make_ListNode(*(new vector<int>( {} )))
            )
        );
        
        assert(
            Equals(
                removeNthFromEnd( make_ListNode(*(new vector<int>( {1, 2, 3, 4, 5} ))), 5 ),
                make_ListNode(*(new vector<int>( {2, 3, 4, 5} )))
            )
        );

        assert(
            Equals(
                removeNthFromEnd( make_ListNode(*(new vector<int>( {1, 2, 3, 4, 5} ))), 2 ),
                make_ListNode(*(new vector<int>( {1, 2, 3, 5} )))
            )
        );

        assert(
            Equals(
                removeNthFromEnd( make_ListNode(*(new vector<int>( {1, 2, 3, 4, 5} ))), 1 ),
                make_ListNode(*(new vector<int>( {1, 2, 3, 4} )))
            )
        );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}