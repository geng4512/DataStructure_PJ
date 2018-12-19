#ifndef KDTREE_H
#define KDTREE_H

#include <stack>
#include "Geo.h"

const int KDTREENODE_SIZE = 2e6 + 5;
const double alpha = 0.75;

struct KDtreeNode {
	double mx[2], mn[2], x[2];
	bool del;
	int id, size;
	KDtreeNode *lc, *rc;
	KDtreeNode() {}
	KDtreeNode(Point P) {
		mx[0] = mn[0] = x[0] = P.x;
		mx[1] = mn[1] = x[1] = P.y;
		id = del = 0;
		size = 1;
		lc = rc = NULL;
	}
	bool isBad();
	void pushup();
	void clear();
};


struct KDTree {
	KDtreeNode *Root;
	KDtreeNode *ReBuildNode;
	KDtreeNode KDtreeNodePool[KDTREENODE_SIZE];
	pair<Point, id> ReBuildPool[KDTREENODE_SIZE];
	vector<int> Ans;
	hashmap<int, int> Id2Cnt;
	vector<Point> MyPoint;

	int NodeCnt, ReBuildCnt, ReBuildDim, Cnt;

	KDTree() {
		Id2Cnt.clear();
		NodeCnt = ReBuildCnt = Cnt = 0;
		Root = NULL;
	}

	stack<KDtreeNode*> bin;

	KDtreeNode *newNode();

	KDtreeNode *Build(int l, int r, int Dim);

	void Travel(KDtreeNode * x);

	void ReBuild(KDtreeNode * x, int Dim);

	void Insert(KDtreeNode * x, KDtreeNode v, int Dim);

	void Insert(Point v);

	void GetNode(KDtreeNode * x);

	void Find(KDtreeNode * x, vector<pair<double, double>> &Poly);

	void Find(vector<pair<double, double>> &Poly);

	void Erase(KDtreeNode * x, Point v, int id);

	void Erase(int id);
}
#endif