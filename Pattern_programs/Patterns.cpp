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


void pattern10(int n){

    for(int i=1;i<=2*n-1;i++){
       
        int star=i;
        if(i > n) star=2*n-i;

        for (int j=1;j<=star;j++)
        cout <<"* ";
        
        cout<<endl;
    }
}


void pattern11(int n){

    int start=1;
    for(int i=1;i<=n;i++){
        if (i%2 == 0) start=0;
        else start=1;
        
        for(int j=1;j<=i;j++){
            cout<< start <<" ";

            start=1-start;
        }
        cout<<endl;
    }
}

void pattern12(int n){

    // int space=2*(n-1);
    int space=2*n-2;
    for(int i=1;i <=n;i++){
        //numbers

        for (int j=1 ;j<=i;j++){
            cout << j;
        }
        // spaces
        for(int j=0;j<space;j++){
            cout << ' ';
        }
        //numbers
        for (int j=i ;j>0;j--){
            cout << j;
        }
        space-=2;
        cout<<endl;
    }
}


void pattern13(int n){
    int c=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
        {
            cout<<c<<' ';
            c+=1;
        }
        cout<<endl;
    }
}

void pattern14(int n){

    for(int i=1;i<=n;i++){
        for(char j='A';j<'A'+i;j++)
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }
}

void pattern15(int n){

    for(int i=1;i<=n;i++){
        for(char j='A';j<'A'+(n-i+1);j++)
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }
}



void pattern16(int n){
    for(int i=0;i<n;i++){
        char ch ='A'+i;
        for(int j=0;j<=i;j++)
        {
            cout<<ch<<' ';
        }
        cout<<endl;
    }
}

void pattern17(int n){
   for(int i =0 ; i<n ; i++){
        
        char ch='A';
        int breakpoint=(2*i+1) / 2;
        for(int space_1=0;space_1 < n-i-1;space_1++){
            cout << ' ';
        }
       
            for(int star=1;star <= 2*i+1;star++){
            cout<<ch;
            if(star <= breakpoint) ch++;
            else ch--;
        
        }
        
        // for(int space_2=0;space_2<n-i-1;space_2++){
        //     cout << " ";
        // }
        cout<<endl;
}
}



void pattern18_1(int n){
    for(int i=0;i<n;i++){
        char ch ='E'-i;
        for(int j=0;j<=i;j++)
        {
            cout<<ch<<' ';
            ch++;
        }
        cout<<endl;
    }
}



void pattern18_2(int n){
    for(int i=0;i<n;i++){
        char ch ='E'- i;
        for(char j=ch;j<='E';j++)
        {
            cout<<ch<<' ';
            ch++;
        }
        cout<<endl;
    }
}



void pattern19(int n){

    int i,j;
    int space=0;
    for(i=1;i<=n;i++){

        //star

        for(j=1;j<=n-i+1;j++){
            cout<<'*';
        }
        //space
        for(j=1;j<space+1;j++){
            cout<<' ';
        }

        //star
         for(j=1;j<=n-i+1;j++){
            cout<<'*';
        }

        cout<<endl;
        space+=2;
    }
    int space1=8;
    for(i=1;i<=n;i++){

        //star

        for(j=1;j<=i;j++){
            cout<<'*';
        }
        //space
        for(j=0;j<space1;j++){
            cout<<' ';
        }

        //star
         for(j=1;j<=i;j++){
            cout<<'*';
        }

        cout<<endl;
        space1-=2;
    }

}


void pattern20(int n){
    int space=2*n -2;
    int i,j;
    for(i=1;i<=2*n-1;i++){

        int star=i;
        
        if(i > n) star = 2*n - i ;
        for(j=0;j<star;j++){
            cout<<'*';
        }
        
        for(j=1;j<=space;j++){
            cout<<' ';
        }
        
        for(j=0;j<star;j++){
            cout<<'*';
        }
        if(i < n) space-=2;
        else space+=2;

        cout<<endl;

    }
}


void pattern21(int n){
    int i,j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){

            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;

    }
}

#include <math.h>

void pattern22(int n){
    int i,j;
    int num=1;
    int size=2*n-1;
    for(i=0;i<n*2-1;i++){
        
        for(j=0;j<n*2-1;j++){
            
            int top=i;
            int left=j;
            int right=size - 1 - i;
            int bottom=size - 1 - j;

            int d=min(min(top,left),min(bottom,right));


            cout << (n-d) << ' ';
    }

        cout<<endl;
}

}


int main(){


    int n=4;
    
    pattern22(n);
    return 0;
}