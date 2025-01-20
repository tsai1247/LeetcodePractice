#include "Template.cpp"

class SelectionSort : public SortAlgorithm
{
public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    SelectionSort* Sort() 
    {
        for(int i=0; i<n; i++)
        {
            int index = i;
            for(int j=i; j<n; j++)
            {
                if(arr[index] > arr[j])
                {
                    index = j;
                }
            }
            Swap(arr[i], arr[index]);
        }

        return this;
    }
};

int main()
{
    (new SelectionSort()) -> Test();
    return 0;
}