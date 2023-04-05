#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *                1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
private: 
    int n = 10, pick = 6;
    void set(int n, int pick)
    {
        this->n = n;
        this->pick = pick;
    }
    int guess(int num)
    {
        if(num < pick)
            return 1;
        if(num > pick)
            return -1;
        return 0;
    }

public:
    int guessNumber(int n) {
        unsigned int left = 1, right = n;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int sol = guess(mid);
            if(sol == 1)
            {
                left = mid + 1;
            }
            else if(sol == -1)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }


    void test() {
        set(10, 6);
        assert(guessNumber(10) == 6 );

        set(10, 10);
        assert(guessNumber(10) == 10 );
        
        set(17, 1);
        assert(guessNumber(17) == 1 );

        set(2126753390, 1702766719);
        assert(guessNumber(2126753390) == 1702766719 );

        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}