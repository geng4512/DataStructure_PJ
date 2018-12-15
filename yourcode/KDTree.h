#ifndef KDTREE_H
#define KDTREE_H

const int KDTREENODE_SIZE = 2e6 + 5;
const double alpha = 0.75;

struct KDtreeNode {
	double mx[2], mn[2], x[2];
	bool del;
	KDtreeNode *lc, *rc;
	KDtreeNode() {}
	KDtreeNode(Point P) {
		mx[0] = mn[0] = x[0] = P.x;
		mx[1] = mn[1] = x[1] = P.y;
		del = 0;
		lc = rc = NULL;
	}
} KDtreeNodePool[KDTREENODE_SIZE];
struct KDTree {
	KDtreeNode *Root;
	KDtreeNode *RebuildNode;

	vector<KDtreeNode*> bin;

	KDtreeNode *newNode() {
	}

	bool NeedRebuild(KDtreeNode * x) {
	}
}
#endif