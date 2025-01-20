#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
public:
    bool traverse(int row, int column, vector<vector<int>>& grid1, vector<vector<int>>& grid2, 
                  vector<vector<bool>>& isvisited)
    {
        if(row < 0 || row >= grid1.size() || column < 0 || column >= grid1[row].size() )
            return true;
        if(isvisited[row][column] || grid2[row][column] == 0)
            return true;
        if(grid2[row][column] != grid1[row][column])
            return false;
        
        bool result = true;
        isvisited[row][column] = true;
        result &= traverse(row-1, column  , grid1, grid2, isvisited);
        result &= traverse(row+1, column  , grid1, grid2, isvisited);
        result &= traverse(row  , column-1, grid1, grid2, isvisited);
        result &= traverse(row  , column+1, grid1, grid2, isvisited);
        
        return result;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>> isvisited(grid1.size(), *(new vector<bool>(grid1[0].size(), false)));
        
        int cnt = 0;
        for(int i=0; i<grid1.size(); i++)
        {
            for(int j=0; j<grid1[i].size(); j++)
            {
                if(!isvisited[i][j] && grid1[i][j] == 1 && grid2[i][j] == 1)
                {
                    cnt += traverse(i, j, grid1, grid2, isvisited);
                }
            }
        }
        
        return cnt;
    }

    void test() {
        assert(countSubIslands( *(new vector<int>( {2,7,11,15} )) ) == expected answer );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}