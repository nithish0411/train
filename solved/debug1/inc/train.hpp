#include"headers.hpp"
#include"passenger.hpp"
#ifndef TRAIN_H
#define TRAIN_H
#include"ticket.hpp"
/*
struct 3ac_coaches
{
	string names;
	3ac_coaches* next;
	vector<pair<int,ticket*>> list;
	3ac_coaches(string name): names(name),next(nullptr){} 
};
struct 2ac_coaches
{
	string names;
    2ac_coaches* next;
    vector<pair<int, ticket*>> list;
    2ac_coaches(string name): names(name),next(nullptr){}
};
struct sl_coaches
{
	string names;
    sl_coaches* next;
    vector<pair<int, ticket*>> list;
    sl_coaches(string name): names(name),next(nullptr){}
};
struct s2_coaches
{
	string names;
    s2_coaches* next;
    vector<pair<int, ticket*>> list;
    s2_coaches(string name): names(name),next(nullptr){}
};*/
struct coach
{
    string names;
    vector<pair<int, ticket*>> list;
    coach(string name): names(name){}
};
class train 
{
	string trainName;
	string trainType;
    int trainNumber;
    string departureTime;
	string origin;
	string destination;
	int count;
public:
	int sl_count;
	int s2_count;
    vector<coach*>  sl_coaches;
	vector<coach*> s2_coaches;
	multimap<string,float> inter_stations;
	map<string,int> stations;
    train(string name,string type,int number, string time, string org, string dest);
	string get_train_type();
	string get_train_name();
    int get_train_number();
    string get_departure_time();
	string get_origin();
    string get_destination();
	void set_train_type(string);
	void set_train_name(string);
	void set_train_number(int);
	void set_departure_time(string);
	void set_origin(string);
	void set_destination(string);
    void train_info();
	void show_tickets(string,string,string);
	void add_coach();
	void add_sl_ticket(coach*);
	void add_2s_ticket(coach* ch);
	int add_stations();
	friend void book_ticket(train*,vector<passenger*> *,string,string,string);
	friend void cancel_ticket();
};
extern map<string,float> km_fare;
 extern vector<train*> trains;
#endif
