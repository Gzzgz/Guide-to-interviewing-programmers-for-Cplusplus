/*
【名称】求最短通路值
【题目】用一个整型矩阵matrix表示一个网络，1代表有路，0代表无路，每一个位置
只要不越界，都有上下左右4个方向，求从最左上角到最右下角的最短通路值
例如：
1 0 1 1 1
1 0 1 0 1
1 1 1 0 1
0 0 0 0 1
返回12
【难度】尉
*/

#include <iostream>
#include <queue>

void walkTo(int pre, int tor, int toc, int** m, int** map,
	int rows, int cols, std::queue<int>& rq, std::queue<int>& cq) {
	if (tor < 0 || tor == rows || toc < 0 || toc == cols
		|| m[tor][toc] != 1 || map[tor][toc] != 0) {
		return;
	}
	map[tor][toc] = pre + 1;
	rq.push(tor);
	cq.push(toc);
}

int minPathValue(int** m, int rows, int cols) {
	if (m == nullptr || rows == 0 || cols == 0 || m[0][0] != 1
		|| m[rows - 1][cols - 1] != 1) {
		return 0;
	}
	int res = 0;
	int** map = new int*[rows];
	for (int i = 0; i < rows; i ++) {
		map[i] = new int[cols];
		for (int j = 0; j < cols; j ++) {
			map[i][j] = 0;
		}
	}
	map[0][0] = 1;
	std::queue<int> rq, cq;
	rq.push(0);
	cq.push(0);
	int r = 0;
	int c = 0;
	while (!rq.empty()) {
		r = rq.front();
		c = cq.front();
		rq.pop();
		cq.pop();
		if (r == rows - 1 && c == cols - 1) {
			return map[r][c];
		}
		walkTo(map[r][c], r - 1, c, m, map, rows, cols, rq, cq);
		walkTo(map[r][c], r + 1, c, m, map, rows, cols, rq, cq);
		walkTo(map[r][c], r, c - 1, m, map, rows, cols, rq, cq);
		walkTo(map[r][c], r, c + 1, m, map, rows, cols, rq, cq);
	}
	return res;
}

int main() {
	int arr[] = {
		1,0,1,1,1,
		1,0,1,0,1,
		1,1,1,0,1,
		0,0,0,0,1};
	int count = 0;
	int** m = new int*[4];
	for (int i = 0; i < 4; i ++) {
		m[i] = new int[5];
		for (int j = 0; j < 5; j ++) {
			m[i][j] = arr[count++];
		}
	}
	
	std::cout << minPathValue(m, 4, 5) << std::endl;
	delete[] m;

	return 0;
}
