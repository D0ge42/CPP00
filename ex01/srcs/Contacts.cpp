#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contacts.hpp"

Contact::Contact()
{}

Contact::Contact(int id,std::string first_name, std::string last_name, std::string nickname, std::string phone_number , std::string darkest_secret)
{
	this->id = id;
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::~Contact()
{}


int	Contact::getId()
{
	return this->id;
}

void Contact::setId(int id)
{
	this->id = id;
}

std::string Contact::get_first_name()
{
	return this->first_name;
}

std::string Contact::get_last_name()
{
	return this->last_name;
}
std::string Contact::get_phone_number()
{
	return this->phone_number;
}
std::string Contact::get_nickname()
{
	return this->nickname;
}
std::string Contact::get_darkest_secret()
{
	return this->darkest_secret;
}
//
// void Phonebook::display_contact(int i)const
// {
// 	_contacts[i].showContact();
// }
// 
