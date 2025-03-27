class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char, int> mp;
        unordered_map<int, int> cards_with_rank;

        for (char c : suits) {
            mp[c]++;
        }

        for (int i : ranks) {
            cards_with_rank[i]++;
        }

        if (mp.size() == 1) {
            return "Flush";
        }

        for (auto x : cards_with_rank) {
            if (x.second >= 3)
                return "Three of a Kind";
        }

        for (auto x : cards_with_rank) {
            if (x.second == 2)
                return "Pair";
        }

        return "High Card";
    }
};
