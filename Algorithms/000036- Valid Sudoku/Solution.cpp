#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n^2) (the board size)
// Space complexity: O(n) (save n booleans in map at most) 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, bool> mp;
        // check all rows
        for(int row=0; row<9; row++)
        {
            for(int column = 0; column<9; column++)
            {
                if(board[row][column] == '.')
                    continue;
                if( mp[board[row][column]] )
                {
                    cout<<"row "<<row<<column<<endl;
                    return false;
                }
                else
                    mp[board[row][column]] = true;
            }
            mp.clear();
        }
        
        // check all columns
        for(int column=0; column < 9; column++)
        {
            for(int row=0; row<9; row++)
            {
                if(board[row][column] == '.')
                    continue;
                if( mp[board[row][column]] )
                {
                    cout<<"column "<<row<<column<<endl;
                    return false;
                }
                else
                    mp[board[row][column]] = true;
            }
            mp.clear();
        }
        
        // check all 3*3 chunks
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                // in chunk board[i*3:i*3+2][j*3:j*3+2]
                for(int row=i*3; row<i*3+3; row++)
                {
                    for(int column=j*3; column<j*3+3; column++)
                    {
                        if(board[row][column] == '.')
                            continue;
                        if( mp[board[row][column]] )
                        {
                            cout<<"chunk "<<row<<column<<endl;
                            return false;
                        }
                        else
                            mp[board[row][column]] = true;
                    }
                }
                mp.clear();
            }
        }
        return true;
    }

    void test() {
        assert(
            isValidSudoku( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'5','3','.','.','7','.','.','.','.'})),
                    *(new vector<char>({'6','.','.','1','9','5','.','.','.'})),
                    *(new vector<char>({'.','9','8','.','.','.','.','6','.'})),
                    *(new vector<char>({'8','.','.','.','6','.','.','.','3'})),
                    *(new vector<char>({'4','.','.','8','.','3','.','.','1'})),
                    *(new vector<char>({'7','.','.','.','2','.','.','.','6'})),
                    *(new vector<char>({'.','6','.','.','.','.','2','8','.'})),
                    *(new vector<char>({'.','.','.','4','1','9','.','.','5'})),
                    *(new vector<char>({'.','.','.','.','8','.','.','7','9'}))
                }))
            ) == true
        );
        assert(
            isValidSudoku( 
                *(new vector<vector<char>>({
                    *(new vector<char>({'8','3','.','.','7','.','.','.','.'})),
                    *(new vector<char>({'6','.','.','1','9','5','.','.','.'})),
                    *(new vector<char>({'.','9','8','.','.','.','.','6','.'})),
                    *(new vector<char>({'8','.','.','.','6','.','.','.','3'})),
                    *(new vector<char>({'4','.','.','8','.','3','.','.','1'})),
                    *(new vector<char>({'7','.','.','.','2','.','.','.','6'})),
                    *(new vector<char>({'.','6','.','.','.','.','2','8','.'})),
                    *(new vector<char>({'.','.','.','4','1','9','.','.','5'})),
                    *(new vector<char>({'.','.','.','.','8','.','.','7','9'}))
                }))
            ) == false
        );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}