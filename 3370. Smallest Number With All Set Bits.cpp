class Solution {
public:
    bool check(int n)
    {
        vector<int>bits;

        while(n>0)
        {
            bits.push_back(n%2);
            n/=2;

        }


        return count(bits.begin(),bits.end(),1) == bits.size() ? true : false;
    }

    int smallestNumber(int n) {

        int res;

        while(true)
        {
            if(check(n))
            {
                res = n;
                break;
            }
            else
            {
                n++;
            }
        }


        return  res; 

    }
};
