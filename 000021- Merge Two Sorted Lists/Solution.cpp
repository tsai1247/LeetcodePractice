#include<bits/stdc++.h>
using namespace std;

/*
# Problem 21. tag: Easy
## Question:
You are given the heads of two sorted linked lists list1 and list2.Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.Return the head of the merged linked list.

Example 1:
	Input: list1 = [1,2,4], list2 = [1,3,4]
	Output: [1,1,2,3,4,4]

Example 2:
	Input: list1 = [], list2 = []
	Output: []

Example 3:
	Input: list1 = [], list2 = [0]
	Output: [0]

Constraints:
	The number of nodes in both lists is in the range [0, 50].
	-100 <= Node.val <= 100
	Both list1 and list2 are sorted in non-decreasing order.

*/


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

#include "../ListNode.h"

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == NULL)
			return list2;
		if(list2 == NULL)
			return list1;
		
		
		ListNode* cur1, *cur2, *head = new ListNode();
		if(list1->val < list2->val)
		{
			head->next = list1; 
			cur1 = head;
			cur2 = list2;
		}
		else
		{
			head->next = list2; 
			cur1 = head;
			cur2 = list1;
		}
		while(cur1->next != NULL && cur2 != NULL)
		{
			if(cur1->next->val < cur2->val)
			{
				cur1 = cur1->next;
			}
			else
			{
				ListNode* tmp = cur1->next;
				cur1->next = cur2;
				cur2 = cur2->next;
				cur1->next->next = tmp;
			}
		}
		
		if(cur1->next==NULL)
			cur1->next = cur2;
		return head->next;
	}

    void test() {
        assert( 
			Equals(
				mergeTwoLists( 
					make_ListNode( *(new vector<int>( {1, 2, 4})) ), 
					make_ListNode( *(new vector<int>( {1, 3, 4} ) ) )
				), 
				make_ListNode( *(new vector<int>( {1, 1, 2, 3, 4, 4} )) )
			)
		);
		
		assert( 
			Equals(
				mergeTwoLists( 
					make_ListNode( *(new vector<int>( {})) ), 
					make_ListNode( *(new vector<int>( {} ) ) )
				), 
				make_ListNode( *(new vector<int>( {} )) )
			)
		);

		assert( 
			Equals(
				mergeTwoLists( 
					make_ListNode( *(new vector<int>( {})) ), 
					make_ListNode( *(new vector<int>( {0} ) ) )
				), 
				make_ListNode( *(new vector<int>( {0} )) )
			)
		);

		assert( 
			Equals(
				mergeTwoLists( 
					make_ListNode( *(new vector<int>( {0})) ), 
					make_ListNode( *(new vector<int>( {} ) ) )
				), 
				make_ListNode( *(new vector<int>( {0} )) )
			)
		);

		assert( 
			Equals(
				mergeTwoLists( 
					make_ListNode( *(new vector<int>( {1, 2, 3})) ), 
					make_ListNode( *(new vector<int>( {4, 5, 6} ) ) )
				), 
				make_ListNode( *(new vector<int>( {1, 2, 3, 4, 5, 6} )) )
			)
		);

		assert( 
			Equals(
				mergeTwoLists( 
					make_ListNode( *(new vector<int>( {4, 5, 6} ) ) ), 
					make_ListNode( *(new vector<int>( {1, 2, 3})) ) 
				), 
				make_ListNode( *(new vector<int>( {1, 2, 3, 4, 5, 6} )) )
			)
		);
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}