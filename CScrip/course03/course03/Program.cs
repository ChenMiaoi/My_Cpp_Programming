using System;

namespace course03
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "hello world";
            // 转换大写
            str = str.ToUpper();
            Console.WriteLine(str);

            //转换小写
            str = str.ToLower();
            Console.WriteLine(str);

            //字符串比较，返回值为bool值
            string str1 = "hello";
            string str2 = "hello";
            bool flag1 = str1.Equals(str2);
            Console.WriteLine(flag1);

            //分割字符串，需要自定义分隔符(char类型的数组)，返回值是一个string类型的数组
            string str3 = "hello,world";
            char[] c = new char[] { ',' };
            string[] ad = str3.Split(c);
            Console.WriteLine(ad[1]);

            //截取字符串
            string str4 = "hello world";
            string ret = str4.Substring(2, 4);
            Console.WriteLine(ret);

            //查找字符在字符串中第一次出现的位置
            string str5 = "hello world";
            Console.WriteLine(str5.IndexOf('o'));

            //查找字符在字符串中最后一次出现的位置
            Console.WriteLine(str5.LastIndexOf('o'));

            //判断字符串是否以...字符串开始
            string str6 = "hello world";
            Console.WriteLine(str6.StartsWith("he"));

            //判断字符串是否以...字符串结束
            Console.WriteLine(str6.EndsWith("he"));

            //替换字符串，将字符串内的子串换成自定义的字符串
            string str7 = "hello world";
            Console.WriteLine(str7.Replace("wor", "row"));

            //判断字符串中是否含有该字符串
            string str8 = "hello world";
            Console.WriteLine(str8.Contains("wro"));

            //去掉字符串的前后空格，返回值是处理后的字符串
            string str9 = " hello world ";
            Console.WriteLine(str9.Trim());

            //去掉字符串之前的空格，和之后的空格
            Console.WriteLine(str9.TrimStart());
            Console.WriteLine(str9.TrimEnd());

            //判断字符串是否为空或Null，注意，是用string来调用的
            //注意，在C#中，Null是不占内存的
            string str10 = "";
            string str11 = null;
            Console.WriteLine(string.IsNullOrEmpty(str10));
            Console.WriteLine(string.IsNullOrEmpty(str11));

            //字符串是引用类型，字符串是存储在堆区的
            //字符串是不可变的，对一个字符串重新赋值是重新建立了一个对象
            //字符串可以只读的字符数组
            string str12 = "hello world";
            Console.WriteLine(str12.Length);
        }
    }
}
