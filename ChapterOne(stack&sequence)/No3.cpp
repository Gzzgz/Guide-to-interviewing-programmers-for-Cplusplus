/*
�����ơ���ν��õݹ麯����ջ��������һ��ջ
����Ŀ��һ��ջ����ѹ��1��2��3��4��5����ô��ջ����ջ�׷ֱ�Ϊ5��4��3��2��1.�����ջת�ú󣬴�ջ����ջ��Ϊ1��2��3��4��5��Ҳ����ʵ��ջ��Ԫ�ص����򣬵���ֻ���õݹ麯����ʵ�֣��������������ݽṹ��
���Ѷȡ�ξ
*/

#include <iostream>
#include <stack>

int getAndRemoveLastElement(std::stack<int>& stack) {

	int res = -1;
	int value = stack.top();
	stack.pop();
	res = value;
	if (!stack.empty()) {
		res = getAndRemoveLastElement(stack);
		stack.push(value);
	}
	return res;
}

void reverse(std::stack<int>& stack) {

	if (stack.empty()) {
		return;
	}
	int value = getAndRemoveLastElement(stack);
	reverse(stack);
	stack.push(value);
}

int main() {

	std::stack<int> reverse_statck;
	for (int i = 1; i < 6; i++) {
		reverse_statck.push(i);
	}

	reverse(reverse_statck);
	for (int i = 0; i < 5; i++) {
		std::cout << "pop: " << reverse_statck.top() << std::endl;
		reverse_statck.pop();
	}

	return 0;
}