class ProductOfNumbers
{
public:
    vector<int> n;
    ProductOfNumbers()
    {
        n.push_back(1);
    }

    void add(int num)
    {
        if (num == 0)
        {
            n.clear();
            n.push_back(1);
        }
        else
        {
            n.push_back(n.back() * num);
        }
    }

    int getProduct(int k)
    {

        if (k > n.size() - 1)
            return 0;

        return n.back() / n[n.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */