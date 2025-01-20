#include<bits/stdc++.h>
#include<cassert>
using namespace std; 

class SortAlgorithm
{
protected:
    vector<int> arr;
    int n;
    void Swap(int& a, int& b)
    {
        assert( (&arr[0] <= &a) && (&a <= &arr[n])  && "Index out of range.");
        assert( (&arr[0] <= &b) && (&b <= &arr[n])  && "Index out of range.");
        int tmp = a;
        a = b;
        b = tmp;
    }

    void Print()
    {
        for(int i=0; i<n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void Assert()
    {
        for(int i=0; i<n-1; i++)
        {
            assert( arr[i] <= arr[i+1] && "Not correct answer.");
        }
        cout << "Success" << endl;
    }

public:
    SortAlgorithm() 
    {
        arr = vector<int>{70, 72, 9, 61, 80, 52, 87, 73, 61, 2, 48};
        n = arr.size();
    }

    virtual SortAlgorithm* Sort() 
    {
        // TODO
        Swap(arr[0], arr[1]);
        Swap(arr[n-1], arr[n-2]);
        return this;
    }

    void Test()
    {
        Sort();
        Print();
        Assert();
    }

};
