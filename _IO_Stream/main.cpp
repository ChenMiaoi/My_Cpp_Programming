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
//	cout << "�������" << endl;
//	cerr << "�������" << endl;
//	clog << "��־���" << endl;
//
//	Stu s;
//	cin >> s._age >> s._name;
//	cout << "���� :> " << s._name << '\t'
//		<< "���� :> " << s._age << endl;
//	printf("���� :> %s\t���� :> %d\n", s._name.c_str(), s._age);
//
//	double d = 1.0 / 3.0;
//	printf("%.2f\n", d);
//	//scanf�������ʱ���Խ����ʣ�����ʹ��string����
//
//	/*
//		���飺
//			1.C++����ȥ��cin��cout�����þ���
//			2.��cout��cin������ĵط�����ȥ������scanf��printf
//			3.���Ǿ�ʹ�÷�����˵������cout���������ʽ��printf��cout����ܶ�
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
//	getline(cin, line);	//�Ի��н���--���ǿո�
//	cout << line << endl;
//}

//�������Ϳ���֧������������Զ������Ͳ���
//�Զ���������Ҫcout��cin�������������Ҫ����operator�������

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

//�Զ������Ͷ������ȥֱ���������߼��ж�
//�Ϳ�������operator void* ���� operator bool
//��operator new�������������е�����

int main()
{
	//��Щoj���в���������Ҫ�������������
	string str;
	while (cin >> str)
	{
		// ...
		cout << str << endl;
	}
}