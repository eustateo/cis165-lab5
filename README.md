# Lab 5: Compound Interest and Loan Payments

Course section: CIS-165-W099

Student: Oscar Eustate De Jesus

## Compound-interest plan

Before the code draft, I planned to ask for the principal balance, annual
interest rate as a percentage, and number of times interest is compounded
during one year. I will display the interest rate, compounding count,
principal, interest earned, and amount in savings.

I needed AI to explain the 1.0 and the order of the formula. After that
explanation, I described these steps: store the principal, divide the
entered percentage by 100 to get a decimal rate, divide that rate by the
number of periods, add 1, and raise the result to the number of periods.
Multiply the principal by that result to get the amount. Finally, subtract
the principal from the amount to get the interest earned.

The code stores the period rate and growth factor separately so I can
follow those steps. `pow(growth_factor, times)` applies the repeated growth.

## Running the compound-interest program

Open https://www.onlinegdb.com/online_c++_compiler and select C++. Replace
the sample source with `compound_interest.cpp`, click **Run**, and enter
the principal, annual rate as a percentage, and compounding count in the
console when prompted. For a 4.25% annual rate, enter `4.25`, not `0.0425`.
Use positive input values for the required tests. Calculate expected results
before each run and compare them with the displayed report.

Terminal alternative:

```sh
g++ -std=c++17 -Wall -Wextra compound_interest.cpp -o compound_interest
./compound_interest
```

## Compound-interest tests

Oscar supplied the expected amount below and reported the output from his
OnlineGDB run. The comparison was then reviewed together with AI assistance.

| Test | Inputs | Expected results | Actual results | Match or correction |
| --- | --- | --- | --- | --- |
| Assigned | Principal 1000; annual rate 4.25%; periods 12 | Oscar's expected amount: 1043.33771631 | Amount $1043.34; interest $43.34 | Amount matches the prediction rounded to two decimal places. Subtracting the principal from the predicted amount gives 43.33771631, which rounds to the displayed interest. |
| Changed | Principal 500; annual rate 6%; periods 4 | Oscar's expected amount $530.68; expected interest $30.68 | Amount $530.68; interest $30.68 | Both displayed results match Oscar's predictions. |

Output reported by Oscar:

```text
Savings after one year
Interest Rate:                4.25%
Times Compounded:                12
Principal:            $     1000.00
Interest Earned:      $       43.34
Amount in Savings:    $     1043.34
```

Changed-test output reported by Oscar:

```text
Savings after one year
Interest Rate:                6.00%
Times Compounded:                 4
Principal:            $      500.00
Interest Earned:      $       30.68
Amount in Savings:    $      530.68
```

During testing, Oscar found that entering `6%` disrupted the program and
requested a numbers-only error message. The original numeric extraction
read the `6` but left `%` for the next input. The revised code reads and
checks the whole line, reports the error, and asks for the same input again.
It also requires positive values and a whole-number compounding count.
Oscar requested general error messages so the user can choose the input
values, rather than messages instructing the user to enter specific numbers.
After the messages were updated, Oscar confirmed that he personally tested
the revised program in OnlineGDB. He also asked for this test to be recorded
in the README. This confirmation is separate from the additional checks
performed by AI.

### Input error handling

If the user enters symbols or letters with the principal or rate, the
program displays:

```text
Error: only numbers are accepted. Do not include symbols.
```

The program reads the entire input line with `getline` and checks it with
`istringstream`. It rejects input such as `6%` because the line contains a
symbol after the number. The loop then asks for the same input again, and
the user chooses the replacement number.

The compounding count must be a whole number. The principal, rate, and
compounding count must also be greater than zero. Invalid input is handled
with checks and retry loops rather than a C++ `try`/`catch` block.

Oscar noticed that the numbers-only error message was repeated and suggested
storing it in a variable. The code now stores it once in the named constant
`NUMBER_ERROR` and reuses it for the principal and rate checks. Its name is
in ALL_CAPS to follow the course rule for named constants.

## Loan-payment plan

Before the loan code draft, I planned to ask the user for the loan amount,
annual interest rate as a percentage, and number of monthly payments.
I explained that the rate must be divided by 100 to become a decimal, then
divided by 12 to become a monthly rate because a year has 12 months.

I will multiply the monthly payment by the number of payments to get the
total I will pay after making all the payments. Then I will subtract the
original loan amount, or capital, to find the interest paid.

For `growth`, I will first add the monthly rate to 1.0, then raise that
sum to the number of payments. For `monthly_payment`, I will multiply
the loan amount, monthly rate, and growth to get the numerator, calculate
`growth - 1.0` for the denominator, and divide the numerator by the
denominator. AI helped clarify that the parentheses group the denominator.

I will display the loan amount, monthly interest rate, number of payments,
monthly payment, amount paid back, and interest paid.

I will test the assigned inputs of a $10,000 loan, 12% annual rate, and
36 payments. For the second test, I chose a $1,000 loan, 5% annual rate,
and 12 monthly payments.

## Loan-payment expected calculations

For the assigned test, Oscar initially predicted a monthly decimal rate of
0.01, a monthly payment of $325.58, total paid of $11,720.93, and interest
of $1,720.93. During review, AI checked the professor's formula and found
that the monthly rate was correct, but the predicted payment differed:

```text
growth = (1 + 0.01)^36 = approximately 1.430768783592
monthly_payment = 10000 * 0.01 * growth / (growth - 1)
                = approximately 332.143098128512
paid_back = monthly_payment * 36 = approximately 11957.151532626420
interest_paid = paid_back - 10000 = approximately 1957.151532626420
```

These are AI-assisted calculation checks, not reported student program
outputs. Totals use the unrounded monthly payment.

After reviewing the difference, I found that I had rounded the intermediate
results in my calculation. I recalculated using the full values and got
the corrected results: $332.14 monthly payment, $11,957.15 paid back,
and $1,957.15 interest. This showed me why I should keep the full values
for calculations and round only the displayed results.

## Loan-payment tests

Oscar personally ran the assigned test in OnlineGDB and supplied this output.

Before the changed-input run using a $1,000 loan, 5% annual rate, and
12 payments, Oscar predicted a monthly payment of $85.61, total paid back
of $1,027.29, and interest paid of $27.29.

| Test | Inputs | Expected results | Actual results | Match or correction |
| --- | --- | --- | --- | --- |
| Assigned | Loan 10000; annual rate 12%; payments 36 | After correcting early rounding: payment $332.14; paid back $11,957.15; interest $1,957.15 | Monthly rate 1.00%; payment $332.14; paid back $11,957.15; interest $1,957.15 | All displayed amounts match the corrected calculations. Original predictions and the rounding correction are documented above. |
| Changed | Loan 1000; annual rate 5%; payments 12 | Oscar's predicted payment $85.61; paid back $1,027.29; interest $27.29 | Monthly rate 0.42%; payment $85.61; paid back $1,027.29; interest $27.29 | All three displayed amounts match Oscar's predictions. |

```text
Enter the loan amount (numbers only): $10000
Enter the annual interest rate as a percentage (numbers only): 12
Enter the number of monthly payments: 36

Loan payment report
Loan Amount:            $    10000.00
Monthly Interest Rate:          1.00%
Number of Payments:                36
Monthly Payment:        $      332.14
Amount Paid Back:       $    11957.15
Interest Paid:          $     1957.15
```

Changed-test output supplied by Oscar after his OnlineGDB run:

```text
Enter the loan amount (numbers only): $1000
Enter the annual interest rate as a percentage (numbers only): 5
Enter the number of monthly payments: 12

Loan payment report
Loan Amount:            $     1000.00
Monthly Interest Rate:          0.42%
Number of Payments:                12
Monthly Payment:        $       85.61
Amount Paid Back:       $     1027.29
Interest Paid:          $       27.29
```

## Running the loan-payment program

In OnlineGDB, select C++ and load `loan_payment.cpp`. Click **Run** and
enter the loan amount, annual interest rate as a percentage, and number of
monthly payments in the console. Enter numbers without currency or percent
symbols. The monthly interest rate in the report is displayed as a percentage.

Terminal alternative:

```sh
g++ -std=c++17 -Wall -Wextra loan_payment.cpp -o loan_payment
./loan_payment
```

## Code explanations

### Why divide a percentage by 100?

I divide the percentage entered by the user by 100 because the formula
needs the rate as a decimal number.

### How does pow represent exponentiation?

I first add the rate for a period to 1.0. Then `pow` raises that result
to the number of periods or payments. The first argument is the value
being raised, and the second is the exponent.

### How is the annual rate converted to a monthly rate?

I divide the annual percentage by 100 to get a decimal rate, then divide
by 12 to get the monthly rate because a year has 12 months.

### Why use double?

If I use `int`, I will lose data because some results are decimal numbers.
Losing the decimal part would give me the wrong answer, so I use `double`
for the money and interest-rate calculations.

### What does the compounding count change?

Dividing the rate by `times` splits the annual rate into smaller rates for
each period. Increasing the exponent `times` applies those smaller growth
steps more frequently. Earned interest joins the principal sooner and starts
earning interest itself.

### Why keep full precision?

I rounded intermediate results in my first loan calculation and got a
different answer. When I used the full values, I got the corrected result.
I need to keep the full numbers during calculations and round only when
displaying money to two decimal places.

### How are total paid back and interest calculated?

I multiply the monthly payment by the number of payments to get the total
paid after all the payments. Then I subtract the original loan amount to
find how much of that total is interest.

### Why store calculations in variables before displaying them?

Assigning variables makes the code more readable. If I need to make a
change, I can change the variable or its calculation in one place instead
of repeating the change in many lines of code.

## Final verification

After the input checks and reusable error message were added, I reran both
final programs in OnlineGDB with the assigned inputs. The savings program
reported $43.34 interest and $1,043.34 in savings for 1000, 4.25%, and
12 periods. The loan program reported a $332.14 monthly payment,
$11,957.15 paid back, and $1,957.15 interest for 10000, 12%, and 36 payments.
Both final reports matched the expected results documented above.
Codex downloaded both final `.cpp` files from OnlineGDB and confirmed that
they were identical to the saved source files in this submission folder.

## AI assistance

I used Codex to explain formulas, draft code after I described my plans,
help fix input errors, and organize the documentation from my answers.
I supplied my expected results, ran the programs in OnlineGDB, and supplied
the outputs documented above. The assigned loan prediction was corrected
with AI assistance after I identified early rounding in my calculation.
Codex also performed supplementary compilation and input checks; those
checks do not replace my personal tests.
