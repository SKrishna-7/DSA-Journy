#include<iostream>
#include<vector>

using namespace std;

//Variation 1: Find the Element at (Row R, Col C)
int factorial(int n){
    if(n==1 || n==0)
    return 1;

    return n*factorial(n-1);
}
int pascal_c_value_brute(int r,int c){

    // using nCr formula

    long long n_fact= factorial(r);
    long long r_fact=factorial(c);

    long long n_r_fact=factorial(r-c);

    long long res=0;
    res=n_fact/(r_fact*n_r_fact);


    return res;
}

// Optimize

int pascal_c_value_optimal(int r,int c){

    // using nCr formula

   long long res=1;

   for(int i=0;i<c;i++){
        res*=r-i;
        res=res/(i+1);

   }

    return res;
}

// Variation 2: Print the Entire Nth Row (Most Common)

vector<int> pascal_row_brute(int r){  // O(n x r)

    vector<int>res;
    
    for(int i=1;i<=r;i++){
        res.push_back(pascal_c_value_optimal(r-1,i-1));
    }

    return res;
}

vector<int> pascal_row_optimal(int r){  // O(n x r)

    vector<int>res_vector;
    long long res=1;
    res_vector.push_back(res);

    for(int i=1;i<r;i++){
            res=res*(r-i);
            res=res/i;

            res_vector.push_back(res);

    }

    return res_vector;
}


vector<vector<int>> pascal_triangle(){
    
}

int main(){

   int n= 5, r = 5, c = 2 ;

//    Variation 1: Find the Element at (Row R, Col C)
    
    //cout<<pascal_c_value_brute(r-1,c-1);
    // cout<<pascal_c_value_optimal(r-1,c-1);

    // Variation 2: Print the Entire Nth Row (Most Common)

    for(auto &i:pascal_row_optimal(r)){
        cout<< i << " ";
    }

    return 0;
}