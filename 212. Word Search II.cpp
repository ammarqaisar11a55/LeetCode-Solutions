class Solution
{
public:
    class TrieNode
    {
    public:
        unordered_map<char, TrieNode *> children;
        bool isEndOfWord;
        string word;

        TrieNode()
        {
            isEndOfWord = false;
        }
    };

    void insert(string word, TrieNode *&root)
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
        Crawler->word = word;
    }

    void DFS(TrieNode *root, int i, int j, vector<string> &res, vector<vector<char>> &board)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || root->children[board[i][j]] == nullptr)
            return;

        root = root->children[board[i][j]];

        if (root->isEndOfWord)
        {
            res.push_back(root->word);
            root->isEndOfWord = false;
        }

        char Temp = board[i][j];
        board[i][j] = '*';

        DFS(root, i + 1, j, res, board);
        DFS(root, i - 1, j, res, board);
        DFS(root, i, j + 1, res, board);
        DFS(root, i, j - 1, res, board);

        board[i][j] = Temp;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        TrieNode *root = new TrieNode();

        for (string word : words)
            insert(word, root);

        vector<string> Res;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (root->children[board[i][j]] != nullptr)
                {
                    DFS(root, i, j, Res, board);
                }
            }
        }

        return Res;
    }
};