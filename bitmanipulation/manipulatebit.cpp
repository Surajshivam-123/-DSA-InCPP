#include<iostream>
using namespace std;
// to find out the kth bit of n
// using lso
int findbit(int n,int k){
    return n&(1<<k)?1:0;
}
// using rso
int findBit(int n,int k){
    return (n>>k)&1?1:0;
}


//   3210
//n=(0101)2=(5)10
//suppose we need to get bit at position 2 which is 1 in this case
int getbit(int n,int pos){
    return((n&(1<<pos)!=0));
}

//suppose we wnt to set bit(make that pos 1) at pos 1;
//0101->0111
int setbit(int n,int pos){
    return (n|(1<<pos));
}

//clearbit(make that pos 0)
//0101->0001
int clearbit(int n,int pos){
    return(n&(~(1<<pos)));
}


// tooggle kth bit
int togglebit(int n,int k){
    return n^(1<<k);
}

// clear the last set bit
int clearLastSetbit(int n){
    return n & (n-1);
}

// to check if number is power of 2
bool powerof2(int n){
    return (n&(n-1))==0;
}

// count number of set bit
int countsetBit1(int n){//__builtin_popcount(n)
    int c=0;
    while(n!=0){
        // if(n&1){
        //     c++;
        // }OR
        c+=n&1;
        n>>=1;
    }
    return c;
}
int countsetBit2(int n){
    int c=0;
    while(n!=0){
        c++;
        n=n & n-1;
    }
    return c;
}

// Minimum Bit Flips to Convert Number
int minBitFlips(int start, int goal) {
        int diff=start^goal;//all different bit will convert into 1
        int c=0;
        while(diff!=0){//count number of set bit
            c++;
            diff=diff&(diff-1);
        }
        return c;
    }


// to find right most bit
int rightmost(int n){
    int temp=n;
    // clear the right most set bit
    n=n & n-1;
    return temp ^ n;
}

// find the xor of n natural numbers
int xorSum(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}


// concept find xor till l and then r and then take xor of both to eleminate similar element
// let find xor of(3,6)
// (1^2)^(1^2^3^4^5^6)=3^4^5^6
int xorInRange(int l,int r){
    return xorSum(l-1)^xorSum(r);
}

// NOTE-XOR Property: When you XOR numbers that all share a common factor in their binary representation, you can factor it out:
// (2×a) ^ (2×b) ^ (2×c) = 2 × (a ^ b ^ c)

// find xor of AP whose common differnce is 2
int xorOperation(int n, int start) {
    //left most number of interval
        int left=start;
    // right most number of interval
        int right=start+2*(n-1);
    // start is odd 
        if(start&1){
            // calculate xor of 1 to n and then eleminate all the left and atlast eleminate all even number in given interval
            int even=0;
            if((left-1)>=0){
                even^=2*xorSum((left-1)/2);
            }
            if((right-1)>=0){
                even^=2*xorSum((right-1)/2);
            }
            return xorSum(right)^xorSum(left-1)^even;
        }
        else{
            // calculate xor of all even number from 2 to n and then remove all the even elemet present in left
            int even=0;
            if((left-2)>=0){
                even^=2*xorSum((left-2)/2);
            }
            even^=2*xorSum(right/2);
            return even;
        }
    }
int main(){
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(5,2)<<endl;
    cout<<findBit(3,0)<<endl;
    cout<<togglebit(3,0)<<endl;
    cout<<clearLastSetbit(5)<<endl;  
    cout<<powerof2(7)<<endl;
    cout<<countsetBit2(5)<<endl;
}