/*
�����ơ�ͨ������������������ɺ�������
����Ŀ����֪һ�ö��������еĽڵ�ֵ����ͬ�������������ȷ��������������飬
��Ҫ�ؽ�������������ͨ������������ֱ��������ȷ�ĺ������顣
���Ѷȡ�ʿ
*/
#include <iostream>
#include <map>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

int setPos(int* p, int pi, int pj, int* n, int ni, int nj,
	int* s, int si, std::map<int, int>& map) {
	if (pi > pj) {
		return si;
	}
	s[si--] = p[pi];
	int i = map[p[pi]];
	si = setPos(p, pj - nj + i + 1, pj, n, i + 1, nj, s, si, map);
	return setPos(p, pi + 1, pi + i - ni, n, ni, i - 1, s, si, map);
}

void getPosArray(int* pre, int* in, int len, int* out) {
	if (len == 0 || pre == nullptr || in == nullptr) {
		return;
	}
	std::map<int, int> map;
	for (int i = 0; i < len; i ++) {
		map.insert(std::pair<int, int>(in[i], i));
	}
	setPos(pre, 0, len - 1, in, 0, len - 1, out, len - 1, map);
}

int main(){

	int pre[7] = {1,2,4,5,3,6,7};
	int in[7] = {4,2,5,1,6,3,7};
	int pos[7] = {0};

	getPosArray(pre, in, 7, pos);
	for (int i = 0; i < 7; i ++) {
		std::cout << pos[i] << std::endl;
	}

	return 0;
}