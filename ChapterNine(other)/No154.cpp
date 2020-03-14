/*
【名称】一种消息接收并打印的结构设计
【题目】消息流吐出2，一种结构接收而不打印2，因为1还没出现；
消息流吐出1，一种结构接收1，并打印1，2；
消息流吐出4，一种结构接收而不打印4，因为3还没出现；
消息流吐出5，一种结构接收而不打印5，因为3还没出现；
消息流吐出7，一种结构接收而不打印7，因为3还没出现；
消息流吐出3，一种结构接收3，并且打印3，4，5；
消息流吐出9，一种结构接收而不打印9，因为6还没出现；
消息流吐出8，一种结构接收而不打印8，因为6还没出现；
消息流吐出6，一种结构接收6，并且打印6，7，8，9.
已知一个消息流会不断吐出整数1-N，但不一定按照顺序吐出。如果上次打印的数为i,
那么当i+1出现时，请打印i+1及其之后接收过的并且连续的所有数，直到1-N全部接收
并打印完，请设计这种接收并打印的结构。
要求：消息流最终会吐出全部的1-N，当然最终也会打印完所有的1-N，要求接收和打印
1-N的全过程，时间复杂度为O(N)。
【难度】尉
*/
#include <iostream>
#include <map>

struct Node {
	int num;
	Node* next;
	Node(int num):num(num),next(nullptr) {}
};

class MessageBox {
public:
	MessageBox() {
		lastPrint = 0;
	}

	void receive(int num) {
		if (num < 1) {
			return;
		}
		Node* cur = new Node(num);
		headmap[num] = cur;
		tailmap[num] = cur;
		if (tailmap.find(num - 1) != tailmap.end()) {
			tailmap[num - 1]->next = cur;
			tailmap.erase(num - 1);
			headmap.erase(num);
		}
		if (headmap.find(num + 1) != headmap.end()) {
			cur->next = headmap[num + 1];
			tailmap.erase(num);
			headmap.erase(num + 1);
		}
		if (headmap.find(lastPrint + 1) != headmap.end()) {
			print();
		}
	}

	void print() {
		Node* node = headmap[++lastPrint];
		headmap.erase(lastPrint);
		while (node != nullptr) {
			std::cout << node->num << " ";
			node = node->next;
			lastPrint++;
		}
		tailmap.erase(--lastPrint);
		std::cout << std::endl;
	}

private:
	std::map<int, Node*> headmap;
	std::map<int, Node*> tailmap;
	int lastPrint;
};

int main() {

	MessageBox box;

	box.receive(2);
	box.receive(1);
	box.receive(4);
	box.receive(5);
	box.receive(7);
	box.receive(3);
	box.receive(9);
	box.receive(8);
	box.receive(6);


	return 0;
}