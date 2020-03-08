/*
【名称】在二叉树中找到两个节点的最近公共祖先
【题目】给定一棵二叉树的头节点head，以及这棵树中的两个节点o1,o2的最近公共祖先节点
进阶：如果查询两个节点的最近公共祖先的操作十分频繁，想法让单条查询的查询时间减少
再进阶：给定二叉树的头节点head，同时给定所有想要进行的查询。二叉树的节点数为N,
查询条数为M,请在时间复杂度为O(N+M)内返回所有查询的结果。
【难度】
原问题：士
进阶问题：尉
再进阶问题：校
*/
#include <iostream>
#include <map>
#include <set>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

Node* lowestAncestor(Node* head, Node* o1, Node* o2) {
	if (head == nullptr || head == o1 || head == o2) {
		return head;
	}
	Node* left = lowestAncestor(head->left, o1, o2);
	Node* right = lowestAncestor(head->right, o1, o2);
	if (left != nullptr && right != nullptr) {
		return head;
	}
	return left != nullptr ? left : right;
}

class Record1{
public:
	std::map<Node*, Node*> map;
	Record1(Node* head) {
		if (head != nullptr) {
			map.insert(std::pair<Node*, Node*>(head, nullptr));
		}
		setMap(head);
	}

	void setMap(Node* head) {
		if (head == nullptr) {
			return;
		}
		if (head->left != nullptr) {
			map.insert(std::pair<Node*, Node*>(head->left, head));
		}
		if (head->right != nullptr) {
			map.insert(std::pair<Node*, Node*>(head->right, head));
		}
		setMap(head->left);
		setMap(head->right);
	}

	Node* query(Node* o1, Node* o2) {
		std::set<Node*> path;
		while (map.find(o1) != map.end()) {
			path.insert(o1);
			o1 = map[o1];
		}
		while (path.find(o2) == path.end()) {
			o2 = map[o2];
		}
		return o2;
	}

};

class Record2 {
public:
	std::map<Node*, std::map<Node*, Node*>> map;

	Record2(Node* head) {
		initMap(head);
		setMap(head);
	}

	void initMap(Node* head) {
		if (head == nullptr) {
			return;
		}
		std::map<Node*, Node*> tmp;
		tmp.insert(std::make_pair(nullptr, nullptr));
		map.insert(std::make_pair(head, tmp));
		initMap(head->right);
	}

	void setMap(Node* head) {
		if (head == nullptr) {
			return;
		}
		headRecord(head->left, head);
		headRecord(head->right, head);
		subRecord(head);
		setMap(head->left);
		setMap(head->right);
	}

	void headRecord(Node* n, Node* h) {
		if (n == nullptr) {
			return;
		}
		map[n].insert(std::pair<Node*, Node*>(h, h));
		headRecord(n->left, h);
		headRecord(n->right, h);
	}

	void subRecord(Node* head) {
		if (head == nullptr) {
			return;
		}
		preLeft(head->left, head->right, head);
		subRecord(head->left);
		subRecord(head->right);
	}

	void preLeft(Node* left, Node* right, Node* h) {
		if (left == nullptr) {
			return;
		}
		preRight(left, right, h);
		preLeft(left->left, right, h);
		preLeft(left->right, right, h);
	}

	void preRight(Node* left, Node* right, Node* h) {
		if (right == nullptr) {
			return;
		}
		map[left].insert(std::pair<Node*, Node*>(right, h));
		preRight(left, right->left, h);
		preRight(left, right->right, h);
	}

	Node* query(Node* o1, Node* o2) {
		if (o1 == o2) {
			return o1;
		}
		if (map.find(o1) != map.end()) {
			return map[o1][o2];
		}
		if (map.find(o2) != map.end()) {
			return map[o2][o1];
		}
		return nullptr;
	}
};


int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	head->right->right = new Node(7);
	head->right->right->left = new Node(8);

	lowestAncestor(head, head->right->left, head->right->right->left);

	//Record1 record1(head);
	//std::cout << record1.query(head->right->left, head->right->right->left)->value << std::endl;

	Record2 record2(head);
	head = record2.query(head->right->left, head->right->right->left);
    std::cout << head->value << std::endl;

	return 0;
}