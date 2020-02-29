/*
【名称】复制含有随机指针节点的链表
【题目】一种特殊的链表节点类描述如下：
class Node{
public:
    int value;
	Node next;
	Node rand;
};
Node类中的value是节点值，next指针和正常单链表中next指针的意义一样，都指向
下一个节点，rand指针是 Node类中新增的指针，这个指针可能指向链表中的任意一个节点，
也可能指向null.
 给定一个由Node节点类型组成的无环单链表的头节点head，请实现一个函数完成这个
 链表中所有结构的复制，并返回复制的新链表的头节点。例如：链表1->2->3->null，
 假设1的rand指针指向3，2的rand指针指向null, 3的rand指针指向1.复制后的链表因该
 也是这种结构，比如1'->2'->3'->null，1’的rand指针指向3',2'的rand指针指向null,
 3'的rand指针指向1'，最后返回1’。
 进阶：不使用额外的数据结构，只用有限的几个变量，且在时间复杂度为O(N)内完成原
 问题要实现的函数。
 【难度】尉
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
/*使用哈希表解，时间复杂度N，空间复杂度N*/
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
/*时间复杂度为N，空间复杂度为1的解法*/
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
