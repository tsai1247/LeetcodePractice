#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(m*n)
// Space complexity: O(m*n) for function call. 
class Solution {
public:
    void Fill(vector<vector<int>>& image, int row, int column, int origin, int target)
    {
        if(row < 0 || row >= image.size() || column < 0 || column >= image[0].size())
            return;
        
        if(image[row][column] == origin)
        {
            image[row][column] = target;
            Fill(image, row-1, column, origin, target);
            Fill(image, row+1, column, origin, target);
            Fill(image, row, column-1, origin, target);
            Fill(image, row, column+1, origin, target);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            Fill(image, sr, sc, image[sr][sc], color);
        return image;
    }

    void test() {
        assert(
            floodFill( 
                *(new vector<vector<int>>({
                    *(new vector<int>({1, 1, 1})),
                    *(new vector<int>({1, 1, 0})),
                    *(new vector<int>({1, 0, 1}))
                })),
                1, 1, 2
            )
            == *(new vector<vector<int>>({
                    *(new vector<int>({2, 2, 2})),
                    *(new vector<int>({2, 2, 0})),
                    *(new vector<int>({2, 0, 1}))
                }))
        );

        assert(
            floodFill( 
                *(new vector<vector<int>>({
                    *(new vector<int>({0, 0, 0})),
                    *(new vector<int>({0, 0, 0}))
                })),
                0, 0, 0 
            )
            ==  *(new vector<vector<int>>({
                    *(new vector<int>({0, 0, 0})),
                    *(new vector<int>({0, 0, 0}))
                }))
        );
            
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}