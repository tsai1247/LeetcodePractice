#include "Template.cpp"

class BucketSort : public SortAlgorithm
{
private:
    const int BUCKET_NUM = 10;

public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    BucketSort* Sort() 
    {
        bucketsort(arr, n);
        return this;
    }

    void bucketsort(vector<int>& arr, int n) 
    {
        int start = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(start > arr[i])
            {
                start = arr[i];
            }
        }
        
        int end = -1;
        for(int i=0; i<n; i++)
        {
            if(end < arr[i])
            {
                end = arr[i];
            }
        }

        if(start >= end)    return;
        
        vector<int> buckets[BUCKET_NUM];
        int bucket_size = (end - start) / BUCKET_NUM + 1;

        for(int i=0; i<n; i++)
        {
            int index = (arr[i] - start) / bucket_size;
            buckets[index].push_back(arr[i]);
        }

        for(int i=0; i<BUCKET_NUM; i++)
        {
            bucketsort(buckets[i], buckets[i].size());
        }

        arr.clear();
        for(int i=0; i<BUCKET_NUM; i++)
        {
            for(int j=0; j<buckets[i].size(); j++)
            {
                arr.push_back(buckets[i][j]);
            }
        }
    }
};

int main()
{
    (new BucketSort()) -> Test();
    return 0;
}