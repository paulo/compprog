#include <bits/stdc++.h>

using namespace std;

struct trieNode {
    trieNode* children[26];
    string word;

    trieNode(string _word) {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
            word = _word;
        }
    }
};

void insert(trieNode* node, string s, int i) {
    if (i == s.size()) {
        node->word = s;
        return;
    }

    int ind = s[i] - 'a';
    if (node->children[ind] == NULL) {
        node->children[ind] = new trieNode("");
    }

    insert(node->children[ind], s, i + 1);
}

class Solution {
    vector<vector<bool>> curr;
    trieNode* node;
    vector<string> res;

   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        if (board.size() == 0) return vector<string>();
        if (board[0].size() == 0) return vector<string>();

        int n = board.size(), m = board[0].size();
        curr = vector<vector<bool>>(n, vector<bool>(m, false));
        node = new trieNode("");

        for (auto w : words) insert(node, w, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (node->children[board[i][j] - 'a'])
                    find(board, n, m, i, j, node);
            }
        }

        return res;
    }

    void find(vector<vector<char>>& board, int n, int m, int i, int j,
              trieNode* node) {
        if (!node) return;
        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";
        }
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (curr[i][j]) return;

        if (!node->children[board[i][j] - 'a']) return;

        curr[i][j] = true;

        find(board, n, m, i + 1, j, node->children[board[i][j] - 'a']);
        find(board, n, m, i - 1, j, node->children[board[i][j] - 'a']);
        find(board, n, m, i, j + 1, node->children[board[i][j] - 'a']);
        find(board, n, m, i, j - 1, node->children[board[i][j] - 'a']);

        curr[i][j] = false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> board = {{'a', 'b'}, {'a', 'a'}};
    vector<string> words = {"aba", "baa", "bab", "aaab", "aaa", "aaaa", "aaba"};

    for (auto s : Solution().findWords(board, words)) {
        cout << s << endl;
    }
    return 0;
}
