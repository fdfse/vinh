#include <iostream>
#include "Transaction.h"

using namespace std;

int main() {
    cout << "=== Test Transaction Management ===" << endl;

    // Tạo giao dịch deposit
    Transaction t1 = Transaction::deposit("T001", "ACC1001", 500.0, "2025-06-06 10:00:00", "Deposit salary");
    bool added = addTransaction(t1);
    cout << "Add deposit transaction T001: " << (added ? "Success" : "Fail") << endl;

    // Tạo giao dịch withdraw
    Transaction t2 = Transaction::withdraw("T002", "ACC1001", 200.0, "2025-06-06 12:00:00", "Withdraw ATM");
    added = addTransaction(t2);
    cout << "Add withdraw transaction T002: " << (added ? "Success" : "Fail") << endl;

    // Tạo giao dịch transfer
    Transaction t3 = Transaction::transfer("T003", "ACC1001", "ACC2002", 100.0, "2025-06-06 13:00:00", "Transfer to friend");
    added = addTransaction(t3);
    cout << "Add transfer transaction T003: " << (added ? "Success" : "Fail") << endl;

    // Thử thêm giao dịch trùng ID
    Transaction t4 = Transaction::deposit("T001", "ACC1003", 300.0, "2025-06-06 14:00:00", "Duplicate ID test");
    added = addTransaction(t4);
    cout << "Add duplicate ID transaction T001: " << (added ? "Success" : "Fail (expected)") << endl;

    // Hiển thị lịch sử giao dịch của ACC1001
    cout << "\nTransaction history for ACC1001:" << endl;
    displayTransactionsByAccount("ACC1001");

    // Hiển thị lịch sử giao dịch của ACC2002
    cout << "\nTransaction history for ACC2002:" << endl;
    displayTransactionsByAccount("ACC2002");

    return 0;
}
