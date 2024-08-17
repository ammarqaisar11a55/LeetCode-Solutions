class MyHashMap
{
public:
    vector<int> N;
    int size;

    MyHashMap()
    {

        size = 1e6 + 1;
        N.resize(size);
        fill(N.begin(), N.end(), -1);
    }

    void put(int key, int value)
    {

        N[key] = value;
    }

    int get(int key)
    {

        return N[key];
    }

    void remove(int key)
    {
        N[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */