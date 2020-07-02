
class Trie {

private:
    struct Node
    {
        char _c;
		bool _has_word = false;
        Node *_nodes[26] = {nullptr};
        Node(char c):_c(c),_has_word(false){}

        void insert(const string & word, int pos)
        {
            if(pos >= word.size()) return;
            char & c = word[pos];
            int idx = c - 'a';
            if(_nodes[idx] == nullptr)
            {
                _nodes[idx] = new Node(c);
            }
			if(pos == word.size() - 1) 
			{
				_nodes[idx]._has_word = true;
			}
			else
			{
            	insert(word, pos+1);
			}
        }

        bool search(const string & word, int pos)
        {
            if(pos >= word.size()) return false;
            char & c = word[pos];
            int idx = c - 'a';
            if(_nodes[idx] == nullptr)
            {
                return false;
            }

			if(pos == word.size() - 1) 
			{
				return _nodes[idx]._has_word;
			}
			else
			{
            	return search(word, pos+1);
			}
        }

        bool startsWith(const string & word, int pos)
        {
            if(pos >= word.size()) return false;
            char & c = word[pos];
            int idx = c - 'a';
            if(_nodes[idx] == nullptr)
            {
                return false;
            }

			if(pos == word.size() - 1) 
			{
				return true;
			}
			else
			{
            	return search(word, pos+1);
			}
        }
    };

    Node _root;

public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        _root.insert(word, 0);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return _root.search(word, 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return _root.startsWith(prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
