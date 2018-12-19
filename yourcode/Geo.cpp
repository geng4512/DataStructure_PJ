#include "Geo.h"

double Cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}

bool SegmentIntersection(Point a, Point b, Point x, Point y) {
	double C1 = Cross((c - a), (b - a));
	double C2 = Cross((d - a), (b - a));
	if(C1 * C2 > 1e-8) return 0;
	C1 = Cross((a - c), (d - c));
	C2 = Cross((b - c), (d - c));
	if(C1 * C2 > 1e-8) return 0;
	return 1;
}

bool PointInPoly(Point x, vector<pair<double, double>> &Poly) {
	int f = -1;
	for(unsigned i = 0; i < Poly.size(); ++ i) {
		Point a(Poly[i]), b(Poly[(i + 1) % Poly.size()])
		if(f == -1) f = (Cross((x - a), (b - a)) > 0);
		else if(f != (Cross((x - a), (b - a)) > 0))
			return 0;
	}
	return 1;
}

int SegmentAndPolyIntersection(Point a, Point b, vector<pair<double, double>> &Poly) {
	int cnt = 0;
	for(unsigned i = 0; i < Poly.size(); ++ i) {
		Point x(Poly[i]), y(Poly[(i + 1) % Poly.size()])
		cnt += SegmentIntersection(a, b, x, y);
	}
	return cnt;
}

//0 represents no space intersected.
int RectangleInPoly(int *mx, int *mn, vector<pair<double, double>> &Poly) {
	int pmn[2] = {1<< 30, 1 << 30},
		pmx[2] = {-0x3f3f3f3f, -0x3f3f3f3f};
	for(int i = 0; i < 2; ++ i) for(auto p : Poly) {
		pmn[i] = min(p[i], pmn[i]);
		pmx[i] = max(p[i], pmx[i]);
	}

	if(pmx[0] < mn[0] || pmx[1] < mn[1] || mx[0] < pmn[0] || mx[1] < pmn[1])
		return 0;

	int cnt = 0;
	Point a, b;

	a = Point(mn[0], mn[1]);
	b = Point(mx[0], mn[1]);
	cnt += SegmentAndPolyIntersection(a, b, Poly);
	if(cnt) return 1;

	a = Point(mx[0], mn[1]);
	b = Point(mx[0], mx[1]);
	cnt += SegmentAndPolyIntersection(a, b, Poly);
	if(cnt) return 1;

	a = Point(mx[0], mx[1]);
	b = Point(mn[0], mx[1]);
	cnt += SegmentAndPolyIntersection(a, b, Poly);
	if(cnt) return 1;

	a = Point(mn[0], mx[1]);
	b = Point(mn[0], mn[1]);
	cnt += SegmentAndPolyIntersection(a, b, Poly);
	if(cnt) return 1;

	if(PointInPoly(a, Poly)) return 2;
	return 0;
}

