/*
【名称】用栈来求解汉诺塔问题
【题目】汉诺塔问题比较经典，这里修改一下游戏规则：现在限制不能从最左侧的塔直接移动到最右侧，也不能从最右侧直接移动到最左侧，而是必须经过中间。求当塔有N层时候，打印最优移动过程和最优移动总步数。
【要求】1.递归实现；2.非递归，用栈模拟
【难度】校
*/

#include <iostream>
#include <stack>

int process1(int num, std::string left, std::string mid,
	std::string right, std::string from, std::string to) {

	if (num == 1) {
		if (from == mid || to == mid) {
			std::cout << "Move 1 from " << from.c_str() << " to " <<
				to.c_str() << std::endl;
			return 1;
		}
		else {
			std::cout << "Move 1 from " << from.c_str() << " to " << to.c_str() <<
				mid.c_str() << std::endl;
			std::cout << "Move 1 from " << mid.c_str() << " to " << to.c_str() << std::endl;
			return 2;
		}
	}
	if (from == mid || to == mid) {
		std::string another = (from == left || to == left) ? right: left;
		int part1 = process1(num - 1, left, mid, right, from, another);
		int part2 = 1;
		std::cout << "Move " << num << " from " << from.c_str() << " to " << to.c_str() << std::endl;
		int part3 = process1(num - 1, left, mid, right, another, to);
		return part1 + part2 + part3;
	}
	else {
		int part1 = process1(num - 1, left, mid, right, from, to);
		int part2 = 1;
		std::cout << "Move " << num << " from " << from.c_str() << " to "
			<< mid.c_str() << std::endl;
		int part3 = process1(num - 1, left, mid, right, to, from);
		int part4 = 1;
		std::cout << "Move " << num << " from " << mid.c_str() << " to " <<
			to.c_str() << std::endl;
		int part5 = process1(num - 1, left, mid, right, from, to);
		return part1 + part2 + part3 + part4 + part5;
	}
}

int hanoiProblem1(int num, std::string left, std::string mid,
	std::string right) {
	if (num < 1)
		return 0;
	return process1(num, left, mid, right, left, right);
}


enum Action {
	No, LToM, MToL, MToR, RToM
};

int fStackToStack(Action record[], Action preNoAct, Action nowAct,
	std::stack<int>& fStack, std::stack<int>& tStack,
	std::string from, std::string to) {

	if (record[0] != preNoAct && fStack.top() < tStack.top()) {
		tStack.push(fStack.top());
		fStack.pop();
		std::cout << "Move " << tStack.top() << " from " << from.c_str() <<
			" to " << to.c_str() << std::endl;
		record[0] = nowAct;
		return 1;
	}
	return 0;
}

int hanoiProblem2(int num, std::string left, std::string mid, 
	std::string right){

	std::stack<int> ls, ms, rs;
	ls.push(INT_MAX);
	ms.push(INT_MAX);
	rs.push(INT_MAX);

	for (int i = num; i > 0; i--) {
		ls.push(i);
	}
	Action record[] = {No};
	int step = 0;

	while (rs.size() != num + 1) {
		step += fStackToStack(record, MToL, LToM, ls, ms, left, mid);
		step += fStackToStack(record, LToM, MToL, ms, ls, mid, left);
		step += fStackToStack(record, RToM, MToR, ms, rs, mid, right);
		step += fStackToStack(record, MToR, RToM, rs, ms, right, mid);
	}

	return step;
}

int main() {

	std::cout << hanoiProblem2(2, "left", "mid",
		"right") << std::endl;

	return 0;
}