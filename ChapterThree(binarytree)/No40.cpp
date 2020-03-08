/*
�����ơ�������������������������Ľڵ�
����Ŀ��һ�ö�����ԭ�������������������������������ڵ������λ�ã�
ʹ����ö��������������������������ҵ�����������ڵ㲢���ء���֪
�����������нڵ��ֵ����һ����������������ͷ�ڵ�head������һ������
Ϊ2�Ķ������ڵ����͵�����errs��errs[0]��ʾһ������ڵ㣬errs[1]
��ʾ��һ������ڵ㡣
���ף������ԭ�����еõ�������������ڵ㣬���ǵ�Ȼ����ͨ����������
�ڵ�Ľڵ�ֵ�÷�ʽ�����ö��������³�Ϊ������������������Ҫ���㲻��
��ô���������ڽṹ����ȫ���������ڵ��λ�ã���ʵ�ֵ����ĺ�����
���Ѷȡ�
ԭ���⣺ξ
�������⣺��
*/
#include <iostream>
#include <stack>


struct Node {
	int value;
	Node* left;
	Node* right;
	Node():value(0), left(nullptr), right(nullptr) {};
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

Node** getTwoErrNodes(Node* head) {
	Node** errs = new Node*[2];
	for (int i = 0; i < 2; i ++) {
		errs[i] = nullptr;
	}
	if (head == nullptr) {
		return errs;
	}
	std::stack<Node*> stack;
	Node* pre = nullptr;
	while (!stack.empty() || head != nullptr) {
		if (head != nullptr) {
			stack.push(head);
			head = head->left;
		}
		else {
			head = stack.top();
			stack.pop();
			if (pre != nullptr && pre->value > head->value) {
				errs[0] = errs[0] == nullptr ? pre : errs[0];
				errs[1] = head;
			}
			pre = head;
			head = head->right;
		}
	}
	return errs;
}

Node** getTwoErrParents(Node* head, Node* e1, Node* e2) {
	Node** parents = new Node*[2];
	for (int i = 0; i < 2; i ++) {
		parents[i] = nullptr;
	}
	if (head == nullptr) {
		return parents;
	}
	std::stack<Node*> stack;
	while (!stack.empty() || head != nullptr) {
		if (head != nullptr) {
			stack.push(head);
			head = head->left;
		}
		else {
			head = stack.top();
			stack.pop();
			if (head->left == e1 || head->right == e1) {
				parents[0] = head;
			}
			if (head->left == e2 || head->right == e2) {
				parents[1] = head;
			}
			head = head->right;
		}
	}
	return parents;
}

Node* recoverTree(Node* head) {

	Node** errs = getTwoErrNodes(head);
	Node** parents = getTwoErrParents(head, errs[0], errs[1]);
	Node* e1 = errs[0];
	Node* e1p = parents[0];
	Node* e1L = e1->left;
	Node* e1R = e1->right;
	Node* e2 = errs[1];
	Node* e2p = parents[1];
	Node* e2L = e2->left;
	Node* e2R = e2->right;
	if (e1 == head) {
		if (e1 == e2p) {
			e1->left = e2L;
			e1->right = e2R;
			e2->right = e1;
			e2->left = e1L;
		}
		else if (e2p->left == e2) {
			e2p->left = e1;
			e2->left = e1L;
			e2->right = e1R;
			e1->left = e2L;
			e1->right = e2R;
		}
		else {
			e2p->right = e1;
			e2->left = e1L;
			e2->right = e1R;
			e1->left = e2L;
			e1->right = e2R;
		}
		head = e2;
	}
	else if (e2 == head) {
		if (e2 == e1p) {
			e2->left = e1L;
			e2->right = e1R;
			e1->left = e2;
			e1->right = e2R;
		}
		else if (e1p->left == e1) {
			e1p->left = e2;
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e1R;
		}
		else {
			e1p->right = e2;
			e1->left = e2L;
			e1->right = e2R;
			e2->left = e1L;
			e2->right = e1R;
		}
		head = e1;
	}
	else {
		if (e1 == e2p) {
			if (e1p->left == e1) {
				e1p->left = e2;
				e1->left = e2L;
				e1->right = e2R;
				e2->left = e1L;
				e2->right = e1;
			}
			else {
				e1p->right = e2;
				e1->left = e2L;
				e1->right = e2R;
				e2->left = e1L;
				e2->right = e1;
			}
		}
		else if(e2 == e1p){
			if (e2p->left == e2) {
				e2p->left = e1;
				e2->left = e1L;
				e2->right = e1R;
				e1->left = e2;
				e1->right = e2R;
			}
			else {
				e2p->right = e1;
				e2->left = e1L;
				e2->right = e1R;
				e1->left = e2;
				e1->right = e2R;
			}
		}
		else {
			if (e1p->left == e1) {
				if (e1p->left == e2) {
					e1->left = e2L;
					e1->right = e2R;
					e2->left = e1L;
					e2->right = e1R;
					e1p->left = e2;
					e2p->left = e1;
				}
				else {
					e1->left = e2L;
					e1->right = e2R;
					e2->left = e1L;
					e2->right = e1R;
					e1p->left = e2;
					e2p->right = e1;
				}
			}
			else {
				if (e2p->left == e2) {
					e1->left = e2L;
					e1->right = e2R;
					e2->left = e1L;
					e2->right = e1R;
					e1p->right = e2;
					e2p->left = e1;
				}
				else {
					e1->left = e2L;
					e1->right = e2R;
					e2->left = e1L;
					e2->right = e1R;
					e1p->right = e2;
					e2p->right = e1;
				}
			}
		}
	}
	return head;
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

	Node* head = new Node(4);
	head->left = new Node(5);
	head->right = new Node(2);
	head->left->left = new Node(1);
	head->left->right = new Node(3);

	Node** errs = getTwoErrNodes(head);

	std::cout << errs[0]->value << " " << errs[1]->value << std::endl;

	head = recoverTree(head);

	showTree(head);

	return 0;
}