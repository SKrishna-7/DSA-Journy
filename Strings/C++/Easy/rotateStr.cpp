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

bool rotateString_optimal(string &str,string &target){

    if(str == target) return true;
    
    string con_str = str + str;

    return con_str.find(target) != string::npos;

}


bool rotateString_optimal_2(string &str,string &target){

    if(str == target) return true;
    
    string con_str = str + str;

    int n=con_str.size();
    int m=target.size();
    
    for(int i=0;i<n-m;i++){
        int j=0;
        
        while(j < m && con_str[i + j] == target[j]){
            j++;
        }
        
        if(j == m) return true;
        }
    
return false;
}

int main(){

    string str="abcde";
    string goal="cdeab";

    // cout<<boolalpha<<rotateString_brute(str,goal);
    cout<<boolalpha<<rotateString_optimal(str,goal);




    return 0;
}