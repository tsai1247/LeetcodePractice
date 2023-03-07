#include<bits/stdc++.h>
using namespace std;
#include "VersionManager.h"

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
        long long left = 0, right = n;
        int min_badversion = n;
        while(left <= right)
        {
            int mid = (left + right) /2;
            if(isBadVersion(mid))
            {
                min_badversion = mid;
                right = mid - 1;
            }
            else
            {
                left = mid +1;
            }
        }
        return min_badversion;
    }

    void test() {
		setBad(4, 1);
        assert(firstBadVersion(4) == 1 );

		setBad(4, 2);
        assert(firstBadVersion(4) == 2 );

		setBad(1, 1);
        assert(firstBadVersion(1) == 1 );

		setBad(4, 4);
        assert(firstBadVersion(4) == 4 );

		setBad(2147483647, 1020000001);
        assert(firstBadVersion(2147483647) == 1020000001 );

		setBad(2147483647, 2147483646);
        assert(firstBadVersion(2147483647) == 2147483646 );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}