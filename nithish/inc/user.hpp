#include"headers.hpp"
#ifndef USER_H
#define USER_H
class user: public users
{
	private:
		string id;
		vector<passenger*> passenger_list;
		char preference;
		float wallet;
	public:
		bool boo;
    	user(string name, int age, char gender, char preference)
        	: users(name,age,gender), preference(preference) {}
		~user()
		{
			cout<<"your account named "<<get_name()<<" was deleted"<<endl;
		}
		char get_preference();
		string get_id();
		void set_id(string id);
		void set_preference(char preference);
		void select_train();
		bool add_passenger(vector<passenger*>*);
		void book_ticket(train *,vector<passenger*>*,string,string,string,vector<coach*>*);
		void show_bookings();
		void add_wallet(float);
		float get_wallet();
};
#endif
struct nodes
{
	nodes* right;
	nodes* left;
    int count;
    struct node* start;
	nodes() : count(0),start(nullptr){}
};

struct node 
{
    user* user_node;
	bool d;
    node* left;
    node* right;
    node( user* u) : user_node(u), d(false), left(nullptr), right(nullptr){}
};
