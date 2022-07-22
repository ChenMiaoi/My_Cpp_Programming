using System;
using System.Text;
using System.Diagnostics;

namespace course04
{
    class Program
    {
        static void Main(string[] args)
        {
            //StringBuilder
            //字符串重复赋值时，会产生大量垃圾数据在内存中
            //StringBuilder不会产生大量的垃圾数据，提高效率
            //StringBuilder 依赖System.Text命名空间
            StringBuilder sb = new StringBuilder();

            //追加数据
            sb.Append("Hello world");
            sb.Append(123456);
            sb.Append(1.255);

            //转化为字符串
            sb.ToString();
            Console.WriteLine(sb);

            //清空数据
            sb.Clear();
            Console.WriteLine(sb);

            /*
                验证StringBuilder效率
                使用Stopwatch，秒表计时器，依赖System.Diagnostics
             */
            string str = "";
            Stopwatch sw = new Stopwatch();
            sw.Start();
            for (int i = 0; i < 500000; i++)
            {
                sb.Append(i);
            }
            sw.Stop();
            Console.WriteLine(sw.Elapsed); //Elapsed直接计算出开始到结束的时长

            sw.Start();
            for (int i = 0; i < 500000; i++)
            {
                str += i;
            }
            sw.Stop();
            Console.WriteLine(sw.Elapsed); //Elapsed直接计算出开始到结束的时长
        }
    }
}
