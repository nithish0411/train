#include"headers.hpp"
#ifndef TICKET_H
#define TICKET_H
class ticket 
{
	int seatNumber;
	float price;
	string trainName;
	string coachName;
	string seatCategory;
	string trainType;
    string passengerName;
  //  bool isAvailable;  
public:
	string from;
	string to;
	ticket* next;
	vector<pair<int,int>> booked;
    ticket(int num,string tname,string cname,string category,string type,string f,string t);
	int get_seat_number();
	string get_train_type();
	void set_train_type(string);
	string get_train_name();
	void set_train_name(string);
	string get_coach_name();
	void set_coach_name(string);
    string get_passenger_name();
	void set_seat_number(int);
	void set_fare(float);
	float get_fare();
	void set_passenger_name(string);
    string get_seat_category();
	void show();

    //bool is_ticket_available();
    //void book_ticket();
   // void cancel_ticket();
};
#endif
