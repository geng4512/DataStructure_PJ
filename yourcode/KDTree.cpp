#include "KDTree.h"
#include "Geo.h"
#include <algorithm>

bool KDtreeNode::isBad() {
	if(lc != NULL && lc -> size > size * alpha + 3) return 1;
	if(rc != NULL && rc -> size > size * alpha + 3) return 1;
	return 0;
}

inline void gmax(double&x, double v) {
	if(x < v) x = v;
}

inline void gmin(double&x, double v) {
	if(x > v) x = v;
}

void KDtreeNode::pushup() {
	size = 1;
	if(lc != NULL) {
		gmax(mx[0], lc -> mx[0]);
		gmin(mn[0], lc -> mn[0]);
		gmax(mx[1], lc -> mx[1]);
		gmin(mn[1], lc -> mn[1]);
		size += lc -> size;
	}
	if(rc != NULL) {
		gmax(mx[0], rc -> mx[0]);
		gmin(mn[0], rc -> mn[0]);
		gmax(mx[1], rc -> mx[1]);
		gmin(mn[1], rc -> mn[1]);
		size += rc -> size;
	}
}

void KDtreeNode::clear() {
	mx[0] = mn[0] = x[0] = 0;
	mx[1] = mn[1] = x[1] = 0;
	id = del = 0;
	size = 0;
	lc = rc = NULL;
}

KDtreeNode * KDTree::newNode() {
	if(!bin.empty()) {
		auto tmp = bin.top();
		bin.pop();
		return tmp;
	}
	return &(KDtreeNodePool[NodeCnt ++]);
}

void KDTree::Travel(KDtreeNode * x) {
	if(x == NULL) return;
	Travel(x -> lc);
	Travel(x -> rc);
	bin.push(x);
	x -> clear();
	if(!x -> del)
		ReBuildPool[++ ReBuildCnt] = Point(x -> x[0], x -> x[1]);
}


KDtreeNode *KDTree::Build(int l, int r, int Dim) {
	if(l > r) return NULL;
	int MID = (l + r) >> 1;
	nth_element(ReBuildPool + l, ReBuildPool + MID, ReBuildPool + r + 1, [&](Point a, Point b) {
		return a[Dim] < b[Dim];
	});
	KDtreeNode *THIS = newNode();
	*THIS = KDtreeNode(ReBuildPool[MID]);
	THIS -> lc = Build(l, MID - 1, Dim ^ 1);
	THIS -> rc = Build(MID + 1, r, Dim ^ 1);
	THIS -> pushup();
	return THIS;
}

void KDTree::ReBuild(KDtreeNode * x, int Dim) {
	Travel(x);
	x = Build(1, ReBuildCnt, Dim);
}