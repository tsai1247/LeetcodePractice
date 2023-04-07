#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)  (Can be optimized to O(3))
class Solution {
public:
    int climbStairs(int n) {
        // a[n] means there are a[n] ways to reach the n steps
        // init: 
            // a[0] = a[1] = 1;
        // recurrence relation: 
            // a[i] = a[i-1] + a[i-2];
        
        int* a = new int[n+1];
        a[0] = 1; a[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            a[i] = a[i-1] + a[i-2];
        }
        
        // the result is a[n].
        int result = a[n];
        delete[] a;
        return result;
    }

    void test() {
        assert(climbStairs(1) == 1 );
        assert(climbStairs(2) == 2 );
        assert(climbStairs(3) == 3 );
        assert(climbStairs(5) == 8 );
        assert(climbStairs(25) == 121393 );
        assert(climbStairs(45) == 1836311903 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}