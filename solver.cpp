#include "solver.hpp"
#include <iostream>
#include <exception>

using namespace std;
using namespace solver;

double solver:: solve (RealVariable x) {
    double Answer=0; 
    double temp = (x.b*x.b)-(4*x.a*x.c);
	if (temp < 0 ){ throw runtime_error("There is no real solution"); }
    if ( x.a == 0 ) Answer = (-1*x.c)/x.b;
	else{
		temp = sqrt(temp);
		Answer =(-1*x.b + temp)/(2*x.a);   
    }
    return Answer;
}

RealVariable solver::operator+ (const RealVariable& x , const RealVariable& y){	return RealVariable(x.a + y.a, x.b + y.b, x.c + y.c);}
RealVariable solver::operator+ (const RealVariable& x , const double num){	return RealVariable(x.a , x.b , x.c + num);}
RealVariable solver::operator+ ( const double num , const RealVariable& x){	return RealVariable(x.a , x.b , x.c + num);}
RealVariable solver::operator- (const RealVariable& x , const RealVariable& y){return RealVariable(x.a - y.a, x.b - y.b, x.c - y.c);}
RealVariable solver::operator- (const RealVariable& x , const double num){return RealVariable(x.a , x.b , x.c - num);}
RealVariable solver::operator- ( const double num , const RealVariable& x){return RealVariable(-x.a , -x.b , num-x.c);}
RealVariable solver::operator* (const double num , const RealVariable& x){return RealVariable(x.a*num , x.b*num , x.c*num);}
RealVariable solver::operator* (const RealVariable& x , const double num){return RealVariable(x.a*num , x.b*num , x.c*num);}

RealVariable solver::operator/ (const RealVariable& x , const RealVariable& y){
	RealVariable Ans(x.a, x.b, x.c);
	if (Ans.a!=0 && y.a!=0) { Ans.a = 0; Ans.c+=Ans.a/y.a; }
	else if (Ans.a!=0 && y.b!=0) { Ans.a = 0; Ans.b+=Ans.a/y.b; }
	else if(Ans.b!=0 && y.b!=0) { Ans.b = 0; Ans.c+=Ans.b/y.b; }
	return Ans;
}
RealVariable solver::operator/ (const RealVariable& x , const double c){
	if (c==0) throw runtime_error("Can't divide by zero");
	RealVariable Ans(x.a, x.b, x.c);
	if (x.a!=0) Ans.a = Ans.a/c;
	else if (x.b!=0) Ans.b = Ans.b/c;
	else if (x.c!=0) Ans.c = Ans.c/c;
	return Ans;
}
RealVariable solver::operator/ ( const double c , const RealVariable& x){
	RealVariable Ans(x.a, x.b, x.c);
	if (x.a!=0) Ans.a = c/Ans.a;
	else if (x.b!=0) Ans.b = c/Ans.b;
    else if (x.c!=0) Ans.c = c/Ans.c;
	return Ans;
}

RealVariable solver::operator^ (const RealVariable& x , int n){
	if (n==0) return RealVariable(0, 0, 1);
	else if (n==1) return x;
	else if (n==2) return RealVariable(x.a+(x.b*x.b), 0, x.c);
	else throw runtime_error("max power is 2");
}

RealVariable solver::operator== (const RealVariable& x , const RealVariable& y){
	RealVariable Ans(x.a, x.b, x.c);
	
	if (y.a!=0) Ans.a = x.a+(-1*y.a);
	if (y.b!=0) Ans.b = x.b+(-1*y.b);
	if (y.c!=0) Ans.c = x.c+(-1*y.c);
	
	return Ans;
}
RealVariable solver::operator== (const RealVariable& x , const double c){
	RealVariable Ans(x.a, x.b, x.c);
	Ans.c+= (-1*c);
	return Ans;
}
RealVariable solver::operator== ( const double c , const RealVariable& x){
	RealVariable Ans(x.a, x.b, x.c);
	Ans.c+= (-1*c);
	return Ans;
}

/*
=======================================Complex===============================
*/

complex<double> solver:: solve (ComplexVariable x){
	complex<double> dis = (x.b * x.b) - (complex<double> (4, 0) *x.a*x.c);
	complex<double> ans = 0;
	if (x.a == complex<double> (0,0)){ ans = (-x.c)/x.b; }
	else {
		dis = sqrt(dis);
		ans = ((complex<double>(-1)*x.b)+dis)/(complex<double>(2, 0)*x.a);
	}
	return ans;
}

ComplexVariable solver::operator+ (const ComplexVariable &x , const ComplexVariable &y){return ComplexVariable(x.a+y.a, x.b+y.b, x.c+y.c);}
ComplexVariable solver::operator+ (const ComplexVariable &x , std::complex<double> num){return ComplexVariable(x.a, x.b, x.c+num);}
ComplexVariable solver::operator+ ( std::complex<double> num ,const ComplexVariable &x){return ComplexVariable(x.a, x.b, x.c+num);}
ComplexVariable solver::operator+ (const ComplexVariable &x , double num){return ComplexVariable(x.a, x.b, x.c+num);}
ComplexVariable solver::operator+ ( double num ,const ComplexVariable &x){return ComplexVariable(x.a, x.b, x.c+num);}
ComplexVariable solver::operator- (const ComplexVariable &x , const ComplexVariable &y){return ComplexVariable(x.a-y.a, x.b-y.b, x.c-y.c);}
ComplexVariable solver::operator- (const ComplexVariable &x , std::complex<double> num){return ComplexVariable(x.a, x.b, x.c-num);}
ComplexVariable solver::operator- ( std::complex<double> num ,const ComplexVariable &x){return ComplexVariable(-x.a, -x.b, num-x.c);}
ComplexVariable solver::operator- (const ComplexVariable &x , double num){return ComplexVariable(x.a, x.b, x.c-num);}
ComplexVariable solver::operator- ( double num ,const ComplexVariable &x){return ComplexVariable(-x.a, -x.b, num-x.c);}
ComplexVariable solver::operator* (const ComplexVariable &x , std::complex<double> num){return ComplexVariable(x.a*num, x.b*num, x.c*num);}
ComplexVariable solver::operator* ( std::complex<double> num ,const ComplexVariable &x){return ComplexVariable(x.a*num, x.b*num, x.c*num);}
ComplexVariable solver::operator* (const ComplexVariable &x , double num){return ComplexVariable(x.a*num, x.b*num, x.c*num);}
ComplexVariable solver::operator* ( double num ,const ComplexVariable &x){return ComplexVariable(x.a*num, x.b*num, x.c*num);}

ComplexVariable solver::operator/ (const ComplexVariable &x , const ComplexVariable &y){
	ComplexVariable Ans(x.a, x.b, x.c);
	if (Ans.a != std::complex<double> (0) && y.a != std::complex<double> (0) ){
         Ans.a =0;
         Ans.c+= Ans.a/y.a;
     }
     if (Ans.a != std::complex<double> (0) && y.b != std::complex<double> (0) ){
         Ans.a =0;
         Ans.b+= Ans.a/y.b;   
     }
     if (Ans.b != std::complex<double> (0) && y.b != std::complex<double> (0)){
         Ans.c+= Ans.b/y.b;
         Ans.b =0;
     }
     return Ans;
}
ComplexVariable solver::operator/ (const ComplexVariable &x , std::complex<double> num){return ComplexVariable(x.a/num, x.b/num, x.c/num);}
ComplexVariable solver::operator/ ( std::complex<double> num ,const ComplexVariable &x){return ComplexVariable(num/x.a, num/x.b, num/x.c);}
ComplexVariable solver::operator/ (const ComplexVariable &x , double num){return ComplexVariable(x.a/num, x.b/num, x.c/num);}
ComplexVariable solver::operator/ ( double num ,const ComplexVariable &x){return ComplexVariable(num/x.a, num/x.b, num/x.c);}

ComplexVariable solver::operator^ (const ComplexVariable &x , int n){
	if (n==0) return ComplexVariable();
	else if (n==1) return x;
	else if (n==2) return ComplexVariable(x.a+(x.b*x.b), 0, x.c);
	else throw runtime_error("max power is 2");
}

ComplexVariable solver::operator== (const ComplexVariable &x ,const  ComplexVariable &y){
	ComplexVariable Ans(x.a, x.b, x.c);
	if (y.a !=std::complex<double> (0)){ Ans.a = x.a + (std::complex<double> (-1)*y.a); }
	else if (y.b !=std::complex<double> (0)){ Ans.b = x.b + (std::complex<double> (-1)*y.b); }
	else if (y.c !=std::complex<double> (0)){ Ans.c = x.c + (std::complex<double> (-1)*y.c); }
	return Ans;
}
ComplexVariable solver::operator== (const ComplexVariable &x , std::complex<double> c){
	ComplexVariable Ans(x.a, x.b, x.c);
	Ans.c = x.c + (std::complex<double> (-1)*c);
	return Ans;
}
ComplexVariable solver::operator== ( std::complex<double> c ,const ComplexVariable &x){
	ComplexVariable Ans(x.a, x.b, x.c);
	Ans.c = x.c + (std::complex<double> (-1)*c);
	return Ans;
}
ComplexVariable solver::operator== (const ComplexVariable &x , double c){
	ComplexVariable Ans(x.a, x.b, x.c);
	Ans.c = x.c + (std::complex<double> (-1)*c);
	return Ans;
}
ComplexVariable solver::operator== ( double c ,const ComplexVariable &x){
	ComplexVariable Ans(x.a, x.b, x.c);
	Ans.c = x.c + (std::complex<double> (-1)*c);
	return Ans;
}
