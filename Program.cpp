#include <iostream>
#include <string>
#include <stdlib.h>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include "Account.h"
#include "Contact.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

void display_options();
list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID);
float prompt_for_float(string prompt);
void remove_account(list<Account>& account_list, int account_ID);
void banks_total_balance(list<Account>& account_list, float account_balance);

int main()
{
	int option, id;
	string name = "";
	string addr, city, state, zip, phone_num;
	float deposit{}, withdrawl{}, balance{}, dividend{};
	bool open_transaction = true;
	Account account;
	Contact contact;
	list<Account> accounts;
	list<Account>::iterator it;

	while (open_transaction) {
		display_options();
		cin >> option;
		switch (option)
		{
		case 0:
			// option '0' - Program should quit
			cout << "\nThank you for visiting our bank. \nCome back soon! \n";
			open_transaction = false;
			break;

		case 1:
			// option '1' - Program should display account information
			cout << "\n-----------------\n";
			if (accounts.size() == 0)
			{
				cout << "No accounts to display.";
				cout << "\n-----------------\n";
			};
			account.display_account_list(accounts);
			break;

		case 2:
			// option '2' - Program should prompt for a deposit amount
			cout << "What account ID do you want to deposit into? ";
			cin >> id;
			it = find_by_id(accounts, id);
			cout << "Amount to deposit: $";
			cin >> deposit;
			if (it != accounts.end())
			{
				it->account_deposit(deposit);
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;

		case 3:
			// option '3' - Program should prompt for a withdrawal amount
			cout << "What account ID do you want to withdraw from? ";
			cin >> id;
			it = find_by_id(accounts, id);
			cout << "Amount to withdraw: $";
			cin >> withdrawl;
			if (it != accounts.end())
			{
				it->account_withdrawl(withdrawl);
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;

		case 4:
			// option '4' - Program should create a new account
			account.account_info();
			account.account_create(accounts);
			break;

		case 5:
			// option '5' - Program should find an account by its id
			cout << "What account ID do you want to display? ";
			cin >> id;
			it = find_by_id(accounts, id);
			if (it != accounts.end())
			{
				cout << "------------------\n";
				it->account_display();
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;

		case 6:
			// option '6' - Program should remove a specified account
			cout << "What account would you like to remove? ";
			cin >> id;
			remove_account(accounts, id);
			break;

		case 7:
			// option '7' - Program should return the total balance of the accounts
			cout << "------------------\n";
			cout << "------------------\n";
			banks_total_balance(accounts, balance);
			cout << "\n------------------\n";
			break;

		case 8:
			// option '8' - Program should add a dividend to all of the accounts
			cout << "------------------\n";
			dividend = prompt_for_float("Enter a dividend as a whole number: ");
			dividend /= 100;
			transform(accounts.begin(), accounts.end(), accounts.begin(), [dividend, account](auto& account_bal) 
				{ account_bal.account_deposit(account_bal.get_balance() * dividend); return account_bal; });
			cout << "\n*** Dividend added ***\n";
			break;
		
		case 9:
			// option '9' - Program should ask for contact information for an account.
			cout << "\nWhat account to add contact information? ";
			cin >> id; 
			it = find_by_id(accounts, id);
			if (it != accounts.end())
			{
				cout << "------------------\n";
				it->account_display();
				it->add_contact();
			}
			else
			{
				cout << "Not a valid account number.\n";
			}
			break;
			
		default:
			// none of the above
			break;
		}
	}

}

void display_options()
{
	cout << endl << "Account menu: ";
	cout << endl << "0. Quit Program";
	cout << endl << "1. Display all accounts information";
	cout << endl << "2. Add a deposit to an account";
	cout << endl << "3. Withdraw from an account";
	cout << endl << "4. Add new account";
	cout << endl << "5. Display account by ID";
	cout << endl << "6. Remove account by ID";
	cout << endl << "7. Bank's total balance";
	cout << endl << "8. Add dividend to all accounts";
	cout << endl << "9. Enter contact information to account";
	cout << endl << "Your choice: ";
}

list<Account>::iterator find_by_id(list<Account>& account_list, int account_ID)
{
	list<Account>::iterator it;
	for (it = account_list.begin(); it != account_list.end(); it++)
	{
		if (it->get_id() == account_ID) {
			return it;
		}
	}
	return it;
}

void remove_account(list<Account>& account_list, int account_ID)
{
	auto removed_account = remove_if(account_list.begin(), account_list.end(), [account_ID](Account& remove)
		{
			return account_ID == remove.get_id();
		});
	account_list.erase(removed_account, account_list.end());
}

void banks_total_balance(list<Account>& account_list, float account_balance)
{
	auto bank_balance = accumulate(account_list.begin(), account_list.end(), 0.0f, [](float bank_balance, auto total)
		{
			return bank_balance + total.get_balance();
		});
	cout << "The total balance at the bank is $ " << bank_balance;
}

float prompt_for_float(string prompt) {
	cout << prompt;
	cin >> prompt;
	return stof(prompt);
}

