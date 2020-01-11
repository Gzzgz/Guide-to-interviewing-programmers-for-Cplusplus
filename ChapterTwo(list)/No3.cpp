/*
【名称】如何仅用递归函数和栈操作逆序一个栈
【题目】一个栈依次压入1、2、3、4、5，那么从栈顶到栈底分别为5、4、3、2、1.将这个栈转置后，从栈顶到栈底为1、2、3、4、5，也就是实现栈中元素的逆序，但是只能用递归函数来实现，不能用其他数据结构。
【难度】尉
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