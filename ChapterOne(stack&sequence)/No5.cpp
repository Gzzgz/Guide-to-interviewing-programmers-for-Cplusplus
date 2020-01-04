/*
�����ơ���һ��ջʵ����һ��ջ������
����Ŀ��һ��ջ��Ԫ�ص�����Ϊ���ͣ������뽫��ջ�Ӷ����װ���С�����˳������ֻ������һ��ջ������֮�⣬���������µı����������������������ݽṹ������������
���Ѷȡ�ʿ
*/

#include <iostream>
#include <stack>

void sortStackByStack(std::stack<int>& stack) {
	std::stack<int> help_;
	
	while (!stack.empty()) {
		int cur = stack.top();
		stack.pop();
		while (!help_.empty() && help_.top() > cur) {
			stack.push(help_.top());
			help_.pop();
		}
		help_.push(cur);
	}
	while (!help_.empty()) {
		stack.push(help_.top());
		help_.pop();

	}
}

int main() {

	int IntArray[5] = {3, 4, 2, 1, 5};
	std::stack<int> sort_stack;
	for (int i = 0; i < 5; i++)
		sort_stack.push(IntArray[i]);
	sortStackByStack(sort_stack);

	for (int i = 0; i < 5; i++) {
		std::cout << "pop: " << sort_stack.top() << std::endl;
		sort_stack.pop();
	}
	

	return 0;
}