/*
【名称】找到二叉树中符合搜索二叉树条件的最大拓扑结构
【题目】给定一棵二叉树的头节点head,已知所有节点的值都不一样，返回
其中最大的且符合搜索二叉树条件的最大拓扑结构的大小
【难度】校
*/
#include <iostream>
#include <map>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

struct Record {
	int left;
	int right;
	Record(int left, int right):left(left),right(right) {}
};

bool isBstNode(Node* head, Node* n, int value) {
	if (head == nullptr) {
		return false;
	}
	if (head == n) {
		return true;
	}
	return isBstNode(head->value > value ? head->left : head->right, n, value);
}

int maxTopo(Node* head, Node* n) {
	if (head != nullptr && n != nullptr && isBstNode(head, n, n->value)) {
		return maxTopo(head, n->left) + maxTopo(head, n->right) + 1;
	}
	return 0;
}

int bstTopoSize1(Node* head) {
	if (head == nullptr) {
		return 0;
	}
	int max = maxTopo(head, head);
	//max = bstTopoSize1(head->left) > max ? bstTopoSize1(head->left) : max;
	//max = bstTopoSize1(head->right) > max ? bstTopoSize1(head->right) : max;
	return max;
}

int modifyMap(Node* n, int v, std::map<Node*, Record*>& m, bool s) {
	if (n == nullptr || (m.find(n) == m.end())) {
		return 0;
	}
	Record* r = m[n];
	if ((s && n->value > v) || ((!s) && n->value < v)) {
		m.erase(n);
		return r->left + r->right + 1;
	}
	else {
		int minus = modifyMap(s ? n->right : n->left, v, m, s);
		if (s) {
			r->right -= minus;
		}
		else {
			r->left -= minus;
		}
		m.insert(std::pair<Node*, Record*>(n, new Record(r->left, r->right)));
		return minus;
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

int posOrder(Node* head, std::map<Node*, Record*>& map) {
	if (head == nullptr) {
		return 0;
	}
	int ls = posOrder(head->left, map);
	int rs = posOrder(head->right, map);
	modifyMap(head->left, head->value, map, true);
	modifyMap(head->right, head->value, map, false);
	Record* lr = nullptr;
	if (map.find(head->left) != map.end()) {
		lr = map[head->left];
	}
	Record* rr = nullptr;
	if (map.find(head->right) != map.end()) {
		rr = map[head->right];
	}
	int lbst = lr == nullptr ? 0 : lr->left + lr->right + 1;
	int rbst = rr == nullptr ? 0 : rr->right + rr->left + 1;
	map.insert(std::pair<Node*, Record*>(head, new Record(lbst, rbst)));
	
	return max(lbst + rbst + 1, max(ls, rs));
}

int bstTopoSize2(Node* head) {
	std::map<Node*, Record*> map;
	return posOrder(head, map);
}

int main() {

	Node* head = new Node(6);
	head->left = new Node(1);
	head->right = new Node(12);
	head->left->left = new Node(0);
	head->left->right = new Node(3);
	head->right->left = new Node(10);
	head->right->right = new Node(13);
	head->right->left->left = new Node(4);
	head->right->left->right = new Node(14);
	head->right->left->left->left = new Node(2);
	head->right->left->left->right = new Node(5);
	head->right->left->right->left = new Node(11);
	head->right->left->right->right = new Node(15);
	head->right->right->left = new Node(20);
	head->right->right->right = new Node(16);

	std::cout << bstTopoSize1(head) << std::endl;
	
	std::cout << bstTopoSize2(head) << std::endl;

	return 0;
}