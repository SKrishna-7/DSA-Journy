#include<iostream>
#include<climits>
using namespace std;

int solve(string &s ,int sign, int i,int res){

    if(i >= s.size() || s[i] < '0' || s[i] > '9'){

        return res * sign;
    }

    int digit = s[i] - '0';

    if(res >INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10 )){

        return (sign == -1) ? INT_MIN : INT_MAX;
    }
    res = res * 10 + digit; 

    return solve(s,sign,i+1,res);
}

int recursiveAtoi(string &s){

    int i=0;
    int n=s.size();

    while(i < n && s[i] == ' ') i++;

    int sign = 1;

    if(i < n && (s[i] == '-' || s[i] == '+')){

        if(s[i] == '-') sign = -1;
        else sign  =1;

        i++;
        
    }

    return solve(s,sign,i,0);
    

}

int main(){

    string s="  -42e343";

    cout<< recursiveAtoi(s);
    return 0;
}