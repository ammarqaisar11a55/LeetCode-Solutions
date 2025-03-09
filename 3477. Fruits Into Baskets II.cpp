class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for (int i = 0; i < fruits.size(); i++)
    {
        int Current_Fruit = fruits[i];

        for (int j = 0; j < baskets.size(); j++)
        {
            if (baskets[j] != -1)
                if (Current_Fruit <= baskets[j])
                {
                    //cout<<Current_Fruit<<" Placed in "<<baskets[j]<<endl;
                    baskets[j] = -1;

                    break;
                }
        }
    }

    return baskets.size() - count(baskets.begin(),baskets.end(),-1);
    }
};
