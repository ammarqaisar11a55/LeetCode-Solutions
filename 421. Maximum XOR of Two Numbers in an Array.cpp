class Solution
{
public:
    class BitTrieNode
    {
    public:
        BitTrieNode *Left = nullptr;
        BitTrieNode *Right = nullptr;
    };

    void Insertion_in_BitTrie(BitTrieNode *&root, int n)
    {
        BitTrieNode *Crawler = root;

        for (int i = 31; i >= 0; i--)
        {
            int ith_bit = (n >> i) & 1;

            if (ith_bit == 1)
            {
                if (Crawler->Right == nullptr)
                {
                    Crawler->Right = new BitTrieNode();
                }
                Crawler = Crawler->Right;
            }
            else
            {
                if (Crawler->Left == nullptr)
                {
                    Crawler->Left = new BitTrieNode();
                }
                Crawler = Crawler->Left;
            }
        }
    }

    int Calculate_XOR(BitTrieNode *&root, int N)
    {
        BitTrieNode *Crawler = root;
        int XOR = 0;

        for (int i = 31; i >= 0; i--)
        {
            int Current_ith_Bit = (N >> i) & 1;

            if (Current_ith_Bit == 1)
            {
                if (Crawler->Left != nullptr)
                {
                    XOR += pow(2, i) * 1;
                    Crawler = Crawler->Left;
                }
                else
                {
                    XOR += pow(2, i) * 0;
                    Crawler = Crawler->Right;
                }
            }
            else
            {
                if (Crawler->Right != nullptr)
                {
                    XOR += pow(2, i) * 1;
                    Crawler = Crawler->Right;
                }
                else
                {
                    XOR += pow(2, i) * 0;
                    Crawler = Crawler->Left;
                }
            }
        }

        return XOR;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        BitTrieNode *root = new BitTrieNode();

        for (int i : nums)
        {
            Insertion_in_BitTrie(root, i);
        }

        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int Current_XOR = Calculate_XOR(root, nums[i]);
            res = max(res, Current_XOR);
        }

        return res;
    }
};