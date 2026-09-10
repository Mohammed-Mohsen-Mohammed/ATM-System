# 🏧 ATM System Simulation (C++)

A lightweight, console-based ATM simulator built in **C++** that mimics core self-service banking operations. The system reads and syncs client accounts in real time using persistent file storage.

---

### ✨ Features
* 🔐 **Client Authentication:** Login using Account Number & Pin Code.
* ⚡ **Quick Withdraw:** Fast cash withdrawal options.
* 💵 **Custom Withdraw:** Flexible cash withdrawal (enforces multiples of 5).
* 💳 **Deposit & Balance Check:** Instant real-time balance updates.
* 🛡️ **Validation & Overdraw Protection:** Prevents exceeding current balance and handles invalid input errors.
* 💾 **File-Based Storage:** Auto-saves and syncs data to `Clients.txt` using a custom delimiter (`#//#`).

---

### 🛠️ Built With
* **Language:** C++
* **Concepts:** Procedural Programming, Structs & Enums, File I/O (`fstream`), Vectors (`std::vector`).

---

### 🚀 Quick Start

1. **Clone the repo**
   ```bash
   git clone https://github.com/Mohammed-Mohsen-Mohammed/ATM-System.git
   cd ATM-System
   ```

2. **Make sure `Clients.txt` is present**
   Add a sample record:
   ```text
   A101#//#1234#//#Mohamed Mohsen#//#01012345678#//#5000.00
   ```

3. **Compile & Run**
   ```bash
   g++ main.cpp -o atm
   ./atm
   ```

---

### 👤 Author
* **Mohamed Mohsen** - [GitHub](https://github.com/Mohammed-Mohsen-Mohammed) • [LinkedIn](https://www.linkedin.com/in/mohammed-mohsen-mohammed/)
