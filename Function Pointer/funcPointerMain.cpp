#include <iostream>
#include "cFuncPointer.hpp"

using namespace std;

void intrptHandle0()
{
	cout << endl << "Interrupt Handle 0 callback";
};
void intrptHandle1()
{
	cout << endl << "Interrupt Handle 1 callback";
};
void intrptHandle2()
{
	cout << endl << "Interrupt Handle 2 callback";
};
void intrptHandle3()
{
	cout << endl << "Interrupt Handle 3 callback";
};

void intrptHandle4()
{
	cout << endl << "Interrupt Handle 4 callback";
};

int main()
{
	funcPointer interrupt(50);

	cout << endl << interrupt.assignFunc(intrptHandle0,0);
	cout << endl << interrupt.assignFunc(intrptHandle1,1);
	cout << endl << interrupt.assignFunc(intrptHandle2,2);
	cout << endl << interrupt.assignFunc(intrptHandle3,3);
	cout << endl << interrupt.assignFunc(intrptHandle4,4);

	cout << endl << interrupt.runFunc(4);

	cout << endl << interrupt.runFunc(2);

	return 0;
}