#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    int traverseAnIsland(int row, int column, vector<vector<int>>& grid, 
                         vector<vector<bool>>& isvisited)
    {
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size())
            return -250001;
        if(isvisited[row][column] || grid[row][column] == 0)
            return 0;
        
        isvisited[row][column] = true;
        int result = 1;
        
        result += traverseAnIsland(row-1, column  , grid, isvisited);
        result += traverseAnIsland(row+1, column  , grid, isvisited);
        result += traverseAnIsland(row  , column-1, grid, isvisited);
        result += traverseAnIsland(row  , column+1, grid, isvisited);
        
        return result;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> isvisited(grid.size(), *(new vector<bool>(grid[0].size(), false)));
        
        int cnt = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(!isvisited[i][j] && grid[i][j] == 1)
                {
                    cnt += max(0, traverseAnIsland(i, j, grid, isvisited));
                }
            }
        }
        return cnt;
    }

    void test() {
        assert(numEnclaves( *(new vector<int>( {2,7,11,15} )) ) == expected answer );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}