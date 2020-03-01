/*
【名称】构造数组的MaxTree
【题目】一个数组的MaxTree定义如下：
1.数组必须没有重复元素；
2.是一颗二叉树，每一个值对应一个二叉树节点；
3.包括MaxTree在内且在其中的每一课子树上，值最大的节点都是头节点。
【难度】校
*/

#include <iostream>
#include <stack>
#include <vector>
#include <map>

class Node {
public:
	Node() {};
	Node(int data) {
		value_ = data;
		left_ = nullptr;
		right_ = nullptr;
	}

public: 
	int value_;
	Node* left_;
	Node* right_;
};

void popStackSetMap(std::stack<Node*>& in_stack, std::map<Node*, Node*>& node_map) {
	Node* popNode = in_stack.top();
	in_stack.pop();
	if (in_stack.empty()) {
		node_map[popNode] = nullptr;
	}
	else {
		node_map[popNode] = in_stack.top();
	}
}

Node* getMaxTree(std::vector<int>& arr) {

	std::vector<Node*> nArr;
	for (int i = 0; i < arr.size(); i++) {
		nArr.push_back(new Node(arr[i]));
	}

	std::stack<Node*> node_stack;
	std::map<Node*, Node*> lBigMap, rBigMap;
	for (int i = 0; i < arr.size(); i++) {
		Node* curNode = nArr[i];
		while ((!node_stack.empty()) 
			&& (node_stack.top()->value_ < curNode->value_)) {
			popStackSetMap(node_stack, lBigMap);
		}
		node_stack.push(curNode);
	}
	while (!node_stack.empty()) {
		popStackSetMap(node_stack, lBigMap);
	}

	for (int i = arr.size() - 1; i >= 0; i--) {
		Node* curNode = nArr[i];
		while ((!node_stack.empty()) && 
			(node_stack.top()->value_ < curNode->value_)) {
			popStackSetMap(node_stack, rBigMap);
		}
		node_stack.push(curNode);
	}
	while (!node_stack.empty()) {
		popStackSetMap(node_stack, rBigMap);
	}

	Node* head = nullptr;
	for (int i = 0; i < arr.size(); i++) {
		Node* curNode = nArr[i];
		Node* left = lBigMap[curNode];
		Node* right = rBigMap[curNode];
		if (left == nullptr && right == nullptr) {
			head = curNode;
		}
		else if (left == nullptr) {
			if (right->left_ == nullptr) {
				right->left_ = curNode;
			}
			else {
				right->right_ = curNode;
			}
		}
		else if (right == nullptr) {
			if (left->left_ == nullptr) {
				left->left_ = curNode;
			}
			else {
				left->right_ = curNode;
			}
		}
		else {
			Node* parent = left->value_ > right->value_ ? right : left;
			if (parent->left_ == nullptr) {
				parent->left_ = curNode;
			}
			else {
				parent->right_ = curNode;
			}
		}
	}

	return head;

}

void print_tree(Node* root) {
	if (root == nullptr)
		return;
	print_tree(root->left_);
	std::cout << root->value_ << " ";
	print_tree(root->right_);
}

int main() {

	std::vector<int> vec = { 3,4,5,1,2};
	Node* out_node =  getMaxTree(vec);

	print_tree(out_node);

	return  0;
}