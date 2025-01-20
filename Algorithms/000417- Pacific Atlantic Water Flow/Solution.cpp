#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Solution {
private:
const int None      = 0x00;
const int Pacific   = 0x01;
const int Atlantic  = 0x10;
const int Both      = 0x11;
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result(heights.size(), *(new vector<int>(heights[0].size(), None)));
        
        
        
        // Pacific Ocean
        {
            vector<vector<bool>> isvisited(heights.size(), *(new vector<bool>(heights[0].size(), false)));
            queue<pair<int, int>> qu;
            for(int i=0; i<heights.size(); i++)
                qu.push(make_pair(i, 0));
            for(int j=0; j<heights[0].size(); j++)
                qu.push(make_pair(0, j));
            
            while(!qu.empty())
            {
                auto [i, j] = qu.front(); qu.pop();
                if(i < 0 || i >= heights.size() || j < 0 || j >= heights[i].size())
                    continue;
                
                if(isvisited[i][j])
                    continue;
                
                result[i][j] |= Pacific;
                isvisited[i][j] = true;
                auto cur = heights[i][j];
                if(i > 0 && cur <= heights[i-1][j])
                    qu.push(make_pair(i-1, j));
                if(j > 0 && cur <= heights[i][j-1])
                    qu.push(make_pair(i, j-1));
                if(i < heights.size()-1 && cur <= heights[i+1][j])
                    qu.push(make_pair(i+1, j));
                if(j < heights[i].size()-1 && cur <= heights[i][j+1])
                    qu.push(make_pair(i, j+1));
            }
        }
        
        // Atlantic Ocean
        {
            vector<vector<bool>> isvisited(heights.size(), *(new vector<bool>(heights[0].size(), false)));
            queue<pair<int, int>> qu;
            for(int i=0; i<heights.size(); i++)
                qu.push(make_pair(i, heights[0].size()-1));
            for(int j=0; j<heights[0].size(); j++)
                qu.push(make_pair(heights.size()-1, j));
            
            while(!qu.empty())
            {
                auto [i, j] = qu.front(); qu.pop();
                if(i < 0 || i >= heights.size() || j < 0 || j >= heights[i].size())
                    continue;
                
                if(isvisited[i][j])
                    continue;
                
                result[i][j] |= Atlantic;
                isvisited[i][j] = true;
                auto cur = heights[i][j];
                if(i > 0 && cur <= heights[i-1][j])
                    qu.push(make_pair(i-1, j));
                if(j > 0 && cur <= heights[i][j-1])
                    qu.push(make_pair(i, j-1));
                if(i < heights.size()-1 && cur <= heights[i+1][j])
                    qu.push(make_pair(i+1, j));
                if(j < heights[i].size()-1 && cur <= heights[i][j+1])
                    qu.push(make_pair(i, j+1));
            }
        }
        
        vector<vector<int>> ret;
        for(int i=0; i<result.size(); i++)
        {
            for(int j=0; j<result[i].size(); j++)
            {
                cout << result[i][j] << " ";
                if(result[i][j] == Both)
                    ret.push_back(*(new vector<int>({i, j})));
            }
            cout<<endl;
        }
        return ret;
    }

    void test() {
        assert(pacificAtlantic
( *(new vector<int>( {2,7,11,15} )) ) == expected answer );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}