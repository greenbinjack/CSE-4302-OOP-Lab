#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    string accountType;
    double currentBalance;
    const double minimumBalance;
    static int totalAccounts;
    static int activeAccounts;
    static double totalSourceTax;

public:
    BankAccount (string accNum, string accHolderName, string accType, double balance, double minBalance)
        : accountNumber (accNum), accountHolderName (accHolderName), accountType (accType), currentBalance (balance), minimumBalance (minBalance) {
        totalAccounts++;
        activeAccounts++;
    }

    void showInfo () const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: BDT " << currentBalance << endl;
        cout << "Minimum Balance: BDT " << minimumBalance << endl;
    }

    void showBalance () const {
        cout << "Current Balance: BDT " << currentBalance << endl;
    }

    void deposit (double amount) {
        if (amount > 0) {
            currentBalance += amount;
            cout << "BDT " << amount << " deposited successfully. Current Balance: BDT " << currentBalance << endl;
        } else {
            cout << "Invalid amount. Cannot deposit." << endl;
        }
    }

    void withdrawal (double amount) {
        if (amount > 0 && (currentBalance - amount >= minimumBalance)) {
            currentBalance -= amount;
            cout << "BDT " << amount << " withdrawn successfully. Current Balance: BDT " << currentBalance << endl;
        } else if (amount <= 0) {
            cout << "Invalid amount. Cannot withdraw." << endl;
        } else {
            cout << "Insufficient balance. Cannot withdraw. Minimum balance required is BDT " << minimumBalance << endl;
        }
    }

    void giveInterest (double interestRate = 3.0) {
        double interest = (interestRate / 100.0) * currentBalance;
        double sourceTax = (10.0 / 100.0) * interest;
        double netInterest = interest - sourceTax;
        totalSourceTax += sourceTax;
        currentBalance += netInterest;
        cout << "Interest of BDT " << netInterest << " credited after 10% source tax deduction. Current Balance: BDT " << currentBalance << endl;
    }

    static int getTotalAccounts () {
        return totalAccounts;
    }

    static int getActiveAccounts () {
        return activeAccounts;
    }

    static double getTotalSourceTax () {
        return totalSourceTax;
    }

    friend BankAccount Larger (const BankAccount& A, const BankAccount& B);

    ~BankAccount() {
        cout << "Account of Mr./Ms. " << accountHolderName << " with account no. " << accountNumber << " is destroyed with a balance BDT " << currentBalance << endl;
        activeAccounts--;
    }
};

int BankAccount::totalAccounts = 0;
int BankAccount::activeAccounts = 0;
double BankAccount::totalSourceTax = 0.0;

void display_stat() {
    cout << "Total accounts created: " << BankAccount::getTotalAccounts () << endl;
    cout << "Active accounts: " << BankAccount::getActiveAccounts () << endl;
    cout << "Total source tax collected: BDT " << BankAccount::getTotalSourceTax () << endl;
}

BankAccount Larger (const BankAccount& A, const BankAccount& B) {
    if (A.currentBalance > B.currentBalance) {
        return A;
    } else {
        return B;
    }
}

int main() {
    BankAccount account1("12345", "Alice", "Savings", 5000, 1000);
    BankAccount account2("67890", "Bob", "Current", 8000, 2000);

    account1.showInfo();
    account1.deposit(1000);
    account1.withdrawal(2000);
    account1.giveInterest();

    account2.showInfo();
    account2.deposit(2000);
    account2.withdrawal(3000);
    account2.giveInterest(5);

    display_stat();

    BankAccount largerAccount = Larger(account1, account2);
    cout << "The account with larger balance is: " << endl;
    largerAccount.showInfo();

    return 0;
}
