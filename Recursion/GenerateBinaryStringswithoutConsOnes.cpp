#include<iostream>
#include<vector>

using namespace std;

vector<string> generateBinaryStrings(int n){

    vector<string> binaryStrings={""};

    for(int i=0;i<n;i++){

        vector<string> newString;

        for(auto &s:binaryStrings){
            newString.push_back(s + '1');

            if(s.empty() || s.back() != '0'){
                newString.push_back(s + '0');
            }
        }

        binaryStrings = move(newString);
    }

    return binaryStrings;
}


void solver(int n,vector<string> &binaryStrings,string &current){

    if(current.length() == n){
        binaryStrings.push_back(current);
        return ;
    }

    current.push_back('0');
    solver(n,binaryStrings,current);
    current.pop_back();

    if(current.empty() || current.back() != '1'){

        current.push_back('1');
        solver(n,binaryStrings,current);
        current.pop_back();
    }


}
vector<string> generateBinaryStrings_rec(int n){

    
    
    vector<string> binaryStrings;

    if(n == 0) return binaryStrings;

    string current ="";

    solver(n,binaryStrings,current);
    

    return binaryStrings;
}


int main(){

    int n=3;

    for(auto &s : generateBinaryStrings_rec(n)){
        cout<< s << endl;
    }
    return 0;
}