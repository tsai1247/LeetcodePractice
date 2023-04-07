#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(log n)
// Space complexity: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            // cout<<left<<" "<<mid<<" "<<right<<endl;
            
            if(mid == 0)
            {
                left = mid + 1;
            }
            else if(mid == arr.size() - 1)
            {
                right = mid - 1;
            }
            else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1])
            {
                left = mid + 1;
            }
            else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1])
            {
                right = mid - 1;
            }
            else if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else
            {
                return -1;
            }
        }
        return -1;
    
    }

    void test() {
        assert(peakIndexInMountainArray( *(new vector<int>( {3,5,3,2,0} )) ) == 1 );
        assert(peakIndexInMountainArray( *(new vector<int>( {3,5,3} )) ) == 1 );
        assert(peakIndexInMountainArray( *(new vector<int>( {0,2,3,5,3} )) ) == 3 );
        assert(peakIndexInMountainArray( *(new vector<int>( {0,10,5,2} )) ) == 1 );
        assert(peakIndexInMountainArray( *(new vector<int>( {0,1,2,0} )) ) == 2 );
        cout<<"test succeeded.\n";
    }
};

int main()
{
    Solution().test();
}