#include<iostream>

using namespace std;

class IDosa{

    public:
    virtual string getDescription() = 0;
    virtual int getCost() = 0;

    virtual ~IDosa() noexcept = default;
};


class PlainDosa : public IDosa{

public:


    string getDescription() override {
        return "Plain Dosa..";
    }

    int getCost() override {
        return 10;
    }
};

#include<memory>

class DosaDecorator : public IDosa{

    protected:
        unique_ptr<IDosa> itemInside;

    public:
    
    DosaDecorator(unique_ptr<IDosa> item){
        itemInside = move(item);
    }
    
    string getDescription() override {

        return itemInside->getDescription();
    }

    int getCost() override {
        return itemInside->getCost();
    }
};



class Masala : public DosaDecorator{

    public:

        Masala(unique_ptr<IDosa> item) : DosaDecorator(move(item)){}
        

        int getCost() override{
            return 20 + itemInside->getCost();
        }

        string getDescription() override {

            return itemInside->getDescription() + " With Masala..";
    }

};

class Cheese : public DosaDecorator{

    public:
    
    Cheese(unique_ptr<IDosa> item) :  DosaDecorator(move(item)) {}
    

    int getCost() override{
        return 30 + itemInside->getCost();
    }

    string getDescription() override {

        return itemInside->getDescription() + " With Cheese..";
    }
};
int main(){

    unique_ptr<IDosa> dosa = make_unique<PlainDosa>();
    
    cout<<dosa->getCost() << endl;
    cout<<dosa->getDescription() << endl;
    
    dosa = make_unique<Masala>(make_unique<Cheese>(move(dosa)));
 
    // dosa = make_unique<Cheese>(move(dosa));

    cout<<dosa->getCost() << endl;
    cout<<dosa->getDescription() << endl;
    

    return 0;
}