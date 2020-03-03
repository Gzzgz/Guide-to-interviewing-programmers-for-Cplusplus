/*
【名称】分别用递归和非递归方式实现二叉树先序中序后序遍历
【题目】约定先序遍历顺序为根，左，右；中序遍历顺序为左，根，右；
后序遍历顺序为左，右，根
【难度】校
*/
#include <iostream>
#include <stack>


struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value) :
		value(value), left(nullptr), right(nullptr) {}
};

void preOrderRecur(Node* head) {
	if (head == nullptr) {
		return;
	}
	std::cout << head->value << std::endl;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

void inOrderRecur(Node* head) {
	if (head == nullptr) {
		return;
	}
	inOrderRecur(head->left);
	std::cout << head->value << std::endl;
	inOrderRecur(head->right);
}

void posOrderRecur(Node* head) {
	if (head == nullptr) {
		return;
	}
	posOrderRecur(head->left);
	posOrderRecur(head->right);
	std::cout << head->value << std::endl;
}

void preOrderUnRecur(Node* head) {
	if (head != nullptr) {
		std::stack<Node*> stack;
		stack.push(head);

		while (!stack.empty()) {
			head = stack.top();
			stack.pop();
			std::cout << head->value << std::endl;
			if (head->right != nullptr) {
				stack.push(head->right);
			}
			if (head->left != nullptr) {
				stack.push(head->left);
			}
		}
	}
}

void inOrderUnRecur(Node* head) {
	if (head != nullptr) {
		std::stack<Node*> stack;
		while (!stack.empty() || head != nullptr) {
			if (head != nullptr) {
				stack.push(head);
				head = head->left;
			}
			else {
				head = stack.top();
				stack.pop();
				std::cout << head->value << std::endl;
				head = head->right;
			}
		}
	}
}

void posOrderUNRecur1(Node* head) {
	if (head != nullptr) {
		std::stack<Node*> s1, s2;
		s1.push(head);
		while (!s1.empty()) {
			head = s1.top();
			s1.pop();
			s2.push(head);
			if (head->left != nullptr) {
				s1.push(head->left);
			}
			if (head->right != nullptr) {
				s1.push(head->right);
			}
		}
		while (!s2.empty()) {
			std::cout << s2.top()->value << std::endl;
			s2.pop();
		}
	}
}

void posOrderUNRecur2(Node* head) {
	if (head != nullptr) {
		std::stack<Node*> stack;
		stack.push(head);
		Node* c = nullptr;
		while (!stack.empty()) {
			c = stack.top();
			if (c->left != nullptr && head != c->left && head != c->right) {
				stack.push(c->left);
			}
			else if (c->right != nullptr && head != c->right) {
				stack.push(c->right);
			}
			else {
				std::cout << stack.top()->value << std::endl;
				stack.pop();
				head = c;
			}
		}
	}
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->right->left = new Node(6);
	head->right->right = new Node(7);

	//preOrderRecur(head);
	//preOrderUnRecur(head);

	//preOrderRecur(head);
	//inOrderUnRecur(head);

	posOrderRecur(head);
	posOrderUNRecur1(head);
	posOrderUNRecur2(head);

	return 0;
}