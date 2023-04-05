#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int tribonacci(int n) {
        int trib[4] = {0, 1, 1};
        
        // if n <= 2, return corresponding inital value
        if(n <= 2)
            return trib[n];
        
        // else, iterate for n-2 times.
        for(int i=3; i<=n; i++)
        {
            trib[3] = trib[0] + trib[1] + trib[2];
            trib[0] = trib[1];
            trib[1] = trib[2];
            trib[2] = trib[3];
        }
        
        // the result will be trib[3], the value we got at the last iteration.
        return trib[3];
    }

    void test() {
        assert(tribonacci( 0 ) == 0 );
        assert(tribonacci( 1 ) == 1 );
        assert(tribonacci( 2 ) == 1 );
        assert(tribonacci( 3 ) == 2 );
        assert(tribonacci( 4 ) == 4 );
        assert(tribonacci( 6 ) == 13 );
        assert(tribonacci( 37 ) == 2082876103 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}