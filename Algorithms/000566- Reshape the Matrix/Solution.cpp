#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(r*c)
// Space complexity: O(r*c)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // check the format is possible
        if(mat.size() * mat[0].size() != r * c)
            return mat;
        
        vector<vector<int>> ret;
        vector<int> cur;

        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[i].size(); j++)
            {
                cur.push_back(mat[i][j]);
                if(cur.size() == c)
                {
                    ret.push_back(cur);
                    cur.clear();
                }
            }
        }
        return ret;
    }

    void test() {
        assert(
            matrixReshape( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1, 2} )),
                    *(new vector<int>( {3, 4} ))
                })), 
                1, 4
            )
            == *(new vector<vector<int>>({
                    *(new vector<int>( {1, 2, 3, 4} )),
                }))
        );

        assert(
            matrixReshape( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1, 2} )),
                    *(new vector<int>( {3, 4} ))
                })), 
                2, 4
            )
            == *(new vector<vector<int>>({
                    *(new vector<int>( {1, 2} )),
                    *(new vector<int>( {3, 4} ))
                }))
        );

        assert(
            matrixReshape( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1} )),
                })), 
                1, 1
            )
            == *(new vector<vector<int>>({
                    *(new vector<int>( {1} )),
                }))
        );

        assert(
            matrixReshape( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1} )),
                    *(new vector<int>( {2} )),
                })), 
                1, 2
            )
            == *(new vector<vector<int>>({
                    *(new vector<int>( {1, 2} )),
                }))
        );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}