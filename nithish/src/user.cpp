#include"user.hpp"
#include"train.hpp"
extern vector<train*> trains;
extern map<string,float> km_fare;
char user:: get_preference()
{
	return preference;
}
string user:: get_id()
{
	return id;
}
void user:: set_id(string id)
{
	this->id=this->id+id;
}
void user: set_preference(char preference)
{
	this->preference=preference;
}
void user:: add_wallet(float f)
{
	wallet = f;
}
float user:: get_wallet()
{
	return wallet;
}
void user:: select_train()
{
	vector<passenger*> temp;
	re:
	string name,src,dest;
	getchar();
	cout<<"Enter source station: "<<endl;
	getline(cin,src);
	cout<<"Enter destination station: "<<endl;
	getline(cin,dest);
	bool l=0;
	float f1,f2;
	float amount;
	size_t size;
	for(train* train1: trains)
    {
		bool b1=0;
		for(auto& map : train1.inter_stations)
		{
			if(map.first==src)
			{
				f1=map.second;
				b1=1;
			}
			if(b1)
			{
				if(map.first==dest)
				{
					f2=map.second;
					train1->train_info();
                	cout<<endl;
					l=1;
				}
			}
		}
    }
	if(!l)
	{
		cout<<"No trains bw stations"<<endl;
		cout<<"ok to reselect !ok to back"<<endl;
		string r;
		getline(cin,r);
		if(r!="ok")
		{
			return;
		}
	}
	cout<<"Enter train name: "<<endl;
	getline(cin,name);
	for(train* train1: trains)
    {
    	if(name==train1->get_train_name()
        {
			string cat;
			cout<<"Enter seat category 2s or sl"<<endl;
			getline(cin,cat);
			if(cat=="2s")
			{
				boo = 1;
				amount = (f2-f1) * km_fare[cat]);
			}
			else if(cat=="sl")
			{
				boo=0;
				amount = (f2-f1) * km_fare[cat]);
			}
			else 
			{
			}
			train1->show_tickets(src,dest,cat);
			string con;
			cout<<"ok to book !ok to reselect "<<endl;
			getline(cin,con);
			if(con!="ok")
			{
				goto re;
			}
			bool b1 = add_passenger(&temp);
			if(b1)
			{
				amount = amount * temp.size();
				if(get_wallet() >= amount)
				{
					goto book;
				}
				else
				{
					float am;
					cout<<"Insufficient balance in wallet needs.."<<amount - get_wallet()<<endl;
					again:
					cout<<"Enter ok to add money !ok to cancel"<<endl;
					string mon;
					getline(cin,mon);
					if(mon=="ok")
					{
						count<<"Enter amount: "<<endl;
						getline(cin,am);
						if(am< (amount-get_wallet()))
						{
							cout<<"Try to enter more money"<<endl;
							goto again;
						}
						else
						{
							set_wallet(am);
							goto book;
						}
					}
				}
				book:
				set_wallet(get_wallet()-amount);
				book_ticket(train1,&temp,src,dest,cat);
				for(auto* te: temp)
				{
					if(te->get_ticket())
					{
						te->get_ticket->set_fare(amount);
						passenger_list.push_back(te);
					}
					else
					{
						te->delete;
					}
				}
				cout<<"ticket Booked successfully"<<endl;
			}
			else
			{
				string con1;
                cout<<"ok to reselect train !ok to cancel"<<endl;
				getchar();
                getline(cin,con1);
				if(con1=="ok")
				{
					goto re;
				}
				else
				{
					return;
				}
			}
		}
	}
}
bool user:: add_passenger(vector<passenger*>* temp)
{
	string name;
    int age;
    char gender;
    char prefer;
	re:
    cout<<"Enter details:"<<endl;
    cout<<"Enter name"<<endl;
    getchar();
    getline(cin,name);
    cout<<"Enter age"<<endl;
    cin>>age;
    cout<<"Enter gender"<<endl;
    cin>>gender;
    cout<<"Enter preference"<<endl;
    cin>>prefer;
	temp->push_back(new passenger(name,age,gender,prefer);
	cout<<"Enter /more/ to add passengers /continue/ to proceed booking /cancel/ to withdraw ";
	string ch:
	cin>>ch;
	if(ch=="cancel")
	{
		for(auto ps: *temp)
		{
			delete ps;
		}
		temp->clear();
		return 0;
	}
	else if(ch=="more")
	{
		goto re;
	}
	else
	{
		return 1;
	}
}
void user:: book_ticket(train* t,vector<passenger*> *temp,string src,string dest,string cat)
{
	string name;
	int e = stations[src];
	int s= stations[dest];
    bool fi,se =0;
	vector<coach*>* coach_hold;
    ticket* temp = ls->second;
    ticket* fir,ticket* sec;
	int sc = t->stations[src];
	int de = t->stations[dest];
	bool k,k1;
	if(boo)
	{
		for(auto &te: *temp)
		{
			k1=0;
			k=1;
			re2_2s:
			for(auto& coach : t->2s_coaches)
        	{
				bool s=1;
				bool s1=0;
                bool s2=0;
				bool s3=0;
            	for(vector<pair<int, ticket*>>:iterator ls = coach->list.begin(); ls != coach->list.end();)
            	{
					fi=0,se=0;
					if(k1)
					{
						if(ls->second)
                    	{
							if(stations[src]>=stations[ls->second->from] && stations[dest]<=stations[ls->second->to])
                            {
								if(stations[src]!=stations[ls->second->from])
                        		{
                            
                                	fir = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
									ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
									stations[ls->second->from],src);
                                    fi=1;
                        		}
                        		if(stations[dest]!=stations[ls->second->to])
                        		{
                    				sec = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
									ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
									dest,stations[ls->second->to]);
									se=1;
                        		}
								te->set_ticket(ls->second);
							}
							if(!f1 && !se)
							{
								if(!ls->second->next)
								{
                            		ls->second=nullptr;
								}
								else
								{
									ls->second = ls->second->next;
								}
                            	k=0;
                            	goto re1_2s;
							}
							else if(f1 && !se)
							{
								if(!ls->second->next)
                                {
                                    ls->second=fir;
                                }
                                else
                                {
                                    ticket* temps1 = ls->second->next;
									ls->second=fir;
									fir->next = temps1;
                                }
								te->get_ticket()->from =src;
								k=0;
                                goto re1_2s;
							}
							else if(!f1 && se)
							{
								if(!ls->second->next)
                                {
                                    ls->second=sec;
                                }
                                else
                                {
                                    ticket* temps2 = ls->second->next;
                                    ls->second=sec;
                                    sec->next = temps2;
                                }
                                te->get_ticket()->to =dest;
								 k=0;
                                goto re1_2s;
							}
							else
                            {
								if(!ls->second->next)
                                {
                                    ls->second=fir;
									fir->next=sec;
                                }
                                else
                                {
                                    ticket* temps3 = ls->second->next;
                                    ls->second=fir;
									fir->next = sec;
                                    sec->next = temps3;
                                }
								te->get_ticket()->from =src;
                                te->get_ticket()->to =dest;
								k=0;
                                goto re1_2s;
                            }
							se=0;
							fi=0;
							while(temp->next)
                    		{
								if(stations[src]>=stations[temp->next->from] && stations[dest]<=stations[temp->next->to])
                    			{
                        			if(stations[src]!=stations[temp->next->from] )
                        			{
                                   		fir = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
										temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,
										stations[temp->next->from],src);
                                    	fi=1;
                               		}
									if(stations[dest]!=stations[temp->next->to])
                        			{
                           				sec = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
										temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,dest,
										stations[temp->next->to]);
                               			se =1;
                            		}
									if(!f1 && !se)
                         			{
                                		ticket* temp1 = temp->next->next;
										ticket* temp2 = temp->next; 
								 		te->set_ticket(temp2);
										temp->next = temp1;
                                		k=0;
                                		goto re1_2s;
                            		}
                            		else if(f1 && !se)
                            		{
										ticket* temp3 = temp->next->next;
										te->set_ticket(temp->next);
										te->get_ticket()->from =src;
										temp->next = fir;
										fir->next = temp3;
                                 		k=0;
                                		goto re1_2s;
                            		}
                            		else if(!f1 && se)
                            		{
										ticket* temp4=temp->next->next;
										te->set_ticket(temp->next);
										te->get_ticket()->to =dest;
										temp->next=sec;
										sec->next = temp4;
                               		  	k=0;
                              		  	goto re1_2s;
                            		}
                            		else
                            		{
										ticket* temp5 = temp->next->next;
										te->set_ticket(temp->next);
										te->get_ticket()->from =src;
                               		 	te->get_ticket()->to =dest;
										temp->next = fir;
										fir->next = sec;
										sec->next = temp5;
                                 		k=0;
                                		goto re1_2s;
                           			}
                    			}
								temp = temp->next;
							}
							fi = 0;
							se =0;
                    		if(stations[src]>=stations[temp->from] && stations[dest]<=stations[temp->to])
                    		{	
								if(stations[src]!=stations[temp->from] && stations[src]!=stations[temp->from])
								{
									fir = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
									temp->get_seat_category(),temp->get_train_type,stations[temp->from],src);
									fi=1;
								}
								if(stations[dest]!=stations[temp->to] && stations[dest]!=stations[temp->to])
								{
									sec = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
									temp->get_seat_category(),temp->get_train_type,dest,stations[temp->to]);
								}
								if(!f1 && !se)
                  				{	
									te->set_ticket(temp);
                        			temp = nullptr;
   					 	   			k=0;
                            		goto re1_2s;
                        		}
                            	else if(f1 && !se)
                            	{
									te->set_ticket(temp);
									te->get_ticket()->from =src;
									temp = fir;
                               		k=0;
                               	 	goto re1_2s;
                            	}
								else if(!f1 && se)
                           		{
									te->set_ticket(temp);
									te->get_ticket()->to = dest;
									temp = sec;
                                	 k=0;
                                	goto re1_2s;
                           		 }
                           		else
                            	{
									te->set_ticket(temp);
									te->get_ticket()->from =src;
									te->get_ticket()->to =dest;
									temp = fir;
									fir->next = sec;
                                 	k=0;
                                	goto re1_2s;
                            	}
							}
						}
						goto re_2s;
					}
					if(s)
					{
						char c = te->get_preference();
						switch(c)
						{
							case 'w':
								s1=1;
								break;
							case 'm':
								s1=1;
								break;
							case 's':
								s1=1;
								break;
						}
						s=0;
					}
					fi=0;
					se=0;
                	if(ls->second)
                	{
                		if(stations[src]>=stations[ls->second->from] && stations[dest]<=stations[ls->second->to])
                    	{
							if(stations[src]!=stations[ls->second->from])
                        	{                    	
                        		fir = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
								ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
								stations[ls->second->from],src);
                            	fi=1;
                        	}
                        	if(stations[dest]!=stations[ls->second->to])
                        	{
                        		sec = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
								ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
								dest,stations[ls->second->to]);
								se=1;
                        	}
							te->set_ticket(ls->second);
						}
						if(!f1 && !se)
						{
							if(!ls->second->next)
							{
                            	ls->second=nullptr;
							}
							else
							{
								ls->second = ls->second->next;
							}
                        	k=0;
                        	goto re1_2s;
						}
						else if(f1 && !se)
						{
							if(!ls->second->next)
                        	{
                        		ls->second=fir;
                        	}
                        	else
                        	{
                        		ticket* temps1 = ls->second->next;
								ls->second=fir;
								fir->next = temps1;
                        	}
							te->get_ticket()->from =src;
							k=0;
                        	goto re1_2s;
						}
						else if(!f1 && se)
						{
							if(!ls->second->next)
                        	{
                        		ls->second=sec;
                        	}
                        	else
                        	{
                        		ticket* temps2 = ls->second->next;
                            	ls->second=sec;
                            	sec->next = temps2;
                        	}
                        	te->get_ticket()->to =dest;
							k=0;
                        	goto re1_2s;
						}
						else
                    	{
							if(!ls->second->next)
                        	{
                        	ls->second=fir;
							fir->next=sec;
                        	}
                       		else
                        	{
                        		ticket* temps3 = ls->second->next;
                            	ls->second=fir;
								fir->next = sec;
                            	sec->next = temps3;
                        	}
							te->get_ticket()->from =src;
                        	te->get_ticket()->to =dest;
							k=0;
                        	goto re1_2s;
                  		}
						se=0;
						fi=0;
						while(temp->next)
                    	{
							if(stations[src]>=stations[temp->next->from] && stations[dest]<=stations[temp->next->to])
                    		{
                        		if(stations[src]!=stations[temp->next->from] )
                        		{                          
                            		fir = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
									temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,
									stations[temp->next->from],src);
                                	fi=1;
                        		}
                        		if(stations[dest]!=stations[temp->next->to])
                        		{                    
									sec = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
									temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,dest,
									stations[temp->next->to]);
                                	se =1;
								}
						 		if(!f1 && !se)
                         		{
                                	ticket* temp1 = temp->next->next;
									ticket* temp2 = temp->next; 
									te->set_ticket(temp2);
									temp->next = temp1;
                               		k=0;
                                	goto re1_2s;
                            	}
                            	else if(f1 && !se)
                            	{
									ticket* temp3 = temp->next->next;
									te->set_ticket(temp->next);
									te->get_ticket()->from =src;
									temp->next = fir;
									fir->next = temp3;
                               		k=0;
                               		goto re1_2s;
                            	}
                            	else if(!f1 && se)
                            	{
									ticket* temp4=temp->next->next;
									te->set_ticket(temp->next);
									te->get_ticket()->to =dest;
									temp->next=sec;
									sec->next = temp4;
                               		k=0;
                               	 	goto re1_2s;
                            	}	
                            	else
                            	{
									ticket* temp5 = temp->next->next;
									te->set_ticket(temp->next);
									te->get_ticket()->from =src;
                                	te->get_ticket()->to =dest;
									temp->next = fir;
									fir->next = sec;
									sec->next = temp5;
                                	k=0;
                                	goto re1_2s;
                           		}	
                    		}
							temp = temp->next;
						}
						fi = 0;
						se =0;
                    	if(stations[src]>=stations[temp->from] && stations[dest]<=stations[temp->to])
                    	{	
							if(stations[src]!=stations[temp->from] && stations[src]!=stations[temp->from])
							{								
								fir = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
								temp->get_seat_category(),temp->get_train_type,stations[temp->from],pair.first);
								fi=1;
							}
							if(stations[dest]!=stations[temp->to] && stations[dest]!=stations[temp->to])
							{						
								sec = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
								temp->get_seat_category(),temp->get_train_type,pair.first,stations[temp->to]);
							}
						}
						if(!f1 && !se)
                  		{	
							te->set_ticket(temp);
                        	temp = nullptr;
   					 	   	k=0;
                            goto re1_2s;
                       	}
                        else if(f1 && !se)
                        {
							te->set_ticket(temp);
							te->get_ticket()->from =src;
							temp = fir;
                            k=0;
                            goto re1_2s;
                        }
						else if(!f1 && se)
                        {
							te->set_ticket(temp);
							te->get_ticket()->to = dest;
							temp = sec;
                            k=0;
                            goto re1_2s;
                        }
                        else
                        {
							te->set_ticket(temp);
							te->get_ticket()->from =src;
							te->get_ticket()->to =dest;
							temp = fir;
							fir->next = sec;
                            k=0;
                            goto re1_2s;
                        }
					}
					if(!s3)
					{
						s3=1;
						advance(s3,4);
						goto re_2s;
					}
					else
					{
						s3=0;
						goto re_2s;
					}
					if(!s2)
					{
						s2=1;
						advance(ls,2);
						goto re_2s;
					}
					else
                    {
                        advance(ls,2);
						s2=0;
                        goto re_2s;
                    }
					if(!s1)
                    {
						s1=1;
						goto re_2s;
                    }
					else
                    {
                        advance(ls,4);
						s1=0;
						goto re_2s;
                    }
					re_2s:
					ls++;
				}
				re1_2s:
				if(k)
				{
					k1=1;
					goto re2_2s;
				}
            }
        }
	}
	else
	{
	for(auto &te: *temp)
	{
		k1=0;
		k=1;
		re2_sl:
		for(auto& coach : t->sl_coaches)
        {
			bool s=1;
			bool s1=0;
            bool s2=0;
            for(vector<pair<int, ticket*>>::iterator ls = coach->list.begin(); ls != coach->list.end();)
            {
				fi=0;se=0;
				if(k1)
				{
					if(ls->second)
                    {
                    	if(stations[src]>=stations[ls->second->from] && stations[dest]<=stations[ls->second->to])
                        {
							if(stations[src]!=stations[ls->second->from])
                        	{                           		
                                fir = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
								ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
								stations[ls->second->from],src);
                                fi=1;                     
                        	}
                        	if(stations[dest]!=stations[ls->second->to])
                        	{                          
                            	sec = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
								ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
								dest,stations[ls->second->to]);
								se=1;                               	
                        	}
							te->set_ticket(ls->second);
						}
						if(!f1 && !se)
						{
							if(!ls->second->next)
							{
                            	ls->second=nullptr;
							}
							else
							{
								ls->second = ls->second->next;
							}
                            k=0;
                            goto re1_sl;
						}
						else if(f1 && !se)
						{
							if(!ls->second->next)
                            {
                            	ls->second=fir;
                            }
                            else
                            {
                            	ticket* temps1 = ls->second->next;
								ls->second=fir;
								fir->next = temps1;
                            }
							te->get_ticket()->from =src;
							k=0;
                            goto re1_sl;
						}
						else if(!f1 && se)
						{
							if(!ls->second->next)
                            {
                            	ls->second=sec;
                            }
                            else
                            {
                            	ticket* temps2 = ls->second->next;
                                ls->second=sec;
                                sec->next = temps2;
                            }
                            te->get_ticket()->to =dest;
							k=0;
                            goto re1_sl;
						}
						else
                        {
							if(!ls->second->next)
                            {
                            	ls->second=fir;
								fir->next=sec;
                            }
                            else
                            {
                                ticket* temps3 = ls->second->next;
                                ls->second=fir;
								fir->next = sec;
                                sec->next = temps3;
                            }
							te->get_ticket()->from =src;
                            te->get_ticket()->to =dest;
							k=0;
                            goto re1_sl;
                       	}
						se=0;
						fi=0;
						while(temp->next)
                    	{
							if(stations[src]>=stations[temp->next->from] && stations[dest]<=stations[temp->next->to])
                    		{
                        		if(stations[src]!=stations[temp->next->from] )
                        		{                            	
                                	fir = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
									temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,
									stations[temp->next->from],src);
                                    fi=1;
                        		}
                        		if(stations[dest]!=stations[temp->next->to])
                        		{                           
									sec = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
									temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,
									dest,stations[temp->next->to]);
                                    se =1;
								}
						 		if(!f1 && !se)
                         		{
                                	ticket* temp1 = temp->next->next;
									ticket* temp2 = temp->next; 
								 	te->set_ticket(temp2);
									temp->next = temp1;
                                	k=0;
                                	goto re1_sl;
                            	}
                            	else if(f1 && !se)
                            	{
									ticket* temp3 = temp->next->next;
									te->set_ticket(temp->next);
									te->get_ticket()->from =src;
									temp->next = fir;
									fir->next = temp3;
                               		k=0;
                                	goto re1_sl;
                           		}
                            	else if(!f1 && se)
                            	{
									ticket* temp4=temp->next->next;
									te->set_ticket(temp->next);
									te->get_ticket()->to =dest;
									temp->next=sec;
									sec->next = temp4;
                                 	k=0;
                                	goto re1_sl;
                            	}
                            	else
                            	{
									ticket* temp5 = temp->next->next;
									te->set_ticket(temp->next);
									te->get_ticket()->from =src;
                                	te->get_ticket()->to =dest;
									temp->next = fir;
									fir->next = sec;
									sec->next = temp5;
                                 	k=0;
                                	goto re1_sl;
                           		}
                    		}
							temp = temp->next;
						}
						fi = 0;
						se =0;
                    	if(stations[src]>=stations[temp->from] && stations[dest]<=stations[temp->to])
                    	{	
							if(stations[src]!=stations[temp->from] && stations[src]!=stations[temp->from])
							{								
								fir = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
								temp->get_seat_category(),temp->get_train_type,stations[temp->from],src);
								fi=1;
							}
							if(stations[dest]!=stations[temp->to] && stations[dest]!=stations[temp->to])
							{
								sec = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
								temp->get_seat_category(),temp->get_train_type,dest,stations[temp->to]);
							}
						}
							if(!f1 && !se)
                  			{		
								te->set_ticket(temp);
                        		temp = nullptr;
   					 	   		k=0;
                            	goto re1_sl;
                        	}
                            else if(f1 && !se)
                            {
								te->set_ticket(temp);
								te->get_ticket()->from =src;
								temp = fir;
                                k=0;
                                goto re1_sl;
                            }
							else if(!f1 && se)
                           	{
								te->set_ticket(temp);
								te->get_ticket()->to = dest;
								temp = sec;
                                k=0;
                                goto re1_sl;
                            }
                            else
                            {
								te->set_ticket(temp);
								te->get_ticket()->from =src;
								te->get_ticket()->to =dest;
								temp = fir;
								fir->next = sec;
                                k=0;
                                goto re1_sl;
                            }
						}
					}
					goto re_sl;
				}
				if(s)
				{
					char c = te->get_preference();
					switch(c)
					{
						case 'l':
							s1=1;
							break;
						case 'm':
							s1=1;
							advance(ls,1);
							break;
						case 'u':
							s1=1;
							advance(ls,2);
							break;
						case 'w':
							s2=1;
							advance(ls,6);
							break;
						case 's':
							s2=1;
							advance(ls,7);
							break;
					}
					s=0;
				}
				fi=0;
				se=0;
                if(ls->second)
                {
                	if(stations[src]>=stations[ls->second->from] && stations[dest]<=stations[ls->second->to])
                    {
						if(stations[src]!=stations[ls->second->from])
                        {                    	
                        	fir = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
							ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
							stations[ls->second->from],src);
                            fi=1;
                        }
                        if(stations[dest]!=stations[ls->second->to])
                        {
                        	sec = new ticket(ls->second->get_seat_number(),ls->second->get_train_name(),
							ls->second->get_coach_name(),ls->second->get_seat_category(),ls->second->get_train_type,
							dest,stations[ls->second->to]);
							se=1;
                        }
						te->set_ticket(ls->second);
					}
					if(!f1 && !se)
					{
						if(!ls->second->next)
						{
                           	ls->second=nullptr;
						}
						else
						{
							ls->second = ls->second->next;
						}
						k=0;
                        goto re1_sl;
					}
					else if(f1 && !se)
					{
						if(!ls->second->next)
                        {
                        	ls->second=fir;
                        }
                        else
                        {
                        	ticket* temps1 = ls->second->next;
							ls->second=fir;
							fir->next = temps1;
                        }
						te->get_ticket()->from =src;
						k=0;
                        goto re1_sl;
					}
					else if(!f1 && se)
					{
						if(!ls->second->next)
                       	{
                       		ls->second=sec;
                       	}
                       	else
                       	{
                       		ticket* temps2 = ls->second->next;
                           	ls->second=sec;
                           	sec->next = temps2;
                       	}
                       	te->get_ticket()->to =dest;
						k=0;
                       	goto re1_sl;
					}
					else
                    {
						if(!ls->second->next)
                       	{
                    	   	ls->second=fir;
							fir->next=sec;
                      	}
                       	else
                       	{
                       		ticket* temps3 = ls->second->next;
                           	ls->second=fir;
							fir->next = sec;
                           	sec->next = temps3;
                       	}
						te->get_ticket()->from =src;
                       	te->get_ticket()->to =dest;
						k=0;
						goto re1_sl;
                  	}
					se=0;
					fi=0;
					while(temp->next)
                    {
						if(stations[src]>=stations[temp->next->from] && stations[dest]<=stations[temp->next->to])
                    	{
                        	if(stations[src]!=stations[temp->next->from] )
                        	{                          
                            	fir = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
								temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,
								stations[temp->next->from],src);
                               	fi=1;
                       		}
                       		if(stations[dest]!=stations[temp->next->to])
                       		{                    
								sec = new ticket(temp->next->get_seat_number(),temp->next->get_train_name(),
								temp->next->get_coach_name(),temp->next->get_seat_category(),temp->next->get_train_type,dest,
								stations[temp->next->to]);
                               	se =1;
							}
							if(!f1 && !se)
                         	{
                               	ticket* temp1 = temp->next->next;
								ticket* temp2 = temp->next; 
								te->set_ticket(temp2);
								temp->next = temp1;
                             	k=0;
                                goto re1_sl;
                            }
                            else if(f1 && !se)
                            {
								ticket* temp3 = temp->next->next;
								te->set_ticket(temp->next);
								te->get_ticket()->from =src;
								temp->next = fir;
								fir->next = temp3;
                             	k=0;
                               	goto re1_sl;
                            }
                            else if(!f1 && se)
                            {
								ticket* temp4=temp->next->next;
								te->set_ticket(temp->next);
								te->get_ticket()->to =dest;
								temp->next=sec;
								sec->next = temp4;
                               	k=0;
                              	goto re1_sl;
                            }	
                            else
                            {
								ticket* temp5 = temp->next->next;
								te->set_ticket(temp->next);
								te->get_ticket()->from =src;
                                te->get_ticket()->to =dest;
								temp->next = fir;
								fir->next = sec;
								sec->next = temp5;
                                k=0;
                                goto re1_sl;
                           	}	
                    	}
						temp = temp->next;
					}
					fi = 0;
					se =0;
                    if(stations[src]>=stations[temp->from] && stations[dest]<=stations[temp->to])
                    {	
						if(stations[src]!=stations[temp->from] && stations[src]!=stations[temp->from])
						{								
							fir = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
							temp->get_seat_category(),temp->get_train_type,stations[temp->from],pair.first);
							fi=1;
						}
						if(stations[dest]!=stations[temp->to] && stations[dest]!=stations[temp->to])
						{						
							sec = new ticket(temp->get_seat_number(),temp->get_train_name(),temp->get_coach_name(),
							temp->get_seat_category(),temp->get_train_type,pair.first,stations[temp->to]);
						}
					}
					if(!f1 && !se)
               		{	
						te->set_ticket(temp);
                     	temp = nullptr;
   				 	   	k=0;
                        goto re1_sl;
                    }
                    else if(f1 && !se)
                    {
						te->set_ticket(temp);
						te->get_ticket()->from =src;
						temp = fir;
                        k=0;
                        goto re1_sl;
                    }
					else if(!f1 && se)
                    {
						te->set_ticket(temp);
						te->get_ticket()->to = dest;
						temp = sec;
                        k=0;
                        goto re1_sl;
                    }
                    else
                    {
						te->set_ticket(temp);
						te->get_ticket()->from =src;
						te->get_ticket()->to =dest;
						temp = fir;
						fir->next = sec;
                        k=0;
                        goto re1_sl;
                    }
				}
				if(s2)
                {
                	advance(ls,7);
                    goto re_sl;
                }
				if(!s1)
                {
                    advance(ls,4);
					s1=1;
					goto re_sl;
                }
				else
                {
                    advance(ls,2);
					s1=0;
					goto re_sl;
                }
				re_sl:
				ls++;
			}
			re1_sl:
			if(k)
			{
				k1=1;
				goto re2_sl;
			}
        }
    }
	}
}
void user:: show_bookings()
{
	int a=1;
	for(auto ps: passenger_list)
	{
		cout<<a++<<"=>"<<endl;
		cout<<"Name: "<<ps->get_name()<<endl;
		cout<<"Age: "<<ps->get_age()<<endl;
		cout<<"gender: "<<ps->get_gender()<<endl;
		ps->get_ticket()->show();
	//	cout<<ps->get_ticket()->get_seat_category()<<endl;
		cout<<endl;
	}
}
void user:: cancel_ticket()
{
	show_bookings();
	int check;
	cout<<"select ticket s.no to be canceled"<<endl;
	cin>>check;
	passenger* pass;
	ticket* ts;
	train* tr;
	int a=1;
	int seat_no;
	string coach_na;
	vector<coach*>* coach_ls;
	for(auto ps: passenger_list)
    {
		if(a==check)
		{
			pass = ps;
			ts = ps->get_ticket();
			seat_no = ts->get_seat_number();
			coach_na = ts->get_coach_name();
			break;
		}
		a++;
	}
	for(train* t: trains)
	{
		if(t->get_train_name()==ts->get_train_name())
		{
			tr = t;
		}
	}
	bool b1 =0;
	bool b2=0;
	ticket* ts1;
	ticket* ts2;
	ticket* ts11 = nullptr;
	ticket* ts22 = nullptr;
	if(coach_na[0]=='2')
	{
		for(auto& coach : tr->2s_coaches)
        {
			for(vector<pair<int, ticket*>>::iterator ls = coach->list.begin(); ls != coach->list.end();)
            {
				advance(ls,ts->get_seat_number());
				ticket* temp = ls->second;
				while(temp)
				{
					if(tr->stations[temp->to]==ts->from)
					{
						b1=1;
						ts1=temp;
					}
					if(tr->stations[temp->to]<ts->from)
					{
						ts11=temp;
					}
					if(tr->stations[temp->from]> ts->to)
					{
						ts22=temp;
					}
					if(tr->stations[temp->from]==ts->to)
					{
						b2=1;
						ts2=temp;
					}
					temp=temp->next;
				}
				if(!b1 && b2)
				{
					ts2->from=ts->from;
				}
				else if(b1 && !b2)
				{
					ts1->to=ts->to;
				}
				else if(b1 && b2)
				{
					ts1->to = ts2->to;
					ts1->next=ts2->next;
				}
				else
				{
					if(ts11)
					{
						tickte* temps = ts11->next;
						ts11->next = ts;
						ts->next = ts22;
					}
				}
				delete pass;
				cout<<"ticket cancellation successful"<<endl;
				return;
				ls++;
			}
		}
	}
	else if(coach_na[0]=='s')
	{
		for(auto& coach : tr->sl_coaches)
        {
        	for(vector<pair<int, ticket*>>::iterator ls = coach->list.begin(); ls != coach->list.end();)
            {
            	advance(ls,ts->get_seat_number());
                ticket* temp = ls->second;
                while(temp)
                {
                	if(tr->stations[temp->to]==ts->from)
                    {
                    	b1=1;
                        ts1=temp;
                    }
                    if(tr->stations[temp->to]<ts->from)
                    {
                        ts11=temp;
                    }
                    if(tr->stations[temp->from]> ts->to)
                    {
                        ts22=temp;
                    }
                    if(tr->stations[temp->from]==ts->to)
                    {
                        b2=1;
                        ts2=temp;
                    }
                    temp=temp->next;
                }
				if(!b1 && b2)
                {
                	ts2->from=ts->from;
                }
                else if(b1 && !b2)
                {
                    ts1->to=ts->to;
                }
                else if(b1 && b2)
                {
                    ts1->to = ts2->to;
                    ts1->next=ts2->next;
                }
                else
                {
                   	if(ts11)
                    {
                    	tickte* temps = ts11->next;
                        ts11->next = ts;
                        ts->next = ts22;
                    }
                }
				delete pass;
                cout<<"ticket cancellation successful"<<endl;
                return;
                ls++;
           	}
        }
	}
}
