/*
【名称】龙与地下城游戏问题
【题目】给定一个二维数组map，含义是一张地图，例如：
-2 -3  3
-5 -10 1
0  30 -5
游戏的规则如下：
1.骑士从左上角出发，每次只能向右或向下走，最后到达右下角见到公主；
2.地图中每个位置的值代表骑士要遭遇的事情，如果是负数，说明此处右
怪兽，要让骑士损失血量，如果非负数，代表此处有血瓶，能让骑士回血；
3.骑士从左上角到右下角的过程中，走到任何一个位置时，血量都不能少于1
【难度】尉
*/
#include <iostream>

int minHP1(int** m, int rows, int cols) {
	if (rows ==0 || cols == 0) {
		return 1;
	}
	int** dp = new int*[rows];
	for (int i = 0; i <rows; i ++) {
		dp[i] = new int[cols];
		for (int j = 0; j < cols; j ++) {
			dp[i][j] = 0;
		}
	}
	dp[rows - 1][cols - 1] = m[rows - 1][cols - 1] > 0 ? 1 : -m[rows - 1][cols - 1] + 1;
	rows--; cols--;
	for (int j = cols - 1; j >= 0; j --) {
		dp[rows][j] = dp[rows][j + 1] - m[rows][j] > 1 ? dp[rows][j + 1] - m[rows][j] : 1;
	}
	int right = 0;
	int down = 0;
	for (int i = rows - 1; i >= 0; i --) {
		dp[i][cols] = dp[i + 1][cols] - m[i][cols] > 1 ? dp[i + 1][cols] - m[i][cols] : 1;
		for (int j = cols - 1; j >= 0; j --) {
			right = dp[i][j + 1] - m[i][j] > 1 ? dp[i][j + 1] - m[i][j] : 1;
			down = dp[i + 1][j] - m[i][j] > 1 ? dp[i + 1][j] - m[i][j] : 1;
			dp[i][j] = right < down ? right : down;
		}
	}
	int res = dp[0][0];
	for (int i = 0; i < rows; i ++) {
		delete[] dp[i];
	}
	delete[] dp;
	return res;
}

int minHP2(int** m, int rows, int cols) {
	if (rows == 0 || cols == 0) {
		return 1;
	}
	int more = rows > cols ? rows : cols;
	int less = rows < cols ? rows : cols;
	bool rowmore = more == rows;

	int* dp = new int[less];
	for (int i = 0; i <less; i++) {
		dp[i] = 0;
	}
	dp[less - 1] = m[rows - 1][cols - 1] > 0 ? 1 : -m[rows - 1][cols - 1] + 1;
	int row = 0;
	int col = 0;
	for (int j = less - 2; j >= 0; j --) {
		row = rowmore ? more - 1 : j;
		col = rowmore ? j : more - 1;
		dp[j] = dp[j + 1] - m[row][col] > 1 ? dp[j + 1] - m[row][col] : 1;
	}
	int choosen1 = 0;
	int choosen2 = 0;
	for (int i = more - 2; i >= 0; i --) {
		row = rowmore ? i : less - 1;
		col = rowmore ? less - 1 : i;
		dp[less - 1] = dp[less - 1] - m[row][col] > 1 ? dp[less - 1] - m[row][col] : 1;
		for (int j = less - 2; j >= 0; j --) {
			row = rowmore ? i : j;
			col = rowmore ? j : i;
			choosen1 = dp[j] - m[row][col] > 1 ? dp[j] - m[row][col] : 1;
			choosen2 = dp[j + 1] - m[row][col] > 1 ? dp[j + 1] - m[row][col] : 1;
			dp[j] = choosen1 < choosen2 ? choosen1 : choosen2;
		}
	}
	int res = dp[0];
	delete[] dp;
	return res;

}


int main() {
	int arr[] = {-2, -3, 3, -5, -10, 1, 0, 30, -5};
	int count = 0;
	int** map = new int*[3];
	for (int i = 0; i < 3; i ++) {
		map[i] = new int[3];
		for (int j = 0; j < 3; j ++) {
			map[i][j] = arr[count++];
		}
	}

	std::cout << minHP2(map, 3, 3) << std::endl;

	for (int i = 0; i < 3; i ++) {
		delete[] map[i];
	}
	delete[] map;

	return 0;
}