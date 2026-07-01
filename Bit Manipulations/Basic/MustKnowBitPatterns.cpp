#include<iostream>

using namespace std;

// Swap 2 numbers

void swapNumbers(int &a, int &b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}

// Check if ith bit is set or not
bool isSet(int num,int i){

    // leftShift
    // return (num & (1 << i)) != 1;
    
    return ((num >> i) & 1) == 1;
}

// Set ith bit to set
int set_ithBitToSet(int num,int i){

    return num | (1 << i);
}

//Clear ith bit

int clear_ithBit(int num,int i){

    return num & (~(1<<i));
}

// Toggle ith Bit

int toggle_ithBit(int num,int i){

    return num ^ (1<<i);
}

// Remove the last set Bit
int removeLastSetBit(int num,int i){

    return num & (num -1);
}

// Check if a number is power of 2 or not

bool isPowerOfTwo(int n){

    return (n > 0) && ((n & (n - 1)) == 0);
}

// count the number of set bits

int countSetBits(int num){

    int cnt=0;

    while(num > 0){

        cnt+= num & 1;
        num = num >> 1;
    }
    return cnt;
}


int main(){

    int num=13;
    int i=2;

    int a=10,b=20;

    // swapNumbers(a,b);

    // cout<<boolalpha << clear_ithBit(num,i) << endl;

    cout<< countSetBits(num);
    return 0;
}