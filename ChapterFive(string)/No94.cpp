/*
�����ơ��ֵ�����ǰ׺������ʵ��
����Ŀ���ֵ����ֳ�Ϊǰ׺��Trie�����Ǵ����ַ������������ݽṹ���������
���е��ʵ��ַ�����'a'-'z'����ʵ���ֵ����ṹ�������������ĸ���Ҫ���ܡ�
1.void insert(String word):���word�����ظ���ӣ�
2.void delete(String word):ɾ��word, ���word��Ӷ�Σ���ɾ��һ����
3.boolean search(String word):��ѯword�Ƿ����ֵ����У�
4.int prefixNumber(String pre):�������ַ���preΪǰ׺�ĵ���������
���Ѷȡ�ξ
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