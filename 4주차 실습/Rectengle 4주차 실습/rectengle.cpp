#include<iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0, int num = 0) // int 1개 구현
{ xLow=x; yLow=y; height=h; width=w; rNum = num;}

Rectangle::~Rectangle()
{ cout << "delete" << endl; }

int Rectangle::GetNum() {return rNum;}
int Rectangle::GetHeight() {return height; }
int Rectangle::GetWidth() { return width; }
int Rectangle::GetArea() { return width*height; }

ostream& operator <<(ostream& os, Rectangle& r)
{
    os << "Position is: " << r.xLow << " ";
    os << r.yLow << endl;
    os << "Height is: " << r.height << endl;
    os << "Width is: " << r.width << endl;
    return os;
}