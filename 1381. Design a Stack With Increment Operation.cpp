class CustomStack
{
public:
    int *Arr;
    int current_index;
    int size;

    CustomStack(int maxSize)
    {
        Arr = new int[maxSize];
        current_index = -1;
        size = maxSize;
    }

    void push(int x)
    {
        if (current_index < size - 1)
        {
            current_index++;
            Arr[current_index] = x;
        }
    }

    int pop()
    {
        if (current_index >= 0)
        {
            int result = Arr[current_index];
            current_index--;
            return result;
        }
        else
            return -1;
    }

    void increment(int k, int val)
    {
        if (current_index + 1 < k)
        {
            for (int i = 0; i < current_index + 1; i++)
                Arr[i] += val;
        }
        else
        {
            for (int i = 0; i < k; i++)
                Arr[i] += val;
        }
    }
};
