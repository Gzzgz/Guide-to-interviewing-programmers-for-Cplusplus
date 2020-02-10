/*
【名称】折纸问题
【题目】请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕
后展开。此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。如果从纸条的下边
向上方连续对折2次，压出折痕后展开，此时由三条折痕，从上到下依次是下折痕，下折痕，
上折痕。给定一个输入参数N,代表纸条都从下边向上方连续对折N次，请从上到下打印
所有折痕的方向。
例如：N=1，down
N=2, down,down,up
【难度】尉
*/
#include <iostream>


void printProcess(int i, int n, bool down) {
	if (i > n) {
		return;
	}
	printProcess(i + 1, n, true);
	std::string str = down ? "down" : "up";
	std::cout << str.c_str() << std::endl;
	printProcess(i + 1, n, false);
}

void printAllFolds(int n) {
	printProcess(1, n, true);
}


int main() {

	printAllFolds(2);

	return 0;
}