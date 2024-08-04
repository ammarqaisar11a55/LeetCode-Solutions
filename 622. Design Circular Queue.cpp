class MyCircularQueue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularQueue(int k)
    {
        arr = new int[k];
        size = k;
        front = rear = -1;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        if (rear == front)
        {
            rear = front = -1;
            return true;
        }

        front = (front + 1) % size;
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[front];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty()
    {
        return (rear == -1 && front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }
};