#include "Transaction.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

Transaction transactionList[MAX_TRANSACTIONS];
int transactionCount = 0;

Transaction::Transaction() {
    transactionID = "";
    transType = "";
    amount = 0;
    timestamp = "";
    note = "";
    fromAccountID = "";
    toAccountID = "";
}

Transaction::Transaction(const string& transID, const string& type, double amount,
                         const string& timeStamp, const string& note,
                         const string& fromID, const string& toID)
    : transactionID(transID), transType(type), amount(amount), timestamp(timeStamp),
      note(note), fromAccountID(fromID), toAccountID(toID) {}

string Transaction::getTransactionID() const { return transactionID; }
string Transaction::getType() const { return transType; }
double Transaction::getAmount() const { return amount; }
string Transaction::getTimestamp() const { return timestamp; }
string Transaction::getNote() const { return note; }
string Transaction::getFromAccountID() const { return fromAccountID; }
string Transaction::getToAccountID() const { return toAccountID; }

// Các hàm tạo giao dịch cụ thể
Transaction Transaction::deposit(const string& transID, const string& fromAccountID,
                                 double amount, const string& timeStamp, const string& note) {
    return Transaction(transID, "deposit", amount, timeStamp, note, fromAccountID, "");
}

Transaction Transaction::withdraw(const string& transID, const string& fromAccountID,
                                  double amount, const string& timeStamp, const string& note) {
    return Transaction(transID, "withdraw", amount, timeStamp, note, fromAccountID, "");
}

Transaction Transaction::transfer(const string& transID, const string& fromAccountID,
                                  const string& toAccountID, double amount,
                                  const string& timeStamp, const string& note) {
    return Transaction(transID, "transfer", amount, timeStamp, note, fromAccountID, toAccountID);
}

// Trả về thời gian hiện tại
string Transaction::getCurrentTime() const {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtm);
    return string(buffer);
}

// Thêm giao dịch vào mảng
bool addTransaction(const Transaction& t) {
    if (transactionCount >= MAX_TRANSACTIONS) {
        return false; // Quá giới hạn
    }
    if (isTransactionIDExists(t.getTransactionID())) {
        return false; // Trùng ID
    }
    transactionList[transactionCount++] = t;
    return true;
}

// Hiển thị giao dịch của tài khoản
void displayTransactionsByAccount(const string& accountID) {
    cout << "Transaction History for Account: " << accountID << endl;
    for (int i = 0; i < transactionCount; i++) {
        Transaction& t = transactionList[i];
        if (t.getFromAccountID() == accountID) {
            cout << "ID: " << t.getTransactionID()
                 << ", Type: " << t.getType()
                 << ", Amount: " << t.getAmount()
                 << ", Timestamp: " << t.getTimestamp()
                 << ", Note: " << t.getNote()
                 << ", To: " << t.getToAccountID() << endl;
        }
    }
}

// Kiểm tra ID đã tồn tại chưa
bool isTransactionIDExists(const string& transID) {
    for (int i = 0; i < transactionCount; i++) {
        if (transactionList[i].getTransactionID() == transID) {
            return true;
        }
    }
    return false;
}
