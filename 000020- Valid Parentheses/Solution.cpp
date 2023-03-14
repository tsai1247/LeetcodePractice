#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n) (put all left parentheses into stack when the string is composed of all left parentheses.)
class Solution {
public:
    bool isMatch(char left, char right)
    {
        return (left == '(' && right == ')') 
            || (left == '[' && right == ']') 
            || (left == '{' && right == '}');
    }
    
    bool isLeft(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }
    
    bool isRight(char c)
    {
        return c == ')' || c == ']' || c == '}';
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(auto& c : s)
        {
            if(isLeft(c))
            {
                st.push(c);
            }
            else if(isRight(c) && !st.empty())
            {
                char left = st.top();
                if(isMatch(left, c))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        
        return st.empty();
    }

    void test() {
        assert(isValid("([]{()[]})") == true );
        assert(isValid("()[]{}") == true );
        assert(isValid("{[()]}") == true );
        assert(isValid("([{") == false );
        assert(isValid("]})") == false );
        assert(isValid("[][({})") == false );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}