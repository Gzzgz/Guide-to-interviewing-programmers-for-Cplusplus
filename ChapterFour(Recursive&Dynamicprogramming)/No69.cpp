/*
【名称】跳跃游戏
【题目】给定数组arr，arr[i]=k代表可以从位置i向右跳1-k个距离，比如arr[2]==3,
代表从位置2可以跳到位置3，4，5。如果从位置0出发返回最少跳几次能跳到arr最后的位置上
要求：如果arr长度为N,要求实现时间复杂度为O(N),额外空间复杂度为O(1)的方法
【难度】士
*/

#include <iostream>

int jump(int* arr, int len) {
	if (len == 0) {
		return 0;
	}
	int jump = 0;
	int cur = 0;
	int next = 0;
	for (int i = 0; i < len; i ++) {
		if (cur < i) {
			jump++;
			cur = next;
		}
		next = next > (i + arr[i]) ? next : (i + arr[i]);
	}
	return jump;
}

int main() {

	int arr[] = {3,2,3,1,1,4};
	std::cout << jump(arr, 6) << std::endl;

	return 0;
}