#include "Template.cpp"

class QuickSort : public SortAlgorithm
{
public: 
    // Given vector<int>& arr, int n
    // Given Swap(int& a, int& b)
    QuickSort* Sort() 
    {
        quicksort(0, n-1);

        return this;
    }

    void quicksort(int start, int end)
    {
        if(start >= end) return;

        // sort betwwen arr[start] and arr[end], including both side
        int pivot = arr[end];
        int left = start, right = end - 1;
        while(true)
        {
            while(arr[left] < pivot) left++;
            while(arr[right] > pivot) right--;

            if(left >= right)
                break;

            Swap(arr[left], arr[right]);
        }

        Swap(arr[left], arr[end]);
        quicksort(start, left - 1);
        quicksort(left + 1, end);

        return;        
    }
};

int main()
{
    (new QuickSort()) -> Test();
    return 0;
}