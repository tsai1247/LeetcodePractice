#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public: 
    bool traverseAnIsland(int row, int column, vector<vector<int>>& grid, 
        vector<vector<bool>>& isvisited)
    {
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[row].size())
            return false;
        if(isvisited[row][column] || grid[row][column] == 1)
            return true;
        
        bool result = true;
        isvisited[row][column] = true;
        
        result &= traverseAnIsland(row-1, column  , grid, isvisited);
        result &= traverseAnIsland(row+1, column  , grid, isvisited);
        result &= traverseAnIsland(row  , column-1, grid, isvisited);
        result &= traverseAnIsland(row  , column+1, grid, isvisited);
        return result;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> isvisited(grid.size(), *(new vector<bool>(grid[0].size(), false)));
        
        int cnt = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(!isvisited[i][j] && grid[i][j] == 0)
                {
                    cnt += traverseAnIsland(i, j, grid, isvisited);
                }
            }
        }
        
        return cnt;
    }
    
    void test() {
        assert(closedIsland( *(new vector<int>( {2,7,11,15} )) ) == expected answer );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}