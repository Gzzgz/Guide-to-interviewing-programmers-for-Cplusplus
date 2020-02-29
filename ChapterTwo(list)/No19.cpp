/*
�����ơ����ƺ������ָ��ڵ������
����Ŀ��һ�����������ڵ����������£�
class Node{
public:
    int value;
	Node next;
	Node rand;
};
Node���е�value�ǽڵ�ֵ��nextָ���������������nextָ�������һ������ָ��
��һ���ڵ㣬randָ���� Node����������ָ�룬���ָ�����ָ�������е�����һ���ڵ㣬
Ҳ����ָ��null.
 ����һ����Node�ڵ�������ɵ��޻��������ͷ�ڵ�head����ʵ��һ������������
 ���������нṹ�ĸ��ƣ������ظ��Ƶ��������ͷ�ڵ㡣���磺����1->2->3->null��
 ����1��randָ��ָ��3��2��randָ��ָ��null, 3��randָ��ָ��1.���ƺ���������
 Ҳ�����ֽṹ������1'->2'->3'->null��1����randָ��ָ��3',2'��randָ��ָ��null,
 3'��randָ��ָ��1'����󷵻�1����
 ���ף���ʹ�ö�������ݽṹ��ֻ�����޵ļ�������������ʱ�临�Ӷ�ΪO(N)�����ԭ
 ����Ҫʵ�ֵĺ�����
 ���Ѷȡ�ξ
*/

// code from https://blog.csdn.net/wzc2608/article/details/80675416

#include <iostream>
#include <map>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* rand;
	Node(int val) : value(val), next(nullptr), rand(nullptr) {}
};
/*ʹ�ù�ϣ��⣬ʱ�临�Ӷ�N���ռ临�Ӷ�N*/
Node* copyList(Node* head)
{
	map<Node*, Node*> nMap;
	Node* cur = head;
	while (cur)
	{
		Node* newcur = new Node(cur->value);
		nMap[cur] = newcur;
		cur = cur->next;
	}

	cur = head;
	while (cur)
	{
		Node* pNode = nMap[cur];
		pNode->next = nMap[cur->next];
		pNode->rand = nMap[cur->rand];
		cur = cur->next;
	}
	return nMap[head];
}
/*ʱ�临�Ӷ�ΪN���ռ临�Ӷ�Ϊ1�Ľⷨ*/
Node* copyList2(Node* head)
{
	if (head == nullptr)
		return nullptr;
	Node* cur = head;
	Node* pnext = nullptr;

	while (cur)
	{
		pnext = cur->next;
		Node* pNode = new Node(cur->value);
		cur->next = pNode;
		pNode->next = pnext;
		cur = pnext;
	}
	cur = head;

	while (cur)
	{
		cur->next->rand = cur->rand == nullptr ? nullptr : cur->rand->next;
		cur = cur->next->next;
	}
	Node* res = head->next;
	cur = head;
	Node* curCopy = nullptr;

	while (cur)
	{
		pnext = cur->next->next;
		curCopy = cur->next;
		cur->next = pnext;
		curCopy->next = pnext == nullptr ? nullptr : pnext->next;
		cur = pnext;
	}
	return res;
}

void Print(Node* head)
{
	if (head == nullptr)
	{
		cout << "the node is null" << endl;
		return;
	}
	else
	{
		int num = head->rand ? head->rand->value : 0;
		cout << "the node val is " << head->value << "\n"
			<< "the rand node val is " << num << endl;
	}
	cout << endl;
	Print(head->next);
	return;
}

int main()
{
	Node* pNode0 = new Node(1);
	Node* pNode1 = new Node(2);
	Node* pNode2 = new Node(3);

	pNode0->next = pNode1;
	pNode1->next = pNode2;

	pNode0->rand = pNode2;
	pNode2->rand = pNode0;

	Node* new1 = copyList(pNode0);
	Print(new1);
	cout << "========================" << endl;
	Node* new2 = copyList2(pNode0);
	Print(new2);
}
