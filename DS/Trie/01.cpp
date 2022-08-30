01.cpp
struct Node {
	Node *links[26];
	bool flag = false;


	Node * get(char ch) {
		return links[ch - 'a'];
	}


//returns if there is a link corresponding to the letter
	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}


//add's the new link in front of the given letter
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

//settes end flag to true impling that the word has ended
	void setEnd() {
		flag = true;
	}

//if the word is end the bool flag is turned true
	bool isEnd() {
		return flag;
	}


};

class Trie {


private: Node * root;


public:
	Trie() {
		//just create new node
		root = new Node();
	}

	void insert(string word) {
		Node *node = root;

		for (int i = 0; i < word.length(); i++) {

			if (node->containsKey(word[i]) == false) {
				node->put(word[i], new Node());
			}

			node = node->get(word[i]);
		}

		node->setEnd();
	}

	bool search(string word) {

		Node *node = root;

		for (int i = 0; i < word.length(); i++) {

			if (node->containsKey(word[i]) == false)
				return false;

			node = node->get(word[i]);
		}


		return node->isEnd();
	}

	bool startsWith(string prefix) {

		Node * node = root;

		for (int i = 0; i < prefix.length(); i++) {
			if (node->containsKey(prefix[i]) == false)
				return false;

			node = node->get(prefix[i]);
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