/*
【名称】用一个栈实现另一个栈的排序
【题目】一个栈中元素的类型为整型，现在想将该栈从顶到底按从小到大的顺序排序，只许申请一个栈，除此之外，可以申请新的变量，但不能申请额外的数据结构，如何完成排序？
【难度】士
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