#include<bits/stdc++.h>
using namespace std;

/*
# Problem 278. tag: Easy
## Question:
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example 1:
	Input: n = 5, bad = 4
	Output: 4
	Explanation:
	call isBadVersion(3) -> false
	call isBadVersion(5) -> true
	call isBadVersion(4) -> true
	Then 4 is the first bad version.

Example 2:
	Input: n = 1, bad = 1
	Output: 1

Constraints:
	1 <= bad <= n <= 231 - 1

*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include "VersionManager.h"

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