#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    vector<string> transactionHistory;

    void recordTransaction(const string& type, double amount);

public:
    BankAccount(const string& accNumber, const string& accHolderName);

    void deposit(double amount);
    void withdraw(double amount);
    void transfer(BankAccount& recipient, double amount);
    void displayBalance() const;
    void displayTransactionHistory() const;
    const string& getAccountNumber() const;
    const string& getAccountHolderName() const;

};

class Bank {
private:
    vector<BankAccount> accounts;

    string generateAccountNumber() const;

public:
    BankAccount& createAccount(const string& accHolderName);
    BankAccount* findAccount(const string& accNumber);

};

#endif // BANKACCOUNT_H