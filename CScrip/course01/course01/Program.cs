using System;

namespace course01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            //整形 类型
            int score = 1;

            //浮点 类型 -- 和C++一样
            float f1 = 100;
            float f2 = 1.2f;

            double f3 = 1;

            //布尔 类型
            bool flag = true;

            //字符串类型，可以存储空字符串
            string playName = "Monkey";

            //字符类型，与C++不同，char类型必须使用字符来赋值，char不可以存储空字符
            char num = '1';


            //占位符

            string name = "hhe";
            int age = 100;
            string sex = "man";

            Console.WriteLine("我的名字是{0}，我今年{1}岁了， 我的性别是{2}", name, age, sex);

            //用户输入
            string hh;
            hh = Console.ReadLine();
            Console.WriteLine(hh);

            //使用
            Console.WriteLine(score);
            Console.WriteLine(playName);
            Console.WriteLine(num);
        }
    }
}
