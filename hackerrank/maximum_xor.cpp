#pragma GCC optimize ("Ofast")

#include <vector>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;
using std::cin;
using std::ofstream;

class BinaryTrie {
private:
    class TrieNode {
    private:
        TrieNode *c[2] = {nullptr};

    public:
        explicit constexpr TrieNode() {}

        ~TrieNode() {
            delete c[0];
            delete c[1];
        }

        inline constexpr TrieNode *get(bool b) const {
            return c[b];
        }

        inline constexpr void set(bool b, TrieNode *t) {
            c[b] = t;
        }
    };

    TrieNode *root;

public:
    BinaryTrie() : root(new TrieNode) {}

    ~BinaryTrie() {
        delete root;
    }

    void insert(uint val) {
        auto node = this->root;
        for (int i = 31; i >= 0; i--) {
            if (node->get((val >> i) & 1u) == nullptr)
                node->set((val >> i) & 1u, new TrieNode);
            node = node->get((val >> i) & 1u);
        }
    }

    uint findClosest(uint val) {
        auto node = this->root;
        uint res = 0;

        for (int i = 31; i >= 0; i--) {
            if (node->get((val >> i) & 1u) != nullptr) {
                node = node->get((val >> i) & 1u);
                res += 1u << i;
            } else {
                node = node->get(((val >> i) & 1u) ^ 1u);
            }
        }

        return res;
    }
};

vector<uint> maxXor(const vector<uint> &arr, const vector<uint> &queries) {
    auto res = vector<uint>(queries.size());
    auto trie = BinaryTrie();

    for (const auto &n : arr)
        trie.insert(n);

    for (uint i = 0; i < queries.size(); i++)
        res[i] = trie.findClosest(~queries[i]);

    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    uint n;
    cin >> n;
    vector<uint> arr(n);
    for (uint i = 0; i < n; i++)
        cin >> arr[i];

    uint m;
    cin >> m;
    vector<uint> queries(m);
    for (uint i = 0; i < m; i++)
        cin >> queries[i];

    vector<uint> result = maxXor(arr, queries);
    for (uint i = 0; i < result.size(); i++)
        fout << result[i] << '\n';

    fout.close();

    return 0;
}
