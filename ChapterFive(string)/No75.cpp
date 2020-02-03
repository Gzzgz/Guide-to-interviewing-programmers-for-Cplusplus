/*
【名称】判断两个字符串是否互为旋转词
【题目】如果一个字符串str，把字符串str前面任意的部分挪到后面形成的字符串
叫作str的旋转词。比如str=“12345”,str的旋转词有"12345","23451", "34512",
"45123","51234".给定两个字符串a,b，请判断a和b是否互为旋转词。
要求：如果a，b长度不一样，那么a,b必然不互为旋转词，可以直接返回false，当
a和b长度一样，都为N,要求解法的时间复杂度为O(N)
【难度】士
*/

#include <iostream>


bool isRotation(std::string a, std::string b) {
	if (a == "" || b == "" || a.length() != b.length()) {
		return false;
	}
	std::string b2 = b + b;
	return b2.find(a) != -1;
}

int main() {

	std::string arr1 = "abcd";
	std::string arr2 = "cdab";
	std::string arr3 = "cdba";

	std::cout << "arr1 arr2: " << isRotation(arr1, arr2) << std::endl;
	std::cout << "arr1 arr3: " << isRotation(arr1, arr3) << std::endl;

	return 0;
}