#include"passenger.hpp"
char passenger:: get_preference()
{
	return preference;
}
void passenger:: set_preference(char preference)
{
	this->preference=preference;
}
ticket* passenger:: get_ticket()
{
	return tickets;
}
void passenger:: set_ticket(ticket* t)
{
	tickets=t;
}
