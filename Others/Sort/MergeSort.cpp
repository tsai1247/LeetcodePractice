#include "Template.cpp"

class MergeSort : public SortAlgorithm
{
public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    MergeSort* Sort() 
    {
        arr = mergesort(0, n-1);
        return this;
    }

    vector<int> mergesort(int start, int end)
    {
        // start >= end, then no need to sort
        if(start >= end)    return arr;

        // sort from start to mid, and mid+1 to end
        // save results into arr1[start:mid] and arr2[mid+1:end]
        int mid = (start + end) / 2;
        vector<int> arr1 = mergesort(start, mid);
        vector<int> arr2 = mergesort(mid+1, end);

        // merge arr1[start:mid] and arr2[mid1:end] into arr[start:end]
        int i = start, j = mid + 1, cur = start;
        while(i <= mid && j <= end)
        {
            if(arr1[i] < arr2[j])
            {
                arr[start++] = arr1[i++];
            }
            else
            {
                arr[start++] = arr2[j++];
            }
        }

        while(i <= mid)
        {
            arr[start++] = arr1[i++];
        }

        while(j <= end)
        {
            arr[start++] = arr2[j++];
        }

        return arr;
    }
};

int main()
{
    (new MergeSort()) -> Test();
    return 0;
}