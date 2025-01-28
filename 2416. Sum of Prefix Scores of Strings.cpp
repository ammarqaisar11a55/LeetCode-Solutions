class Solution
{
public:
    class TrieNode
    {
    public:
        unordered_map<char, TrieNode *> Childs;
        int PreFix_Count = 0;
    };

    void Insert_In_Trie(TrieNode *&root, string Word)
    {
        TrieNode *Trie_Crawler = root;

        for (int i = 0; i < Word.length(); i++)
        {
            if (Trie_Crawler->Childs[Word[i]] == NULL)
            {
                Trie_Crawler->Childs[Word[i]] = new TrieNode();
            }

            Trie_Crawler = Trie_Crawler->Childs[Word[i]];
            Trie_Crawler->PreFix_Count++;
        }
    }

    int Count_Score(TrieNode *&root, string word)
    {
        int score = 0;
        TrieNode *Trie_Crawler = root;

        for (char c : word)
        {
            score += Trie_Crawler->Childs[c]->PreFix_Count;
            Trie_Crawler = Trie_Crawler->Childs[c];
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string> &words)
    {
        TrieNode *Root = new TrieNode();

        for (string word : words)
            Insert_In_Trie(Root, word);

        vector<int> Res;

        for (string word : words)
            Res.push_back(Count_Score(Root, word));

        return Res;
    }
};