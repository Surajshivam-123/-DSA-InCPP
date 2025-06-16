#include<iostream>
using namespace std;
//1.)! (logical NOT)
//2.)Address-of operator: &
// https://learn.microsoft.com/en-us/cpp/cpp/address-of-operator-amp?view=msvc-170
//3.)One's complement operator: ~
    // C++ specifies compl as an alternative spelling for ~
    //Step-by-Step Explanation:

// 1. Binary Representation of 5 (in 8-bit for simplicity):

// 00000101  (binary for 5)


// 2. Bitwise Complement (~) Operation:

// The bitwise complement flips all the bits:


// 11111010  (this is the bitwise NOT of 5)


// 3. Interpreting the Result (Two's Complement Representation):

// The result 11111010 is in two’s complement form, which represents a negative number.

// To find its decimal value:

// Invert the bits: 00000101

// Add 1: 00000110 (which is 6 in decimal)

// Since the original number was negative, the final result is -6.
//4.)Indirection Operator:*//Pointer dereference
//5.)Unary plus(+) and Unary minus(-)
//6.)Prefix operator and postfix operator
//7.
int main(){
    cout<<~5<<endl;
    char a='y';
    cout<<+a<<endl;//converted into int(ascii)
    cout<<-a<<endl;//converted into negative of int(ascii)
    a++;
    cout<<a<<endl;
return 0;
}