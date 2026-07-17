#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

class Account
{
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int acc)
    {
        accountNumber = acc;
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully\n";
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance\n";
            return false;
        }

        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));
        cout << "Amount Withdrawn Successfully\n";
        return true;
    }

    bool transfer(Account &receiver, double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance\n";
            return false;
        }

        balance -= amount;
        receiver.balance += amount;

        history.push_back(Transaction("Transfer Sent", amount));
        receiver.history.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successful\n";
        return true;
    }

    void showHistory()
    {
        if (history.empty())
        {
            cout << "No Transactions\n";
            return;
        }

        cout << "\nTransaction History\n";

        for (int i = 0; i < history.size(); i++)
        {
            cout << history[i].type << " : " << history[i].amount << endl;
        }
    }

    void showBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }
};

class Customer
{
public:
    string name;
    Account account;

    Customer(string n, int acc) : account(acc)
    {
        name = n;
    }

    void display()
    {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Account Number: " << account.accountNumber << endl;
        account.showBalance();
    }
};

int main()
{
    Customer c1("Charan",1001);
    Customer c2("Rahul",1002);

    int choice;
    double amount;

    do
    {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. View Balance\n";
        cout << "5. Transaction History\n";
        cout << "6. Customer Details\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Amount: ";
                cin >> amount;
                c1.account.deposit(amount);
                break;

            case 2:
                cout << "Enter Amount: ";
                cin >> amount;
                c1.account.withdraw(amount);
                break;

            case 3:
                cout << "Enter Amount: ";
                cin >> amount;
                c1.account.transfer(c2.account, amount);
                break;

            case 4:
                c1.account.showBalance();
                break;

            case 5:
                c1.account.showHistory();
                break;

            case 6:
                c1.display();
                break;

            case 7:
                cout << "Thank You\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 7);

    return 0;
}
