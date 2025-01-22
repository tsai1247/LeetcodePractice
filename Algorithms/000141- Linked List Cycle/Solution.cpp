#include<bits/stdc++.h>
#include "../../ListNode.h"
using namespace std;

// Time complexity: O(n) (n次迴圈後，slow跟fast會拉開n的距離，也是有cycle時最差的清況)
// Space complexity: O(1)
// The solution fits the follow-up.
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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode* slow = head, *fast = head;
        while(slow != NULL && fast != NULL)
        {
            fast = fast->next;
            // 不會有同時是NULL的情況，因為唯一可能的時候在第一次loop，而這個case會被if擋下來
            if(fast == NULL)
                break;
            fast = fast->next;
            slow = slow->next;

            if(slow == fast)
                return true;
        }
        return false;
    }

    void test() {
        ListNode* list;
        
        list = make_ListNode(*(new vector<int>( {3,2,0,-4} )))->addCycle(3, 1);
        assert(hasCycle(list) == true );

        list = make_ListNode(*(new vector<int>( {1, 2} )))->addCycle(1, 0);
        assert(hasCycle(list) == true );
        
        list = make_ListNode(*(new vector<int>( {1, 2} )))->addCycle(1, 1);
        assert(hasCycle(list) == true );

        list = make_ListNode(*(new vector<int>( {1} )));
        assert(hasCycle(list) == false );
        
        list = make_ListNode(*(new vector<int>( {1} )))->addCycle(0, 0);
        assert(hasCycle(list) == true );

        list = make_ListNode(*(new vector<int>( {} )));
        assert(hasCycle(list) == false );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}