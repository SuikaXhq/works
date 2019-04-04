class MyBase31 {
int a, b, c;
public:
	MyBase31(int x, int y, int z):a(x), b(y), c(z) {
		cout << ¡°¡­BaseClass31 Object is created!¡±<< end;
		cout << a << ¡°  ¡° << b << ¡°  ¡° <<  c << endl;
	}
	~ MyBase31(){
		cout << ¡°¡­BaseClass31 Object is destroyed!¡±<< end;
	}
}

class MyBase32 {
	int a, b, c;
public:
	MyBase32(int x, int y, int z) {
		cout << ¡°¡­BaseClass32 Object is created!¡±<< end;
		cout << a << ¡°  ¡° << b << ¡°  ¡° <<  c << endl;
		a=x, b=y, c=z; cout << a << ¡°  ¡° << b << ¡°  ¡° <<  c << endl;
	}
	~ MyBase32(){
		cout << ¡°¡­BaseClass32 Object is destroyed!¡±<< end;
	}
}

int main() {
	MyBase31 a(1,2,3);
	MyBase32 b(4,5,6);
}
