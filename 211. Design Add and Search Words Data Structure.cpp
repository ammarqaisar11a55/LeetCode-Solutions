class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() { isEndOfWord = false; }
};
class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* Crawler = root;

        for (int i = 0; i < word.length(); i++) {
            if (Crawler->children[word[i]] == nullptr) {
                Crawler->children[word[i]] = new TrieNode();
            }

            Crawler = Crawler->children[word[i]];
        }

        Crawler->isEndOfWord = true;
    }

    bool search(string word) { return dfs(0, word, root); }

    bool dfs(int index, string& word, TrieNode* crawler) {
        if (crawler == NULL)
            return false;

        if (index >= word.length()) {
            return crawler->isEndOfWord == true ? true : false;
        }

        char current_character = word[index];

        if (current_character == '.') {

            for (auto& [key, child] : crawler->children) {
                if (dfs(index + 1, word, child)) {
                    return true;
                }
            }

            return false;
        } else {
            if (crawler->children[current_character] == NULL)
                return false;

            return dfs(index + 1, word, crawler->children[current_character]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
