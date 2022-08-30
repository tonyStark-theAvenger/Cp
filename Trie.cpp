#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


//Trie Node


struct Node {
	Node *links[26];
	bool flag = false;


	void print() {
		for (int i = 0; i < 26; i++) {
			cout << links[i] << " ";
		}
		cout << endl;
	}

	//function to get link corresponding to the char
	Node * getLink(char ch) {
		return links[ch - 'a'];
	}



	//function to check if there is a link for the given char
	bool isLink(char ch) {
		return links[ch - 'a'] != NULL;
	}



	//function to create the link for the given char with the newly created node
	void createLink(char ch, Node *node) {
		links[ch - 'a'] = node;
	}


	//set the current node as the end
	void setEnd() {
		flag = true;
	}



	//get the value of the flag for the current node
	bool isEnd() {
		return flag;
	}
}* root;



void inertWord(string s) {

	Node * r = root;
	for (auto ch : s) {

		if (!r->isLink(ch)) {
			r->createLink(ch, new Node());
		}


		r = r->getLink(ch);
	}

	r->setEnd();
}


bool isPresent(string s) {

	Node * r = root;
	for (auto ch : s) {

		if (!r->isLink(ch)) {
			return false;
		}

		r = r->getLink(ch);
	}


	return r->isEnd() ;

}


bool isWithCommonPrefix(string prefix) {
	Node * r = root;
	for (auto ch : prefix) {
		if (!r->isLink(ch)) {
			return false;
		}

		r = r->getLink(ch);
	}

	return true;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	root =  new Node();

	inertWord("abc");

	cout << isPresent("ab") << endl;

	cout << isWithCommonPrefix("ab") << endl;
	cout << isPresent("a") << endl;



	return 0;
}