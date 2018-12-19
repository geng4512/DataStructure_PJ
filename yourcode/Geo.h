#ifndef GEO_H
#define GEO_H
struct Point {
	double x, y;

	Point() {}

	Point(double a, double b):x(a), y(b) {}

	Point(pair<double, double> a):x(a.first), y(a.second) {}

	inline Point operator - (Point rhs) const {
		return Point(a - rhs.a, b - rhs.b);
	}

	inline Point operator + (Point rhs) const {
		return Point(a + rhs.a, b + rhs.b);
	}

	Point & operator [] (int x) const {
		if(x == 0) return x;
		return y;
	}
};

//Cross product of vector a and b;
double Cross(Point a, Point b);

//Judge if segment a-b intersect with x-y
bool SegmentIntersection(Point a, Point b, Point x, Point y);

int SegmentAndPolyIntersection(Point a, Point b, vector<pair<double, double>> &Poly);

bool PointInPoly(Point x, vector<pair<double, double>> &Poly);

int RectangleInPoly(int *mx, int *mn, vector<pair<double, double>> &Poly);

#endif