#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

//int main()
//{
//	//��Щoj���в���������Ҫ�������������
//	string str;
//	while (cin >> str)
//	{
//		// ...
//		cout << str << endl;
//	}
//}

//void ReadFile()
//{
//	ifstream ifs("main.cpp");
//	char ch;
//	/*while ((ch = ifs.get()) != EOF)
//	{
//		cout << ch;
//	}*/
//
//	/*while (ifs.get(ch))
//	{
//		cout << ch;
//	}*/
//
//	while (ifs)
//	{
//		cout << (char)ifs.get();
//	}
//	cout << endl;
//}
//
//void WriteFile()
//{
//	ofstream ofs("write.txt");
//	ofs.put('a');
//	ofs.write("hello world", 10);
//}
//
//int main()
//{
//	ReadFile();
//	WriteFile();
//	return 0;
//}

struct ServerInfo
{
	char _ip[20];
	int _port;
};

struct ConfigManager
{
public:
	ConfigManager(const char* filename)
		: _filename(filename)
	{}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs.read((char*)&info, sizeof(info));
	}
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs.write((char*)&info, sizeof(info));
	}

	void WriteTxT(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs.write(info._ip, strlen(info._ip));
		ofs.put('\n');
		string portstr = to_string(info._port);
		ofs.write(portstr.c_str(), portstr.size());
	}
	void ReadTxT(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs.getline(info._ip, 20);
		char portbuf[20];
		ifs.getline(portbuf, 20);
		info._port = stoi(portbuf);
	}
private:
	string _filename;
};

//int main()
//{
//	ServerInfo winfo = { "192.0.0.1", 80 };
//	ServerInfo rinfo;
//	//��д -- ������ -- ��д�򵥣���Ч��ݡ� ȱ�㣺�����ַ����ַ������ڴ���д���ļ���������
//	//ConfigManager cfbin("config.bin");
//	//cfbin.WriteBin(winfo);
//	//ConfigManager cfbin("config.bin");
//	//cfbin.ReadBin(rinfo);
//
//	//��д -- �ı�
//	/*ConfigManager cftxt("config.txt");
//	cftxt.WriteTxT(winfo);*/
//	ConfigManager cftxt("config.bin");
//	cftxt.ReadBin(rinfo);
//	return 0;
//}

int main()
{
	ServerInfo info = { "192.0.0.1", 80 };
	//char buf[128];
	////���л�
	//sprintf(buf, "%s %d", info._ip, info._port);

	////�����л�
	//ServerInfo rinfo;
	//sscanf(buf, "%s%d", rinfo._ip, &rinfo._port);

	/*stringstream ssm;
	ssm << info._ip << " " << info._port;
	string buf = ssm.str();*/

	stringstream ssm;
	ssm.str("127.0.0.1 90");
	ServerInfo rinfo;
	ssm >> rinfo._ip >> rinfo._port;
	return 0;
}