#include <iostream>
#include <string>

using namespace std;

// Global variables
int option;
int option1;
int currentUser = -1;

double depositeAmount;
double withdrawal_amount;
double amount_to_send;

// Account information
string name[3] = {"Tanya", "Shamein", "Amo"};
string password[3] = {"ABC", "EFG", "HIJ"};

int accountNumber[3] = {1234, 2468, 1357};

double balance[3] = {2000, 1500, 3000};


// LOGIN FUNCTION
bool login()
{
    string enteredName;
    string enteredPassword;

    cout << "---------------------------------" << endl;
    cout << "          WELCOME TO STC BANK     " << endl;
    cout << "---------------------------------" << endl;

    cout << "Please enter your login information below..." << endl;

    cout << "Full name: " << endl;
    cin >> enteredName;

    cout << "Password: " << endl;
    cin >> enteredPassword;

    for (int i = 0; i < 3; i++)
    {
        if (enteredName == name[i] &&
            enteredPassword == password[i])
        {
            currentUser = i;

            cout << "You have successfully logged in!" << endl;
            cout << "Welcome, " << name[currentUser] << endl;

            return true;
        }
    }

    cout << "Invalid Name or Password. Try again." << endl;

    return false;
}


// DEPOSIT FUNCTION
void deposit()
{
    cout << "-----------" << endl;
    cout << "1. Deposit" << endl;
    cout << "-----------" << endl;

    cout << "Which account type would you like to deposit to?" << endl;
    cout << "1. GCC Account" << endl;
    cout << "2. IT Account" << endl;
    cout << "3. STC Account" << endl;

    cin >> option1;

    switch (option1)
    {
        case 1:
            cout << "GCC Account selected." << endl;
            break;

        case 2:
            cout << "IT Account selected." << endl;
            break;

        case 3:
            cout << "STC Account selected." << endl;
            break;

        default:
            cout << "Invalid account type." << endl;
            return;
    }

    cout << "How much would you like to deposit?" << endl;
    cin >> depositeAmount;

    if (depositeAmount <= 0)
    {
        cout << "Please enter a valid amount." << endl;
        return;
    }

    balance[currentUser] += depositeAmount;

    cout << "You have successfully deposited R"
         << depositeAmount << endl;

    cout << "Your new balance is R"
         << balance[currentUser] << endl;
}


// WITHDRAW FUNCTION
void withdraw()
{
    cout << "------------" << endl;
    cout << "2. Withdraw" << endl;
    cout << "------------" << endl;

    cout << "How much would you like to withdraw?" << endl;
    cin >> withdrawal_amount;

    if (withdrawal_amount <= 0)
    {
        cout << "Please enter a valid amount." << endl;
    }
    else if (withdrawal_amount > balance[currentUser])
    {
        cout << "Sorry, you have insufficient funds." << endl;
        cout << "Please try again." << endl;
    }
    else
    {
        balance[currentUser] -= withdrawal_amount;

        cout << "You have successfully withdrawn R"
             << withdrawal_amount << endl;

        cout << "Available balance: R"
             << balance[currentUser] << endl;
    }
}


// SEND CASH FUNCTION
void send_cash()
{
    int receiverAccount;
    int receiverIndex = -1;

    cout << "--------------" << endl;
    cout << "3. Send Money" << endl;
    cout << "--------------" << endl;

    cout << "Enter the recipient's account number:" << endl;
    cin >> receiverAccount;

    // Find recipient account
    for (int i = 0; i < 3; i++)
    {
        if (accountNumber[i] == receiverAccount)
        {
            receiverIndex = i;
            break;
        }
    }

    if (receiverIndex == -1)
    {
        cout << "Account number not found." << endl;
        return;
    }

    if (receiverIndex == currentUser)
    {
        cout << "You cannot send money to your own account." << endl;
        return;
    }

    cout << "How much would you like to send?" << endl;
    cin >> amount_to_send;

    if (amount_to_send <= 0)
    {
        cout << "Please enter a valid amount." << endl;
    }
    else if (amount_to_send > balance[currentUser])
    {
        cout << "Transfer unsuccessful." << endl;
        cout << "You have insufficient funds." << endl;
    }
    else
    {
        balance[currentUser] -= amount_to_send;
        balance[receiverIndex] += amount_to_send;

        cout << "You have successfully sent R"
             << amount_to_send << endl;

        cout << "Money sent to: " << name[receiverIndex] << endl;

        cout << "Your current balance is R"
             << balance[currentUser] << endl;
    }
}


// CHECK BALANCE FUNCTION
void check_balance()
{
    cout << "------------------" << endl;
    cout << "4. Check Balance" << endl;
    cout << "------------------" << endl;

    cout << "Hello, " << name[currentUser] << endl;

    cout << "Account Details:" << endl;

    cout << "Account type: STC Account" << endl;

    cout << "Account holder: "
         << name[currentUser] << endl;

    cout << "Account number: "
         << accountNumber[currentUser] << endl;

    cout << "Your current balance is R"
         << balance[currentUser] << endl;
}


// EXIT FUNCTION
void exitProgram()
{
    cout << "---------------------------------" << endl;
    cout << "     Thank you for choosing us!   " << endl;
    cout << "---------------------------------" << endl;
}


// MENU FUNCTION
void menu()
{
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "                  STC BANK                   " << endl;
    cout << "---------------------------------------------" << endl;

    cout << "                     MENU                    " << endl;

    cout << "Choose among the options provided:" << endl;

    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Send Cash" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your option: ";
    cin >> option;

    switch (option)
    {
        case 1:
            deposit();
            break;

        case 2:
            withdraw();
            break;

        case 3:
            send_cash();
            break;

        case 4:
            check_balance();
            break;

        case 5:
            exitProgram();
            break;

        default:
            cout << "Invalid input, please try again." << endl;
            break;
    }
}


// MAIN FUNCTION
int main()
{
    if (login())
    {
        do
        {
            menu();

        } while (option != 5);
    }

    return 0;
}
