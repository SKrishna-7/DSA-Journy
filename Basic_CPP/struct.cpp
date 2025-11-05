#include <iostream>

using namespace std;


struct Address{
    string street;
    string city;
    double pin;
};

struct Student{
    int id;
    string name;
    float mark;

    Address address;
};


int main(){

    
   Student s1= {25,"Suresh Krishnan",100,"Ambur","Vellore",635802};
   Student s2= {24,"Shahid",0};

    cout << s1.id << " " + s1.name << " " << s1.mark;
    cout << endl;
    cout << s2.id << " " + s2.name << " " << s2.mark;

    

    return 0;
}

