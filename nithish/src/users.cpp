#include"users.hpp"	
string users :: get_name()
{
	return name;
}
int users :: get_age()
{
    return age;
}
char users :: get_gender()
{
    return gender;
}
void users :: set_name(string name)
{
    this->name=name;
}
void users :: set_age(int age)
{
	this->age=age;
}
void users :: set_gender(char gender)
{
	this->gender=gender;
}
