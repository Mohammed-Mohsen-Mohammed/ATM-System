# 🏧 ATM System

A console-based **ATM System built with C++** that simulates common banking operations such as authentication, withdrawals, deposits, and balance checking.

The system uses **file handling** to store client information and persist account balance updates.

---

## 📌 Overview

The **ATM System** is a C++ console application developed to practice fundamental programming concepts through a practical banking scenario.

After logging in with a valid **Account Number** and **PIN Code**, users can access different banking operations through the ATM main menu.

All client information is stored in a text file, allowing account balances to remain updated between program runs.

---

## ✨ Features

* 🔐 **User Authentication**

  * Login using Account Number and PIN Code.
  * Validates credentials against stored client data.

* 💸 **Quick Withdraw**

  * Provides predefined withdrawal amounts.
  * Prevents withdrawals that exceed the available balance.

* 💰 **Normal Withdraw**

  * Allows users to enter a custom withdrawal amount.
  * Requires the amount to be a multiple of 5.

* 💵 **Deposit**

  * Allows users to deposit a positive amount.
  * Requires confirmation before completing the transaction.

* 📊 **Check Balance**

  * Displays the current account balance.

* 🚪 **Logout**

  * Returns the user to the login screen.

* 💾 **File-Based Data Storage**

  * Stores client information in `Clients.txt`.
  * Updates account balances after successful transactions.

---

## 🛠️ Technologies & Concepts

### Technologies

* **C++**
* **STL**
* **File Handling**

### Concepts Practiced

* Structs
* Enums
* Functions
* `vector`
* `fstream`
* String manipulation
* String parsing
* References
* `const` references
* Input validation
* Searching collections
* Type conversion
* File-based data persistence

---

## 📂 Project Structure

```text
ATM-System/
│
├── ATM-System.cpp
├── Clients.txt
├── .gitignore
└── README.md
```

### Files

**`ATM-System.cpp`**
Contains the complete implementation of the ATM application.

**`Clients.txt`**
Stores client information using the following format:

```text
AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance
```

Example:

```text
1001#//#1234#//#Mohammed Mohsen#//#01000000000#//#5000
```

---

## 🔄 Application Flow

```text
                    ┌─────────────┐
                    │    Start    │
                    └──────┬──────┘
                           │
                           ▼
                    ┌─────────────┐
                    │    Login    │
                    └──────┬──────┘
                           │
                    ┌──────▼──────┐
                    │ Credentials │
                    │    Valid?   │
                    └───┬─────┬───┘
                        │     │
                      No│     │Yes
                        │     │
                        ▼     ▼
                    Try Again  Main Menu
                              │
                ┌─────────────┼─────────────┐
                │             │             │
                ▼             ▼             ▼
             Withdraw      Deposit      Check Balance
                │             │             │
                └─────────────┼─────────────┘
                              │
                              ▼
                         Update File
                              │
                              ▼
                           Logout
                              │
                              ▼
                            Login
```

---

## 💾 Data Storage

Client data is stored locally inside `Clients.txt`.

Each client record follows this format:

```text
AccountNumber#//#PinCode#//#Name#//#Phone#//#AccountBalance
```

The application:

1. Loads client records from the file.
2. Searches for the authenticated client.
3. Performs the requested transaction.
4. Updates the account balance.
5. Saves the updated records back to the file.

---

## ▶️ How to Run

### Prerequisites

You need a C++ development environment such as:

* Visual Studio
* Visual Studio Code with a C++ compiler
* GCC / MinGW

### Steps

1. Clone the repository.

```bash
git clone https://github.com/Mohammed-Mohsen-Mohammed/ATM-System.git
```

2. Open the project in your preferred C++ environment.

3. Make sure `Clients.txt` is located in the application's working directory.

4. Build and run the program.

5. Use one of the sample accounts stored in `Clients.txt` to log in.

---

## 🧪 Sample Login

You can test the application using:

```text
Account Number: 1001
PIN Code:       1234
```

After successful login, the main menu provides:

```text
[1] Quick Withdraw
[2] Normal Withdraw
[3] Deposit
[4] Check Balance
[5] Logout
```

---

## 🎯 What I Practiced

This project helped me apply C++ fundamentals in a practical application, especially:

* Working with files as persistent storage.
* Processing structured data.
* Building reusable functions.
* Validating user input.
* Searching and updating records.
* Managing application state.
* Designing a menu-driven console application.

---

## 👨‍💻 Author

**Mohamed Mohsen**

* GitHub: [Mohammed Mohsen](https://github.com/Mohammed-Mohsen-Mohammed)
* LinkedIn: [Mohammed Mohsen](https://www.linkedin.com/in/mohammed-mohsen-mohammed/)

---

⭐ If you find this project useful, feel free to explore the repository.
