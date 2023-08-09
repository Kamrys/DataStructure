#include <iostream>
using namespace std;
void edit(int** p, int& b) {
	*p = &b;
}
void main() {
	int a = 123;
	int* p = NULL;
	//通过对二级指针的使用来改变p所指向的值
	edit(&p, a);
	cout << p << endl << *p;
}
/*
void edit(int* ptr, int& b) {
	ptr = &b;
}
void main() {
	int a = 123;
	int* p = NULL;
	edit(p, a);
	cout << p << endl << *p;
//报错，传入的p会将值NULL拷贝给函数内的ptr,函数只是改变了局部变量ptr值,没有改变p值
}
*/