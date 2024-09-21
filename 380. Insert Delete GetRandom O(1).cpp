class RandomizedSet
{
public:
    unordered_set<int> st;
    vector<int> values;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {

        if (st.find(val) != st.end())
            return false;

        st.insert(val);
        values.push_back(val);
        return true;
    }

    bool remove(int val)
    {

        if (st.find(val) == st.end())
            return false;

        st.erase(val);

        auto p = find(values.begin(), values.end(), val);

        *p = values.back();
        values.pop_back();

        return true;
    }

    int getRandom()
    {

        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */