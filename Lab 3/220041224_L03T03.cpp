#include <bits/stdc++.h>
using namespace std;

class Medicine {
private:
    char trade_name[30], generic_name[30];
    double unit_price, discountPercent;
public:
    Medicine () : unit_price (0.0), discountPercent (5.0) {}
    void assignName (const char name[], const char genericName[]) {
        strcpy (trade_name, name);
        strcpy (generic_name, genericName);
    }
    void assignPrice (double price) {
        if (price < 0) {
            cout << "Price can not be negative. Invalid input" << endl;
            return;
        }
        unit_price = price;
    }
    void setDiscountPercent (double percent) {
        discountPercent = percent;
    }
    double getDiscountPercent () {
        return discountPercent;
    }
    double getUnitPrice () {
        return unit_price;
    }
    double getSellingPrice (int nos = 1) {
        return getUnitPrice () * (100.0 - getDiscountPercent ()) / 100 * nos;
    }
    void display () {
        cout << fixed << setprecision (2) << "MRP. of " << trade_name << " (" << generic_name << ") is BDT " << getUnitPrice ()
             << ". Current discount " << getDiscountPercent () << "%. Selling price BDT " << getSellingPrice () << "." << endl;
    }
};

int main () {
    Medicine napa;
    napa.assignName ("napa", "paracaetemol");
    napa.assignPrice (30);
    napa.setDiscountPercent (10);
    napa.display ();
    cout << "5 units of napa costs: " << napa.getSellingPrice (5) << endl;

    Medicine ace;
    ace.assignName ("ace", "paracaetemol");
    ace.assignPrice (65);
    ace.setDiscountPercent (20);
    ace.display ();

    return 0;
}
