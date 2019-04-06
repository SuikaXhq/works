#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;


/******************************** Virtual Classes Begin ********************************/
/////////////////////////////////////////////////////////////////////////////////////////

class Shape {
public:
	static const double PI;
	
	virtual void display() const = 0;		//display message of the shape
};

const double Shape::PI = 3.1415927;






class TwoDimensionalShape : public Shape {
public:
	virtual double getArea() const = 0;
	virtual void display() const;
};

void TwoDimensionalShape::display() const {
	cout << "The area is " << getArea();
	cout << endl;
}






class ThreeDimensionalShape : public Shape {
public:
	virtual double getArea() const = 0; 
	virtual double getVolume() const = 0;
	virtual void display() const;
};

void ThreeDimensionalShape::display() const {
	cout << "The surface area is " << getArea();
	cout << endl;
	cout << "The volume is " << getVolume();
	cout << endl;
}


///////////////////////////////////////////////////////////////////////////////////////
/******************************** Virtual Classes End ********************************/




/******************************** Two Dimensional Shape Classes Begin ********************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////

class Circle : public TwoDimensionalShape {
	
	double radius;

public:
	Circle(double=0);
	virtual double getArea() const;
	virtual void display() const;
	
	//getter & setter
	void setRadius(double);
	double getRadius() const;
};


Circle::Circle(double r) {
	setRadius(r);
}
double Circle::getArea() const {
	return PI*radius*radius;
}
void Circle::display() const {
	cout << "Circle with radius " << getRadius() << ":" << endl;
	TwoDimensionalShape::display();
}


//getter & setter
void Circle::setRadius(double r) {
	if (r >= 0) {
		radius = r;
	} else {
		throw invalid_argument("Radius must be >= 0.");
	}
}
double Circle::getRadius() const {
	return radius;
}









class Square : public TwoDimensionalShape {
	
	double sideLength;

public:
	Square(double=0);
	virtual double getArea() const;
	virtual void display() const;
	
	//getter & setter
	void setSideLength(double);
	double getSideLength() const;
};


Square::Square(double side) {
		setSideLength(side);
}
double Square::getArea() const {
	return sideLength*sideLength;
}
void Square::display() const {
	cout << "Square with side length " << getSideLength() << ":" << endl;
	TwoDimensionalShape::display();
}


//getter & setter
void Square::setSideLength(double side) {
	if (side >= 0) {
		sideLength = side;
	} else {
		throw invalid_argument("Side length must be >= 0.");
	}
}
double Square::getSideLength() const {
	return sideLength;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************** Two Dimensional Shape Classes End ********************************/







/******************************** Three Dimensional Shape Classes Begin ********************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Sphere : public ThreeDimensionalShape {
	
	double radius;
	
public:
	Sphere(double);
	virtual double getArea() const;
	virtual double getVolume() const;
	virtual void display() const;
	
	//getter & setter
	void setRadius(double);
	double getRadius() const;
};


Sphere::Sphere(double r) {
	setRadius(r);
}
double Sphere::getArea() const {
	return 4*PI*radius*radius;
}
double Sphere::getVolume() const {
	return 4.0/3*PI*radius*radius*radius;
}
void Sphere::display() const {
	cout << "Sphere with radius " << getRadius() << ":" << endl;
	ThreeDimensionalShape::display();
}


//getter & setter
void Sphere::setRadius(double r) {
	if (r >= 0) {
		radius = r;
	} else {
		throw invalid_argument("Radius must be >= 0.");
	}
}
double Sphere::getRadius() const {
	return radius;
}







class Cube : public ThreeDimensionalShape {
	
	double sideLength;
	
public:
	
	Cube(double=0);
	virtual double getArea() const;
	virtual double getVolume() const;
	virtual void display() const;
	
	//getter & setter
	void setSideLength(double);
	double getSideLength() const;
};


Cube::Cube(double side) {
	setSideLength(side);
}
double Cube::getArea() const {
	return 6*sideLength*sideLength;
}
double Cube::getVolume() const {
	return sideLength*sideLength*sideLength;
}
void Cube::display() const {
	cout << "Cube with side length " << getSideLength() << ":" << endl;
	ThreeDimensionalShape::display();
}


//getter & setter
void Cube::setSideLength(double side) {
	if (side >= 0) {
		sideLength = side;
	} else {
		throw invalid_argument("Side Length must be >= 0.");
	}
}
double Cube::getSideLength() const {
	return sideLength;
}








class Cylinder : public ThreeDimensionalShape {
	
	double radius;
	double height;
	
public:
	Cylinder(double=0, double=0);
	virtual double getArea() const;
	virtual double getVolume() const;
	virtual void display() const;
	
	//getter & setter
	void setRadius(double);
	double getRadius() const;
	void setHeight(double);
	double getHeight() const;
};


Cylinder::Cylinder(double r, double h) {
	setRadius(r);
	setHeight(h);
}
double Cylinder::getArea() const {
	return 2*PI*radius*radius + 2*PI*radius*height;
}
double Cylinder::getVolume() const {
	return PI*radius*radius*height;
}
void Cylinder::display() const {
	cout << "Cylinder with radius " << getRadius() << " and height " << getHeight() << ":" << endl;
	ThreeDimensionalShape::display();
}


//getter & setter
void Cylinder::setRadius(double r) {
	if (r >= 0) {
		radius = r;
	} else {
		throw invalid_argument("Radius must be >= 0.");
	}
}
double Cylinder::getRadius() const {
	return radius;
}
void Cylinder::setHeight(double h) {
	if (h >= 0) {
		height = h;
	} else {
		throw invalid_argument("Height must be >= 0.");
	}
}
double Cylinder::getHeight() const {
	return height;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
/******************************** Three Dimensional Shape Classes End ********************************/




int main() {
	vector<Shape*> shapes(5);
	shapes[0] = new Circle(2);
	shapes[1] = new Square(5);
	shapes[2] = new Sphere(4);
	shapes[3] = new Cube(1.5);
	shapes[4] = new Cylinder(9, 1.2);

	for (int i = 0; i < 5; ++i) {
		shapes[i]->display();
		cout << endl;
	}
	
	for (int i = 0; i < 5; ++i) {
		delete shapes[i];
	}
}

