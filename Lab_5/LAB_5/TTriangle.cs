using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_5
{
    internal class TTriangle //Загальний клас трикутника    
    {
        protected Point P1, P2, P3; // Вершини трикутника

        public TTriangle(Point p1, Point p2, Point p3)
        {
            P1 = p1;
            P2 = p2;
            P3 = p3;

        }
        //Знаходження сторін трикутника
        public double getA()
        {
            return Math.Sqrt(Math.Pow((P2.X - P1.X), 2) + Math.Pow((P2.Y - P1.Y), 2));
        }

        public double getB()
        {
            return Math.Sqrt(Math.Pow((P3.X - P1.X), 2) + Math.Pow((P3.Y - P1.Y), 2));
        }

        public double getC()
        {
            return Math.Sqrt(Math.Pow((P3.X - P2.X), 2) + Math.Pow((P3.Y - P2.Y), 2));
        }
        //Знаходження періметру 
        public double GetPerimetr()
        {
            return getA() + getB() + getC();
        }
        //Віртуальний метод отримання площі трикутника
        public virtual double GetSquare()
        {
            return 0;
        }

        public override string ToString()
        {
            return $"Triangle with coordinates A:{P1}, B:{P2}, C:{P3}\n";
        }
    }
}