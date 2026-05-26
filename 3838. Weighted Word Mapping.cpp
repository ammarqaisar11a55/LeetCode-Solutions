class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;

        unordered_map<int, char> reversed_mappiing;

        int temp = 0;

        for (char c = 'z'; c >= 'a'; c--) {
            reversed_mappiing[temp++] = c;
        }

        for (int i = 0; i < words.size(); i++) {
            int weight_of_single = 0;

            for (int j = 0; j < words[i].length(); j++) {
                int score_of_letter = weights[words[i][j] - 'a'];
                weight_of_single += score_of_letter;
            }

            res += reversed_mappiing[weight_of_single % 26];
        }

        return res;
    }
};