#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    const int MONTHS_PER_YEAR = 12;
    const string NUMBER_ERROR = "Error: only numbers are accepted. Do not include symbols.\n";
    double loan_amount;
    double annual_rate;
    int payments;
    string line;

    while (true)
    {
        cout << "Enter the loan amount (numbers only): $";
        if (!getline(cin, line))
        {
            return 1;
        }
        istringstream input(line);
        if (!(input >> loan_amount) || !(input >> ws).eof())
        {
            cout << NUMBER_ERROR;
        }
        else if (loan_amount <= 0)
        {
            cout << "Error: the loan amount must be greater than zero.\n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter the annual interest rate as a percentage (numbers only): ";
        if (!getline(cin, line))
        {
            return 1;
        }
        istringstream input(line);
        if (!(input >> annual_rate) || !(input >> ws).eof())
        {
            cout << NUMBER_ERROR;
        }
        else if (annual_rate <= 0)
        {
            cout << "Error: the rate must be greater than zero.\n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter the number of monthly payments: ";
        if (!getline(cin, line))
        {
            return 1;
        }
        istringstream input(line);
        if (!(input >> payments) || !(input >> ws).eof())
        {
            cout << "Error: only whole numbers are accepted. Do not include symbols.\n";
        }
        else if (payments <= 0)
        {
            cout << "Error: the payment count must be greater than zero.\n";
        }
        else
        {
            break;
        }
    }

    double monthly_rate = annual_rate / 100.0 / MONTHS_PER_YEAR;
    double growth = pow(1.0 + monthly_rate, payments);
    double monthly_payment = loan_amount * monthly_rate * growth / (growth - 1.0);
    // Keep the unrounded payment when calculating the total paid.
    double paid_back = monthly_payment * payments;
    double interest_paid = paid_back - loan_amount;
    double monthly_percent = monthly_rate * 100.0;

    cout << fixed << setprecision(2);
    cout << "\nLoan payment report\n";
    cout << left << setw(24) << "Loan Amount:"
         << "$" << right << setw(12) << loan_amount << endl;
    cout << left << setw(24) << "Monthly Interest Rate:"
         << right << setw(12) << monthly_percent << "%" << endl;
    cout << left << setw(24) << "Number of Payments:"
         << right << setw(13) << payments << endl;
    cout << left << setw(24) << "Monthly Payment:"
         << "$" << right << setw(12) << monthly_payment << endl;
    cout << left << setw(24) << "Amount Paid Back:"
         << "$" << right << setw(12) << paid_back << endl;
    cout << left << setw(24) << "Interest Paid:"
         << "$" << right << setw(12) << interest_paid << endl;

    return 0;
}
