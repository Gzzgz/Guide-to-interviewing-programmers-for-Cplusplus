/*
�����ơ����ִ�����TOPK����
����Ŀ������string���͵�����strArr���ٸ�������k�����ϸ�������˳���ӡ����
����ǰk�����ַ�����
strArr=['1','1','2','3'],k=2, no1:1, no2:2 ��no1:1, no2:3
Ҫ�����strArr����N,ʱ�临�Ӷ�O(Nlogk)
��������Ŀ����Ʋ�ʵ��TopKRecord�ṹ�����Բ��������м����ַ��������ҿ��Ը����ַ���
���ֵ������ʱ��ӡ�����������ǰk���ַ���������Ϊ:
1.k��TopKRecordʵ������ʱָ�������Ҳ��ٱ仯��
2.����add(string)����������TopKRecord�����ַ�����
3.����printTopK()����������ӡ�����������ǰk���ַ�������ӡ����Щ�ַ�����
��Ӧ�Ĵ������ɣ���Ҫ���ϸ�����˳���ӡ��
Ҫ��1.�κ�ʱ�̣�add������ʱ�临�ӶȲ�����O(logk);
2.�κ�ʱ�̣�printTopK����ʱ�临�Ӷ�O(k)
���Ѷȡ�ԭ���⣺ξ�� ��������:У
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
	std::string str;
	int times;
	Node(std::string s, int time):str(s),times(time) {}
};

void swap(Node** heap, int index1, int index2) {
	Node* tmp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = tmp;
}

void heapify(Node** heap, int index, int heapSize) {
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int smallest = index;
	while (left < heapSize) {
		if (heap[left]->times < heap[index]->times) {
			smallest = left;
		}
		if (right < heapSize && heap[right]->times < heap[smallest]->times) {
			smallest = right;
		}
		if (smallest != index) {
			swap(heap, smallest, index);
		}
		else {
			break;
		}
		index = smallest;
		left = index * 2 + 1;
		right = index * 2 + 2;
	}
}

void heapInsert(Node** heap, int index) {
	while (index != 0) {
		int parent = (index - 1) / 2;
		if (heap[index]->times < heap[parent]->times) {
			swap(heap, parent, index);
			index = parent;
		}
		else {
			break;
		}
	}
}

void printTopKAndRank(std::vector<std::string> arr, int topK) {
	if (topK < 1) {
		return;
	}
	std::map<std::string, int> map;
	for (int i = 0; i < arr.size(); i ++) {
		std::string cur = arr[i];
		if (map.find(cur) == map.end()) {
			map[cur] = 1;
		}
		else {
			map[cur] += 1;
		}
	}
	Node** heap = new Node*[topK];
	int index = 0;
	std::map<std::string, int>::iterator iter;
	for (iter = map.begin(); iter != map.end(); iter++) {
		std::string str = iter->first;
		int times = iter->second;
		Node* node = new Node(str, times);
		if (index != topK) {
			heap[index] = node;
			heapInsert(heap, index++);
		}
		else {
			if (heap[0]->times < node->times) {
				heap[0] = node;
				heapify(heap, 0, topK);
			}
		}
	}

	for (int i = index - 1; i != 0; i --) {
		swap(heap, 0, i);
		heapify(heap, 0, i);
	}

	for (int i = 0; i != topK; i ++) {
		if (heap[i] == nullptr) {
			break;
		}
		else {
			std::cout << "No." << i + 1 << ": ";
			std::cout << heap[i]->str << ", times:";
			std::cout << heap[i]->times << std::endl;
		}
	}
}

class TopKRecord {
public:

	TopKRecord(int size) {
		heap = new Node*[size];
		index = 0;
		length = size;
	}

	void swap(int index1, int index2) {
		nodeIndexMap[heap[index1]] = index2;
		nodeIndexMap[heap[index2]] = index1;
		Node* tmp = heap[index1];
		heap[index1] = heap[index2];
		heap[index2] = tmp;
	}

	void heapify(int index, int heapSize) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int smallest = index;
		while (left < heapSize) {
			if (heap[left]->times > heap[index]->times) {
				smallest = left;
			}
			if (right < heapSize && heap[right]->times < heap[smallest]->times) {
				smallest = right;
			}
			if (smallest != index) {
				swap(smallest, index);
			}
			else {
				break;
			}
			index = smallest;
			left = index * 2 + 1;
			right = index * 2 + 2;
		}
	}

	void heapInsert(int index) {
		while (index != 0) {
			int parent = (index - 1) / 2;
			if (heap[index]->times < heap[parent]->times) {
				swap(parent, index);
				index = parent;
			}
			else {
				break;
			}
		}
	}

	void printTopK() {
		std::cout << "Top: ";
		for (int i = 0; i != length; i ++) {		
			if (heap[i] == nullptr) {
				break;
			}
			std::cout << "str: " << heap[i]->str<<" ";
			std::cout << "times: " << heap[i]->times<<std::endl;
		}
	}

	void add(std::string str) {
		Node* curNode = nullptr;
		int preIndex = -1;
		if (strNodeMap.find(str) == strNodeMap.end()) {
			curNode = new Node(str, 1);
			strNodeMap[str] = curNode;
			nodeIndexMap[curNode] = -1;
		}
		else {
			curNode = strNodeMap[str];
			curNode->times++;
			preIndex = nodeIndexMap[curNode];
		}
		if (preIndex == -1) {
			if (index == length) {
				if (heap[0]->times < curNode->times) {
					nodeIndexMap[heap[0]] = -1;
					nodeIndexMap[curNode] = 0;
					heap[0] = curNode;
					heapify(0, index);
				}
			}
			else {
				nodeIndexMap[curNode] = index;
				heap[index] = curNode;
				heapInsert(index++);
			}
		}
		else {
			heapify(preIndex, index);
		}
	}

private:
	Node** heap;
	int index;
	std::map<std::string, Node*>strNodeMap;
	std::map<Node*, int>nodeIndexMap;
	int length;
};

int main() {

	std::vector<std::string> strs = {"1", "2", "3", "2", "3"};

	printTopKAndRank(strs, 2);


	TopKRecord top(2);
	top.add("A");
	top.add("B");
	top.add("B");
	top.add("C");
	top.printTopK();

	return 0;
}