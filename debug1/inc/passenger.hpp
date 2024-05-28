#include"headers.hpp"
#include"users.hpp"
#include"ticket.hpp"
#ifndef PASSENGER_H
#define PASSENGER_H
class passenger : public users
{
	char preference;
	ticket* tickets;
	public:
    	passenger(string name, int age, char gender, char preference)
        	: users(name,age,gender), preference(preference),tickets(nullptr){}
		char get_preference();
		void set_preference(char preference);
		ticket* get_ticket();
		void set_ticket(ticket*);
};
#endif
