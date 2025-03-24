class CombinationIterator {
public:
    vector<string> results;
    int current_index = 0;

    void Solve(int index, string s, string current_combination,
               int expected_length) {
        if (current_combination.length() == expected_length) {
            results.push_back(current_combination);
            return;
        }

        for (int i = index; i < s.length(); i++) {

            current_combination.push_back(s[i]);
            Solve(i + 1, s, current_combination, expected_length);
            current_combination.pop_back();
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        Solve(0, characters, "", combinationLength);
    }

    string next() { return results[current_index++]; }

    bool hasNext() { return current_index < results.size() ? true : false; }
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
