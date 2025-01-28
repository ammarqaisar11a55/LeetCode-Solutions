class Solution
{
public:
    class TrieNode
    {
    public:
        unordered_map<char, TrieNode *> Childs;
        vector<string> Suggestions;
    };

    void Trie_Insertion(TrieNode *&root, string word)
    {
        TrieNode *Crawlwer = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (Crawlwer->Childs[word[i]] == nullptr)
            {
                Crawlwer->Childs[word[i]] = new TrieNode();
            }

            Crawlwer = Crawlwer->Childs[word[i]];

            if (Crawlwer->Suggestions.size() < 3)
            {
                Crawlwer->Suggestions.push_back(word);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {

        sort(products.begin(), products.end());

        vector<vector<string>> Res;

        TrieNode *Root = new TrieNode();

        for (int i = 0; i < products.size(); i++)
        {
            Trie_Insertion(Root, products[i]);
        }

        for (int i = 0; i < searchWord.length(); i++)
        {
            vector<string> Single_Letter_Suggestions;

            int j = 0;

            if (Root->Childs[searchWord[i]] == nullptr)
                break;

            while (j < Root->Childs[searchWord[i]]->Suggestions.size())
            {
                Single_Letter_Suggestions.push_back(Root->Childs[searchWord[i]]->Suggestions[j]);
                j++;
            }

            Root = Root->Childs[searchWord[i]];
            Res.push_back(Single_Letter_Suggestions);
        }

        while (Res.size() < searchWord.size())
        {
            Res.push_back({});
        }

        return Res;
    }
};