#include<iostream>
#include<string>
#include"Data.h"
using namespace std;
int main() {
	Data a1;
	a1.Print();
	Data a2("1/1/2024");
	a2.Print();
	Data a3(20, 2, 2024);
	a3.Print();
	Data a4(250, 2024);
	a4.Print();

	return 0;
}
