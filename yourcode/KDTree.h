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
	Point ReBuildPool[KDTREENODE_SIZE];

	int NodeCnt, ReBuildCnt, ReBuildDim;

	KDTree() {
		NodeCnt = ReBuildCnt = 0;
		Root = NULL;
	}

	stack<KDtreeNode*> bin;

	KDtreeNode *newNode();

	KDtreeNode *Build(int l, int r, int D);

	void Travel(KDtreeNode * x);

	void ReBuild(KDtreeNode * x, int Dim);

}
#endif