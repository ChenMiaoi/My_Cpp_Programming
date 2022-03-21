#include "Date.h"

void test1()
{
	Date d1(2000, 2, 29);
	Date d2(1212, 12, 54);
}

void test2()
{
	Date d1;
	d1.Print();
	Date d2(2022, 3, 21);
	Date d3;
	d3 = d2;
	d3.Print();
	d3 = d3;
	d3.Print();
	Date d4(d3);
	d4.Print();
}

void test3()
{
	Date d1(2022, 3, 21);
	d1 += 50;
	d1.Print();
	d1 -= 50;
	d1.Print();
	d1 -= -50;
	d1.Print();
	d1 += -50;
	d1.Print();
}

void test4()
{
	Date d1(2022, 3, 21);
	d1 + 50;
	d1.Print();

	d1 = d1 + 50;
	d1.Print();

	d1 - 50;
	d1.Print();

	d1 = d1 - 50;
	d1.Print();
}

void test5()
{
	Date d1(2022, 3, 21);
	d1++;
	d1.Print();

	++d1;
	d1.Print();

	d1--;
	d1.Print();

	--d1;
	d1.Print();
}

void test6()
{
	Date d1(2022, 3, 21);
	Date d2(2022, 1, 1);
	Date d3(2021, 3, 21);
	std::cout << d1 - d2 << std::endl;	
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
}