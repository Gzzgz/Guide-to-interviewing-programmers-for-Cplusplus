/*
�����ơ������������С������ɺ�
����Ŀ������һ����������arr���������е�ֵ������������������С������ɺ͸��
1.��arrÿ���Ӽ��ڵ�����Ԫ�ؼ���������ֺܶ�ֵ��������С�ļ�Ϊmin�����ļ�Ϊmax;
2.������[min,max]�ϣ�������������Ա�arrĳһ���Ӽ���ӵõ�����ô������С���Ǹ�
����arr����С������ɺͣ�
3.������[min, max]�ϣ�������е��������Ա� arr��ĳһ���Ӽ���ӵõ�����ômax+1
��arr����С������ɺ͡�
��д����������������arr����С������ɺ͡�
��������Ŀ�������֪��������arr�п϶���1��������Ƿ��ܸ���صõ���С������ɺ�
���Ѷȡ�ξ
*/
#include <iostream>
#include <set>

void process(int* arr, int len, int i, int sum, std::set<int>& set) {
	if (i == len) {
		set.insert(sum);
		return;
	}
	process(arr, len, i + 1, sum, set);
	process(arr, len, i + 1, sum + arr[i], set);
}

int unformedSum1(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 1;
	}
	std::set<int> set;
	process(arr, len, 0, 0, set);
	int min = INT_MAX;
	for (int i = 0; i < len; i ++) {
		min = min < arr[i] ? min : arr[i];
	}
	for (int i = min + 1; i != INT_MAX; i ++) {
		if (set.find(i) == set.end()) {
			return i;
		}
	}
	return 0;
}


int unformedSum2(int* arr, int len) {
	if (arr == nullptr || len == 0) {
		return 1;
	}
	int sum = 0;
	int min = INT_MAX;
	for (int i = 0; i < len; i ++) {
		sum += arr[i];
		min = min < arr[i] ? min : arr[i];
	}
	bool* dp = new bool[sum + 1];
	memset(dp, 0, sizeof(bool) * len);
	dp[0] = true;
	for (int i = 0; i < len; i ++) {
		for (int j = sum; j >= arr[i]; j --) {
			dp[j] = dp[j - arr[i]] ? true : dp[j];
		}
	}
	for (int i = min; i < sum + 1; i ++) {
		if (!dp[i]) {
			return i;
		}
	}
	return sum + 1;
}


int main() {
	
	int arr[] = {3, 2, 5};

	std::cout << unformedSum2(arr, 3) << std::endl;

	return 0;
}