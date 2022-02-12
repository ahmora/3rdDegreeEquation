/**
 * This is a library for c++ used to model third degree equations
 *
 * @author: Alejandro Hernandez Mora
 */
#include <string>
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

class Equation{
  
private:
  double a,b,c,d;

  
public:
  Equation(double a, double b, double c, double d){
    this->a=a;
    this->b=b;
    this->c=c;
    this->d=d;
  }

  string toString(){
    return to_string(a) + "x^3 + " + to_string(b) + "x^2 + " + to_string(c) + "x + " + to_string(d);
  }

  //Discriminant to determine if its 0 without precission problems.
  double discriminant(){
    return (18*a*b*c*d) - (4*pow(b,3)*d) + (pow(b,2)*pow(c,2)) - (4*a*pow(c,3)) - (27*pow(a,2)*pow(d,2));
  }

  string solve(){
    //Monic polynomial (higher coeficient equals to one)
    //x^3+(b/a)x^2+(c/a)x+(d/a)=0
    double a1=b/a,b1=c/a,c1=d/a;

    //Set p and q from depressed cubic form
    double p = b1 - (a1*a1)/3; // p= (3ac-b^2) / 3a^2
    double q = (2*a1*a1*a1)/27 - (a1*b1)/3 + c1; // q = 2b^3 -9abc + 27a^2 d / 27 a^3
    //Normalized discriminant for calculations
    double discriminant = (q*q) + (4*p*p*p)/27;
    //cout<< " El discriminante es "<<discriminant<<endl;
    //To store the roots values
    double r1,r2,r3;
    double u,v;

    //Case 1 discriminant =0
    if(this->discriminant() ==0){ //Discriminant equals 0.
      //Case 1.1 p equals 0. 
      if (p==0){ //The polynomial has only one real root.
	return "{"+ to_string(-(a1/3))+"}";
      }
      //Case 1.2
      //p != 0, so the polynomial has two real roots.
      u = -q/2;
      if (u> 0)
	u=cbrt(u);
      else if (u<0)
	u=-cbrt(-u);

      //Real roots
      r1 = 2*u -(a1/3);
      r2 = -u -(a1/3);
      
      return "{"+to_string(r1)+","+to_string(r2)+"}";
    }

    //Case 2. Discriminant >0 One real root, 2 complex roots.
    if (discriminant > 0) { //discriminante > 0
      u=(-q+sqrt(discriminant))/2;
      if (u> 0)
	u=cbrt(u);
      else if (u<0)
	u=-cbrt(-u);
      
      v = -(q + sqrt(discriminant))/2;
      if (v> 0)
	v=cbrt(v);
      else if (v<0)
	v=-cbrt(-v);

      //Real root
      r1 = u + v -(a1/3);
      //Imaginary roots.
      r2 = -(u+v)/2 -(a1/3);
      r3 = sqrt(3)/2*(u-v);
      return "{"+to_string(r1)+"}";

    }
 
    //Case 3: The polynomial has 3 real roots
    if ( discriminant < 0 ) { //3 real roots
      r1 = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt(-27/(p*p*p)))/3) -(a1/3);
      r2 = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +2*M_PI/3) -(a1/3);
      r3 = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +4*M_PI/3) -(a1/3);
      return "{"+to_string(r1)+","+to_string(r2)+","+to_string(r3)+"}";
    }
  }

};



