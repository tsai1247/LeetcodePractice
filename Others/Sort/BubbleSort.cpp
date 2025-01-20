#include "Template.cpp"

class BubbleSort : public SortAlgorithm
{
public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    BubbleSort* Sort() 
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                }
            }
        }

        return this;
    }
};

int main()
{
    (new BubbleSort()) -> Test();
    return 0;
}