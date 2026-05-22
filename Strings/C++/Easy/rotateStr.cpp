#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;


bool rotateString_brute(string str,string goal){

    if (str.length() != goal.length()) return false;
    
    
    for(int i=0;i<str.size();i++){
        
    //     string res="";
    //    res+= str.substr(i) + str.substr(0,i);
        
        str=str.substr(1) + str[0];

       if(str == goal) return true;
    }

    return false;
}

int main(){

    string str="abcde";
    string goal="cdeab";

    cout<<boolalpha<<rotateString_brute(str,goal);



    return 0;
}