class MinStack
{
public:
    stack<int> Normal;
    stack<int> Minis;
    int mini;

    MinStack()
    {
    }

    void push(int val)
    {
        Normal.push(val);
        if (Minis.empty() || Minis.top() >= val)
            Minis.push(val);
    }

    void pop()
    {
        if (Minis.top() == Normal.top())
            Minis.pop();
        Normal.pop();
    }

    int top()
    {
        return Normal.top();
    }

    int getMin()
    {
        return Minis.top();
    }
};