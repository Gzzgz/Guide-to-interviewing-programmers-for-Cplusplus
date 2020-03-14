/*
�����ơ�һ����Ϣ���ղ���ӡ�Ľṹ���
����Ŀ����Ϣ���³�2��һ�ֽṹ���ն�����ӡ2����Ϊ1��û���֣�
��Ϣ���³�1��һ�ֽṹ����1������ӡ1��2��
��Ϣ���³�4��һ�ֽṹ���ն�����ӡ4����Ϊ3��û���֣�
��Ϣ���³�5��һ�ֽṹ���ն�����ӡ5����Ϊ3��û���֣�
��Ϣ���³�7��һ�ֽṹ���ն�����ӡ7����Ϊ3��û���֣�
��Ϣ���³�3��һ�ֽṹ����3�����Ҵ�ӡ3��4��5��
��Ϣ���³�9��һ�ֽṹ���ն�����ӡ9����Ϊ6��û���֣�
��Ϣ���³�8��һ�ֽṹ���ն�����ӡ8����Ϊ6��û���֣�
��Ϣ���³�6��һ�ֽṹ����6�����Ҵ�ӡ6��7��8��9.
��֪һ����Ϣ���᲻���³�����1-N������һ������˳���³�������ϴδ�ӡ����Ϊi,
��ô��i+1����ʱ�����ӡi+1����֮����չ��Ĳ�����������������ֱ��1-Nȫ������
����ӡ�꣬��������ֽ��ղ���ӡ�Ľṹ��
Ҫ����Ϣ�����ջ��³�ȫ����1-N����Ȼ����Ҳ���ӡ�����е�1-N��Ҫ����պʹ�ӡ
1-N��ȫ���̣�ʱ�临�Ӷ�ΪO(N)��
���Ѷȡ�ξ
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