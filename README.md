# ATM System Simulation (C++)

A robust, console-based Automated Teller Machine (ATM) simulation developed in modern C++. This application mimics real-world self-service banking kiosks, providing client authentication, transaction handling (Quick Withdraw, Custom Withdraw, Deposit), real-time balance inquiries, and persistent file-based storage compatible with standard core banking data schemas.

---

## Key Features

- **Client Authentication & Session Management**:
  - Secure credential verification utilizing unique `AccountNumber` and `PinCode` combinations.
  - Interactive login loop with state tracking and input validation.
  
- **Flexible Transaction Processing**:
  - **Quick Withdraw**: Predefined common withdrawal denominations ($20, $50, $100, $200, $400, $600, $800, $1000).
  - **Normal Withdraw**: Custom cash extraction with business rule validation (enforces multiples of 5).
  - **Deposit**: Instant balance augmentation with positive-value validation.
  - **Check Balance**: Instant real-time financial balance inquiries.

- **Overdraw & Validation Controls**:
  - Dynamic balance checking preventing overdrafts or negative cash requests.
  - Terminal stream sanitization (`cin.fail()`, `cin.clear()`, `cin.ignore()`) to prevent input hanging or invalid data type panics.

- **Data Persistence & File I/O Integration**:
  - Seamless data synchronization with `Clients.txt` using structured delimited records (`#//#`).
  - Read-on-demand and in-place vector record updating for client data.

---

## System Architecture & Data Flow

```
[ Clients.txt (Data Source) ]
             ▲
             │ (File Stream Serialization / Deserialization)
             ▼
   [ Vector<stClient> ] 
             ▲
             │ (State Sync)
             ▼
   [ Session / CurrentClient ] ──► [ ATM Menu Controller ]
                                       ├── Quick Withdraw
                                       ├── Normal Withdraw (Multiple of 5)
                                       ├── Cash Deposit
                                       └── Check Balance
```

---

## Tech Stack & Core Concepts

- **Language**: C++ (C++11 / C++14 / C++17)
- **Standard Library Components**:
  - `std::vector` for dynamic in-memory database representation.
  - `std::fstream` (`ifstream` / `ofstream`) for atomic file transactions.
  - `std::string` manipulation with custom delimiter parsing (`SplitString`).
  - `std::iomanip` & `std::numeric_limits` for robust console stream formatting and error resilience.
- **Architectural Paradigms**:
  - Structured Programming & Data Modeling via `struct` and strongly typed `enum`.
  - Separation of Concerns: File I/O operations, business transaction logic, and UI display routines.

---

## File Format (`Clients.txt`)

Data is stored line-by-line using `#//#` as a field separator:

```text
A101#//#1234#//#Mohamed Mohsen#//#01012345678#//#5420.50
A102#//#4321#//#Ahmed Ali#//#01198765432#//#1200.00
```

Field Mapping:
1. `AccountNumber` (string)
2. `PinCode` (string)
3. `Name` (string)
4. `Phone` (string)
5. `AccountBalance` (double)

---

## Getting Started

### Prerequisites
- Any modern C++ compiler supporting C++11 or higher (GCC / Clang / MSVC).
- Git.

### Building & Running

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Mohammed-Mohsen-Mohammed/ATM-System.git
   cd ATM-System
   ```

2. **Ensure `Clients.txt` exists**:
   Create a `Clients.txt` file in the project root directory with sample data:
   ```text
   A101#//#1234#//#Mohamed Mohsen#//#01012345678#//#5000.00
   ```

3. **Compile**:
   - Using **g++ / Clang**:
     ```bash
     g++ -std=c++11 main.cpp -o atm_system
     ```
   - Using **Visual Studio**:
     Open the folder or `.sln`, set build configuration to `Release` or `Debug`, and press `Ctrl + F5`.

4. **Run**:
   ```bash
   ./atm_system
   ```

---

## Author

- **Mohamed Mohsen** - *Computer Science Student & Aspiring Backend Developer*
  - GitHub: [@Mohammed-Mohsen-Mohammed](https://github.com/Mohammed-Mohsen-Mohammed)
  - LinkedIn: [mohammed-mohsen-mohammed](https://www.linkedin.com/in/mohammed-mohsen-mohammed/)
