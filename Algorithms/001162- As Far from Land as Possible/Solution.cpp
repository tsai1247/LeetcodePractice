#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>> distances(grid.size(), *(new vector<int>(grid[0].size(), -1)));
        vector<vector<bool>> isvisited(grid.size(), *(new vector<bool>(grid[0].size(), false)));
        
        
        queue<pair<pair<int, int>, int>> qu;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++)
                if(grid[i][j] == 1)
                    qu.push(make_pair(make_pair(i, j), 0));
        int distance = -1;
        while(!qu.empty())
        {
            auto [node, value] = qu.front(); qu.pop();
            auto [i, j] = node;
            if(i < 0 || i >= grid.size() || j <0 || j >= grid[i].size())
                continue;
            if(isvisited[i][j])
                continue;

            isvisited[i][j] = true;
            distances[i][j] = value;
            qu.push(make_pair(make_pair(i+1, j  ), value+1));
            qu.push(make_pair(make_pair(i-1, j  ), value+1));
            qu.push(make_pair(make_pair(i  , j-1), value+1));
            qu.push(make_pair(make_pair(i  , j+1), value+1));
            
            if(grid[i][j] == 0)
                distance = max(distances[i][j], distance);
        }
        
        return distance;
    }

    void test() {
        assert(maxDistance( *(new vector<int>( {2,7,11,15} )) ) == expected answer );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}