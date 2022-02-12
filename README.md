# 3rdDegreeEquation
This is a small program written on C++ to solve 3rd degree equations

### Prerequisites
* c++

### Installation
just need to clone this repository to your local computer and you are all set.

### Executing the project
To execute the project you can use the Makefile provided.
To compile and run the program with default parameters use:
```
$ make
$ make run
```

To execute the program with your own parameters you must complile with ```make``` first and then execute:
```
$ ./findroots a b d c
```
with ```a,b,c``` and ```d```, real numbers.

### File Manifest

### Testing the project

### Version
Version 1.0
Not fully tested.

## Solution

The third degree equation is an equation of the form ```ax³+bx²+cx+d```, where ```a,b,c``` and ```d``` are real coeficients, with ```a!=0```.
A third degree equation always has at least one real root. A value for ```x``` where the value of ```f(x)``` is 0.

To solve this problem, we must recall that the determinant is a value given for every polynomial that can give us information about the possible roots for the polynomial.
This program uses the discriminant as a key to divide the possible findings of the roots in 4 different cases.
Along with the discriminant we also use the depressed cubic form of the equation, where we tansform the polynomial to the form ```t³+pt+q=0```. Where ```p``` and ```q``` gives us more information.
This allows us to divide the problem in 4 different cases:
* Case 1: discriminant =0
    * Case 1.1: p = 0
        In this case we have a polynomial with only one real root.
    * Case 1.2: p!=0
        In this case we have a polynomial with two real roots.
* Case 2: discriminant >0.
    In this case we have one real root, but 2 complex roots. Although we will focus only in the real roots.
*Case 3: discriminant <0.
    In this case we have 3 real roots. In this case the polynomial can be facthorized as ```(x-r1)(x+r2)(x-r3)``` where ```r1,r2```and ```r3``` are the real roots.