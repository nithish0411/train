#include"main.hpp"


int main() 
{
    binary_tree* b = new binary_tree;
    user* us1 = new user("mon", 16, 'M', 'U');
    user* us2 = new user("kvfv", 3, 'M', 'M');
    user* us3 = new user("sejnv", 22, 'M', 'L');
    user* us4 = new user("rjitng", 22, 'M', 'L');
    user* us5 = new user("fdsffs", 22, 'F', 'L');
    user* us6 = new user("uittm",23,'M','L');

    b->insert(us1);
    b->insert(us2);
    b->insert(us3);
    b->insert(us4);
    b->insert(us5);
    b->insert(us6);
//    delete b;
	while(1)
	{
		// cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		cout<<"1=> user 2=> admin 3=> exit"<<endl;
		int ch;
		// string input;
		// getline(cin,input);
		cin >> ch;
		// cin.sync();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		// ch = stoi(input)
		// getchar();
		switch(ch)
		{
			case 1: 
				while(1)
				{
					cout<<"1=> login 2=>register 3=>delete 4=> back"<<endl;
					int a;
					cin>>a;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					switch(a)
					{
						case 1:
							functions(login(b));
							break;
						case 2:
							add_user(b);
							break;
						case 3:
							remove_user(b);
							break;
						case 4:
							goto go_1;
		            }
				}
				go_1:
					break;
			case 2:
				while(1)
				{
					cout<<"1=> add train 2=> show trains 3=>show users 4=> back"<<endl;
					int b1;
					cin>>b1;
					switch(b1)
					{
						case 1:
							add_train();
							break;
						case 2:
							show_trains();
							break;
						case 3:
							b->shows();
							break;
						case 4:
							goto go_2;
					}
				}
				go_2:
				break;
			case 3:
				return 1;
         }
	}
    return 0;
}
node* binary_tree:: insert_user(node* n, user* u) 
{
	if (!n) 
	{
    	return n = new node(u);
    }
	else if(n && n->d)
	{
		n->user_node=u;
		n->d=false;
		return n;
	}
	if(u->get_name() < n->user_node->get_name()) 
	{
		if(n->left==NULL)
		{
            n->left = insert_user(n->left, u);
		}
		else
		{
			insert_user(n->left,u);
		}
	}
	else 
	{
		if(n->right==NULL)
        {
        	n->right = insert_user(n->right,u);
        }
        else
        {
        	insert_user(n->right,u);
        }
	}
    return n;
}
void binary_tree:: check_name(nodes* root,user* u)
{
	if(u->get_name()<"mzzzzzzz" && u->get_name()>="a")
	{
		u->set_id("7");
		u->set_id("0000");
		root->left->count += 1;
		u->set_id(to_string(root->left->count));
		root->left->start = insert_user(root->left->start,u);
	}
	else
	{
		u->set_id("4");
		u->set_id("0000");
		root->right->count += 1;
        u->set_id(to_string(root->right->count));
		root->right->start = insert_user(root->right->start,u);
	}
}
void binary_tree:: check_age(nodes* root, user* u)
{
	if(u->get_age()<60)
	{
		u->set_id("9");
		check_name(root->left,u);
	}
	else
	{
		u->set_id("3");
		check_name(root->right,u);
	}
}
nodes* binary_tree:: check_gender(nodes* root,user* u)
{
	nodes* temp = root;
	if(u->get_gender()=='F' || u->get_gender()== 'f')
	{
		u->set_id("1");
		check_age(root->left,u);
	}
	else
	{
		u->set_id("2");
		check_age(root->right,u);
	}
	return temp;
}
void binary_tree:: show(node* n)
{
	if(!n)
    {
    	return;
    }
	if(!n->d)
	{
    	cout << "Name: " << n->user_node->get_name() <<  endl;
		cout << "Age: " << n->user_node->get_age() << endl;
        cout << "Gender: " << n->user_node->get_gender() << endl;
        cout << "Preference: " << n->user_node->get_preference() << endl;
	}
    show(n->left);
    // cout<<"right"<<endl;
    show(n->right);
}
node* binary_tree:: private_search(node* n,string name)
{
	if(!n || n->d)
	{
		return NULL;
	}
	if(n->user_node->get_name()==name)
    {
    	return n;
    }
   	if(name<n->user_node->get_name())
    {
       return private_search(n->left,name);
    }
    else
    {
       return private_search(n->right,name);
    }
}
binary_tree:: binary_tree()
{
	root = new nodes();
	root->left=new nodes();
	root->right= new nodes();
	root->left->left=new nodes();
	root->left->right=new nodes();
	root->right->left=new nodes();
	root->right->right=new nodes();
	
	root->left->left->left=new nodes();
	root->left->left->right=new nodes();
	root->left->right->left=new nodes();
	root->left->right->right=new nodes();
	root->right->left->left=new nodes();
	root->right->left->right=new nodes();
	root->right->right->left=new nodes();
	root->right->right->right=new nodes();
}
void binary_tree:: insert(user* u) 
{
    root = check_gender(root, u);
}
void binary_tree:: shows()
{
	show(root->left->left->left->start);
	show(root->left->left->right->start);
	show(root->left->right->left->start);
	show(root->left->right->right->start);
	show(root->right->left->left->start);
	show(root->right->left->right->start);
	show(root->right->right->left->start);
	show(root->right->right->right->start);
}
node* binary_tree:: p_search(string name,string id)
{
	string con_id;
	stringstream s(id);
	getline(s,con_id,'0');
	if (con_id.empty())
	{
		return nullptr;
	}
	int check = stoi(con_id);
	switch(check)
	{
		case 197:
			return private_search(root->left->left->left->start,name);
		case 194:
			return private_search(root->left->left->right->start,name);
		case 137:
			return private_search(root->left->right->left->start,name);
		case 134:
			return private_search(root->left->right->right->start,name);
		case 297:
			return private_search(root->right->left->left->start,name);
		case 294:
			return private_search(root->right->left->right->start,name);
		case 237:
			return private_search(root->right->right->left->start,name);
		case 234:
			return private_search(root->right->right->right->start,name);
		default:
			return nullptr;
	}
	return NULL;
}
node* binary_tree:: search()
{
	string name;
    string id;
    cout<<"Enter details:"<<endl;
    cout<<"Enter name"<<endl;
	// getchar();
	// cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,name);
    cout<<"Enter your id"<<endl;
	getline(cin,id);
	return p_search(name,id);
}
void add_user(binary_tree* b)
{
	string name;
	int age;
	char gender;
	char prefer;
	cout<<"Enter details:"<<endl;
	cout<<"Enter name"<<endl;
	// getchar();
	getline(cin,name);
	cout<<"Enter age"<<endl;
	cin>>age;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cout<<"Enter gender"<<endl;
	cin>>gender;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cout<<"Enter preference"<<endl;
	cin>>prefer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	// getchar();
	user* us = new user(name,age,gender,prefer);
	b->insert(us);
	cout<<"Your id was "<<us->get_id()<<" (make a note on this) "<<endl;
}

void functions(node* l)
{
	if(l)
	{
		 
		while(1)
		{
			cout<<"1=> select train 2=> show bookings 3=>delete account 4=>cancel ticket 5=>back"<<endl;
			int ch;
			cin>>ch;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			switch(ch)
			{
				case 1:
					l->user_node->select_train();
					break;
				case 2:
					l->user_node->show_bookings();
					break;
				case 3:
				{
					user* del= l->user_node;
    				delete del;
    				l->user_node=nullptr;
    				l->d=true;
					return;
				}
				break;
				case 4:
					l->user_node->cancel_ticket();
					break;
				case 5:
					return;
			}
		}
	}
	else
	{
		cout<<"Try again after some time"<<endl;
		return;
	}
}
node* login(binary_tree* b)
{
	int count=0;
	re:
	node* log = b->search();
	if(log==NULL)
	{
		if(count==2)
		{
			return NULL;
		}
		count++;
		cout<<"Incorrect credentials try again..."<<endl;
		goto re;
	}
	return log; 
}
void remove_user(binary_tree* b)
{
	node* j = b->search();
	if(j == nullptr)
	{
		cout << "user not found " << endl;
		return;
	}
	user* del= j->user_node;
	delete del;
	j->user_node=nullptr;
	j->d=true;
}
void show_trains()
{
	for(train* train1: trains)
	{
		train1->train_info();
		cout<<endl;
	}
}
void add_train()
{
	string name;
	string type;
	int num;
	string time; 
	string org; 
	string dest;
	cout<<"Enter train name: "<<endl;
	getchar();
    getline(cin,name);
	cout<<"Enter train type: "<<endl;
	getline(cin,type);
	cout<<"Enter train number: "<<endl;
	cin>>num;
	cout<<"Enter train start time: "<<endl;
	getchar();
	getline(cin,time);
	cout<<"Enter origin station: "<<endl;
	getline(cin,org);
	cout<<"Enter destination station: "<<endl;
    getline(cin,dest);
	train* tr = new train(name,type,num,time,org,dest);
	tr->add_coach();
	tr->inter_stations.insert(make_pair(org,0));
	tr->stations.insert(make_pair(org,1));
	num = tr->add_stations();
	tr->set_destination(dest);
	float f;
	cout<<"Enter distance from source to destination"<<endl;
	cin >> f;
	getchar();
	tr->inter_stations.insert(make_pair(dest,f));
	tr->stations.insert(make_pair(dest,num));
	trains.push_back(tr);
}
