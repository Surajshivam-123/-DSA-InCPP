#include<iostream>
using namespace std;
class Complex{
    int x;
    int y;
    public:
    Complex(int a=0,int b=0) : x(a),y(b){}
    print(){
        cout<<x<<"+i"<<y<<endl;
    }
    Complex operator +(Complex);
    Complex operator ++();
    Complex operator ++(int);
    friend ostream& operator<<(ostream& out,const Complex&);
    friend istream& operator>>(istream& in,Complex&);
};
ostream& operator<<(ostream& out,const Complex& c){
    out<<c.x<<"+i"<<c.y;
    return out;
}
istream& operator>>(istream& in,Complex& c){
    cout<<"Enter real part:";
    in>>c.x;
    cout<<"Enter imaginary part:";
    in>>c.y;
    return in;
}
Complex Complex::operator +(Complex c1){
    Complex temp;
    temp.x=x+c1.x;
    temp.y=y+c1.y;
    return temp;
}
Complex Complex::operator ++(){//preincrement operator
    x=x+1;
    y=y+1;
    return *this;
}
Complex Complex::operator ++(int){//postincrement operator using dummy
    Complex temp=*this;
    x=x+1;
    y=y+1;
    return temp;
}
int main(){
    Complex C1(4,5);
    Complex C2;
    Complex C3(6,7);
    Complex C1c,C3c;
    C2=C1+C1;
    C2.print();//8+i10
    C1c=++C1;
    C1c.print();//5+i6
    C1.print();//5+i6
    C3c=C3++;
    C3c.print();//6+i7
    C3.print();//7+i8
    Complex C4,C5,C6(8,9);
    cin>>C4>>C5;
    cout<<C4+C6;
return 0;
}