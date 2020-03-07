/*
�����ơ��ж϶������Ƿ�Ϊƽ�������
����Ŀ��ƽ�������������Ϊ��Ҫô��һ�ÿ�����Ҫô�κ�һ���ڵ��
���������߶Ȳ�ľ���ֵ������1.����һ�ö�������ͷ�ڵ�head���ж�
��ö������Ƿ�Ϊƽ���������
Ҫ������������Ľڵ���ΪN��Ҫ��ʱ�临�Ӷ�ΪO(N)
���Ѷȡ�ʿ
*/
#include <iostream>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value) :value(value), left(nullptr), right(nullptr) {}
};

int getHeight(Node* head, int level, bool& res) {
	if (head == nullptr) {
		return level;
	}
	int Lh = getHeight(head->left, level + 1, res);
	if (!(res)) {
		return level;
	}
	int Rh = getHeight(head->right, level + 1, res);
	if (!(res)) {
		return level;
	}
	if (std::abs(Lh - Rh) > 1) {
		(res) = false;
	}
	return Lh >= Rh ? Lh : Rh;
}

bool isBalance(Node* head) {
	bool res = true;
	getHeight(head, 1, res);
	return res;
}

int main() {

	Node* t2 = new Node(2);
	t2->left = new Node(4);
	t2->left->left = new Node(8);
	t2->right = new Node(5);
	t2->left->left->right = new Node(10);

	Node* t3 = new Node(4);
	t3->left = new Node(8);
	t3->right = new Node(9);

	std::cout << isBalance(t2) << std::endl;
	std::cout << isBalance(t3) << std::endl;

	return 0;
}