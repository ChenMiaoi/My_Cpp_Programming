using System;

namespace course02
{
    class Program
    {
        static int Func(int a)
        {
            return 1;
        }
        static void Func()
        {
            Console.WriteLine("Hello world"); 
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int[] arr = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            for (int i = 0; i < 10; i++) {
                Console.WriteLine(arr[i]);
            }

            int[,] arr1 = new int[, ]{ 
                {1, 2, 3},{ 4, 5, 6 }
            };
            Func();
            Func(1);
        }
    }
}
