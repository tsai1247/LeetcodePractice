#include "Template.cpp"

class CocktailSort : public SortAlgorithm
{
public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    CocktailSort* Sort() 
    {
        int left = 0, right = n-1;

        bool sorted = false;
        while(!sorted)
        {
            sorted = true;
            for(int i=left; i<right; i++)
            {
                if(arr[i] > arr[i+1])
                {
                    Swap(arr[i], arr[i+1]);
                    sorted = false;
                }
            }
            right--;

            for(int i=right; i>left; i--)
            {
                if(arr[i-1] > arr[i])
                {
                    Swap(arr[i-1], arr[i]);
                    sorted = false;
                }
            }
            left++;
        }
        return this;
    }
};

int main()
{
    (new CocktailSort()) -> Test();
    return 0;
}