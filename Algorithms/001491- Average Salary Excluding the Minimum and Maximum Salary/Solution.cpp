#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0, minimum = INT_MAX, maximum = 0;
        for(auto& num : salary)
        {
            sum += num;
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }
        return (sum - minimum - maximum)*1.0 / (salary.size()-2);
    }

    void test() {
        assert(average( *(new vector<int>( {1000, 2000, 3000} )) ) == 2000 );
        assert(average( *(new vector<int>( {4000, 3000, 1000, 2000} )) ) == 2500 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}