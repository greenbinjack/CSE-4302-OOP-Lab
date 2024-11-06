#include <iostream>
using namespace std;

class Account {
private:
    string accountNo;
    string accountName;
    float balance;
public:
    Account () {}
    Account (string name, float initialBalance) : accountName (name), balance (initialBalance) {}

    string get_account_no () {
        return accountNo;
    }
    string get_account_name () {
        return accountName;
    }
    float get_balance () {
        return balance;
    }
    void set_account_name (string name) {
        accountName = name;
    }
    void set_balance (float amount) {
        balance = amount;
    }
    void set_account_no (string account_no) {
        accountNo = account_no;
    }

    void description ();
};

class CurrentAccount : public Account {
private:
    static const int serviceCharge = 100;
    static const int accountPrefix = 100;
    static int nextAccount;
public:
    CurrentAccount () {}
    CurrentAccount (string name, float initialBalance) : Account(name, initialBalance) {
        set_account_no (to_string (accountPrefix) + "-" + to_string (nextAccount));
        nextAccount++;
    }

    static int nextAccountNo () {
        return nextAccount;
    }

    void description () {
        cout << "This is a Current Account" << endl;
    }
};
int CurrentAccount :: nextAccount = 1;

class SavingsAccount : public Account {
    float interestRate;
    static const int accountPrefix = 200;
    static int nextAccount;

public:
    SavingsAccount () {}
    SavingsAccount (string name, float initialBalance, float rate) : Account (name, initialBalance), interestRate (rate) {
        set_account_no (to_string (accountPrefix) + "-" + to_string (nextAccount));
        nextAccount++;
    }

    static int nextAccountNo () {
        return nextAccount;
    }
    float get_interest_rate () {
        return interestRate;
    }
    void set_interest_rate (float iRate) {
        interestRate = iRate;
    }

    void description () {
        cout << "This is a Savings Account" << endl;
    }
};
int SavingsAccount :: nextAccount = 1;

class MonthlyDepositScheme : public Account {
protected:
    float interestRate;
    float monthlyDepositAmount;
    static const int accountPrefix = 300;
    static int nextAccount;

public:
    MonthlyDepositScheme () {}
    MonthlyDepositScheme (string name, float initialBalance, float rate, float depositAmount)
     : Account(name, initialBalance), interestRate(rate), monthlyDepositAmount (depositAmount) {
        set_account_no (to_string (accountPrefix) + "-" + to_string (nextAccount));
        nextAccount++;
    }

    static int nextAccountNo () {
        return nextAccount;
    }
    float get_interest_rate () {
        return interestRate;
    }
    void set_interest_rate (float iRate) {
        interestRate = iRate;
    }
    float get_monthly_deposit_amount () {
        return return monthlyDepositAmount;
    }
    void set_monthly_deposit_amount (float _monthlyDepositAmount) {
        monthlyDepositAmount = _monthlyDepositAmount;
    }

    void description () {
        cout << "This is a MonthlyDepositScheme Account" << endl;
    }
};
int MonthlyDepositScheme :: nextAccount = 1;

class LoanAccount : public Account {
    float interestRate;
    float monthlyDepositAmount;
    static const int accountPrefix = 900;
    static int nextAccount;

public:
    LoanAccount () {}
    LoanAccount (string name, float loanAmount, float rate, float monthlyPayment)
     : Account (name, loanAmount), interestRate (rate), monthlyDepositAmount (monthlyPayment) {
        set_account_no (to_string (accountPrefix) + "-" + to_string (nextAccount));
        nextAccount++;
    }

    static int nextAccountNo () {
        return nextAccount;
    }
    float get_interest_rate () {
        return interestRate;
    }
    void set_interest_rate (float iRate) {
        interestRate = iRate;
    }
    float get_monthly_deposit_amount () {
        return return monthlyDepositAmount;
    }
    void set_monthly_deposit_amount (float _monthlyDepositAmount) {
        monthlyDepositAmount = _monthlyDepositAmount;
    }

    void description () {
        cout << "This is a Loan Account" << endl;
    }
};
int LoanAccount :: nextAccount = 1;

class TwoYearMDS : public MonthlyDepositScheme {
private:
    float maximumInterest;
public:
    TwoYearMDS () {}
    TwoYearMDS (string name, float initialBalance, float rate, float depositAmount, float maxInterest)
     : MonthlyDepositScheme(name, initialBalance, rate, depositAmount), maximumInterest (maxInterest) {}

    float get_max_interest () {
        return maximumInterest;
    }
    void set_maximum_interest_rate (float _maximumInterest) {
        maximumInterest = _maximumInterest;
    }

    void description () {
        cout << "This is a Two Year MDS Account" << endl;
    }
};

class FiveYearMDS : public MonthlyDepositScheme {
private:
    float maximumInterest;
public:
    FiveYearMDS () {}
    FiveYearMDS (string name, float initialBalance, float rate, float depositAmount, float maxInterest)
     : MonthlyDepositScheme (name, initialBalance, rate, depositAmount), maximumInterest (maxInterest) {}

    float get_max_interest () {
        return maximumInterest;
    }
    void set_maximum_interest_rate (float _maximumInterest) {
        maximumInterest = _maximumInterest;
    }

    void description () {
        cout << "This is a Five Year MDS Account" << endl;
    }
};

class InitialDepositMDS : public MonthlyDepositScheme {
private:
    float maximumInterest;
    float initialDepositAmount;
public:
    InitialDepositMDS () {}
    InitialDepositMDS (string name, float initialBalance, float rate, float depositAmount, float maxInterest, float initialDeposit)
     : MonthlyDepositScheme (name, initialBalance, rate, depositAmount), maximumInterest (maxInterest), initialDepositAmount (initialDeposit) {}

    float get_max_interest () {
        return maximumInterest;
    }
    void set_maximum_interest_rate (float _maximumInterest) {
        maximumInterest = _maximumInterest;
    }
    float get_initial_deposit_amount () {
        return initialDepositAmount;
    }
    void set_initial_deposit_amount (float _initialDepositAmount) {
        initialDepositAmount = _initialDepositAmount;
    }

    void description () {
        cout << "This is a Initial Deposit MDS Account" << endl;
    }
};

int main () {
    CurrentAccount currentAcc;
    SavingsAccount savingsAcc;
    MonthlyDepositScheme monthlyDeposit;
    LoanAccount loanAcc;
    TwoYearMDS twoYearMDS;
    FiveYearMDS fiveYearMDS;
    InitialDepositMDS initialDepositMDS;

    currentAcc.description ();
    savingsAcc.description ();
    monthlyDeposit.description ();
    loanAcc.description ();
    twoYearMDS.description ();
    fiveYearMDS.description ();
    initialDepositMDS.description ();

    return 0;
}
