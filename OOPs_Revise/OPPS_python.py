from __future__ import annotations
from typing import List, Optional
from datetime import datetime
import uuid


class Customer:

    
    def __init__(self,name:str,mail:str,phone:str,address:str,accounts:List["Account"] = []):
        self.__customer_id=str(uuid.uuid4())[:4]
        self.__name=name
        self.__email=mail
        self.__phone=phone
        self.__address=address
        self.__accounts=accounts
        self.__created_at=datetime.now()

    #--------------- Getter Methods ----------------
    def get_customer_id(self) -> str:
        return self.__customer_id

    def get_name(self) -> str:
        return self.__name

    def get_email(self) -> str:
        return self.__email

    def get_phone(self) -> str:
        return self.__phone

    def get_accounts(self) -> List["Account"]:
        return self.__accounts

    #------------------------------------------------

    def open_account(self,acc_type:str,amount:float):
        account=Account(acc_type,amount,self,[])
        self.__accounts.append(account)
        print(f"[INFO] Account {account.get_account_number()} opened for {self.__name}.")
        
    
    def close_account(self,account_number:str):
        for acc in self.__accounts:
            if acc.get_account_number() == account_number:
                self.__accounts.remove(acc)
                print(f"[INFO] Account {account_number} closed for {self.__name}.")
                return
            
        print(f"[WARN] Account {account_number} not found for {self.__name}.")

    
    def get_account(self,account_number:str):
        for acc in self.__accounts:
            if acc.get_account_number() == account_number:
                return acc
        
        return None
        
    
    def view_profile(self):
        """Display customer information."""
        print("========== CUSTOMER PROFILE ==========")
        print(f"Customer ID : {self.__customer_id}")
        print(f"Name        : {self.__name}")
        print(f"Email       : {self.__email}")
        print(f"Phone       : {self.__phone}")
        print(f"Address     : {self.__address}")
        print(f"Accounts    : {[a.get_account_number() for a in self.__accounts]}")
        print(f"Created At  : {self.__created_at.strftime('%Y-%m-%d %H:%M:%S')}")
        print("======================================")



class Transaction:
    def __init__(self, txn_type: str, amount: float, status: str, source_acc: str, target_acc: Optional[str] = None):
        self.txn_id = str(uuid.uuid4())[:8]
        self.txn_type = txn_type  
        self.amount = amount
        self.timestamp = datetime.now()
        self.status = status
        self.source_acc = source_acc
        self.target_acc = target_acc

    def summary(self):
        return {
            "Transaction ID": self.txn_id,
            "Type": self.txn_type,
            "Amount": self.amount,
            "Status": self.status,
            "Source": self.source_acc,
            "Target": self.target_acc,
            "Time": self.timestamp.strftime("%Y-%m-%d %H:%M:%S")
        }


class Account:

    def __init__(self,account_type:str,balance:float,customer:Customer,transactions:List[Transaction] = []):

        self.__account_number=str(uuid.uuid4())[:5]
        self.__account_type=account_type
        self.__balance=balance
        self.__customer=customer
        self.__transactions=transactions

    def get_account_number(self):
        return self.__account_number
    
    def get_transactions(self):
        return self.__transactions
    
    def get_balance(self):
        return self.__balance

    def deposit(self,amount:float,acc:"Account"):

        if amount < 0:
            print("[ERROR] Invalid Deposit Ammount .")
            return
        txn = Transaction("Deposit", amount, "Success", self.get_account_number())
        self.__transactions.append(txn)
        self.__balance += amount
        print(f"[SUCCESS] Deposited ₹{amount}. New balance: ₹{self.__balance}")

    
    def withdraw(self,amount:float,acc:"Account"):
        if amount <= 0:
            print("[ERROR] Invalid Withdrawal Ammount.")
            return
        if amount > self.__balance:
            print("[ERROR] Insufficient balance.")
            return
        self.__balance -= amount
        print(f"[SUCCESS] Withdrawn ₹{amount}. New balance: ₹{self.__balance}")
        txn = Transaction("Withdrawn", amount, "Success", self.get_account_number())
        self.__transactions.append(txn)


    def transfer(self,target_account:"Account",amount:float):
        if amount <= 0:
            print("[ERROR] Transfer amount must be positive.")
            return
        if amount > self.__balance:
            print("[ERROR] Insufficient balance for transfer.")
            return
        
        self.__balance -= amount
        target_account.__balance += amount

        txn = Transaction("Transfer", amount, "Success", self.__account_number,target_account.get_account_number())
        self.__transactions.append(txn)
        print(
            f"[SUCCESS] Transferred ₹{amount} from {self.__account_number} "
            f"to {target_account.get_account_number()}"
        )

    def check_balance(self,account:"Account"):

        print(f"[INFO] Your Current Balance is {account.get_balance()}")

    def show_transactions(self,account:"Account"):
        print("\n--- Transaction History ---")
        if not account.get_transactions():
            print("No transactions found.")
            return
        for t in account.get_transactions():
            print(t.summary())

   
class Bank:
    def __init__(self):
        
        
        self.customers:List[Customer] = []


    def register_customer(self):
        print("\n=== Register New Customer ===")
        name = input("Enter name: ")
        email = input("Enter email: ")
        phone = input("Enter phone: ")
        address = input("Enter address: ")
        customer = Customer(name, email, phone, address)
        self.customers.append(customer)
        print(f"[SUCCESS] Customer {name} registered! ID: {customer.get_customer_id()}")

    def find_customer(self, customer_id: str) -> Optional[Customer]:
        for c in self.customers:
            if c.get_customer_id() == customer_id:
                return c
        return None
    
    def list_customers(self):
        if not self.customers:
            print("[INFO] No customers registered yet.")
            return
        print("\n=== All Customers ===")
        for c in self.customers:
            print(f"ID: {c.get_customer_id()} | Name: {c.get_name()}")
        print("=======================")

if __name__ == "__main__":

    bank = Bank()
        
    while True:
        print("\n===== MAIN MENU =====")
        print("1. Register New Customer")
        print("2. List Customers")
        print("3. Login as Customer")
        print("4. Exit")
        choice = input("Enter choice (1-4): ")


        if choice == "1":
            bank.register_customer()

        elif choice == "2":
            bank.list_customers()


        elif choice == "3":

            customer_id=input("Enter your Customer ID : ")

            customer=bank.find_customer(customer_id)

            if not customer:
                print("[WARN] Customer not found.")
                continue

            while True:
                print(f"\n=== Welcome {customer.get_name()} ===")
                print("1. Open Account")
                print("2. Close Account")
                print("3. Deposit")
                print("4. Withdraw")
                print("5. Check Balance")
                print("6. Transfer")
                print("7. View Profile")
                print("8. View Profile")
                print("9. Logout")
                
                user_choice = input("Enter your Option : ")

                if user_choice == "1":
                    acc_type = input("Enter account type (Savings/Current): ")
                    amount = float(input("Enter initial deposit: "))
                    # account=Account(acc_type,amount,customer,[])
                    # customer.open_account(account)

                    customer.open_account(acc_type,amount)

                elif user_choice == "2":
                    acc_no = input("Enter account number: ")
                    customer.close_account(acc_no)

                elif user_choice == "3":
                    acc_no = input("Enter account number: ")
                    acc = customer.get_account(acc_no)
                    if acc:
                        amount = float(input("Enter amount: "))
                        acc.deposit(amount,acc)
                        
                    else:
                        print("[WARN] Account not found.")

                elif user_choice == "4":
                    acc_no = input("Enter account number: ")
                    acc = customer.get_account(acc_no)
                    if acc:
                        amount = float(input("Enter amount: "))
                        acc.withdraw(amount,acc)
                    else:
                        print("[WARN] Account not found.")

                elif user_choice == "5":
                    acc_no = input("Enter account number: ")
                    acc = customer.get_account(acc_no)          

                    if acc:
                        acc.check_balance(acc)
                    else:
                        print("[WARN] Account not found.")

                    
                elif user_choice == "6":
                    src = input("Enter source account number: ")
                    target = input("Enter target account number: ")
                    src_acc = customer.get_account(src)
                    target_acc = customer.get_account(target)
                    if src_acc and target_acc:
                        amount = float(input("Enter amount: "))
                        src_acc.transfer(target_acc, amount)
                    else:
                        print("[WARN] One or both accounts not found.")

                elif user_choice == "7":
                    print(customer.get_customer_id())
                    customer.view_profile()

                elif user_choice == '8':
                    acc_no = input("Enter account number: ")
                    acc = customer.get_account(acc_no)          

                    if acc:
                        acc.show_transactions(acc)
                    else:
                        print("[WARN] Account not found.")
                elif user_choice == "9":
                    print(f"Logging out {customer.get_name()}...")
                    break

                else:
                    print("[ERROR] Invalid choice!")

        elif choice == "4":
            print("Thank you for using the bank system. Goodbye!")
            break

        else:
            print("[ERROR] Invalid choice. Try again.")
            