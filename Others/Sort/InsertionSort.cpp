#include "Template.cpp"

class InsertionSort : public SortAlgorithm
{
public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    InsertionSort* Sort() 
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i; j>0; j--)
            {
                if(arr[j] < arr[j-1])
                {
                    Swap(arr[j], arr[j-1]);
                }
                else
                {
                    break;
                }
            }
        }

        return this;
    }
};

int main()
{
    (new InsertionSort()) -> Test();
    return 0;
}