/*
�����ơ�ͳ�ƺ��������в�ͬ�Ķ�����
����Ŀ������һ������N�����N<1����������ṹ�����������������Ľ��Ϊ{1��2��3��������N}.
�뷵�ؿ��ܵĶ������ṹ�ж��١�
���ף�N�ĺ��岻�䣬������ܵĶ������ṹ��M�֣��뷵��M����������ͷ�ڵ㣬ÿһ�ö���������һ�ֿ��ܵĽṹ
���Ѷȡ�ξ
*/
#include <iostream>
#include <vector>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

int numTrees(int n) {
	if (n< 2) {
		return 1;
	}
	int* num = new int[n + 1];
	memset(num, 0, sizeof(int) * (n + 1));
	num[0] = 1;
	for (int i = 1; i < n + 1; i ++) {
		for (int j = 1; j < i + 1; j ++) {
			num[i] += num[j - 1] * num[i - j];
		}
	}
	return num[n];
}

Node* cloneTree(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* res = new Node(head->value);
	res->left = cloneTree(head->left);
	res->right = cloneTree(head->right);
	return res;
}

std::vector<Node*> generate(int start, int end) {
	std::vector<Node*> res;
	if (start > end) {
		res.push_back(nullptr);
	}
	Node* head = nullptr;
	for (int i = start; i < end + 1; i ++) {
		head = new Node(i);
		std::vector<Node*> lsubs = generate(start, i - 1);
		std::vector<Node*> rsubs = generate(i + 1, end);
		for (std::vector<Node*>::iterator iterleft = lsubs.begin();
			iterleft != lsubs.end(); iterleft++) {
			for (std::vector<Node*>::iterator iterright = rsubs.begin();
				iterright != rsubs.end(); iterright++) {
				head->left = *iterleft;
				head->right = *iterright;
				res.push_back(cloneTree(head));
			}
		}
	}
	return res;
}

std::vector<Node*> generateTrees(int n) {
	return generate(1, n);
}

int main() {

	//std::cout << numTrees(3) << std::endl;
	std::vector<Node*> vec = generateTrees(3);

	for (int i = 0; i < vec.size(); i ++) {
		std::cout << vec[i]->value<<std::endl;
	}

	return 0;
}