#include "Contact.h"
#include <istream>

Contact::Contact() : address{}, city{}, state{}, zip_code{}, phone_number{} {}
Contact::Contact(string address, string city, string state, string zip_code, string phone_number) : address(""), city(""), state(""), zip_code(""), phone_number("") {}

string Contact::get_address() const
{
	return address;
}
string Contact::get_city() const
{
	return city;
}
string Contact::get_state() const
{
	return state;
}
string Contact::get_zip() const
{
	return zip_code;
}
string Contact::get_phone() const
{
	return phone_number;
}

void Contact::enter_contact()
{
	string street_num, street_name;
	cout << "\nPlease enter your contact information: ";
	cout << "\nStreet number: ";
	cin >> street_num;
	cout << "\nStreet name: ";
	cin >> street_name;
	cout << "\nCity: ";
	cin >> city;
	cout << "\nState: ";
	cin >> state;
	cout << "\nZip Code: ";
	cin >> zip_code;
	cout << "\nPhone number: ";
	cin >> phone_number;
	cout << endl;
	address = street_num + " " + street_name;
}

void Contact::display_contact_info() const
{
	cout << address << ",\n";
	cout << city << ", " << state << " " << zip_code << "\n";
	cout << phone_number;
}

