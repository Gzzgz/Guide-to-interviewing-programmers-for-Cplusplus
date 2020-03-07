/*
【名称】先序，中序，后序数组两两结合重构二叉树
【题目】已知一棵二叉树的所有节点值都不相同，给定这棵二叉树正确的先序，中序，后序数组，
请分别用三个函数实现任意两种数组结合重构原来的二叉树，并返回重构二叉树的头节点，
【难度】
先序与中序结合 士
中序和后序结合 士
先序和后序结合 尉
*/
#include <iostream>
#include <map>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

Node* preIn(int* p, int pi, int pj, int* n, int ni, int nj,
	std::map<int, int>& map) {
	if (pi > pj) {
		return nullptr;
	}
	Node* head = new Node(p[pi]);
	int index = map[p[pi]];
	head->left = preIn(p, pi + 1, pi + index - ni, n, ni, index - 1, map);
	head->right = preIn(p, pi + index - ni + 1, pj, n, index + 1, nj, map);
	return head;
}

Node* preInToTree(int* pre, int* in, int len) {
	if (pre == nullptr || in == nullptr || len == 0) {
		return nullptr;
	}
	std::map<int, int> map;
	for (int i = 0; i < len; i ++) {
		map.insert(std::pair<int, int>(in[i], i));
	}
	return preIn(pre, 0, len - 1, in, 0, len - 1, map);
}

Node* inPos(int* n, int ni, int nj, int* s, int si, int sj,
	std::map<int, int>& map) {
	if (si > sj) {
		return nullptr;
	}
	Node* head = new Node(s[sj]);
	int index = map[s[sj]];
	head->left = inPos(n, ni, index - 1, s, si, si + index - ni - 1, map);
	head->right = inPos(n, index + 1, nj, s, si + index - ni, sj - 1, map);
	return head;
}

Node* InPosToTree(int* in, int* pos, int len) {
	if (pos == nullptr || in == nullptr || len == 0) {
		return nullptr;
	}
	std::map<int, int> map;
	for (int i = 0; i < len; i++) {
		map.insert(std::pair<int, int>(in[i], i));
	}
	return inPos(in, 0, len - 1, pos, 0, len - 1, map);
}

Node* prePos(int* p, int pi, int pj, int* s, int si, int sj,
	std::map<int, int>& map) {
	Node* head = new Node(s[sj--]);
	if (pi == pj) {
		return head;
	}
	int index = map[p[++pi]];
	head->left = prePos(p, pi, pi + index - si, s, si, index, map);
	head->right = prePos(p, pi + index - si + 1, pj, s, index + 1, sj, map);
	return head;
}

Node* prePosToTree(int* pre, int* pos, int len) {
	if (pre == nullptr || pos == nullptr || len == 0) {
		return nullptr;
	}
	std::map<int, int> map;
	for (int i = 0; i < len; i ++) {
		map.insert(std::pair<int, int>(pos[i], i));
	}
	return prePos(pre, 0, len - 1, pos, 0, len - 1, map);
}

void showTree(Node* head) {

	if (head == nullptr) {
		return;
	}
	std::cout << head->value << std::endl;
	showTree(head->left);
	showTree(head->right);
}

int main() {

	int pre[7] = {1,2,4,5,3,6,7};
	int in[7] = {4,2,5,1,6,3,7};
	int pos[7] = {4,5,2,6,7,3,1};

	//Node* head = preInToTree(pre, in, 7);
	//Node* head = InPosToTree(in, pos, 7);
	Node* head = prePosToTree(pre, pos, 7);
	showTree(head);

	return 0;
}