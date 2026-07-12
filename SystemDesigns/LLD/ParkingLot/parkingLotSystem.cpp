#include<iostream>
#include<vector>

using namespace std;


class Vehicle{
    
    private:

    string licence_number=0;

    public:

    Vehicle(string licence_number){

        this->licence_number = licence_number;
    }


    virtual string getVechicle_type() = 0;

    virtual ~Vehicle() {}

    
};

class Car : public Vehicle{

    public:
        Car(string licence_number) :
            Vehicle(licence_number) {}
        
    string getVechicle_type() override {
            return "Car";
    }

    
};

class Bike : public Vehicle{

    string getVechicle_type() override {
            return "Bike";
    }

};

int main(){

   Vehicle* v1 = new Car("TN23");

    cout<<v1->getVechicle_type();


    return 0;
}