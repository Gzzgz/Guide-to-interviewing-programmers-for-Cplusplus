/*
�����ơ����һ����getMin���ܵ�ջ
����Ŀ��ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����С��Ԫ�صĲ�����
��Ҫ��1.pop��push��getMin������ʱ�临�Ӷȶ���O(1)��2.��Ƶ�ջ���Ϳ������ֳɵ�ջ�ṹ��
���Ѷȡ�ʿ 
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
		else { //��MyStack1 ��һ��
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
			StackMin_.pop(); //��MyStack1 ��һ��
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