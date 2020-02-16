/*
�����ơ�������³���Ϸ����
����Ŀ������һ����ά����map��������һ�ŵ�ͼ�����磺
-2 -3  3
-5 -10 1
0  30 -5
��Ϸ�Ĺ������£�
1.��ʿ�����Ͻǳ�����ÿ��ֻ�����һ������ߣ���󵽴����½Ǽ���������
2.��ͼ��ÿ��λ�õ�ֵ������ʿҪ���������飬����Ǹ�����˵���˴���
���ޣ�Ҫ����ʿ��ʧѪ��������Ǹ���������˴���Ѫƿ��������ʿ��Ѫ��
3.��ʿ�����Ͻǵ����½ǵĹ����У��ߵ��κ�һ��λ��ʱ��Ѫ������������1
���Ѷȡ�ξ
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