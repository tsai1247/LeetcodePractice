#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(m*n)
// Space complexity: O(m*n) for function call
class Solution {
public:
    void visit(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int column)
    {
        if(row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size())
            return;
        
        if(!visited[row][column] && grid[row][column] == '1')
        {
            visited[row][column] = true;
        
            // visit 4 directions
            visit(grid, visited, row-1, column);
            visit(grid, visited, row+1, column);
            visit(grid, visited, row, column-1);
            visit(grid, visited, row, column+1);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false) );
        
        int cnt = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    visit(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void test() {
        assert(
            numIslands( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'1', '1', '1', '1', '0'})),
                    *(new vector<char>({'1', '1', '0', '1', '0'})),
                    *(new vector<char>({'1', '1', '0', '0', '0'})),
                    *(new vector<char>({'0', '0', '0', '0', '0'})),
                }))
            )
            == 1
        );

        assert(
            numIslands( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'1', '1', '0', '0', '0'})),
                    *(new vector<char>({'1', '1', '0', '0', '0'})),
                    *(new vector<char>({'0', '0', '1', '0', '0'})),
                    *(new vector<char>({'0', '0', '0', '1', '1'})),
                }))
            )
            == 3
        );

        assert(
            numIslands( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'1'})),
                }))
            )
            == 1
        );

        assert(
            numIslands( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'0'})),
                }))
            )
            == 0
        );

        assert(
            numIslands( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'0'})),
                    *(new vector<char>({'1'})),
                    *(new vector<char>({'0'})),
                    *(new vector<char>({'1'})),
                    *(new vector<char>({'0'})),
                    *(new vector<char>({'1'})),
                }))
            )
            == 3
        );


        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}