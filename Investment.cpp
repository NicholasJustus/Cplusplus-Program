#include <iostream>
#include <iomanip>

using namespace std;

class Investment {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

public:
    // Constructor
    Investment(double initInvestment, double monthDeposit, double annInterest, int years) {
        initialInvestment = initInvestment;
        monthlyDeposit = monthDeposit;
        annualInterest = annInterest;
        numYears = years;
    }

    // Function to calculate and display balance without monthly deposits
    void calculateWithoutMonthlyDeposit() {
        double balance = initialInvestment;
        double earnedInterest;

        cout << "Balance and Interest Without Additional Monthly Deposits\n";
        cout << "===============================================\n";
        cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(20) << "Year End Earned Interest\n";
        cout << "-----------------------------------------------\n";

        for (int i = 1; i <= numYears; i++) {
            earnedInterest = balance * (annualInterest / 100);
            balance += earnedInterest;
            cout << setw(10) << i << setw(20) << fixed << setprecision(2) << balance
                << setw(20) << fixed << setprecision(2) << earnedInterest << "\n";
        }
        cout << "-----------------------------------------------\n";
    }

    // Function to calculate and display balance with monthly deposits
    void calculateWithMonthlyDeposit() {
        double balance = initialInvestment;
        double earnedInterest;

        cout << "Balance and Interest With Additional Monthly Deposits\n";
        cout << "===============================================\n";
        cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(20) << "Year End Earned Interest\n";
        cout << "-----------------------------------------------\n";

        for (int i = 1; i <= numYears; i++) {
            double yearlyInterest = 0;
            for (int month = 1; month <= 12; month++) {
                earnedInterest = (balance + monthlyDeposit) * ((annualInterest / 100) / 12);
                balance += monthlyDeposit + earnedInterest;
                yearlyInterest += earnedInterest;
            }
            cout << setw(10) << i << setw(20) << fixed << setprecision(2) << balance
                << setw(20) << fixed << setprecision(2) << yearlyInterest << "\n";
        }
        cout << "-----------------------------------------------\n";
    }
};

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int numYears;

    // Input prompt
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: ";
    cin >> initialInvestment;
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
    cout << "Annual Interest: ";
    cin >> annualInterest;
    cout << "Number of years: ";
    cin >> numYears;

    // Create an Investment object
    Investment myInvestment(initialInvestment, monthlyDeposit, annualInterest, numYears);

    // Display input values
    cout << "\nPress any key to continue...\n";
    cin.ignore();
    cin.get();

    // Calculate and display balances without monthly deposits
    myInvestment.calculateWithoutMonthlyDeposit();

    // Calculate and display balances with monthly deposits
    myInvestment.calculateWithMonthlyDeposit();

    return 0;
}
