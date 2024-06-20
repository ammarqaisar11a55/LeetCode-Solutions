class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {

        gain.insert(gain.begin(), 0);

        for (int i = 1; i < gain.size(); i++)
        {
            gain[i] = gain[i - 1] + gain[i];
        }

        return *max_element(gain.begin(), gain.end());
    }
};