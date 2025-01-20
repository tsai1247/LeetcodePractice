#include "Template.cpp"

class CountingSort : public SortAlgorithm
{
private:
    const int BUCKET_NUM = 10;

public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    CountingSort* Sort() 
    {
        if(n <= 0)  return this;
        int min = arr[0], max = arr[0];
        for(int i=1; i<n; i++)
        {
            if(min > arr[i])
            {
                min = arr[i];
            }
            
            if(max < arr[i])
            {
                max = arr[i];
            }
        }

        int size = max - min + 1;
        int count[size];
        for(int i=0; i<size; i++)
        {
            count[i] = 0;
        }

        for(auto i : arr)
        {
            count[i - min]++;
        }

        arr.clear();
        for(int i=0; i<size; i++)
        {
            while(count[i] > 0)
            {
                arr.push_back(i + min);
                count[i]--;
            }
        }

        return this;
    }

};

int main()
{
    (new CountingSort()) -> Test();
    return 0;
}