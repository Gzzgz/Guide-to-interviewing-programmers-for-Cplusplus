/*
【名称】Tarjan算法与并查集解决二叉树节点间最近公共祖先的批量查询问题
【题目】如下定义：
class Node{
public:
    int value;
	Node left;
	Node right;
};

class Query{
public:
    Node o1;
	Node o2;
};
一个Query类的实例表示一条查询语句，表示想要查询o1和o2节点的最近公共祖先节点。
给定一棵二叉树的头节点head，并给定所有的查询语句，即一个Query类型的数组Query[]
ques,请返回Node类型的数组Node[] ans，ans[i]代表ques[i]这条查询的答案，即ques[i].o1
和ques[i].o2的最近公共祖先。
【要求】如果二叉树的节点数为N，查询语句的条数为M，整个处理过程的时间复杂度要求达到O(N+M)
【难度】校
*/

// code from https://blog.csdn.net/wzc2608/article/details/80876548

#include <iostream>
#include <list>
#include <vector>
#include <map>

struct Node {
	int value;
	Node* left;
	Node* right;
	Node(int value):value(value),left(nullptr),right(nullptr) {}
};

struct Query {
	Node* o1;
	Node* o2;
	Query(Node* o1, Node* o2):o1(o1),o2(o2){}
	Query():o1(nullptr),o2(nullptr){}
};

class DisJointSets {
public:
	std::map<Node*, Node*> fatherMap;
	std::map<Node*, int> rankMap;

	DisJointSets() {
	}

	void makeSets(Node* head) {
		fatherMap.clear();
		rankMap.clear();
		preOrderMake(head);
	}

	void preOrderMake(Node* head) {
		if (head == nullptr) {
			return;
		}
		//fatherMap.insert(std::make_pair(head, head));
		//rankMap.insert(std::make_pair(head, 0));
		fatherMap[head] = head;
		rankMap[head] = 0;

		preOrderMake(head->left);
		preOrderMake(head->right);
	}

	Node* findFather(Node* n) {
		Node* father = fatherMap[n];
		if (father != n) {
			father = findFather(father);
		}
		//fatherMap.insert(std::make_pair(n, father));
		fatherMap[n] = father;
		return father;
	}

	void unionFcn(Node* a, Node* b) {
		if (a == nullptr || b == nullptr) {
			return;
		}
		Node* afather = findFather(a);
		Node* bfather = findFather(b);

		if (afather != bfather) {
			int afrank = rankMap[afather];
			int bfrank = rankMap[bfather];
			if (afrank < bfrank) {
				//fatherMap.insert(std::make_pair(afather, bfather));
				fatherMap[afather] = bfather;
			}
			else if (afrank > bfrank) {
				//fatherMap.insert(std::make_pair(bfather, afather));
				fatherMap[bfather] = afather;
			}
			else {
				//fatherMap.insert(bfather, afather);
				//rankMap.insert(std::make_pair(afather, afrank + 1));
				fatherMap[bfather] = afather;
				rankMap[afather] = afrank + 1;
			}
		}
	}
};

class Tarjan {
public:
	std::map<Node*, std::list<Node*> > queryMap;
	std::map<Node*, std::list<int> > indexMap;
	std::map<Node*, Node*> ancestorMap;
	DisJointSets sets;

public:
	Tarjan() {
		//sets = new DisJointSets();
	}

	std::vector<Node*> query(Node* head, std::vector<Query*>& ques) {
		
		std::vector<Node*> ans(ques.size());
		setQueries(ques, ans);
		sets.makeSets(head);
		setAnswers(head, ans);
		return ans;
	}

	void setQueries(std::vector<Query*>& ques, std::vector<Node*>& ans) {
		Node* o1 = nullptr;
		Node* o2 = nullptr;
		for (int i = 0; i < ques.size(); i ++) {
			o1 = ques[i]->o1;
			o2 = ques[i]->o2;
			if (o1 == o2 || o1 == nullptr || o2 == nullptr) {
				ans[i] = o1 != nullptr ? o1 : o2;
			}
			else {
				if (queryMap.find(o1) == queryMap.end()) {
					//std::list<Node*> node_tmpv;
					//std::list<int> int_tmpv;
					//queryMap.insert(std::make_pair(o1, node_tmpv));
					//indexMap.insert(std::make_pair(o1, int_tmpv));
					std::list<Node*> nlist;
					queryMap[o1] = nlist;
					std::list<int> ilist;
					indexMap[o1] = ilist;
				}
				if (queryMap.find(o2) == queryMap.end()) {
					/*std::vector<Node*> node_tmpv;
					std::vector<int> int_tmpv;
					queryMap.insert(std::make_pair(o2, node_tmpv));
					indexMap.insert(std::make_pair(o2, int_tmpv));*/
					std::list<Node*> nlist;
					queryMap[o2] = nlist;
					std::list<int> ilist;
					indexMap[o2] = ilist;
				}
				queryMap[o1].push_back(o2);
				indexMap[o1].push_back(i);
				queryMap[o2].push_back(o1);
				indexMap[o2].push_back(i);
			}
		}
	}

	void setAnswers(Node* head, std::vector<Node*>& ans) {
		if (head == nullptr) {
			return;
		}
		setAnswers(head->left, ans);
		sets.unionFcn(head->left, head);
		//ancestorMap.insert(std::make_pair(sets.findFather(head), head));
		ancestorMap[sets.findFather(head)] = head;
		setAnswers(head->right, ans);
		sets.unionFcn(head->right, head);
		ancestorMap.insert(std::make_pair(sets.findFather(head), head));
		//ancestorMap[sets.findFather(head)] = head;
		
		std::list<Node*> nlist = queryMap[head];
		std::list<int> ilist = indexMap[head];
		
		Node* node = nullptr;
		Node* nodeFather = nullptr;
		int index = 0;
		
		while (!nlist.empty()) {
			node = nlist.front();
			nlist.pop_front();
			index = ilist.front();
			ilist.pop_front();
			nodeFather = sets.findFather(node);
			if (ancestorMap.find(nodeFather) != ancestorMap.end()) {
				ans[index] = ancestorMap[nodeFather];
			}
		}
	}
};

std::vector<Node*> tarJanQuery(Node* head, std::vector<Query*>& quries) {
	Tarjan tarjan;

	return tarjan.query(head, quries);
}

int main() {

	Node* head = new Node(1);
	head->left = new Node(2);
	head->right = new Node(3);
	head->left->left = new Node(4);
	head->left->right = new Node(5);
	head->left->right->left = new Node(7);
	head->left->right->right = new Node(8);
	head->right->right = new Node(6);
	head->right->right->left = new Node(9);

	std::vector<Query*> ques;
	ques.push_back(new Query(head->left->left, head->left->right));
	ques.push_back(new Query(head->left->right->right, head->right->right->left));

	std::vector<Node*> ans = tarJanQuery(head, ques);

	for (int i = 0; i < ans.size(); i ++) {
		std::cout << ans[i]->value << std::endl;
	}

	return 0;
}