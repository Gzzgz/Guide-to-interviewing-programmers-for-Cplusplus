/*
����Ŀ����дһ���࣬������ջʵ�ֶ��У�֧�ֶ��еĻ���������add, poll, peek��
���Ѷȡ�ξ
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