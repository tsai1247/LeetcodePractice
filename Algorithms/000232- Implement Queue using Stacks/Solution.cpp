#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n) for push, O(1) for others
// Space complexity: O(n)
class MyQueue {
private:
    stack<int> st;

public:
    MyQueue() {
    }
    
    void push(int x) {
        stack<int> tmp;
        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        tmp.push(x);
        
        while(!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        int ret = peek();
        st.pop();
        return ret;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }

    void test() {
        MyQueue queue;
        queue.push(1);
        queue.push(2);
        assert(queue.peek() == 1);
        assert(queue.pop() == 1);
        assert(queue.empty() == false);
        assert(queue.pop() == 2);
        assert(queue.empty() == true);
        cout<<"test succeeded.\n";
    }
};

int main()
{
    MyQueue().test();
}