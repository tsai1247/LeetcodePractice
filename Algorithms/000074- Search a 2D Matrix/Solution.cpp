#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log(m*n))
// Space complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix[0].size();
        int left = 0, right = matrix.size() * row_size - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(matrix[mid/row_size][mid%row_size] > target)
            {
                right = mid - 1;
            }
            else if(matrix[mid/row_size][mid%row_size] < target)
            {
                left = mid + 1;
            }
            else // if(matrix[mid/row_size][mid%row_size] == target)
            {
                return true;
            }
        }
        return false;
    }

    void test() {
        assert(
            searchMatrix( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1,3,5,7} )),
                    *(new vector<int>( {10,11,16,20} )),
                    *(new vector<int>( {23,30,34,60} )) 
                })),
                3
            )
            == true
        );

        assert(
            searchMatrix( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1,3,5,7} )),
                    *(new vector<int>( {10,11,16,20} )),
                    *(new vector<int>( {23,30,34,60} )) 
                })),
                0
            )
            == false
        );

        assert(
            searchMatrix( 
                *(new vector<vector<int>>({
                    *(new vector<int>( {1,3,5,7} )),
                    *(new vector<int>( {10,11,16,20} )),
                    *(new vector<int>( {23,30,34,60} )) 
                })),
                61
            )
            == false
        );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}