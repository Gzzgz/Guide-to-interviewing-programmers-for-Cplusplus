/*
【名称】判断t1树中是否有与t2树拓扑结构完全相同的子树
【题目】给定彼此独立的两棵树头节点分别为t1,t2，判断t1中是否有与
t2树拓扑结构完全相同的子树
【难度】校
*/
#include <iostream>
#include <string>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

int* getNextArray(std::string ms) {
	if (ms.length() == 1) {
		return new int[1] {-1};
	}
	int* next = new int[ms.length()];
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int cn = 0;
	while (pos < ms.length()) {
		if (ms[pos - 1] == ms[cn]) {
			next[pos++] = ++cn;
		}
		else if (cn > 0) {
			cn = next[cn];
		}
		else {
			next[pos++] = 0;
		}
	}
	return next;
}

int getIndexOf(std::string s, std::string m) {
	if (s.length() < m.length() || m.length() < 1) {
		return -1;
	}
	int si = 0;
	int mi = 0;
	int* next = getNextArray(m);
	while (si < s.length() && mi < m.length()) {
		if (s[si] == m[mi]) {
			si++;
			mi++;
		}else if (next[mi] == -1) {
			si++;
		}
		else {
			mi = next[mi];
		}
	}
	return mi == m.length() ? si - mi : -1;
}

std::string serialByPre(Node* head) {
	if (head == nullptr) {
		return "#!";
	}
	std::string res = head->value + "!";
	res += serialByPre(head->left);
	res += serialByPre(head->right);
	return res;
}

bool isSubtree(Node* t1, Node* t2) {
	std::string t1str = serialByPre(t1);
	std::string t2str = serialByPre(t2);
	return getIndexOf(t1str, t2str) != -1;
}

int main() {

	Node*  h1 = new Node(1);
	h1->left = new Node(2);
	h1->right = new Node(3);
	h1->right->left = new Node(6);
	h1->right->right = new Node(7);
	h1->left->left = new Node(4);
	h1->left->right = new Node(5);
	h1->left->left->right = new Node(8);
	h1->left->right->left = new Node(9);

	Node* h2 = new Node(2);
	h2->left = new Node(4);
	h2->right = new Node(5);
	h2->left->right = new Node(8);
	h2->right->left = new Node(9);

	std::cout << isSubtree(h1, h2) << std::endl;

	return 0;
}