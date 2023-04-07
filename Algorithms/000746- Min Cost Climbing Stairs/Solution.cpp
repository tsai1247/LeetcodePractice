#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n) (it can be optimized to O(3))
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // a[i] means the minimum cost to reach i-step
        int* a = new int[cost.size()+1];
        
        // inital: we can start from index 0 or 1, so the cost to reach index 0/1 are 0.
        a[0] = 0; a[1] = 0;
        
        // recurrence relation: 
        // we can reach a[i-2], spend cost[i-2] and walk 2 steps the top, 
        // or reach a[i-1], spend cost[i-1] and walk 1 step the top, 
        for(int i=2; i<=cost.size(); i++)
        {
            a[i] = min(a[i-2] + cost[i-2], a[i-1] + cost[i-1]);
        }
        
        // the result is a[n]
        int result = a[cost.size()];
        delete[] a;
        return result;
    }

    void test() {
        assert(minCostClimbingStairs( *(new vector<int>( {10,15,20} )) ) == 15 );
        assert(minCostClimbingStairs( *(new vector<int>( {1,100,1,1,1,100,1,1,100,1} )) ) == 6 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}