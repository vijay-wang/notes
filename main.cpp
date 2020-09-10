#include <iostream>

using namespace std;

class Test
{
public:
	int var_d;
	int var_c;
	Test(int a):var_c(a){ cout <<"构造函数被调用"<<endl; };
	
	static int get_num( void ){ return var_b; };
	static int var_a;
private:
	static int var_b;	
};

//Test::Test(int a):var_c（a）
//{
//	cout <<"构造函数被调用"<<endl;
//}

int Test::var_a=1;
int Test::var_b=2;

void print_num( void )
{
	static int var_a=1;
	cout << var_a<<endl;
	var_a++;
	
}

int main() {
	print_num();
	print_num();
	print_num();
	print_num();
	cout <<Test::get_num()<< endl;
	Test a(100);
	a.var_d=101;
	cout <<a.var_c<<endl;
	return 0;
}

