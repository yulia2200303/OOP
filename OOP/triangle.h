
struct Point {
	double x;
	double y;

	Point(){
		this-> x= 0;
		this->y = 0;
	}

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};


class Triangle {
	Point a_;
	Point b_;
	Point c_;
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle&);
	~Triangle();
	void Print();
	Point GetPointA();
	Point GetPointB();
	Point GetPointC();
	Point GetPoint(int i);
	void SetPointA(Point point);
	void SetPointB(Point point);
	void SetPointC(Point point);
	void SetPoint(int i, Point point);
	static double GetSide(Point a, Point b);
	bool IsIsosceles();
	bool IsEquilateral();
	bool IsRectangular();
	bool IsArbitrary();
	double GetPerimeter();
};

void DisplayType(Triangle *arr, int size);
void DisplayMinMaxPerimeter(Triangle *arr, int size);