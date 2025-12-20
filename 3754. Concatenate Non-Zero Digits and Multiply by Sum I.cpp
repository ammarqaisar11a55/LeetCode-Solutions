class Solution {
public:
    long long sumAndMultiply(int n) {
        long long int x = 0;

    string nn = to_string(n);
    long long int sum = 0;

    for(char c : nn)
    {
        if(c!='0')
        {
            x = x*10 + (c-'0');
            sum += (c-'0');
        }
    }

    return x * sum;
    }
};
