#include<vector>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

ListNode* make_ListNode(vector<int>& list)
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