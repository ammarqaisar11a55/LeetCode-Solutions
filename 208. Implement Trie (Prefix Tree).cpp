class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *Crawler = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (Crawler->children[word[i]] == nullptr)
            {
                Crawler->children[word[i]] = new TrieNode();
            }

            Crawler = Crawler->children[word[i]];
        }

        Crawler->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *Crawler = root;

        for (int i = 0; i < word.length(); i++)
        {
            if (Crawler->children[word[i]] == nullptr)
            {
                return false;
            }

            Crawler = Crawler->children[word[i]];
        }

        return Crawler->isEndOfWord == true ? true : false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *Crawler = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (Crawler->children[prefix[i]] == nullptr)
            {
                return false;
            }

            Crawler = Crawler->children[prefix[i]];
        }

        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */