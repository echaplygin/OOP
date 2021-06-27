#include<iostream>
using namespace std;

class Fraction
{
	int integer;            // Целая часть
	int numerator;          // Числитель
	int denominator;        //Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}

	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1; // Фильрация данных
		this->denominator = denominator;
	}
	//Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:" << this << endl;		
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;		
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:" << this << endl;
	}


	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators
	Fraction operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssingnment:\t" << this << endl;
		return *this;
	}

	// Increment/Decrement:
	Fraction& operator++() //Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction& operator++(int) //Postfix (Suffix) increment
	{
		Fraction old = *this; //Сохраняем старое значение. CopyConstructor
		integer++;
		return old; //CopyConstructor
	}

	//Methods:
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;

	}
	void print()const
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;

	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	return result;*/
	return Fraction //Здесь мы явно вызываем конструктор, который создает временный безымянный объект с нужным нам результатом.
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);

}


//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; // Default constructor
	A.print();
	Fraction B = 3; // Single-argument construction
	B.print();
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D; //CopyConstructor
	E.print();

	Fraction F; //DefaultConstructor
	F = E;        //operator= CopyAssingnment
	F.print();
#endif

	int a = 2;
	int b = 3;
	int c = a * b;



	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	C.print();

	for (Fraction i(1,4); i.get_integer()<10; i++)
	{
		i.print();
		cout << endl;
	}
	


//	A.print();
//	A.to_improper();
//	A.print();
//	A.to_proper();
//	A.print();


}