#include"headers.hpp"
#ifndef USERS_H
#define USERS_H
	class users
	{
		protected:
			string name;
    		int age;
    		char gender;
		public:
			users(string name,int age,char gender)
			: name(name),age(age),gender(gender){}
			string get_name();
        	int get_age();
        	char get_gender();
			void set_name(string name);
        	void set_age(int age);
        	void set_gender(char gender);
	};
#endif
