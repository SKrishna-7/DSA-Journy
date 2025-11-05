#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Customer;
class Transaction;
class Account;

class Account
{

private:
    string account_number;
    string account_type;
    float balance;
    Customer *customer; // this account belongs to that specific customer in memory
    vector<Transaction> transactions;

public:
    Account(string acc_type, float balance, Customer *customer) : account_type(acc_type), balance(balance), customer(customer)
    {

        account_number = "z" + to_string(rand() % 10000 + 1000);
    }
    string get_account_number()
    {
        return account_number;
    }

    float get_balance()
    {
        return balance;
    }

    void check_balance()
    {
        cout << "\n\n[INFO] Your Current Balance is " << balance;
    }

    void deposit(float amount)
    {
        if (amount < 0)
        {
            cout << "\n\n[ERROR] Invalid Deposit Amount.";
        }
        balance += amount;
        cout << "\n\n[SUCCESS] Amount Deposited to " << account_number;
    }

    void withdraw(float amount)
    {

        if (amount <= 0)
        {
            cout << "[ERROR] Invalid Withdrawal Ammount.";
            return;
        }
        if (amount > balance)
        {
            cout << "[ERROR] Insufficient balance.";
            return;
        }

        balance -= amount;

        cout << "[SUCCESS] Withdrawn ₹ " << amount << " New balance: ₹ " << balance;
    }

    void transfer(float amount, Account &target_acc)
    {

        if (amount < 0)
        {
            cout << "[ERROR] Invalid Amount.";
        }
        if (amount > this->balance)
        {
            cout << "[ERROR] Insufficient Balance.";
        }

        balance -= amount;
        target_acc.balance += amount;

        cout << "[SUCCESS] Transferred ₹" << amount << " from " << account_number << " to " << target_acc.account_number << " Balance : " << target_acc.balance;
    }
};

class Customer
{

private:
    static int next_id;
    string customer_id;
    string name;
    string email;
    string phone;
    string address;
    vector<Account *> accounts;
    string created_at;

public:
    Customer(string name, string email, string phone, string address)
    {

        this->name = name;
        this->email = email;
        this->phone = phone;
        this->address = address;

        customer_id = to_string(++next_id);

        cout << "\n[INFO] New Customer Registered: " << name << " (ID: " << customer_id << ")\n";
    };

    void open_account(string acc_type, float amount)
    {

        accounts.push_back(new Account(acc_type, amount, this));
        cout << "[INFO] " << name << " opened a new " << acc_type << " account." << endl;
    }

    void close_account(string acc_no)
    {

        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {

            if ((*it)->get_account_number() == acc_no)
            {
                delete *it;
                accounts.erase(it);
                cout << "[INFO] Account " << acc_no << " closed successfully.\n";
                return;
            }
        }
        cout << "[WARN] Account not found.\n";
    }

    Account *get_account(string acc_no)
    {

        for (auto acc : accounts)
        {
            if (acc->get_account_number() == acc_no)
            {
                return acc;
            }
        }
        return nullptr;
    }

    string get_name()
    {
        return name;
    }

    string get_customer_id()
    {
        return customer_id;
    }

    void view_profile()
    {
        cout << "\n\n==== CUSTOMER PROFILE ====\n";
        cout << "ID        : " << customer_id << endl;
        cout << "Name      : " << name << endl;
        cout << "Email     : " << email << endl;
        cout << "Phone     : " << phone << endl;
        cout << "Address   : " << address << endl;
        cout << "Created At: " << created_at << endl;
        cout << "\n==============================================\n";

        if (!accounts.empty())
        {
            for (auto acc : accounts)
            {
                cout << "Account Number :  " << acc->get_account_number() << endl;
            }
        }
        else
        {
            // cout << "\n==============================================\n";
        }
    }
};

int Customer::next_id = 1000;

class Transaction
{

private:
    string txn_id;
    string txn_type;
    float amount;
    string status;
    string src_account;
    string target_account;

public:
    void summary();
};

class Bank
{

private:
    vector<Customer> customers;
    int customer_id;
    string name;
    string mail;
    string phone;
    string address;
    //    string name;

public:
    Bank()
    {
        cout << "Welcome to Sunna Paana Bankuu.......";
    }

    void register_customer()
    {

        cout << "\n\n========================Register New Customer============================\n";

        cout << "\nName : ";
        getline(cin >> ws, name);
        cout << "\nEmail : ";
        getline(cin >> ws, mail);
        cout << "\nPhone : ";
        getline(cin >> ws, phone);
        cout << "\nAddress : ";
        getline(cin >> ws, address);

        Customer customer = {name, mail, phone, address};

        customers.push_back(customer);

        cout << "\n[SUCCESS] New Customer Registered: " << name << " (ID: " << customer.get_customer_id() << ")\n";

        customer.view_profile();
        return;
    }

    Customer *find_customer(string customer_id)
    {
        // Because looping by value copies each element,
        // while looping by reference allows modifying or accessing the original object in the container.

        for (auto &customer : customers)
        {
            if (customer.get_customer_id() == customer_id)
            {
                return &customer;
            }
        }

        return nullptr;
    }

    void list_customers()
    {

        if (customers.empty())
        {
            cout << "\n[INFO] No customers registered yet.";
            return;
        }

        cout << "\n\n====== All Customers ======";

        for (auto &customer : customers)
        {
            cout << " \n ID " << customer.get_customer_id() << " | Name : " << customer.get_name();
        }
        cout << "\n==================================================";
    }
};

void customer_menu(Customer *customer)
{
    int user_choice;

    while (true)
    {
        cout << "\n======== Welcome " << customer->get_name() << " =======" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Close Account" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Transfer" << endl;
        cout << "7. View Profile" << endl;
        cout << "8. View Transactions" << endl;
        cout << "9. Logout" << endl;

        cout << "Enter your Option: ";
        cin >> user_choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (user_choice)
        {
        case 1:
        {
            cout << "[INFO] Opening new account..." << endl;

            string acc_type;
            float amount;
            cout << "\n\nEnter Account type Savings/Current : " << endl;
            getline(cin >> ws, acc_type);

            cout << "\n\nEnter Deposit Amount : ";
            cin >> amount;

            customer->open_account(acc_type, amount);

            cout << "[SUCCESS] New Account Opened..." << endl;

            break;
        }

        case 2:
        {

            cout << "[INFO] Closing account..." << endl;

            string acc_num;
            cout << "\n\nEnter your Account number : " << endl;
            getline(cin >> ws, acc_num);

            customer->close_account(acc_num);

            break;
        }

        case 3:
        {
            cout << "[INFO] Deposit selected." << endl;
            string acc_num;
            cout << "\n\nEnter your Account number : " << endl;
            getline(cin >> ws, acc_num);

            Account *acc = customer->get_account(acc_num);

            if (acc)
            {
                float amount;
                cout << "\n\nEnter Deposit Amount : " << endl;
                cin >> amount;

                acc->deposit(amount);
            }

            break;
        }
        case 4:
        {
            cout << "[INFO] Withdraw selected." << endl;

            string acc_num;
            cout << "\n\nEnter your Account number : " << endl;
            getline(cin >> ws, acc_num);

            Account *acc = customer->get_account(acc_num);

            if (acc)
            {
                float amount;
                cout << "\n\nEnter Withdraw Amount : " << endl;
                cin >> amount;

                acc->withdraw(amount);
            }
            break;
        }
        case 5:
        {
            cout << "[INFO] Checking balance..." << endl;
            string acc_num;
            cout << "\n\nEnter your Account number : " << endl;
            getline(cin >> ws, acc_num);

            Account *account = customer->get_account(acc_num);

            if (!account)
            {
                cout << "\n\n[WARN] Account not found.";
            }
            else
            {
                account->check_balance();
            }
        }

        break;
        case 6:
        {
            cout << "[INFO] Transfer funds..." << endl;
            string scr_acc_num;
            string target_acc_num;

            cout << "\n\nEnter  Source Account number : " << endl;
            getline(cin >> ws, scr_acc_num);

            cout << "\n\nEnter Target Account number : " << endl;
            getline(cin >> ws, target_acc_num);

            Account *scr_acc = customer->get_account(scr_acc_num);
            Account *target_acc = customer->get_account(target_acc_num);

            if (scr_acc && target_acc)
            {

                float amount;
                cout << "Enter the Amount to Transfer : ";
                cin >> amount;

                scr_acc->transfer(amount, *target_acc);
            }
            else
            {
                cout << "[ERROR] Account not found.";
            }

            break;
        }
        case 7:
            cout << "[INFO] Viewing profile..." << endl;
            customer->view_profile();
            break;
        case 8:
            cout << "[INFO] Viewing transactions..." << endl;
            break;
        case 9:
            cout << "[INFO] Logging out " << customer->get_name() << "..." << endl;
            return;
        default:
            cout << "[ERROR] Invalid choice! Please try again." << endl;
        }
    }
}

int main()
{

    Bank bank;
    // bank.register_customer();

    // bank.register_customer();

    // bank.list_customers();

    // Customer *c1 = bank.find_customer("1001");

    // c1->view_profile();

    string customer_id;

    while (true)
    {

        cout << "\n\n============== MAIN MENU ================" << endl;
        cout << "1.Register New Customer " << endl;
        cout << "2.List Customers" << endl;
        cout << "3.Login as Customer " << endl;
        cout << "4.Exit" << endl;

        int choice;
        cout << "\n Enter Option : ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            bank.register_customer();
            break;

        case 2:
            bank.list_customers();
            break;

        case 3:
        {
            cout << "\n\nEnter You Customer ID : ";
            getline(cin >> ws, customer_id);

            Customer *customer = bank.find_customer(customer_id);

            if (customer == nullptr)
            {
                cout << "[WARN] Customer not found.";
            }

            else
            {
                customer_menu(customer);
            }
            break;
        }

        case 4:
            cout << "\n[INFO] Exiting the system. Thank you!\n";
            return 0;

        default:
            break;
        }
    }

    return 0;
}
