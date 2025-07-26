// This is the definition for the class Money.
// Values of this type are amounts of money in U.S. currency.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <vector>

using namespace std;
class Money
{
public:
    friend Money operator+(const Money &amount1, const Money &amount2);
    // Returns the sum of the values of amount1 and amount2.
    friend Money operator-(const Money &amount1, const Money &amount2);
    // Returns amount1 minus amount2.
    friend Money operator-(const Money &amount);
    // Returns the negative of the value of amount.
    friend bool operator==(const Money &amount1, const Money &amount2);
    // Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator<(const Money &amount1, const Money &amount2);
    // Returns true if amount1 is less than amount2; false otherwise.
    Money& operator+=(const Money &other);
    // Assign addition of other to this.
    Money& operator-=(const Money &other);
    // Assign subtraction of other to this.
    Money(long dollars, int cents);
    // Initializes the object so its value represents an amount with
    // the dollars and cents given by the arguments. If the amount
    // is negative, then both dollars and cents should be negative.
    Money(long dollars);
    // Initializes the object so its value represents $dollars.00.
    Money();
    // Initializes the object so its value represents $0.00.
    double get_value() const;
    // Returns the amount of money recorded in the data portion of the calling
    // object.
    void set_value(long cents_in);
    // Sets all_cents to cents_in
    void set_value(double amount);
    // Sets all_cents to equivalent integer version of amount
    friend istream &operator>>(istream &ins, Money &amount);
    // Overloads the >> operator so it can be used to input values of type
    // Money. Notation for inputting negative amounts is as in − $100.00.
    // Precondition: If ins is a file input stream, then ins has already been
    // connected to a file.

    friend ostream &operator<<(ostream &outs, const Money &amount);
    // Overloads the << operator so it can be used to output values of type
    // Money. Precedes each output value of type Money with a dollar sign.
    // Precondition: If outs is a file output stream, then outs has already been
    // connected to a file.
private:
    long all_cents;
};

int digit_to_int(char c);
// Used in the definition of the overloaded input operator >>.
// Precondition: c is one of the digits '0' through '9'.
// Returns the integer for the digit; for example, digit_to_int('3') returns 3.
Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) // If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}
Money::Money(long dollars) : all_cents(dollars * 100)
{
    // Body intentionally blank.
}
Money::Money() : all_cents(0)
{
    // Body intentionally blank.
}
double Money::get_value() const
{
    return (all_cents * 0.01);
}

void Money::set_value(long cents_in)
{
    all_cents = cents_in;
}

void Money::set_value(double amount)
{
    all_cents = amount * 100;
}

Money operator+(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator==(const Money &amount1, const Money &amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money operator-(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money operator-(const Money &amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator<(const Money &amount1, const Money &amount2)
{
    if (amount1.all_cents < amount2.all_cents)
        return true;
    return false;
}

Money& Money::operator+=(const Money& other) {
    this->all_cents += other.all_cents;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    this->all_cents -= other.all_cents;
    return *this;
}

istream &operator>>(istream &ins, Money &amount)
{
    char one_char, decimal_point,
        digit1, digit2; // digits for the amount of cents
    long dollars;
    int cents;
    bool negative; // set to true if input is negative.
    ins >> one_char;
    if (one_char == '−')
    {
        negative = true;
        ins >> one_char; // read '$'
    }
    else
        negative = false;
    // if input is legal, then one_char == '$'
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}
// Uses cstdlib and iostream:
ostream &operator<<(ostream &outs, const Money &amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "− $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

class Check
{
public:
    Check() : check_number(0), check_amount(), is_cashed(false) {}
    // Initializes the object so its value represents $0.00.
    Check(int number, Money amount, bool is_cashed) : check_number(number), check_amount(amount), is_cashed(is_cashed) {}

    // Input & Output
    void input();
    void output() const;

    // Accessors
    int get_check_number() const { return check_number; }
    Money get_check_amount() const { return check_amount; }
    bool get_is_cashed() const { return is_cashed; }

    // Mutators
    void set_check_number(int new_check_number) { check_number = new_check_number; }
    void set_check_amount(Money new_check_amount) { check_amount = new_check_amount; }
    void set_is_cashed(int new_is_cashed) { is_cashed = new_is_cashed; }
private:
    int check_number;
    Money check_amount;
    bool is_cashed;
};

void sort_checks(vector<Check>& checks);

int main()
{
    vector<Check> checks;
    int num_of_checks;

    cout
        << "Check Balancing Program"
        << endl
        << "---------------------------------------------"
        << endl;
    cout 
        << "Please enter the number of checks: "
        << endl;
    cin >> num_of_checks;
    cout
        << "Please enter the check number, amount on check (in the form $##.##)"
        << endl
        << "and whether or not the check has been cashed by typing 1(Yes) or 0(No) separated by spaces: "
        << endl
        << "Example input: (9 $40.89 1)"
        << endl;

    for (int i = 0; i < num_of_checks; ++i)
    {
        cout 
            << "Loading check #" 
            << i + 1 
            << " of " 
            << num_of_checks 
            << endl;

        Check check;
        check.input();
        checks.push_back(check);
    }

    vector<Money> deposits;
    int num_of_deposits;

    cout
        << "---------------------------------------------"
        << endl
        << "Please enter the number of deposits: "
        << endl;
    cin >> num_of_deposits;

    for (int i = 0; i < num_of_deposits; ++i)
    {
        cout 
            << "Loading deposit #" 
            << i + 1 
            << " of " 
            << num_of_deposits 
            << endl;
        cout 
            << "Please enter the deposit amount in the format of $dollars.cents: "
            << endl;

        Money deposit;
        cin >> deposit;
        deposits.push_back(deposit);
    }

    Money old_balance;

    cout
        << "---------------------------------------------"
        << endl
        << "Please enter the prior account balance in the format of $dollars.cents: "
        << endl;
    cin >> old_balance;

    vector<Check> cashed_check, uncashed_check;

    for (Check check : checks)
        check.get_is_cashed() 
        ? cashed_check.push_back(check) 
        : uncashed_check.push_back(check);

    Money total_cashed_checks_amount, total_uncashed_checks_amount, total_deposits_amount;

    for (Check check : cashed_check)
        total_cashed_checks_amount += check.get_check_amount();
    for (Check check : uncashed_check)
        total_uncashed_checks_amount += check.get_check_amount();
    for (Money deposit : deposits)
        total_deposits_amount += deposit;

    Money account_new_balance = old_balance + total_deposits_amount - total_cashed_checks_amount;
    Money account_new_balance_after_uncahsed_are_cashed = account_new_balance - total_uncashed_checks_amount;

    cout
        << "---------------------------------------------"
        << endl
        << "Cashed checks: "
        << endl;

    if (cashed_check.size() > 0)
    {
        sort_checks(cashed_check);
        for (Check check : cashed_check)
            check.output();
    }
    else if (cashed_check.size() == 0)
        cout
        << "None"
        << endl;

    cout
        << "Total of cashed checks: "
        << total_cashed_checks_amount
        << endl
        << "---------------------------------------------"
        << endl;

    cout
        << "Uncashed checks: "
        << endl;

    if (uncashed_check.size() > 0)
    {
        sort_checks(uncashed_check);
        for (Check check : uncashed_check)
            check.output();
    }
    else if (uncashed_check.size() == 0)
        cout
        << "None"
        << endl;

    cout
        << "Total of uncashed checks: "
        << total_uncashed_checks_amount
        << endl
        << "---------------------------------------------"
        << endl;

    cout 
        << "Total of deposits: " 
        << total_deposits_amount 
        << endl
        << "---------------------------------------------"
        << endl;
    cout 
        << "The new account balance according to the bank"
        << endl
        << "(Old balance + all deposits - cashed checks): " 
        << account_new_balance 
        << endl
        << "---------------------------------------------"
        << endl;
    cout
        << "The actual new balance when all of the uncashed checks are cashed"
        << endl
        << "(New bank account balance - uncashed checks): "
        << account_new_balance_after_uncahsed_are_cashed
        << endl
        << "---------------------------------------------"
        << endl;

    cout 
        << "The difference between the checkbook balance "
        << account_new_balance_after_uncahsed_are_cashed
        << " and the bank balance of "
        << account_new_balance
        << " is: " 
        << total_uncashed_checks_amount
        << endl
        << "---------------------------------------------"
        << endl;

    return 0;
}

void Check::input()
{
    cin >> check_number >> check_amount >> is_cashed;
}

void Check::output() const
{
    cout 
        << "Check number: " 
        << check_number 
        << "    "
        << "Check amount: " 
        << check_amount 
        << endl;
}

void sort_checks(vector<Check>& checks)
{
    int n = checks.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (checks[j].get_check_number() < checks[min].get_check_number())
                min = j;
            if (min != i)
                swap(checks[i], checks[min]);
        }
    }
}