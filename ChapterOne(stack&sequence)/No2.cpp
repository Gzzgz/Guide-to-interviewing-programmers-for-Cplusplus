/*
【题目】编写一个类，用两个栈实现队列，支持队列的基本操作（add, poll, peek）
【难度】尉
*/

#include <iostream>
#include <stack>

class TwoStacksQueue {

public:
	TwoStacksQueue() {
	}
public:
	void add(int pushInt) {
		StackPush_.push(pushInt);
	}
	void poll() {
		if (StackPop_.empty() && !StackPush_.empty()) {
			while (!StackPush_.empty()) {
				StackPop_.push(StackPush_.top());
				StackPush_.pop();
			}
		}
	    StackPop_.pop();
	}
	int peek() {
		if (StackPop_.empty() && !StackPush_.empty()) {
			while (!StackPush_.empty()) {
				StackPop_.push(StackPush_.top());
				StackPush_.pop();
			}
		}
		return StackPop_.top();
	}
private:
	std::stack<int> StackPush_;
	std::stack<int> StackPop_;
};


int main() {

	int IntArray[5] = {1, 2, 3, 4, 5};

	TwoStacksQueue tsq;

	for (int i = 0; i < 5; i++) {
		tsq.add(IntArray[i]);
	}
	for (int i = 0; i < 5; i++) {
		std::cout << "peek: " << tsq.peek() << std::endl;
		tsq.poll();
	}

	return 0;
}