#include<bits/stdc++.h>
#include<cassert>
#include<windows.h>
using namespace std; 

vector<int> arr2;
void routine(void *a)
{
    int n = *(int *) a;

    Sleep(n*10);
    arr2.push_back(n);
    return;
}

vector<int> SleepSort(vector<int>& arr, int n) {
    HANDLE threads[n];

    // Create the threads for each of the input array elements
    for (int i = 0; i < n; i++)
        threads[i] = (HANDLE)_beginthread(&routine, 0,  &arr[i]);

    // Process these threads
    WaitForMultipleObjects(n, threads, TRUE, INFINITE);
    return arr2;
}

int main()
{
    vector<int> arr{70, 72, 9, 61, 80, 52, 87, 73, 61, 2, 48};
    int n = arr.size();

    arr = BubbleSort(arr, n);

    // assert
    for(int i=0; i<n-1; i++)
    {
        assert( arr[i] <= arr[i+1] && "Not correct answer.");
        cout << arr[i] << ", ";
    }
    cout << arr[n-1] << endl;
    cout << "Success" << endl;

    return 0;
}