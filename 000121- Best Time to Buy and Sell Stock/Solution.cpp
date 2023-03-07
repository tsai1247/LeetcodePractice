#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, profit = 0;
        for(auto& price : prices)
        {
            if(profit < (price - min))
            {
                profit = price - min;
            }
            if(min > price)
            {
                min = price;
            }
        }
        return profit;
    }
    void test() {
        assert(maxProfit( *(new vector<int>( {1} )) ) == 0 );
        assert(maxProfit( *(new vector<int>( {7,1,5,3,6,4} )) ) == 5 );
        assert(maxProfit( *(new vector<int>( {7,6,4,3,1} )) ) == 0 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}