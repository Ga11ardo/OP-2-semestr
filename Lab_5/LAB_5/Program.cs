using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Worker worker = new Worker();
            Console.WriteLine("-----------------------------------------------");
            Console.WriteLine("Enter number of triangles you want to create: ");

            int n = Convert.ToInt32(Console.ReadLine());


            RTriangle[] rTriangles = worker.GetRtriangleArray(n);

            ITriangle[] iTriangles = worker.GetItriangleArray(n);

            ETriangle[] eTriangles = worker.GetEtriangleArray(n);
            Console.WriteLine("-----------------------------------------------");
            Console.WriteLine("\nRTriangles array:");
            worker.printArray(rTriangles);
            Console.WriteLine("RTriangles squares:");
            worker.printSquare(rTriangles);

            Console.WriteLine("\nETriangles array:");
            worker.printArray(eTriangles);
            Console.WriteLine("ETriangles squares:");
            worker.printSquare(eTriangles);

            Console.WriteLine("\nITriangles array:");
            worker.printArray(iTriangles);
            Console.WriteLine("ITriangles perimeters:");
            worker.printPerimeter(iTriangles);

            Console.WriteLine("-----------------------------------------------");
            Console.WriteLine("RTriangles SquaresSum:");
            double sumSquaresRt = worker.GetSumSquares(rTriangles);
            Console.WriteLine($"The sum of RTriangles Squares - {Math.Round(sumSquaresRt, 2)}");
            Console.WriteLine("-----------------------------------------------");
            Console.WriteLine("ETriangles SquaresSum:");
            double sumSquaresEt = worker.GetSumSquares(eTriangles);
            Console.WriteLine($"The sum of ETriangles Squares - {Math.Round(sumSquaresEt, 2)}");
            Console.WriteLine("-----------------------------------------------");
            Console.WriteLine("ITriangle PerimetersSum:");
            double sumPerimetersIt = worker.SumOfPerimeteres(iTriangles);
            Console.WriteLine($"The sum of ITriangles Perimeters - {Math.Round(sumPerimetersIt, 2)}");




        }
    }
}