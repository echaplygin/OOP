#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


#define tab "\t"
#define delimiter "\n------------------------------------------------------------------------\n"

//#define CONSTRUCTOR_OVERLOADING


class Point
{
	double x;
	double y;
public:

	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

#ifdef CONSTRUCTOR_OVERLOADING
	//                 Constructors:
	Point() 
	{
		//Конструктор по умолчанию
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		//с одним параметром
		this->x = x;
		this->y = 0;
		cout << "SigleArgumentConstructor:\t" << this << endl;
	}
#endif // CONSTRUCTOR_OVERLOADING

	Point(double x=0, double y=0)
	{
		//с двумя параметрами
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//Shallow copy - поверхностное копирование объекта
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;

	}

	//       Operators:

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}


	//                     Methods:
	double distance(const Point& other)
	{
		//B - this
		//A - other
		//other.x += 100;
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
			//sqrt - Square Root (квадратный корень)
			return distance;
	}

	void print()const
	{
		cout << "X = " << x << tab << "Y = " << y << endl;
	}

};
//#define STRUCT_POINT

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define DISTANCE_CHEK
//#define CONSTRACTOR_CHEK
//#define ASSIGNMENT_CHEK


void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT

	Point A;
	A.x = 2;
	A.y = 3;

	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //Объявляем указатель на Point и берем адрес точки 'A'
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHEK


	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;
	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << B.get_x() << tab << B.get_y() << endl;
	cout << delimiter << endl;
	cout << B.distance(A)  << endl;
	cout << delimiter << endl;
	cout << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << distance(B, A) << endl;

#endif // DISTANCE_CHEK

#ifdef CONSTRACTOR_CHEK  

	Point A; //Default constructor
	A.print();
	Point B = 3; //Single-Argument constructor
	B.print();
	Point C(2, 3); //Parametrazed constructor - конструктор с параметрами
	C.print();
	//Деструктор вызывется не для конструктора, а для объекта

	Point D = C; //CopyConstructor
	D.print();

	Point E; //Default constructor
	E = C;    //CopyAssignment
	E.print();
#endif //CONSTRACTOR_CHEK

#ifdef ASSIGNMENT_CHEK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n-------------------------------------------------------\n";
	A = B = C = Point(4, 5);
	cout << "\n-------------------------------------------------------\n";

	A.print();
	B.print();
	C.print();

#endif //ASSIGNMENT_CHEK





	//for (int i = 0; i < 5; i++)
	//{
	//	cout << i << tab;
	//}
	//cout << endl;



	

	

		

}