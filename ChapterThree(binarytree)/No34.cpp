/*
�����ơ������������л��ͷ����л�
����Ŀ������������¼���ļ��Ĺ��̽��������������л���ͨ���ļ�����
�ؽ�ԭ���������Ĺ��̽����������ķ����л�������һ�ö�������ͷ�ڵ�
head������֪�������ڵ�ֵ������Ϊ32λ���ͣ������һ�ֶ��������л�
�ͷ����л��÷��������ô���ʵ��
���Ѷȡ�ʿ
*/
#include <iostream>
#include <queue>
#include <string>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

std::string serialByPre(Node* head) {
	if (head == nullptr) {
		return "#!";
	}
	std::string res = std::to_string(head->value) + "!";
	res += serialByPre(head->left);
	res += serialByPre(head->right);

	return res;
}

Node* reconPreOrder(std::queue<std::string>& queue) {
	std::string value = queue.front();
	queue.pop();
	if (value == "#") {
		return nullptr;
	}
	Node * head = new Node(stoi(value));
	head->left = reconPreOrder(queue);
	head->right = reconPreOrder(queue);
	return head;
}

std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
	//const char* convert to char*
	char * strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());
	std::vector<std::string> resultVec;
	char* tmpStr = strtok(strc, pattern.c_str());
	while (tmpStr != NULL)
	{
		resultVec.push_back(std::string(tmpStr));
		tmpStr = strtok(NULL, pattern.c_str());
	}

	delete[] strc;

	return resultVec;
}

Node* reconByPreString(std::string preStr) {
	std::vector<std::string> values = split(preStr, "!");
	std::queue<std::string> queue;
	for (int i = 0; i < values.size(); i ++) {
		queue.push(values[i]);
	}
	return reconPreOrder(queue);
}

void showTree(Node* head) {
	if (head == nullptr) {
		return;
	}
	std::cout << head->value << std::endl;
	showTree(head->left);
	showTree(head->right);
}

std::string serialByLevel(Node* head) {
	if (head == nullptr) {
		return "#!";
	}
	std::string res = std::to_string(head->value) + "!";
	std::queue<Node*> queue;
	queue.push(head);
	while (!queue.empty()) {
		head = queue.front();
		queue.pop();
		if (head->left != nullptr) {
			res += std::to_string(head->left->value) + "!";
			queue.push(head->left);
		}
		else {
			res += "#!";
		}
		if (head->right != nullptr) {
			res += std::to_string(head->right->value) + "!";
			queue.push(head->right);
		}
		else {
			res += "#!";
		}
	}
	return res;
}

Node* generateNodeByString(std::string val) {
	if (val == "#") {
		return nullptr;
	}
	return new Node(stoi(val));
}

Node* reconByLevelString(std::string levelStr) {
	std::vector<std::string> values = split(levelStr, "!");
	std::queue<Node*> queue;
	int index = 0;
	Node* head = generateNodeByString(values[index++]);
	if (head != nullptr) {
		queue.push(head);
	}
	Node* node = nullptr;
	while (!queue.empty()) {
		node = queue.front();
		queue.pop();
		node->left = generateNodeByString(values[index++]);
		node->right = generateNodeByString(values[index++]);
		if (node->left != nullptr) {
			queue.push(node->left);
		}
		if (node->right != nullptr) {
			queue.push(node->right);
		}
	}
	return head;
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->right->right = new Node(5);

	std::string res = serialByPre(head);

	std::cout << res << std::endl;

	head = reconByPreString(res);

	showTree(head);

	res = serialByLevel(head);

	std::cout << res << std::endl;

	head = reconByLevelString(res);

	showTree(head);

	return 0;
}