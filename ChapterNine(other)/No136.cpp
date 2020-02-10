/*
�����ơ��ж�һ�����Ƿ��ھ����ڲ�
����Ŀ���ڶ�ά����ϵ�У����е�ֵ����double���ͣ���ôһ�����ο�����4������
����(x1, y1)Ϊ����ĵ㣬(x2,y2)Ϊ���ϵĵ㣬(x3,y3)Ϊ���µĵ㣬(x4,y4)Ϊ����
�ĵ㡣����4�������ľ��Σ��ٸ���һ����(x,y)���ж�(x,y)�Ƿ��ھ����С�
���Ѷȡ�ξ
*/

#include <iostream>

bool isInside(double x1, double y1, double x4, double y4, double x,
	double y) {
	if (x <= x1) {
		return false;
	}
	if (x >= x4) {
		return false;
	}
	if (y >= y1) {
		return false;
	}
	if (y <= y4) {
		return false;
	}
	return true;
}

bool isInside(double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4, double x,
	double y) {
	if (y1 == y2) {
		return isInside(x1, y1, x4, y4, x, y);
	}
	double left = std::abs(y4 - y3);
	double k = std::abs(x4 - x3);
	double s = sqrt(k * k + 1 * 1);
	double sin = left / s;
	double cos = k / s;
	double x1r = cos * x1 + sin * y1;
	double y1r = -x1 * sin + y1 * cos;
	double y4r = -x4 * sin + y4 * cos;
	double x4r = cos * x4 + sin * y4;
	double xr = cos * x + sin * y;
	double yr = -x * sin + y * cos;
	return isInside(x1r, y1r, x4r, y4r, xr, yr);
}

int main() {

	double x1 = 2.00, y1 = 2.50;
	double x2 = 3.00, y2 = 5.00;
	double x3 = 3.00, y3 = 1.50;
	double x4 = 4.00, y4 = 4.00;
	double x = 3.21, y = 3.78;

	std::cout << isInside(x1,y1,x2,y2,x3,y3,x4,y4,x,y) << std::endl;

	return 0;
}