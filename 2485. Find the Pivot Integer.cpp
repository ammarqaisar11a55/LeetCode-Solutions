class Solution {
public:
    int pivotInteger(int n) {
        int total_sum  = 0;

    for(int i = 1; i <= n; i++)
        total_sum += i;

    int left_sum = 0;

    for(int i = 1; i<=n; i++)
    {
        left_sum += i;

        if(left_sum == total_sum + i - left_sum)
            return i;
    }


    return -1;
    }
};
