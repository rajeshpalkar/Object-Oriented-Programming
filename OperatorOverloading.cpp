//
//  main.cpp
//  CPP06
//
//  Created by Rajesh Palkar on 11/11/17.
//  Copyright © 2017 Rajesh Palkar. All rights reserved.
//

#include <iostream>
#include <math.h>

class Point
{
    
    float X, Y;
public:
    Point() // default constructor
    {
        X=0.0;
        Y=0.0;
    }
    Point(float x, float y) // Overloaded constructor
    {
        X = x;
        Y = y;
    }
    
    Point &operator=(const Point &p)   //Operator overloading
    {
        X = p.X;
        Y = p.Y;
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream& stream, const Point p)  //Overloading << operator
    {
        stream << "X :" << p.X << "Y :" << p.Y;
        return stream;
    }
    
    Point(const Point &p) // Copy constructor
    {
        X = p.X;
        Y = p.Y;
    }
    // ~Point(){} // Destructor
    
    float getX()
    {
        return X;
    }
    float getY()
    {
        return Y;
    }
    void displayPoint();
    void setPoint(float x,float y)
    {
        X = x;
        Y = y;
    }
    
};

class Shape
{
protected:
    
    int nc;  // number of corner points
    
    Shape()  // default constructor
    {
        nc = 3;
    }
    
    Shape(int ncp)  // Overloaded
    {
        nc = ncp;
    }
    
    Shape(const Shape &s) // Copy contructor
    {
        nc  = s.nc;
    }
    //  ~Shape();
    void displayShape()
    {
        std::cout<< "\nNumber of Corner Points :" <<nc;
    }
    
    float segmentLength(Point m, Point n)
    {
        float result;
        
        float x = n.getX() - m.getX();
        float sqrX = pow(x,2);
        float y = n.getY() - m.getY();
        float sqrY = pow(y,2);
        
        result = sqrt(sqrX+sqrY);
        return result;
    }
    
    virtual float area()=0;
    virtual float perimeter()=0;
    
};

class Triangle : public Shape
{
    float result;
    Point x, y, z;  // number of corner points
public:
    Triangle()  // default constructor
    {
        nc = 3;    //setting number of corner points to 3 in default constructor
    }
    Triangle(Point p)
    {
        std::cout<<"\n\nTriangle cannot be formed with single point!";
    }
    Triangle(Point p, Point q)
    {
        if((p.getX()==0 and p.getY()==0) || (q.getX()==0 and q.getY()==0))
        {
            std::cout<<"\nAny certain traingle cannot be formed in this case!";
        }
        else
        {
            x = p;
            y = q;
            z.setPoint(0, 0);
        }
    }
    
    Triangle(Point p, Point q, Point r)  // Overloaded
    {
        if((p.getX()==q.getX() and p.getY()==q.getY()) ||
           (p.getX()==r.getX() and p.getY()==r.getY()) ||
           (r.getX()==q.getX() and r.getY()==q.getY()))
        {
            std::cout<<"\nIn this case two out of three points are same hence triangle cannot be formed!";
        }
        else
        {
            x = p ;
            y = q;
            z = r;
        }
    }
    
    Triangle(const Triangle &t) // Copy contructor
    {
        x = t.x;
        y = t.y;
        z = t.z;
    }
    
    // ~Triangle();
    void displayTriangle()
    {
        std::cout<< "x :" << x;
        std::cout<< "y :" << y;
        std::cout<< "z :" << z;
    }
    
    float area(){
        
        float lengthOne = segmentLength(x, y);
        float lengthTwo = segmentLength(y, z);
        float lengthThree = segmentLength(z, x);
        
        float s = (lengthOne + lengthTwo + lengthThree)/2;
        
        result = sqrt(s*(s-lengthOne)*(s-lengthTwo)*(s-lengthThree));
        
        return result;
    }
    float perimeter(){
        
        float lengthOne = segmentLength(x, y);
        float lengthTwo = segmentLength(y, z);
        float lengthThree = segmentLength(z, x);
        
        
        result = lengthOne + lengthTwo + lengthThree;
        
        return result;
    }
    
};
class Rectangle : public Shape
{
protected:
    float result;
    Point w, x, y, z;  // number of corner points
public:
    Rectangle()  // default constructor
    {
        /*  w = 0.0;
         x = 0.0;
         y = 0.0;
         z = 0.0;
         */
        nc = 4; // number of corner points set to four in case of rectangle
    }
    
    Rectangle(Point p)  //with single point
    {
        nc = 4;
        if((p.getX()==0 and p.getY()==0)) // point with same x and y co-ordinate can form a square and avoiding                                         point(0,0)
        {
            std::cout<<"\n\nRectangle cannot be formed with (0,0)!";
        }
        else                                         //             |
        {                                            //             |
            w.setPoint(0, 0);                        //            x.-----.y=p(x,y)
            x.setPoint(0, p.getY());                 //             |     |
            y = p;                                   // -----------w.-----.z---------
            z.setPoint(p.getX(), 0);                 //             |
        }                                            //             |
    }                                                //             |
    
    
    Rectangle(Point p,Point q) //with two points
    {
        if((p.getX()==q.getX()) || (p.getY()==q.getY()))
        {
            if((p.getX()==q.getX()) && (p.getY()==q.getY()))
            {
                Rectangle(p);   // Two points are same hence redirecting to the constructor with one point as parameter.
            }
            else
            {
                std::cout<<"\n\nRectangle cannot be formed because two points on same line!!";
            }
        }
        else
        {
            w = p;
            y = q;
            
            /*float diagonalDist = segmentLength(p, q);
             float dist = diagonalDist/sqrt(2);*/
            
            
            x.setPoint(w.getX(), y.getY());   // x co-ordinate of w Point and y co-ordinate of y Point
            z.setPoint(y.getX(), w.getY());   // x co-ordinate of y Point and x co-ordinate of w Point
        }
        nc = 4;
    }
    
    Rectangle(Point p,Point q, Point r) //with three points
    {
        w = p;
        x = q;
        y = r;
        
        nc = 3;
        
    }
    
    Rectangle(Point p, Point q, Point r, Point s)  // Overloading constructor with four points
    {
        w = p;
        x = q;
        y = r;
        z = s;
        
        nc = 4;
    }
    
    Rectangle(const Rectangle &r) // Copy contructor
    {
        w = r.w;
        x = r.x;
        y = r.y;
        z = r.z;
        
        nc = 4;
    }
    
    // ~Rectangle();
    void displayRectangle()
    {
        if(nc==3)
        {
            std::cout<< "w :" << w;
            std::cout<< "x :" << x;
            std::cout<< "y :" << y;
        }
        else{
            std::cout<< "w :" << w;
            std::cout<< "x :" << x;
            std::cout<< "y :" << y;
            std::cout<< "z :" << z;
        }
    }
    
    float area(){
        
        float lengthOne = 0, lengthTwo =0, lengthThree;
        
        
        /*   if(w.getX()==x.getX() || w.getY()==x.getY())
         {
         lengthOne = segmentLength(w, x);
         if(w.getX()==y.getX() || w.getY() == y.getY())
         lengthTwo = segmentLength(w, y);
         else
         {
         lengthTwo = segmentLength(x, y);
         }
         }
         else if(y.getX()==x.getX() || y.getY()==x.getY())
         {
         lengthOne = segmentLength(x, y);
         if(x.getX()==w.getX() || x.getY() == w.getY())
         lengthTwo = segmentLength(x, w);
         else
         {
         lengthTwo = segmentLength(y, w);
         }
         }*/
        int flag = 0;
        lengthOne = segmentLength(w, x);
        lengthTwo = segmentLength(x, y);
        lengthThree = segmentLength(w, y);
        
        
        if(lengthOne > lengthTwo)
        {
            if(lengthOne > lengthThree)
            {
                flag  = 1;   // max is one
            }
            else
            {
                flag = 3;    // max is three
            }
        }
        else
        {
            if(lengthTwo > lengthThree)
            {
                flag = 2;     // max is two
            }
            else
            {
                flag = 3;     // max is three
            }
            
        }
        
        
        switch (flag) {
            case 1:
                result = lengthTwo * lengthThree;
                break;
            case 2:
                result = lengthOne * lengthThree;
                break;
            case 3:
                result = lengthOne *lengthTwo;
                break;
                
            default:
                break;
        }
        
        
        
        
        // result = lengthOne * lengthTwo;
        
        return result;
    }
    float perimeter(){
        
        float lengthOne = 0, lengthTwo =0, lengthThree =0;
        
        
        /*   if(w.getX()==x.getX() || w.getY()==x.getY())
         {
         lengthOne = segmentLength(w, x);
         if(w.getX()==y.getX() || w.getY() == y.getY())
         lengthTwo = segmentLength(w, y);
         else
         {
         lengthTwo = segmentLength(x, y);
         }
         }
         else if(y.getX()==x.getX() || y.getY()==x.getY())
         {
         lengthOne = segmentLength(x, y);
         if(x.getX()==w.getX() || x.getY() == w.getY())
         lengthTwo = segmentLength(x, w);
         else
         {
         lengthTwo = segmentLength(y, w);
         }
         }*/
        
        int flag = 0;
        lengthOne = segmentLength(w, x);
        lengthTwo = segmentLength(x, y);
        lengthThree = segmentLength(w, y);
        
        
        
        if(lengthOne > lengthTwo)
        {
            if(lengthOne > lengthThree)
            {
                flag  = 1;   // max is one
            }
            else
            {
                flag = 3;    // max is three
            }
        }
        else
        {
            if(lengthTwo > lengthThree)
            {
                flag = 2;     // max is two
            }
            else
            {
                flag = 3;     // max is three
            }
            
        }
        
        
        
        switch (flag) {
                
            case 1:
                result = 2*lengthTwo + 2*lengthThree;
                break;
            case 2:
                result = 2*lengthOne + 2*lengthThree;
                break;
            case 3:
                result = 2*lengthOne + 2*lengthTwo;
                break;
            default:
                break;
        }
        
        // result = 2*lengthOne + 2*lengthTwo; /* + lengthThree + lengthFour;*/
        return result;
    }
    
};

class Square : public Rectangle
{
    /*  float result;
     Point w, x, y, z;  // number of corner points */
public:
    Square()  // default constructor
    {
        /*  w = 0.0;
         x = 0.0;
         y = 0.0;
         z = 0.0;*/
        
        nc = 4; // number of corner points set to four in case of square
    }
    
    Square(Point p)
    {
        if((p.getX()==0 and p.getY()==0)) // avoiding point (0,0)
        {
            std::cout<<"\n\nRectangle cannot be formed with (0,0) or (x,x)!";
        }
        else                                         //             |
        {                                            //             |
            w.setPoint(0, 0);                        //            x.-----.y=p(x,y)
            x.setPoint(0, p.getY());                 //             |     |
            y = p;                                   // -----------w.-----.z---------
            z.setPoint(p.getX(), 0);                 //             |
        }                                            //             |
        
        nc = 4;
    }
    
    Square(Point p, Point q) // with two points
    {
        nc = 4;
        
        if(p.getX()==q.getX())    // when x co-ordinate is same of two points
        {
            w = p;
            x = q;
            
            float dist = segmentLength(p, q);
            y.setPoint(w.getX() + dist,  w.getY());
            z.setPoint(x.getX() + dist, x.getY());
            
            
        }
        else if(p.getY()==q.getY())  // when co-ordinate is same of two points
        {
            w = p;
            x = q;
            
            float dist = segmentLength(p, q);
            y.setPoint(w.getX() ,  w.getY() + dist);
            z.setPoint(x.getX() , x.getY() + dist);
        }
        else  // when either x or y co-ordinate are not same that means these two points are diagonal points
        {
            w = p;
            y = q;
            
            /*float diagonalDist = segmentLength(p, q);
             float dist = diagonalDist/sqrt(2);*/
            
            
            x.setPoint(w.getX(), y.getY());   // x co-ordinate of w Point and y co-ordinate of y Point
            z.setPoint(y.getX(), w.getY());   // x co-ordinate of y Point and x co-ordinate of w Point
            
            
        }
    }
    
    Square(Point p, Point q, Point r) // with three points
    {
        
        /*  float dist1 = segmentLength(p, q);
         float dist2 = segmentLength(q, r);
         
         
         if((p.getX()==q.getX() || p.getX()==r.getX()) and (p.getY()==q.getY() || p.getY()==r.getY()))  // p is common point
         {
         // continue
         }
         
         if((p.getX()==q.getX() || p.getX()==r.getX()) and (p.getY()==q.getY() || p.getY()==r.getY()))  // q is common point
         {
         
         }*/
        
        w = p;
        x = q;
        y = r;
        
        nc = 3;
        
        
    }
    
    Square(Point p, Point q, Point r,Point s)  // Overloading constructor with four points
    {
        w = p;
        x = q;
        y = r;
        z = s;
        
        nc = 4;
    }
    
    Square(const Square &s) // Copy contructor
    {
        w = s.w;
        x = s.x;
        y = s.y;
        z = s.z;
        
        nc = 4;
    }
    
    // ~Square();
    void displaySquare()
    {
        if(nc == 3){
            std::cout<< "w :" << w;
            std::cout<< "x :" << x;
            std::cout<< "y :" << y;
            
        }
        else {
            std::cout<< "w :" << w;
            std::cout<< "x :" << x;
            std::cout<< "y :" << y;
            std::cout<< "z :" << z;
        }
    }
    
    
    //   float area(){
    //        float lengthOne = segmentLength(w, x);
    
    //        result = pow(lengthOne,2);
    //        return result;
    //    }
    //    float perimeter(){
    //        float lengthOne = segmentLength(w, x);
    
    /* float lengthTwo = segmentLength(x, y);
     float lengthThree = segmentLength(y, z);
     float lengthFour = segmentLength(z, w);*/
    
    //        result = 4*lengthOne ; /*+ lengthTwo + lengthThree + lengthFour;*/
    //       return result;
    //  }
    
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    //***************************************************Triangle***************************************************
    Point *p1 = new Point(0,0);
    Point *p2 = new Point(4,0);
    Point *p3 = new Point(0,3);
    
    Triangle *t1 = new Triangle(*p1,*p2,*p3);
    
    float trianglePerimeter = t1->perimeter();
    float triangleArea = t1->area();
    
    
    std::cout<< "\nPerimeter of Triagnle 3 Vertices:" << trianglePerimeter;
    std::cout<< "\nArea of Triangle 3 Vertices:" << triangleArea;
    
    Triangle *t2 = new Triangle(*p2,*p3);
    
    float trianglePerimeter2 = t2->perimeter();
    float triangleArea2 = t2->area();
    
    
    std::cout<< "\n\nPerimeter of Triagnle 2 Vertices:" << trianglePerimeter2;
    std::cout<< "\nArea of Triangle 2 Vertices:" << triangleArea2;
    
    Triangle *t3 = new Triangle(*p2);
    
    float trianglePerimeter3 = t3->perimeter();
    float triangleArea3 = t3->area();
    
    
    std::cout<< "\n\nPerimeter of Triagnle 1 Vertex:" << trianglePerimeter3;
    std::cout<< "\nArea of Triangle 1 Vertex:" << triangleArea3;
    
    //****************************************************Square*************************************************
    
    Point *p11 = new Point(0,0);
    Point *p12 = new Point(4,0);
    Point *p13 = new Point(0,4);
    Point *p14 = new Point(4,4);
    
    
    Square *s1 = new Square(*p11,*p12,*p13,*p14);
    
    float squareArea4 = s1->area();
    float squarePerimeter4 = s1->perimeter();
    
    std::cout<< "\n\nPerimeter of Square 4 Vertices:" << squarePerimeter4;
    std::cout<< "\nArea of Square 4 Vertices:" << squareArea4;
    
    Square *s2 = new Square(*p11,*p12,*p13);
    
    float squareArea3 = s2->area();
    float squarePerimeter3 = s2->perimeter();
    
    std::cout<< "\n\nPerimeter of Square 3 Vertices:" << squarePerimeter3;
    std::cout<< "\nArea of Square 3 Vertices:" << squareArea3;
    
    Square *s3 = new Square(*p11,*p12);
    
    float squareArea2 = s3->area();
    float squarePerimeter2 = s3->perimeter();
    
    std::cout<< "\n\nPerimeter of Square 2 Vertices:" << squarePerimeter2;
    std::cout<< "\nArea of Square 2 Vertices:" << squareArea2;
    
    Square *s4 = new Square(*p14);
    
    float squareArea1 = s4->area();
    float squarePerimeter1 = s4->perimeter();
    
    std::cout<< "\n\nPerimeter of Square 1 Vertex:" << squarePerimeter1;
    std::cout<< "\nArea of Square 1 Vertex:" << squareArea1;
    
    //***************************************************Rectangle************************************************
    
    Point *p21 = new Point(0,0);
    Point *p22 = new Point(4,0);
    Point *p23 = new Point(4,2);
    Point *p24 = new Point(0,2);
    
    
    Rectangle *r1 = new Rectangle(*p21,*p24,*p23,*p22);
    
    float rectangleArea4 = r1->area();
    float rectanglePerimeter4 = r1->perimeter();
    
    std::cout<< "\n\nPerimeter of Rectangle 4 Vertices:" << rectanglePerimeter4;
    std::cout<< "\nArea of Rectangle 4 Vertices:" << rectangleArea4;
    
    Rectangle *r2 = new Rectangle(*p21,*p24,*p23);
    
    float rectangleArea3 = r2->area();
    float rectanglePerimeter3 = r2->perimeter();
    
    std::cout<< "\n\nPerimeter of Rectangle 3 Vertices:" << rectanglePerimeter3;
    std::cout<< "\nArea of Rectangle 3 Vertices:" << rectangleArea3;
    
    Rectangle *r3 = new Rectangle(*p21,*p24);
    
    float rectangleArea2 = r3->area();
    float rectanglePerimeter2 = r3->perimeter();
    
    std::cout<< "\n\nPerimeter of Rectangle 2 Vertices:" << rectanglePerimeter2;
    std::cout<< "\nArea of Rectangle 2 Vertices:" << rectangleArea2;
    
    Rectangle *r4 = new Rectangle(*p23);
    
    float rectangleArea1 = r4->area();
    float rectanglePerimeter1 = r4->perimeter();
    
    std::cout<< "\n\nPerimeter of Rectangle 1 Vertices:" << rectanglePerimeter1;
    std::cout<< "\nArea of Rectangle 1 Vertices:" << rectangleArea1;
    
    //*****************************************************************************************************
    getchar();
    
    return 0;
}

