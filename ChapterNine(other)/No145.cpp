/*
�����ơ�·�������Ϊͳ������
����Ŀ������һ��·������paths,��ʾһ��ͼ��paths[i]==j���������i�������j��
���paths[i]==i,���ʾi�������׶���һ��ͼ��ֻ����һ���׶���ͼ�г��׶���ָ��
�Լ�֮�ⲻ���л���ͳ������Ϊnums=[1,1,3,2,3,0,0,0,0,0],nums[i]==j�������Ϊi
�ĳ�����j����Ҫ��ʵ��һ��void���͵ĺ���������һ��·������paths,ֱ����ԭ����
�ϵ�����ʹ֮��Ϊnums���飬��paths=[9,1,4,9,0,4,8,9,0,1]������������������
[1,1,3,2,3,0,0,0,0,0]
Ҫ��paths����N,ʱ�临�Ӷ�O(N),�ռ临�Ӷ�O(1)
���Ѷȡ�У
*/
#include <iostream>

void pathsToDistances(int* paths, int len) {
	int cap = 0;
	for (int i = 0; i < len; i ++) {
		if (paths[i] == i) {
			cap = i;
		}
		else if (paths[i] > -1) {
			int curI = paths[i];
			paths[i] = -1;
			int preI = i;
			while (paths[curI] != curI) {
				if (paths[curI] > -1) {
					int nextI = paths[curI];
					paths[curI] = preI;
					preI = curI;
					curI = nextI;
				}
				else {
					break;
				}
			}
			int value = paths[curI] == curI ? 0 : paths[curI];
			while (paths[preI] != -1) {
				int lastPreI = paths[preI];
				paths[preI] = --value;
				//curI = preI;
				preI = lastPreI;
			}
			paths[preI] = --value;
		}
	}
	paths[cap] = 0;
}

void distanceToNums(int* disArr, int len) {
	for (int i = 0; i < len; i ++) {
		int index = disArr[i];
		if (index < 0) {
			disArr[i] = 0;
			while (true) {
				index -= 2 * index;
				if (disArr[index] > -1) {
					disArr[index]++;
					break;
				}
				else {
					int nextIndex = disArr[index];
					disArr[index] = 1;
					index = nextIndex;
				}
			}
		}
	}
	disArr[0] = 1;
}

void pathsToNums(int* paths, int len) {
	if (paths == nullptr || len == 0) {
		return;
	}
	pathsToDistances(paths, len);
	distanceToNums(paths, len);
}

int main() {

	int arr[] = {9,1,4,9,0,4,8,9,0,1};
	pathsToNums(arr, 10);
	for (int i = 0; i < 10; i ++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}