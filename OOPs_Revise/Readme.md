# Simple Bank Management System using OOPs 

A **console-based bank management system** built using **Object-Oriented Programming (OOP)** principles in **C++ & Python**.  
This project helped me deeply understand how real-world systems can be modeled using **classes, objects, and relationships**.

---

## 🧠 What I Learned by Building This

By building this project from scratch, I strengthened my understanding of:

- 🧩 **OOP Fundamentals** — Classes, Objects, Constructors, Encapsulation, and Abstraction.  
- ⚙️ **Relationships Between Classes** — One-to-Many (Customer ↔ Account) using Composition.  
- 🧱 **Encapsulation & Access Modifiers** — Proper use of `private`, `public`, getters, and setters.  
- 💡 **Pointers vs References** — Understanding real data sharing and object ownership.  
- 🧮 **Memory Management** — Using `new`, `delete`, and vectors of pointers safely.  
- ⚡ **Function Design** — Passing objects by reference, using the `this` pointer efficiently.  
- 🧰 **STL Vectors** — Managing dynamic lists of customers and accounts.  
- 🧩 **Modular Design** — Separating logic into `Bank`, `Customer`, `Account`, and `Transaction` classes.

---

---

## 🧩 Class Design Overview (UML Concept)

| Class | Description |
|--------|-------------|
| **Bank** | Manages all customers; registration, login, and listing |
| **Customer** | Stores customer details and associated accounts |
| **Account** | Represents a single bank account; handles transactions |
| **Transaction** | (Optional) Tracks transfers and deposits |

### UML Relationship:
- Bank ─── contains ───> multiple Customers
- Customer ─── owns ───> multiple Accounts
- Account ─── records ───> multiple Transactions


✅ **Composition-based design:**  
A `Customer` exists inside a `Bank`, and an `Account` belongs to a `Customer`.

---

## ⚙️ Features Implemented

✅ Register new customer  
✅ Create multiple accounts per customer  
✅ Deposit and withdraw money  
✅ Transfer funds between accounts  
✅ Close accounts safely  
✅ View customer profile and account details  
✅ Extendable transaction history system  

---

---

## 🔍 Concepts Reinforced

| Concept | Description |
|----------|--------------|
| `this` Pointer | Used to reference the current object |
| References (`&`) | For modifying real objects |
| Pointers (`*`) | To dynamically link classes (Customer ↔ Account) |
| Encapsulation | Protecting data using private attributes |
| Composition | Customer *has many* accounts |
| STL Vector | Dynamic storage for accounts and customers |

---
Author

Suresh Krishna S
🎯 AI & DS Student | AI Enthusiast

