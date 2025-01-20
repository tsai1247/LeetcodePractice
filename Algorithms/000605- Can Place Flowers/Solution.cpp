#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    int traverse(int row, int column, vector<vector<int>>& grid, vector<vector<bool>>& isvisited)
    {
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[row].size())
            return 0;
        if(isvisited[row][column] || grid[row][column] == 0)
            return 0;
        
        isvisited[row][column] = true;
        int result = 1;
        result += traverse(row-1, column  , grid, isvisited);
        result += traverse(row+1, column  , grid, isvisited);
        result += traverse(row  , column-1, grid, isvisited);
        result += traverse(row  , column+1, grid, isvisited);
        
        return result;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> isvisited(grid.size(), *(new vector<bool>(grid[0].size(), false)));
        
        int maximum = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(!isvisited[i][j])
                {
                    maximum = max(maximum, traverse(i, j, grid, isvisited));
                }
            }
        }
        
        return maximum;
    }
    
    void test() {
        assert(maxAreaOfIsland( *(new vector<int>( {2,7,11,15} )) ) == expected answer );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}