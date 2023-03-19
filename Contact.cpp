#include "Contact.h"


Contact::Contact() : address{}, city{}, state{}, zip_code{}, phone_number{} {}
Contact::Contact(string address, string city, string state, string zip_code, string phone_number) : address(""), city(""), state(""), zip_code(""), phone_number("") {}

void Contact::contact_info(string address, string city, string state, string zip_code, string phone_number)
{
	cout << "Please enter your contact information: ";
	cout << "Street address: ";
	cin >> address;
	cout << "City: ";
	cin >> city;
	cout << "State: ";
	cin >> state;
	cout << "Zip Code: ";
	cin >> zip_code;
	cout << "Phone number: ";
	cin >> phone_number;
}

void Contact::display_contact_info(string address, string city, string state, string zip_code, string phone_number)
{
	cout << Contact::address << ",\n";
	cout << Contact::city << ", " << Contact::state << " " << Contact::zip_code;
	cout << Contact::phone_number;
}

// shared_ptr<Contact> pointer(nullptr);