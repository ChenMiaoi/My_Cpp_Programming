#include <iostream>
#include <string>

using namespace std;

struct Stu
{
	string _name = "person";
	int _age = 18;

};

//int main()
//{
//	cout << "正常输出" << endl;
//	cerr << "错误输出" << endl;
//	clog << "日志输出" << endl;
//
//	Stu s;
//	cin >> s._age >> s._name;
//	cout << "姓名 :> " << s._name << '\t'
//		<< "年龄 :> " << s._age << endl;
//	printf("姓名 :> %s\t年龄 :> %d\n", s._name.c_str(), s._age);
//
//	double d = 1.0 / 3.0;
//	printf("%.2f\n", d);
//	//scanf在输入的时候会越界访问，不会使得string扩容
//
//	/*
//		建议：
//			1.C++尽量去用cin、cout，能用就用
//			2.用cout、cin不方便的地方，再去考虑用scanf、printf
//			3.但是就使用方便来说，对于cout控制输出形式，printf比cout方便很多
//	*/
//
//	return 0;
//}

//int main()
//{
//	string line;
//	/*cin >> line;
//	cout << line << endl;*/
//
//	getline(cin, line);	//以换行结束--而非空格
//	cout << line << endl;
//}

//内置类型可以支持输入输出，自定义类型不能
//自定义类型想要cout和cin输入输出，就需要重载operator输入输出

//class Person
//{
//	friend ostream& operator<< (ostream& _cout, Person& p);
//public:
//	Person(string name, string sex)
//	{
//		_name = name;
//		_sex = sex;
//	}
//private:
//	string _name;
//	string _sex;
//};
//
//ostream& operator<< (ostream& _cout, Person& p)
//{
//	_cout << p._name << p._sex;
//	return _cout;
//}
//
//int main()
//{
//	Person p("hehe", "1");
//	cout << p << endl;
//}

//自定义类型对象可以去直接做条件逻辑判断
//就可以重载operator void* 或者 operator bool
//跟operator new很像，属于重载中的特例

int main()
{
	//有些oj多行测试用例，要求持续接受输入
	string str;
	while (cin >> str)
	{
		// ...
		cout << str << endl;
	}
}