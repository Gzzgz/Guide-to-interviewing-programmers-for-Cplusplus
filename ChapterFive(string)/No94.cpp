/*
【名称】字典树（前缀树）的实现
【题目】字典树又称为前缀或Trie树，是处理字符串常见的数据结构。假设组成
所有单词的字符仅是'a'-'z'，请实现字典树结构，并包含以下四个主要功能。
1.void insert(String word):添加word，可重复添加；
2.void delete(String word):删除word, 如果word添加多次，仅删除一个；
3.boolean search(String word):查询word是否在字典树中；
4.int prefixNumber(String pre):返回以字符串pre为前缀的单词数量。
【难度】尉
*/

#include <iostream>
#include <string>

typedef struct TrieNode {

	int path;
	int end;
	TrieNode* map[26];

	TrieNode() {
		path = 0;
		end = 0;
		memset(map, NULL, sizeof(map));
	}
};

class Trie {
private:
	TrieNode* root;

public:
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		delete root;
	}

public:
	void insert(std::string word) {
		if (word == "") {
			return;
		}
		TrieNode* node = root;
		int index = 0;
		
		for (int i = 0; i < word.length(); i ++) {
			index = word[i] - 'a';
			if (node->map[index] == nullptr) {
				node->map[index] = new TrieNode();
			}
			node = (node->map[index]);
			node->path++;
		}
		node->end++;
	}
public:
	bool search(std::string word) {
		if (word == "") {
			return false;
		}
		TrieNode* node = root;
		int index = 0;
		for (int i = 0; i < word.length(); i++) {
			index = word[i] - 'a';
			if (node->map[index] == nullptr) {
				return false;
			}
			node = (node->map[index]);
		}
		return node->end != 0;
	}

public:
	void deleted(std::string word) {
		if (search(word)) {
			TrieNode* node = root;
			int index = 0;
			for (int i = 0; i < word.length(); i ++) {
				index = word[i] - 'a';
				if (node->map[index]->path -- == 1) {
					node->map[index] = nullptr;
					return;
				}
				node = (node->map[index]);
			}
			node->end--;
		}
	}
public:
	int prefixNumber(std::string pre) {
		if (pre == "") {
			return 0;
		}
		TrieNode* node = root;
		int index = 0;
		for (int i = 0; i < pre.length(); i ++) {
			index = pre[i] - 'a';
			if (node->map[index] == nullptr) {
				return 0;
			}
			node = (node->map[index]);
		}
		return node->path;
	}
};

int main() {

	Trie tree;
	tree.insert("abc");
	tree.insert("abcd");
	tree.insert("abd");

	std::cout << tree.search("abd") << std::endl;
	tree.deleted("abd");
	std::cout << tree.search("abd") << std::endl;

	return 0;
}