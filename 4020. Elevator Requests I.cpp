class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int res = requests[0];

        for(int i = 1; i < requests.size(); i++)
        {
            if(requests[i] != requests[i - 1])
            {
                res += abs(requests[i] - requests[i - 1]);
            }
        }

        return res;

    }
};
