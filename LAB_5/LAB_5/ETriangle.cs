using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_5
{
    internal class ETriangle : TTriangle // Рівносторонній трикутник
    {
        public ETriangle(Point p1, Point p2, Point p3) : base(p1, p2, p3)
        {
        }
        //Перевизначення методу знаходження площі
        public override double GetSquare()
        {
            return Math.Pow(getA(), 2) * Math.Sqrt(3) / 4;
        }

        public override string ToString()
        {
            return $"ETriangle with coordinates A:{P1}, B:{P2}, C:{P3}\n";
        }


    }
}