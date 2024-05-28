
#ifndef MAIN_H
#define MAIN_H
#include"headers.hpp"
#include"passenger.hpp"
#include"users.hpp"
#include"user.hpp"
#include"train.hpp"
#include"ticket.hpp"
class binary_tree 
{
	nodes* root;
    node* insert_user(node* n, user* u);
	void check_name(nodes* root,user* u);
	void check_age(nodes* root, user* u);
	nodes* check_gender(nodes* root,user* u);
	void show(node* n);
	node* private_search(node* n,string name);
	public:
    	binary_tree();
		void insert(user* u);
		void shows();
		node* p_search(string name,string id);
		node* search();
};
void add_user(binary_tree* b);
void remove_user(binary_tree* b);
void functions(node* l);
node* login(binary_tree* b);
void add_train();
void show_trains();
#endif
