#ifndef PHONEBOOK_HPP 
#define PHONEBOOK_HPP
#include "Contacts.hpp"

/* Class constructor
 * What is a constructor? 
 * Constructor are methods that are automatically executed every time you create an object.
 * Why do we need one?
 * Its purpose is to construct an object and assign values to the object's members.
 * Does it return something?
 * A construct does not return any value.*/

/* Class destructors
 * What is a destructor?
 * A destructor is a method used to deallocate memory and do other cleanup for a class Object
 * A destructor is called for a class object when that object passes out of scope
 * or is explicitly deleted.
 * If no user-defined destructor exists for a class and one is needed, the compiler
 * implicitly decleares a Destructor .*/

class Phonebook
{
	private:
		Contact _contacts[8];
		int number_of_contacts;
		int id;
	public:
		Phonebook(); // Class constructor
		~Phonebook(); // Class destructor
		
		int get_id();
		std::string get_line();
		void add_contact(int id);
		void add_or_replace_contact(Phonebook *pb);
		void search_contact(std::string to_search);
		int  check_user_existence(std::string to_search);
		void display_contact(Contact *contact);
		void display_contacts_list();
		Contact get_contact(int id);
		int show_contact_count() const;

};



#endif

