#include "Date.h"

// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int key_day = dayArray[month];
	if ((month == 2) && ((year % 4 == 0) && (year % 100 == 0) || (year % 400 == 0)) )
		return ++key_day;
	return key_day;
}

//打印日期
void Date::Print()
{
	std::cout << this->_year << "-" << this->_month << "-" << this->_day << std::endl;
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	if (year >= 0 && 
		month > 0 && month < 13 &&
		day   > 0 && day   < GetMonthDay(year, month))
	{
		_year  = year;
		_month = month;
		_day   = day;
	}
	else
	{
		_year = year;
		_month = month;
		_day = day;
		perror("This data is Fail to access");
		std::cout << "The Error Date is : " << _year << "-" << _month << "-" << _day << std::endl;
	}
}

// 拷贝构造函数
Date::Date(const Date& d)
{
	this->_year  = d._year;
	this->_month = d._month;
	this->_day   = d._day;
}

// 赋值运算符重载  d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator= (const Date& d)
{
	if (this != &d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		return *this;
	}
	return *this;
}


// 日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
		*this -= -day;
	else
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
	}
	return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date ref(*this);
	*this += day;
	return ref;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date ref(*this);
	*this -= day;
	return ref;
}

// 日期-=天数
Date& Date::operator-= (int day)
{
	if (day < 0)
		*this += -day;
	else
	{
		_day -= day;
		while (_day < 0)
		{
			_day += GetMonthDay(_year, _month);
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
		}
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date ref(*this);
	*this += 1;
	return ref;
}

// 后置--
Date Date::operator--(int)
{
	Date ref(*this);
	*this -= 1;
	return ref;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (this->_year > d._year)
		return true;
	else
	{
		if (this->_month > d._month)
			return true;
		else
		{
			if (this->_day > d._day)
				return true;
		}
	}
	return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	return this->_year  == d._year  &&
		   this->_month == d._month &&
		   this->_day   == d._day;
}
// >=运算符重载
inline bool Date::operator >= (const Date& d)
{
	return (*this > d) && (*this == d);
}
// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return (*this < d) && (*this == d);
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	int _thisSum = 0;
	for (int i = 1; i < _month; i++)
	{
		_thisSum += GetMonthDay(_year, i);
	}
	_thisSum += _day;

	int _dSum = 0;
	for (int j = 1; j < d._month; j++)
	{
		_dSum += GetMonthDay(d._year, j);
	}
	_dSum += d._day;
	return _thisSum - _dSum;
}

// 析构函数
Date::~Date()
{
	_year  = 0;
	_month = 0;
	_day   = 0;
}