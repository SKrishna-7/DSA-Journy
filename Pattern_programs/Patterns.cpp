#include<iostream>

using namespace std;

void pattern1(int n){
    
    for(int i=1 ; i <=5 ; i++){

        for(int j =1; j<=n ; j++){

            cout << "* ";
        }
    cout << endl;   
    }

}

void pattern2(int n){

    for(int i= 1;i<=5;i++){

        for(int j=1 ;j<=i;j++){
            cout << "* ";
        }
        cout<<endl;

    }

}
void pattern3(int n){

    for(int i= 1;i<=5;i++){

        for(int j=1 ;j<=i;j++){
            cout << j;
        }
        cout<<endl;

    }

}

void pattern4(int n){

    for(int i= 1;i<=5;i++){

        for(int j=1 ;j<=i;j++){
            cout << i;
        }
        cout<<endl;

    }

}



void pattern5_1(int n){

    for(int i=n;i>=0;i--){

        for(int j=1 ;j<=i;j++){
            cout << "* ";
        }
        cout<<endl;

    }
}


void pattern5_2(int n){

    // for(int i=0 ; i<=n ; i++){
    //     for(int j=(n-i)-1;j>=0;j--){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0 ; i<=n ; i++){
        for(int j=1;j<=(n-i)+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}


void pattern6(int n){
    for(int i=1 ; i<=n ; i++){
        for(int j=1;j<=(n-i)+1;j++){
            cout<<j <<" ";
        }
        cout<<endl;
    }
}


void pattern7(int n){
    
    for(int i =0 ; i<n ; i++){
        
        for(int space_1=0;space_1 < n-i-1;space_1++){
            cout << ' ';
        }
       
            for(int star=0;star < 2*i+1;star++){
            cout<<"*";
        
        }
        
        // for(int space_2=0;space_2<n-i-1;space_2++){
        //     cout << " ";
        // }
        cout<<endl;
    }

}


void pattern8_1(int n){
    
    for(int i =n ; i>=0 ; i--){
        
        for(int space_1=0;space_1 < n-i;space_1++){
            cout << ' ';
        }
       
            for(int star=0;star < 2*i+1;star++){
            cout<<"*";
        
        }
        
        // for(int space_2=0;space_2<n-i-1;space_2++){
        //     cout << " ";
        // }
        cout<<endl;
    }

}


void pattern8_2(int n){
    
    for(int i =0 ; i < n; i++){
        
        for(int space_1=0;space_1 < i;space_1++){
            cout << ' ';
        }
       
            for(int star=0;star < 2*n - (2*i+1);star++){
            cout<<"*";
        
        }
        
      
        cout<<endl;
    }

}

void pattern9(int n){
    pattern7(n);
    pattern8_2(n);
}
int main(){


    int n=5;
    
    pattern9(n);
    return 0;
}