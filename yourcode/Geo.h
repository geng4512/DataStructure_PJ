#ifndef GEO_H
#define GEO_H
struct Point {
	double x, y; Point() {}
	Point(double a, double b):x(a), y(b) {}
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

#endif