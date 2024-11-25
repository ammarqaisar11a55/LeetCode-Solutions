class MyQueue
{
public:
    stack<int> stk;
    MyQueue()
    {
    }

    void push(int x)
    {
        stack<int> temp;

        while (!stk.empty())
        {
            temp.push(stk.top());
            stk.pop();
        }

        stk.push(x);

        while (!temp.empty())
        {
            stk.push(temp.top());
            temp.pop();
        }
    }

    int pop()
    {
        int top = stk.top();
        stk.pop();
        return top;
    }

    int peek()
    {
        return stk.top();
    }

    bool empty()
    {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */