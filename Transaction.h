#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

const int MAX_TRANSACTIONS = 100; // Giới hạn tối đa giao dịch

class Transaction {
private:
    string transactionID;
    string transType;
    double amount;
    string timestamp;
    string note;
    string fromAccountID;
    string toAccountID;

public:
    Transaction(); // Constructor mặc định
    Transaction(const string& transID, const string& type, double amount,
                const string& timeStamp, const string& note,
                const string& fromID, const string& toID);

    // Getter
    string getTransactionID() const;
    string getType() const;
    double getAmount() const;
    string getTimestamp() const;
    string getNote() const;
    string getFromAccountID() const;
    string getToAccountID() const;

    // Các hàm tạo giao dịch
    static Transaction deposit(const string& transID, const string& fromAccountID,
                               double amount, const string& timeStamp, const string& note);

    static Transaction withdraw(const string& transID, const string& fromAccountID,
                                double amount, const string& timeStamp, const string& note);

    static Transaction transfer(const string& transID, const string& fromAccountID,
                                const string& toAccountID, double amount,
                                const string& timeStamp, const string& note);

    string getCurrentTime() const;
};

extern Transaction transactionList[MAX_TRANSACTIONS];
extern int transactionCount;


bool addTransaction(const Transaction& t);
void displayTransactionsByAccount(const string& accountID);
bool isTransactionIDExists(const string& transID);

#endif
