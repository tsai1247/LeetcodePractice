#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)   (The problem is about the basic DP, so I didn't optimize it to O(1) with array size of 3)
class Solution {
public:
    int fib(int n) {
        int fibonacci[31] = {0, 1};
        
        for(int i=2; i<=n; i++)
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
        
        return fibonacci[n];
    }

    void test() {
        assert(fib(0) == 0 );
        assert(fib(1) == 1 );
        assert(fib(2) == 1 );
        assert(fib(3) == 2 );
        assert(fib(5) == 5 );
        assert(fib(30) == 832040 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}