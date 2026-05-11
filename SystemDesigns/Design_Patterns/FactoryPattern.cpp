#include<iostream>
#include<memory>

using namespace std;

class Payment{

    public:

    virtual void pay() = 0;
    
    virtual ~Payment() = default;
    
};


class Upi : public Payment{

    public:
    int amount ;

    Upi () {};
    Upi(int amount){
        this->amount = amount;
    }

    void pay() override{
        cout<<"Paid "<< amount << " through UPI....";
    }
};


class CashOnDelivery : public Payment{

    public:
    int amount ;

    CashOnDelivery(){};

    CashOnDelivery(int amount){
        this->amount = amount;
    }

    void pay() override{
        cout<<"Paid through CashOnDelivery....";
    }
};

// 3. The Creator (Base Factory)
class PaymentGateway{

    public:
        virtual unique_ptr<Payment> makePayment(int amount) = 0;

    void initializePayment(int amount){

        unique_ptr<Payment> make_payment = makePayment(amount);

        make_payment->pay();


    }
    
};

class UpiFactory : public PaymentGateway{

    unique_ptr<Payment> makePayment(int amount) override {
        
        return make_unique<Upi>(amount);
    }
};

class CashOnDeliveryFactory : public PaymentGateway{
  
    unique_ptr<Payment> makePayment(int amount) override { 
        return make_unique<CashOnDelivery>(amount);
    }
};

int main(){

    // Upi u(100);
    // u.pay();

    // CashOnDelivery c(300);
    // c.pay();

    unique_ptr<PaymentGateway> upi_method =make_unique<UpiFactory>();

    upi_method->initializePayment(500);
    
    return 0;
}