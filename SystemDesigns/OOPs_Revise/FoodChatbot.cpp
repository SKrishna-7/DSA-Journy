#include<iostream>
#include<vector>
using namespace std;

/* ================= USER ================= */

class User {
private:
    int user_id;
    string name;
    string address;
    string password;
    bool isLoggedIn = false;

public:
    User(int id, string name, string address, string password) {
        this->user_id = id;
        this->name = name;
        this->address = address;
        this->password = password;
    }

    int getUserId() const { return user_id; }
    string getPassword() const { return password; }

    void setLogin(bool status) { isLoggedIn = status; }
    bool getLoginStatus() const { return isLoggedIn; }
};


/* ================= AUTH ================= */

class Authentication {
public:
    bool login(User &user, int id, const string &pass) {
        if (user.getUserId() == id && user.getPassword() == pass) {
            user.setLogin(true);
            cout << "Login Successful\n";
            return true;
        }
        cout << "Login Failed\n";
        return false;
    }

    void logout(User &user) {
        user.setLogin(false);
        cout << "Logged out\n";
    }
};


/* ================= MENU ================= */

class MenuItem {
public:
    string name;
    double price;

    MenuItem(string name, double price) {
        this->name = name;
        this->price = price;
    }
};


/* ================= RESTAURANT ================= */

class Restaurant {
private:
    int id;
    string name;
    string address;
    vector<MenuItem> menu;

public:
    Restaurant(int id, string name, string address) {
        this->id = id;
        this->name = name;
        this->address = address;

        menu.push_back(MenuItem("Dosa", 25));
        menu.push_back(MenuItem("Idli", 10));
        menu.push_back(MenuItem("Omelette", 20));
    }

    void showMenu() const {
        cout << "\n--- MENU ---\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i << ". " << menu[i].name 
                 << " - ₹" << menu[i].price << endl;
        }
    }

    vector<MenuItem> getMenu() const {
        return menu;
    }
};


/* ================= CART ITEM ================= */

class CartItem {
public:
    MenuItem item;
    int quantity;

    CartItem(const MenuItem &item, int quantity) : item(item), quantity(quantity) {}
};


/* ================= PAYMENT (POLYMORPHISM) ================= */

class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() {}
};

class UPI : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using UPI\n";
    }
};

class Card : public Payment {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using Card\n";
    }
};


/* ================= DELIVERY ================= */

class DeliveryAgent {
public:
    void deliver() {
        cout << "Order Delivered 🚚\n";
    }
};


/* ================= ORDER ================= */

class Order {
private:
    const User &user;
    const Restaurant &restaurant;
    vector<CartItem> items;

public:
    Order(const User &user, const Restaurant &restaurant)
        : user(user), restaurant(restaurant) {}

    void addItem(const MenuItem &item, int qty) {
        items.push_back(CartItem(item, qty));
    }

    double getTotal() const {
        double total = 0;
        for (auto &i : items) {
            total += i.item.price * i.quantity;
        }
        return total;
    }

    void showOrder() const {
        if (items.empty()) {
            cout << "No items in order\n";
            return;
        }

        cout << "\n--- ORDER ---\n";
        for (auto &i : items) {
            cout << i.item.name << " x " << i.quantity << endl;
        }
        cout << "Total: ₹" << getTotal() << endl;
    }

    void checkout(Payment *payment, DeliveryAgent &agent) {
        double total = getTotal();
        payment->pay(total);
        agent.deliver();
    }
};


/* ================= MAIN ================= */

int main() {

    User user(101, "Suresh", "Ambur", "1234");
    Authentication auth;
    Restaurant restaurant(1, "Kaja Hotel", "MC Road");

    // Login
    if (!auth.login(user, 101, "1234")) return 0;

    // Show menu
    restaurant.showMenu();

    // Create order
    Order order(user, restaurant);
    auto menu = restaurant.getMenu();

    // Add items
    order.addItem(menu[0], 2); // 2 Dosa
    order.addItem(menu[1], 3); // 3 Idli

    order.showOrder();

    // Payment
    UPI upi;
    DeliveryAgent agent;

    order.checkout(&upi, agent);

    return 0;
}