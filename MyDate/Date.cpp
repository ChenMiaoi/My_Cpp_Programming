#include "Date.h"

// ��ȡĳ��ĳ�µ�����
int Date::GetMonthDay(int year, int month)
{
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int key_day = dayArray[month];
	if ((month == 2) && ((year % 4 == 0) && (year % 100 == 0) || (year % 400 == 0)) )
		return ++key_day;
	return key_day;
}

//��ӡ����
void Date::Print()
{
	std::cout << this->_year << "-" << this->_month << "-" << this->_day << std::endl;
}

// ȫȱʡ�Ĺ��캯��
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

// �������캯��
Date::Date(const Date& d)
{
	this->_year  = d._year;
	this->_month = d._month;
	this->_day   = d._day;
}

// ��ֵ���������  d2 = d3 -> d2.operator=(&d2, d3)
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


// ����+=����
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

// ����+����
Date Date::operator+(int day)
{
	Date ref(*this);
	*this += day;
	return ref;
}

// ����-����
Date Date::operator-(int day)
{
	Date ref(*this);
	*this -= day;
	return ref;
}

// ����-=����
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

// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ����++
Date Date::operator++(int)
{
	Date ref(*this);
	*this += 1;
	return ref;
}

// ����--
Date Date::operator--(int)
{
	Date ref(*this);
	*this -= 1;
	return ref;
}

// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// >���������
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

// ==���������
bool Date::operator==(const Date& d)
{
	return this->_year  == d._year  &&
		   this->_month == d._month &&
		   this->_day   == d._day;
}
// >=���������
inline bool Date::operator >= (const Date& d)
{
	return (*this > d) && (*this == d);
}
// <���������
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=���������
bool Date::operator <= (const Date& d)
{
	return (*this < d) && (*this == d);
}

// !=���������
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// ����-���� ��������
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

// ��������
Date::~Date()
{
	_year  = 0;
	_month = 0;
	_day   = 0;
}