using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_5
{
    internal class Worker
    { //Генерація масивів трикутників
        public ETriangle[] GetEtriangleArray(int n)
        {
            ETriangle[] triangles = new ETriangle[n];
            for (int i = 0; i < n; i++)
            {
                Point[] points = GetEtPointArray();
                triangles[i] = new ETriangle(points[0], points[1], points[2]);
            }
            return triangles;
        }
        public ITriangle[] GetItriangleArray(int n)
        {
            ITriangle[] triangles = new ITriangle[n];
            for (int i = 0; i < n; i++)
            {
                Point[] points = GetItPointArray();
                triangles[i] = new ITriangle(points[0], points[1], points[2]);
            }
            return triangles;
        }

        public RTriangle[] GetRtriangleArray(int n)
        {
            RTriangle[] triangles = new RTriangle[n];
            for (int i = 0; i < n; i++)
            {
                Point[] points = GetRtPointArray();
                triangles[i] = new RTriangle(points[0], points[1], points[2]);
            }
            return triangles;

        }

        //Генерація масиву точок для об'єкту класа трикутників
        public Point[] GetEtPointArray()
        {
            Point[] points = new Point[3];
            Random random = new Random();
            Point p1 = new Point(random.Next(-10, 11), random.Next(-10, 11));
            Point p2 = new Point(random.Next(-10, 11), random.Next(-10, 11));
            Point p3 = new Point();
            p3.X = Math.Round((p2.X - p1.X) * 0.5 - (p2.Y - p1.Y) * Math.Sqrt(3) / 2 + p1.X);
            p3.Y = Math.Round((p2.X - p1.Y) * Math.Sqrt(3) / 2 + (p2.Y - p1.Y) * 0.5 + p1.Y);
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;


            return points;
        }
        public Point[] GetItPointArray()
        {
            Point[] points = new Point[3];
            Random random = new Random();
            Point p1 = new Point(random.Next(-10, 11), random.Next(-10, 11));
            Point p2 = new Point(random.Next(-10, 11), random.Next(-10, 11));
            Point p3 = new Point();
            if (p1.X > p2.X) p3.X = (p2.X - Math.Abs(p1.X - p2.X));

            else p3.X = Math.Abs(p1.X - p2.X) + p2.X;
            p3.Y = p1.Y;
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;

            return points;
        }



        public Point[] GetRtPointArray()
        {
            Point[] points = new Point[3];
            Random random = new Random();
            Point p1 = new Point(random.Next(-10, 11), random.Next(-10, 11));
            Point p2 = new Point(random.Next(-10, 11), random.Next(-10, 11));
            Point p3 = new Point(p1.X, p2.Y);
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;

            return points;
        }

        //Виведення масиву трикутників
        public void printArray(TTriangle[] triangles)
        {
            foreach (var triangle in triangles)
            {
                Console.WriteLine(triangle);

            }

        }
        //Підрахунок суми площ трикутників з масиву
        public double GetSumSquares(TTriangle[] triangles)
        {
            return triangles.Sum(triangle => triangle.GetSquare());
        }

        //Підрахунок суми периметрів трикутників з масиву
        public double SumOfPerimeteres(TTriangle[] triangles)
        {
            return triangles.Sum(triangle => triangle.GetPerimetr());

        }

        //Виведення площ трикутників з масиву
        public void printSquare(TTriangle[] triangles)
        {
            foreach (var triangle in triangles)
            {
                Console.WriteLine(Math.Round(triangle.GetSquare(), 2));
            }
        }
        //Виведення периметрів трикутників з масиву
        public void printPerimeter(ITriangle[] triangles)
        {
            foreach (var triangle in triangles)
            {
                Console.WriteLine(Math.Round(triangle.GetPerimetr(), 2));
            }
        }

    }
}