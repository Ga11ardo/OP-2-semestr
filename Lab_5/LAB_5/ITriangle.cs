using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_5
{
    internal class ITriangle : TTriangle //рівнобедрений трикутник
    {
        public ITriangle(Point p1, Point p2, Point p3) : base(p1, p2, p3)
        {
        }

        public override string ToString()
        {
            return $"ITriangle with coordinates A:{P1}, B:{P2}, C:{P3}\n";
        }


    }
}