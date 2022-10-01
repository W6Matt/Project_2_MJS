#include <iostream>
#include<iomanip>

using namespace std;

// Global variables
double numYears ;
double numMonthlyDis ;
double numAnnualInt ;
double numStartAmount;

double CheckValue () {
    double  numVal;
    try {
        cin >> numVal;
        if (!cin.good()) {
            throw 1;
        }
        if (isdigit(numVal)) {
            throw 2;
        }
        if (numVal < 0) {
            throw 3;
        }
    }
    catch (int a) {
        cout << "Invalid Entry";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        exit(1);
    }
    return numVal;
}


void txtMenu() {
    cout << "**********************************" << '\n';
    cout << "*********** Data Input ***********" << '\n';
    cout << "Initial Investment Amount: $";
    numStartAmount = CheckValue();
    cout << "Monthly Deposit: $";
    numMonthlyDis = CheckValue();
    cout << "Annual Interest: %";
    numAnnualInt= CheckValue();
    cout << "Number of Years ";
    numYears = CheckValue();
    cout << "**********************************" << '\n';
    cout << "**********************************" << '\n';
}

void PrintFunction(int numWidth, int numMonth, double numOpenBal, double numDeposit, double numTotal, double numIntTotal, double numClosingBal){
    const char txtChar  = ' ';
    cout << fixed;
    cout << left << setw(10) << setfill(txtChar) << setprecision(2) << numMonth ;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numOpenBal ;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numDeposit ;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numTotal;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numIntTotal ;
    cout << left << setw(numWidth) << setfill(txtChar) << setprecision(2) << numClosingBal ;
    cout << '\n';

}

void TxtTitle(int numWidth, string txtWith) {
    const char txtChar  = ' ';
    cout << left << setw(110) << setfill('=') << '=';
    cout << '\n';
    cout << " Balance and Interest " << txtWith << " Additional Monthly Deposits" <<  '\n';
    cout << left << setw(110) << setfill('-') << '-';
    cout << '\n';

    cout << left << setw(10) << setfill(txtChar) << "Month" ;
    cout << left << setw(numWidth) << setfill(txtChar) << "Opening Balance" ;
    cout << left << setw(numWidth) << setfill(txtChar) << "Monthly Deposit" ;
    cout << left << setw(numWidth) << setfill(txtChar) << "Total";
    cout << left << setw(numWidth) << setfill(txtChar) << "Interest" ;
    cout << left << setw(numWidth) << setfill(txtChar) << "Closing Balance" ;
    cout << '\n';
}

void txtOutput() {
    double numMonth;
    double numOpenBal;
    double numDeposit;
    double numTotal;
    double numIntTotal;
    double numClosingBal;
    double numIntr;
    const char txtChar  = ' ';
    const int numWidth = 20;


    numMonth = numYears * 12;
    numOpenBal = numStartAmount;
    numIntr = ((numAnnualInt / 100) / 12);
    numDeposit = numMonthlyDis;

// Without monthly deposit
    TxtTitle(numWidth, "Without");

    for (int i = 1; i <= numMonth; ++i) {
        numTotal = numOpenBal + numDeposit;
        numIntTotal = numTotal * numIntr;
        numClosingBal = numTotal + numIntTotal;
        PrintFunction(numWidth ,i, numOpenBal, 0,  numTotal,  numIntTotal,  numClosingBal);
        numOpenBal = numClosingBal;
    }
// With Monthly Deposit
    TxtTitle(numWidth, "With");

    for (int i = 1; i <= numMonth; ++i) {
        numTotal = numOpenBal + numDeposit;
        numIntTotal = numTotal * numIntr;
        numClosingBal = numTotal + numIntTotal;
        PrintFunction(numWidth ,i, numOpenBal, numDeposit,  numTotal,  numIntTotal,  numClosingBal);
        numOpenBal = numClosingBal;
    }

}

void LoopCode(){
    string txtStop ;

    while (true) {
        txtMenu();
        txtOutput();

        cout << '\n' << '\n';
        cout << left << setw(110) << setfill('=') << '=';
        cout << '\n' << '\n';
        cout << "Type y to Calculate again" << '\n';
        cout << "Type any other key to exit" << '\n';
        cin >> txtStop;
        if (txtStop != "y"){
            break;
        }

    }
}

int main() {
    LoopCode();
    return 0;
}
