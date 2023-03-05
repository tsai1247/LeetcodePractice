#include<bits/stdc++.h>
using namespace std;

/*
# Problem 206. tag: Easy
## Question:
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
	Input: head = [1,2,3,4,5]
	Output: [5,4,3,2,1]

Example 2:
	Input: head = [1,2]
	Output: [2,1]

Example 3:
	Input: head = []
	Output: []

Constraints:
	The number of nodes in the list is the range [0, 5000].
	-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

#include "../ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = NULL, *cur = head;
        while(cur!= NULL)
        {
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = ret;
            ret = tmp;
        }
        return ret;
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