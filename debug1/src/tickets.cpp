#include"ticket.hpp"
ticket :: ticket(int num,string tname,string cname,string category,string type,string f,string t)
       : seatNumber(num),trainName(tname),coachName(cname),seatCategory(category),trainType(type),from(f),to(t),next(nullptr){}
string ticket:: get_passenger_name()
{
	return passengerName;
}
string ticket:: get_train_type()
{
	return trainType;
}
void ticket:: set_train_type(string s)
{
	trainType = s;
}
void ticket:: set_passenger_name(string name)
{
   	passengerName = name;
}
string ticket:: get_seat_category()
{
    return seatCategory;
}
void ticket:: set_seat_number(int num)
{
	seatNumber = num;
}
int ticket:: get_seat_number()
{
	return seatNumber;
}
string ticket:: get_train_name()
{
	return trainName;
}
void ticket:: set_train_name(string name)
{
	trainName = name;
}
string ticket:: get_coach_name()
{
	return coachName;
}
void ticket:: set_coach_name(string name)
{
	coachName = name;
}
void ticket:: set_fare(float f)
{
	price = f;
}
float ticket:: get_fare()
{
	return price;
}
void ticket:: show()
{
	cout<<"Train name: "<<trainName<<endl;
	cout<<"Coach name: "<<coachName<<endl;
	cout<<"Seat number: "<<seatNumber<<endl;
	cout<<"Seat category: "<<seatCategory<<endl;
	cout<<"Fare: "<<price<<endl;
}
