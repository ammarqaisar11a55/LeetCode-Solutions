class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> mp;

        for (int i : arr) {
            mp[i]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto [val, freq] : mp) {
            pq.push(freq);
        }

        while (true) {
            if (pq.empty() == false) {
                if (k - pq.top() >= 0) {
                    k -= pq.top();
                    pq.pop();
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        return (int)pq.size();
    }
};