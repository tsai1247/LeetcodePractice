#include<bits/stdc++.h>
#include "../ListNode.h"
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* cur = head->next, *prev = head;
        while(cur != NULL)
        {
            if(prev->val == cur->val) // remove cur
            {
                cur = cur->next;
                prev->next = cur;
            }
            else
            {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return head;
    }

    void test() {
        assert(
            Equals(
                deleteDuplicates( make_ListNode(*(new vector<int>( {} ))) ),
                make_ListNode(*(new vector<int>( {} )))
            )
        );

        assert(
            Equals(
                deleteDuplicates( make_ListNode(*(new vector<int>( {1} ))) ),
                make_ListNode(*(new vector<int>( {1} )))
            )
        );

        assert(
            Equals(
                deleteDuplicates( make_ListNode(*(new vector<int>( {1, 1, 1, 2, 2, 3, 4, 4} ))) ),
                make_ListNode(*(new vector<int>( {1, 2, 3, 4} )))
            )
        );

        assert(
            Equals(
                deleteDuplicates( make_ListNode(*(new vector<int>( {1, 2, 3, 4} ))) ),
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