class Solution
{
public:
    int CalculatePow(int N)
    {
        int Counts = 0;

        while (N != 1)
        {
            if (N & 1)
            {
                N = 3 * N + 1;
            }
            else
            {
                N = N / 2;
            }

            Counts++;
        }

        return Counts;
    }

    int getKth(int lo, int hi, int k)
    {
        unordered_map<int, int> Elements_Power;

        vector<int> elements;

        for (int i = lo; i <= hi; i++)
        {
            elements.push_back(i);
            Elements_Power[i] = CalculatePow(i);
        }

        sort(elements.begin(), elements.end(), [&](int a, int b)
             {
                 if (Elements_Power[a] == Elements_Power[b])
                     return a < b;

                 return Elements_Power[a] < Elements_Power[b];
             });

        return elements[k - 1];
    }
};