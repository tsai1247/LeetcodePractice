#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    void fillChars(vector<char>& chars, int& cur_index, char current, int count)
    {
        // fill the last character and count. 
        if(count > 0)
        {
            // fill the character
            chars[cur_index++] = current;
            
            // fill the count
            if(count > 1)
            {
                string s = to_string(count);
                for(auto c : s)
                {
                    chars[cur_index++] = c;
                }
            }
        }
    }

    int compress(vector<char>& chars) {
        char current = '\0';
        int count = 0;
        int cur_index = 0;
        for(auto cval : chars)
        {
            if(current != cval)
            {
                // fill chars
                fillChars(chars, cur_index, current, count);

                // update current char
                current = cval;
                count = 1;
            }
            else 
            {
                count++;
            }
        }
        // fill chars
        fillChars(chars, cur_index, current, count);

        return cur_index;
    }

    void test() {
        vector<char> testcase = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
        assert(compress( testcase ) == 6 );
        assert(*(new vector<char>( testcase.begin(), testcase.begin() + 6 )) == *(new vector<char>( {'a', '2', 'b', '2', 'c', '3'} )));

        testcase = {'a'};
        assert(compress( testcase ) == 1 );
        assert(*(new vector<char>( testcase.begin(), testcase.begin() + 1 )) == *(new vector<char>( {'a'} )));

        assert(testcase == *(new vector<char>( {'a'} )));
        
        testcase = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
        assert(compress( testcase ) == 4 );
        assert(*(new vector<char>( testcase.begin(), testcase.begin() + 4 )) == *(new vector<char>( {'a', 'b', '1', '2'} )));
        
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}