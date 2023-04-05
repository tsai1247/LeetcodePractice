#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low + 1) / 2 + ( high %2 && low % 2);
    }

    void test() {
        assert(countOdds( 3, 7 )  == 3 );
        assert(countOdds( 3, 8 )  == 3 );
        assert(countOdds( 4, 7 )  == 2 );
        assert(countOdds( 4, 8 )  == 2 );
        assert(countOdds( 1, 1 )  == 1 );
        assert(countOdds( 2, 2 )  == 0 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}