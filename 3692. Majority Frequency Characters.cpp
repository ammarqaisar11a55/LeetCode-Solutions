class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int>freq;

    for(char c : s)
    {
        freq[c]++;
    }

    unordered_map<int,vector<char>>groups;

    int majority_group = INT_MIN;

    for(auto x: freq)
    {
        groups[x.second].push_back(x.first);
        majority_group = max((int)groups[x.second].size(),majority_group);
    }

    vector<char>res;
    int max_freq = INT_MIN;

    for(auto x : groups)
    {
        if(x.second.size() == majority_group && x.first > max_freq)
        {
            res = x.second;
            max_freq = x.first;
        }
    }

    string final_res;

    for(char c : res)
    {
        final_res += c;
    }

    return final_res;
    }
};
