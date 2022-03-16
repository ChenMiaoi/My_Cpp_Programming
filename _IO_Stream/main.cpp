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

//int main()
//{
//	//有些oj多行测试用例，要求持续接受输入
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
//	//读写 -- 二进制 -- 读写简单，高效快捷。 缺点：除了字符和字符串，内存中写到文件中是乱码
//	//ConfigManager cfbin("config.bin");
//	//cfbin.WriteBin(winfo);
//	//ConfigManager cfbin("config.bin");
//	//cfbin.ReadBin(rinfo);
//
//	//读写 -- 文本
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
	////序列化
	//sprintf(buf, "%s %d", info._ip, info._port);

	////反序列化
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