#include<bits/stdc++.h>
#include "../../ListNode.h"
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next
(nullptr) {}
 *     ListNode(int x, ListNode *next) : val
(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)    return head;
        ListNode* cur = head->next, *prev = head;
        while(cur!=NULL)
        {
            if(cur->val == val)
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
        
        if(head->val == val)
            head = head->next;

        return head;
    }

    void test() {
        assert( 
            Equals(
                removeElements( make_ListNode(*(new vector<int>({1,2,6,3,4,5,6}))), 6 ), 
                make_ListNode(*(new vector<int>({1, 2, 3, 4, 5}))) 
            )
        );
        assert( 
            Equals(
                removeElements( make_ListNode(*(new vector<int>({}))), 5 ), 
                make_ListNode(*(new vector<int>({}))) 
            )
        );
        
        assert( 
            Equals(
                removeElements( make_ListNode(*(new vector<int>({1}))), 1 ), 
                make_ListNode(*(new vector<int>({}))) 
            )
        );

        assert( 
            Equals(
                removeElements( make_ListNode(*(new vector<int>({1}))), 6 ), 
                make_ListNode(*(new vector<int>({1}))) 
            )
        );
        
        assert( 
            Equals(
                removeElements( make_ListNode(*(new vector<int>({6, 6, 6, 5, 6, 6, 6}))), 6 ), 
                make_ListNode(*(new vector<int>({5}))) 
            )
        );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}