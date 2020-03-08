/*
【名称】在二叉树中找到累加和为指定值的最长路径长度
【题目】给定一棵二叉树的头节点head和一个32位整数sum，二叉树节点
值类型为整型，求累加和为sum的最长路径长度。路径是指从某个节点往下，
每次最多选择一个孩子节点或者不选所形成的节点链。
【难度】尉
*/
#include <iostream>
#include <map>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};


int preOrder(Node* head, int sum, int presum, int level, int maxlen,
	std::map<int, int>& summap) {
	if (head == nullptr) {
		return maxlen;
	}
	int cursum = presum + head->value;
	if (summap.find(cursum) == summap.end()) {
		summap.insert(std::pair<int, int>(cursum, level));
	}
	if (summap.find(cursum - sum) != summap.end()) {
		maxlen = (level - summap[cursum - sum]) > maxlen ? (level - summap[cursum - sum]) : maxlen;
	}
	maxlen = preOrder(head->left, sum, cursum, level + 1, maxlen, summap);
	maxlen = preOrder(head->right, sum, cursum, level + 1, maxlen, summap);
	if (level == summap[cursum]) {
		summap.erase(cursum); // ??
	}
	return maxlen;
}

int getMaxLength(Node* head, int sum) {
	std::map<int, int> summap;
	summap.insert(std::pair<int, int>(0, 0));
	return preOrder(head, sum, 0, 1, 0, summap);
}

int main() {

	Node* head = new Node(-3);
	head->left = new Node(3);
	head->right = new Node(-9);
	head->right->left = new Node(2);
	head->right->right = new Node(1);
	head->left->left = new Node(1);
	head->left->right = new Node(0);
	head->left->right->left = new Node(1);
	head->left->right->right = new Node(6);

	std::cout << getMaxLength(head, 1) << std::endl;

	return 0;
}