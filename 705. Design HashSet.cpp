class MyHashSet
{
public:
    vector<int> HashSet;
    int size;

    MyHashSet()
    {
        size = 1e6 + 1;
        HashSet.resize(size);
        fill(HashSet.begin(), HashSet.end(), -1);
    }

    void add(int key)
    {
        HashSet[key] = key;
    }

    void remove(int key)
    {
        HashSet[key] = -1;
    }

    bool contains(int key)
    {
        if (HashSet[key] == -1)
            return false;

        return true;
    }
};