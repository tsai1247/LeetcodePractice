#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(1) for push and empty.  O(n) for n times of pop and top.
// Space complexity: O(n)
// flip the all Stack into Queue when Queue is empty.  This way, we will flip each element exactly once.
class MyQueue {
private:
    stack<int> Queue;
    stack<int> Stack;
    int flip()
    {
        while(!Stack.empty())
        {
            Queue.push(Stack.top());
            Stack.pop();
        }
        return Queue.top();
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        Stack.push(x);
    }
    
    int pop() {
        if(Queue.empty())
            flip();
        int ret = Queue.top();
        Queue.pop();
        return ret;
    }
    
    int peek() {
        if(Queue.empty())
            return flip();
        else
            return Queue.top();
    }
    
    bool empty() {
        return Queue.empty() && Stack.empty();
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