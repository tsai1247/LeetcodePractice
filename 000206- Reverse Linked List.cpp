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

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
	bool Equals(ListNode* a, ListNode* b)
	{
		ListNode* a_cur = a, * b_cur = b;
		while(a_cur != NULL && b_cur != NULL)
		{
			if(a_cur->val != b_cur->val)
				return false;
			a_cur = a_cur->next;
			b_cur = b_cur->next;
		}
		return a_cur == NULL && b_cur == NULL;
	}

	ListNode* make_list(vector<int>& list)
	{
		if(list.size() == 0)
			return NULL;
		ListNode* ret = new ListNode(list[0]);
		ListNode* cur = ret;
		for(int i=1; i<list.size(); i++)
		{
			cur->next = new ListNode(list[i]);
			cur = cur->next;
		}
		return ret;
	}
public:
    ListNode* reverseList_iteratively(ListNode* head) {
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
	ListNode* reverseList_recursively(ListNode* head) {
        if(head != NULL && head->next != NULL)
        {
            ListNode* new_head = reverseList_recursively(head->next);            
            head->next->next = head;
            head->next = NULL;
            return new_head;
        }
        return head;
    }

    void test() {
        assert( Equals(
			reverseList_iteratively( 
				make_list( *(new vector<int>( {2,7,11,15} )) ) 
			), 
			make_list( *(new vector<int>( {15,11,7,2} )) )
			)
		);
		assert( Equals(
			reverseList_iteratively( 
				make_list( *(new vector<int>( {2} )) ) 
			), 
			make_list( *(new vector<int>( {2} )) )
			)
		);
		assert( Equals(
			reverseList_iteratively( 
				make_list( *(new vector<int>( {} )) ) 
			), 
			make_list( *(new vector<int>( {} )) )
			)
		);
		assert( Equals(
			reverseList_recursively( 
				make_list( *(new vector<int>( {2,7,11,15} )) ) 
			), 
			make_list( *(new vector<int>( {15,11,7,2} )) )
			)
		);
		assert( Equals(
			reverseList_recursively( 
				make_list( *(new vector<int>( {2} )) ) 
			), 
			make_list( *(new vector<int>( {2} )) )
			)
		);
		assert( Equals(
			reverseList_recursively( 
				make_list( *(new vector<int>( {} )) ) 
			), 
			make_list( *(new vector<int>( {} )) )
			)
		);
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}