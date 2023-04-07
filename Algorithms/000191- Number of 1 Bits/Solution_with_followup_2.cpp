#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(1)
// Space complexity: O(n)
// Note that the relationship between time/space complexity is: spend ((log n) / k) time with 2^k space.
// For a 32-bit integer, we can spend 2^4 spaces and do 8 operations, or spend 2^8 spaces and do just 4 operations.
// Contrast with other two solution, it takes lower avarage time with some spaces.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result_4_bits[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
        return (
                result_4_bits[  n      &0xF ]
            +   result_4_bits[ (n>>4)  &0xF ]
            +   result_4_bits[ (n>>8)  &0xF ]
            +   result_4_bits[ (n>>12) &0xF ]
            +   result_4_bits[ (n>>16) &0xF ]
            +   result_4_bits[ (n>>20) &0xF ]
            +   result_4_bits[ (n>>24) &0xF ]
            +   result_4_bits[ (n>>28) &0xF ]
        );
    }
    void test() {
        assert(hammingWeight( 11 ) == 3 );
        assert(hammingWeight( 128 ) == 1 );
        assert(hammingWeight( 2147483647 ) == 31 );
        assert(hammingWeight( -3 ) == 31 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}