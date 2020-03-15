/*
【名称】丢棋子问题
【题目】一座大楼0-N层，地面算0层，最高一层为N层。已知棋子从0层掉落肯定
不会摔碎，从i层掉落可能会摔碎，也可能不会摔碎(1<=i<=N)。给定整数N作为
楼层数，再给定整数K作为棋子数，返回如果想找到棋子不会摔碎的最高层数，即
使在最差的情况下扔的最少次数，一次只能扔一个棋子。
【难度】校
*/
#include <iostream>

int minf(int a, int b) {
	return a < b ? a : b;
}

int maxf(int a, int b) {
	return a > b ? a : b;
}

int Process1(int nLevel, int kChess) {
	if (nLevel == 0) {
		return 0;
	}
	if (kChess == 1) {
		return nLevel;
	}
	int min = INT_MAX;
	for (int i = 1; i < nLevel + 1; i ++) {
		min = minf(min, maxf(Process1(i - 1, kChess - 1), 
			Process1(nLevel - i, kChess)));
	}
	return min + 1;
}

int solution1(int nLevel, int kChess) {
	if (nLevel < 1 || kChess < 1) {
		return 0;
	}
	return Process1(nLevel, kChess);
}

int solution2(int nLevel, int kChess) {
	if (nLevel < 1 || kChess < 1) {
		return 0;
	}
	if (kChess == 1) {
		return nLevel;
	}
	int** dp = new int*[nLevel + 1];
	for (int i = 0; i < nLevel + 1; i ++) {
		dp[i] = new int[kChess + 1];
		memset(dp[i], 0, sizeof(int) * (kChess + 1));
	}
	for (int i = 1; i < nLevel + 1; i ++) {
		dp[i][1] = i;
	}
	for (int i = 1; i < nLevel + 1; i ++) {
		for (int j = 2; j < kChess + 1; j ++) {
			int min = INT_MAX;
			for (int k = 1; k < i + 1; k ++) {
				min = minf(min, maxf(dp[k - 1][j - 1], dp[i - k][j]));
			}
			dp[i][j] = min + 1;
		}
	}
	return dp[nLevel][kChess];
}

int solution3(int nLevel, int kChess) {
	if (nLevel < 1 || kChess < 1) {
		return 0;
	}
	if (kChess == 1) {
		return nLevel;
	}
	int* preArr = new int[nLevel + 1];
	int* curArr = new int[nLevel + 1];
	memset(preArr, 0, sizeof(int) * (nLevel + 1));
	memset(curArr, 0, sizeof(int) * (nLevel + 1));

	for (int i = 1; i != nLevel + 1; i ++) {
		curArr[i] = i;
	}
	for (int i = 1; i != kChess; i ++) {
		int* tmp = preArr;
		preArr = curArr;
		curArr = tmp;
		for (int j = 1; j < nLevel + 1; j ++) {
			int min = INT_MAX;
			for (int k = 1; k != j + 1; k ++) {
				min = minf(min, maxf(preArr[k - 1], curArr[j - k]));
			}
			curArr[j] = min + 1;
		}
	}
	return curArr[nLevel - 1];
}

int solution4(int nLevel, int kChess) {
	if (nLevel < 1 || kChess < 1) {
		return 0;
	}
	if (kChess == 1) {
		return nLevel;
	}
	int** dp = new int*[nLevel + 1];
	for (int i = 0; i < nLevel + 1; i ++) {
		dp[i] = new int[kChess + 1];
		memset(dp[i], 0, sizeof(int) * (kChess + 1));
	}
	for (int i = 1; i != nLevel + 1; i ++) {
		dp[i][1] = i;
	}
	int* cands = new int[kChess + 1];
	memset(cands, 0, sizeof(int) * (kChess + 1));
	for (int i = 1; i != kChess + 1; i ++) {
		dp[1][i] = 1;
		cands[i] = 1;
	}
	for (int i = 2; i < nLevel + 1; i ++) {
		for (int j = kChess; j > 1; j --) {
			int min = INT_MAX;
			int minEnum = cands[j];
			int maxEnum = j == kChess ? i / 2 + 1 : cands[j + 1];
			for (int k = minEnum; k < maxEnum + 1; k ++) {
				int cur = maxf(dp[k - 1][j - 1], dp[i - k][j]);
				if (cur <= min) {
					min = cur;
					cands[j] = k;
				}
			}
			dp[i][j] = min + 1;
		}
	}
	return dp[nLevel][kChess];
}

int log2N(int n) {
	int res = -1;
	while (n != 0) {
		res++;
		n >>= 1;
	}
	return res;
}

int solution5(int nLevel, int kChess) {
	if (nLevel < 1 || kChess < 1) {
		return 0;
	}
	int bsTimes = log2N(nLevel) + 1;
	if (kChess >= bsTimes) {
		return bsTimes;
	}
	int* dp = new int[kChess];
	memset(dp, 0, sizeof(int) * kChess);
	int res = 0;
	while (true) {
		res++;
		int previous = 0;
		for (int i = 0; i < kChess; i ++) {
			int tmp = dp[i];
			dp[i] = dp[i] + previous + 1;
			previous = tmp;
			if (dp[i] >= nLevel) {
				return res;
			}
		}
	}
}


int main() {

	std::cout << solution5(10, 2) << std::endl;

	return 0;
}