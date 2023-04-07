#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n) // The number of digits for n.
// Space complexity: O(1)
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while(n != 0)
        {
            int cur = n%10;
            product *= cur;
            sum += cur;
            n /= 10;
        }
        return product - sum;
    }

    void test() {
        assert(subtractProductAndSum( 1 ) == 0 );
        assert(subtractProductAndSum( 10 ) == -1 );
        assert(subtractProductAndSum( 234 ) == 15 );
        assert(subtractProductAndSum( 4421 ) == 21 );
        assert(subtractProductAndSum( 99999 ) == 59004 );
        assert(subtractProductAndSum( 100000 ) == -1 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}