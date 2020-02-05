/*
�����ơ�δ���������������ۼӺ�Ϊ����ֵ��������鳤��
����Ŀ������һ������arr�����������򣬵�ÿ��ֵ��Ϊ�������ٸ���һ������k����arr
������������������Ԫ����Ӻ�Ϊk��������鳤�ȡ�
����arr=[1,2,1,1,1],k=3
�ۼӺ�Ϊ3���������Ϊ[1,1,1]�����Խ������3.
���Ѷȡ�ξ
*/

#include <iostream>


int getMaxLength(int* arr, int length, int k) {
	if (length == 0 || k <= 0) {
		return 0;
	}
	int left = 0;
	int right = 0;
	int sum = arr[0];
	int len = 0;
	while (right < length) {
		if (sum == k) {
			len = len > (right - left + 1) ? len : (right - left + 1);
			sum -= arr[left ++];
		}
		else if (sum < k) {
			right++;
			if (right == length) {
				break;
			}
			sum += arr[right];
		}
		else {
			sum -= arr[left++];
		}
	}
	return len;
}

int main() {

	int arr[] = {1,2,1,1,1};
	std::cout << getMaxLength(arr, 5, 3) << std::endl;

	return 0;
}