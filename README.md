# banking_system
# STC Bank – Command Line Banking System (C++)

A simple command line banking system written in C++. Users log in with their name and password, then use a menu to deposit, withdraw, send cash and check their balance.

The program uses **functions, decision making (if/else and switch), loops and arrays**.

## Features

- **Login** with name and password
- **Deposit** money (the user first chooses an account type: GCC, IT or STC; the amount must be more than 0)
- **Withdraw** money (cannot withdraw more than the balance)
- **Send Cash** to another account using the recipient's account number (checks that the account exists, that it is not your own account, and that you have enough funds)
- **Check Balance** (shows account holder, account number and balance)
- **Menu loop** that keeps running until the user chooses Exit
- **Validation** with clear messages for invalid amounts, insufficient funds, unknown account numbers and invalid menu options

## Menu

```
---------------------------------------------
                  STC BANK
---------------------------------------------
                     MENU
Choose among the options provided:
1. Deposit
2. Withdraw
3. Send Cash
4. Check Balance
5. Exit
```

## How It Works

1. The details of 3 users (name, password, account number and balance) are stored in arrays. The same index in each array belongs to the same user.
2. `login()` checks the entered name and password against the arrays. If they match, the user's index is saved in `currentUser`.
3. After a successful login, `menu()` runs inside a `do...while` loop until the user chooses **5. Exit**.
4. A `switch` statement in `menu()` calls the function for the chosen option: `deposit()`, `withdraw()`, `send_cash()`, `check_balance()` or `exitProgram()`.
5. `send_cash()` searches the account numbers with a `for` loop, then moves the money from the sender's balance to the receiver's balance.

## Test Accounts

| Name    | Password | Account Number | Starting Balance |
|---------|----------|----------------|------------------|
| Tanya   | ABC      | 1234           | R2000            |
| Shamein | EFG      | 2468           | R1500            |
| Amo     | HIJ      | 1357           | R3000            |

Names and passwords are case-sensitive.

## How to Compile and Run

You need a C++ compiler such as `g++`.

```bash
g++ main.cpp -o banking
./banking
```
## Author
Shamein Tanyaradzwa Chifamba
