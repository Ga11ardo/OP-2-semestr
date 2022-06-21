using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_5
{
    internal class RTriangle : TTriangle //прямокутний трикутник
    {
        public RTriangle(Point p1, Point p2, Point p3) : base(p1, p2, p3) //Виклик конструктора базового класу 
        {
        }
        //Перевизначення функції(віртуальність функції)
        public override double GetSquare()
        {
            return 0.5 *
           (getA() > getB() ? (getA() > getC() ? getB() * getC() : getA() * getB()) : (getB() > getC() ? getC() * getA() : getA() * getB()));
        }
        public override string ToString()
        {
            return $"RTriangle with coordinates A:{P1}, B:{P2}, C:{P3}\n";
        }
    }
}