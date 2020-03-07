/*
【名称】通过先序和中序数组生成后序数组
【题目】已知一棵二叉树所有的节点值都不同，给定这棵树正确的先序和中序数组，
不要重建整棵树，而是通过这两个数组直接生成正确的后序数组。
【难度】士
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