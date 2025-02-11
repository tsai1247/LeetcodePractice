#include<bits/stdc++.h>
using namespace std;
#include "../../ListNode.h"

// Time complexity: O(depth)
// Space complexity: O(depth)
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
        if(head != NULL && head->next != NULL)
        {
            ListNode* new_head = reverseList(head->next);            
            head->next->next = head;
            head->next = NULL;
            return new_head;
        }
        return head;
    }

    void test() {
        assert( Equals(
			reverseList( 
				make_ListNode( *(new vector<int>( {2,7,11,15} )) ) 
			), 
			make_ListNode( *(new vector<int>( {15,11,7,2} )) )
			)
		);
		assert( Equals(
			reverseList( 
				make_ListNode( *(new vector<int>( {2} )) ) 
			), 
			make_ListNode( *(new vector<int>( {2} )) )
			)
		);
		assert( Equals(
			reverseList( 
				make_ListNode( *(new vector<int>( {} )) ) 
			), 
			make_ListNode( *(new vector<int>( {} )) )
			)
		);
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}