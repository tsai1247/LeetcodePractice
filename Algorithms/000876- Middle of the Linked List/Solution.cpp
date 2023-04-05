#include<bits/stdc++.h>
#include "../ListNode.h"
using namespace std;

// Time complexity: O(n) (run n/2 times in loop)
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        // break when fast is null or fast->next is null
        
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast == NULL)
                break;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    void test() {
        assert( 
            Equals(
                middleNode( make_ListNode(*(new vector<int>( {1} ))) ),
                make_ListNode(*(new vector<int>( {1} )))
            )
        );
        assert( 
            Equals(
                middleNode( make_ListNode(*(new vector<int>( {1, 2} ))) ),
                make_ListNode(*(new vector<int>( {2} )))
            )
        );
        assert( 
            Equals(
                middleNode( make_ListNode(*(new vector<int>( {1, 2, 3, 4} ))) ),
                make_ListNode(*(new vector<int>( {3, 4} )))
            )
        );
        assert( 
            Equals(
                middleNode( make_ListNode(*(new vector<int>( {1, 2, 3, 4, 5} ))) ),
                make_ListNode(*(new vector<int>( {3, 4, 5} )))
            )
        );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}