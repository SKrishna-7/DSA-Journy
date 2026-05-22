#include<iostream>
#include<memory>

using namespace std;

class Infantry{

    public:
    virtual void attack() = 0;

    virtual ~Infantry() = default;
};

class Vehicle{
    
    public:

    virtual void drive() = 0;

    virtual ~Vehicle() = default;

};

class Human_Marine : public Infantry{

    public:
    void attack() override {
        cout<< "Human attacking..";
    }

};


class Human_Tank : public Vehicle{

    
    public:

    void drive() override {
        cout<< "Human driving Tank...";
    }

};

class Alien_Mutant : public Infantry {

    public:

    void attack() override {
        cout<< "Alien attacking..";
    }


};


class BioCruiser : public Vehicle{

    public:

    void drive() override {
        cout<< "Alien driving BioCruiser...";
    }

};


class ArmyFactory{

    public :


    virtual unique_ptr<Infantry> createInfantry() = 0;
    virtual unique_ptr<Vehicle> createVehicle() = 0;

    virtual ~ArmyFactory() noexcept = default;

};

class HumanFactory : public ArmyFactory{

    public:
    
    ~HumanFactory() override = default;

    unique_ptr<Infantry> createInfantry() override{

        return make_unique<Human_Marine>();
    }

    unique_ptr<Vehicle> createVehicle() override {
        return make_unique<Human_Tank>();
    }
};

class AlienFactory : public ArmyFactory {
public:
    ~AlienFactory() override = default;

    unique_ptr<Infantry> createInfantry() override {
        return make_unique<Alien_Mutant>();
    }

    unique_ptr<Vehicle> createVehicle() override {
        return make_unique<BioCruiser>();
    }
};


void SpawnArmy(ArmyFactory& factory){

    unique_ptr<Infantry> infantry = factory.createInfantry();
    unique_ptr<Vehicle> vehicle = factory.createVehicle();

    infantry->attack();
    cout<<endl;
    vehicle->drive();
}

int main(){


    unique_ptr<ArmyFactory> human = make_unique<HumanFactory>();
    unique_ptr<ArmyFactory> alien = make_unique<AlienFactory>();

    SpawnArmy(*human);
    cout<<endl;
    SpawnArmy(*alien);

    return 0;
}