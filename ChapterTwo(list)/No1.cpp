/*
【名称】设计一个有getMin功能的栈
【题目】实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小的元素的操作。
【要求】1.pop、push、getMin操作的时间复杂度都是O(1)；2.设计的栈类型可以用现成的栈结构。
【难度】士 
*/

#include <iostream>
#include <stack>

class MyStack1 {

public:
	MyStack1() {
	}
public:
	void push(int NewNum) {
		if (StackMin_.empty() || NewNum <= getMin()) {
			StackMin_.push(NewNum);
		}
		StackData_.push(NewNum);
		std::cout << "push: " << NewNum << std::endl;
	}
	int pop() {
		int value = -1;
		if (!StackData_.empty()) {
			value = StackData_.top();
			StackData_.pop();
		}
		if (value == getMin()) {
			StackMin_.pop();
		}
		return value;
	}
	int getMin() {
		if (StackMin_.empty()) {
			return -1;
		}
		return StackMin_.top();
	}
private:
	std::stack<int> StackData_;
	std::stack<int> StackMin_;
};

class MyStack2 {

public:
	MyStack2() {
	}
public:
	void push(int NewNum) {
		if (StackMin_.empty() || NewNum <= getMin()) {
			StackMin_.push(NewNum);
		}
		else { //与MyStack1 不一样
			StackMin_.push(StackMin_.top());
		}
		StackData_.push(NewNum);
		std::cout << "push: " << NewNum << std::endl;
	}
	int pop() {
		int value = -1;
		if (!StackData_.empty()) {
			value = StackData_.top();
			StackData_.pop();
			StackMin_.pop(); //与MyStack1 不一样
		}
		return value;
	}
	int getMin() {
		if (StackMin_.empty()) {
			return -1;
		}
		return StackMin_.top();
	}
private:
	std::stack<int> StackData_;
	std::stack<int> StackMin_;
};


int main() {

	int TestArry[6] = {3, 4, 5, 1, 2, 1};


	MyStack1 mystack1;
	for (int i = 0; i < 6; i++)
		mystack1.push(TestArry[i]);

	for (int i = 0; i < 6; i++) {
		int minvalue = mystack1.getMin();
		int popvalue = mystack1.pop();
		std::cout << "pop: " << popvalue << std::endl;
		std::cout << "min: " << minvalue << std::endl;
	}
		
	MyStack1 mystack2;
	for (int i = 0; i < 6; i++)
		mystack2.push(TestArry[i]);

	for (int i = 0; i < 6; i++) {
		int minvalue = mystack2.getMin();
		int popvalue = mystack2.pop();
		std::cout << "pop: " << popvalue << std::endl;
		std::cout << "min: " << minvalue << std::endl;
	}

	return 0;
}