#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    const string NUMBER_ERROR = "Error: only numbers are accepted. Do not include symbols.\n";
    double principal;
    double annual_rate;
    int times;
    string line;

    // Read a whole line so symbols such as % cannot remain in the input.
    while (true)
    {
        cout << "Enter the principal balance (numbers only): $";
        if (!getline(cin, line))
        {
            return 1;
        }
        istringstream input(line);
        if (!(input >> principal) || !(input >> ws).eof())
        {
            cout << NUMBER_ERROR;
        }
        else if (principal <= 0)
        {
            cout << "Error: the principal must be greater than zero.\n";
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
        cout << "Enter the number of times compounded in one year: ";
        if (!getline(cin, line))
        {
            return 1;
        }
        istringstream input(line);
        if (!(input >> times) || !(input >> ws).eof())
        {
            cout << "Error: only whole numbers are accepted. Do not include symbols.\n";
        }
        else if (times <= 0)
        {
            cout << "Error: the compounding count must be greater than zero.\n";
        }
        else
        {
            break;
        }
    }

    double rate = annual_rate / 100.0;
    double period_rate = rate / times;
    double growth_factor = 1.0 + period_rate;
    double amount = principal * pow(growth_factor, times);
    double interest_earned = amount - principal;

    // Format the report without rounding the stored calculations.
    cout << fixed << setprecision(2);
    cout << "\nSavings after one year\n";
    cout << left << setw(22) << "Interest Rate:"
         << right << setw(12) << annual_rate << "%" << endl;
    cout << left << setw(22) << "Times Compounded:"
         << right << setw(13) << times << endl;
    cout << left << setw(22) << "Principal:"
         << "$" << right << setw(12) << principal << endl;
    cout << left << setw(22) << "Interest Earned:"
         << "$" << right << setw(12) << interest_earned << endl;
    cout << left << setw(22) << "Amount in Savings:"
         << "$" << right << setw(12) << amount << endl;

    return 0;
}
