#include<bits/stdc++.h>
#include "../../Concurrency.h"
using namespace std;

// Time complexity: O(   )
// Space complexity: O(   )
class Foo {
private: 
    function<void()> printFirst = [](){ cout<<"first"; };
    function<void()> printSecond = [](){ cout<<"second"; };
    function<void()> printThird = [](){ cout<<"third"; };

    std::mutex mtx;
    std::condition_variable cv;
    int cur = 1;

public:
    Foo() {
        std::thread t1(first, printFirst);
        std::thread t2(second, printSecond);
        std::thread t3(third, printThird);

        t1.join(); t2.join(); t3.join();
    }
    
    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lck(mtx);
        while (cur != 1) cv.wait(lck);

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cur++;
        
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lck(mtx);
        while (cur != 2) cv.wait(lck);
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cur++;
        
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck(mtx);
        while (cur != 3) cv.wait(lck);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        cur++;
        
        cv.notify_all();
    }

    void test() {
        for(int i=0; i<10; i++)
            Foo();
        cout<<"test done.\n";
    }
};

int main()
{
    Foo().test();
}