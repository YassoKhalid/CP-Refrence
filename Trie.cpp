
struct trie {
    static const int MAX_CHAR = 26;
    trie *nxt[MAX_CHAR];
    bool leaf{};

    trie() {
        // set an array to 0s. Here pointers to null
        memset(nxt, 0, sizeof(nxt));
    }

    void insert(string str, int idx = 0) {
        if (idx == (int) str.size())
            leaf = 1;
        else {
            int cur = str[idx] - 'a';
            if (nxt[cur] == 0)
                nxt[cur] = new trie();
            nxt[cur]->insert(str, idx + 1);
        }
    }

    bool word_exist(string str, int idx = 0) {
        if (idx == (int) str.size())
            return leaf;    // there is a string marked here

        int cur = str[idx] - 'a';
        if (!nxt[cur])
            return false;    // such path don't exist

        return nxt[cur]->word_exist(str, idx + 1);
    }

    bool prefix_exist(string str, int idx = 0) {
        if (idx == (int) str.size())
            return true;    // all subword covered

        int cur = str[idx] - 'a';
        if (!nxt[cur])
            return false;    // such path don't exist

        return nxt[cur]->prefix_exist(str, idx + 1);
    }
};
