#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        bool canPlace = true;
        for(int i=0; i<flowerbed.size(); i++) {
            if(flowerbed[i] == 1){
                canPlace = false;
            }
            else if (canPlace && (i+1 == flowerbed.size() || flowerbed[i+1] == 0)) 
            {
                n--;
                canPlace = false;
            }
            else 
            {
                canPlace = true;
            }
            if (n == 0)
            {
                break;
            }
        }
        return n == 0;
    }

    void test() {
        assert(canPlaceFlowers( *(new vector<int>({1,0,0,0,1})), 1 ) == true );
        assert(canPlaceFlowers( *(new vector<int>({1,0,0,0,1})), 2 ) == false );
        assert(canPlaceFlowers( *(new vector<int>({1,0,0,0,1,0,0})), 2 ) == true );
        assert(canPlaceFlowers( *(new vector<int>({1,0,0,0,1})), 0 ) == true );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}