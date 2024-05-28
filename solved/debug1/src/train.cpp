#include"train.hpp" 
#include"ticket.hpp"
map<string,float> km_fare = {{"2s",0.30},{"sl",0.50},{"3ac",1.25},{"2ac",2},{"1ac",3.5}};
//map<string,vector<string,float>> fares = {{"superfast",{{"2s",150},{"sl",}}},{"express",{}},{"ordinary",{}}};
vector<train*> trains;
train :: train(string name,string type,int number, string time, string org, string dest): 
	trainName(name),trainType(type),trainNumber(number),departureTime(time),origin(org), destination(dest){};
string train:: get_train_name()
{
	return trainName;
}
string train:: get_train_type()
{
	return trainType;
}	
int train:: get_train_number()
{
	return trainNumber;
}
string train:: get_departure_time()
{
	return departureTime;
}
string train:: get_origin()
{
	return origin;
}
string train:: get_destination()
{
	return destination;
}
void train:: set_train_name(string name)
{
	trainName = name;
}
void train:: set_train_type(string type)
{
	trainType = type;
}
void train:: set_train_number(int number)
{
	trainNumber = number;
}
void train:: set_departure_time(string time)
{
	departureTime = time;
}
void train:: set_origin(string org)
{
	origin=org;
}
void train:: set_destination(string dest)
{
	destination = dest;
}
void train:: train_info()
{
	cout<<"Train name: "<<trainName<<endl;
	cout<<"Train type: "<<trainType<<endl;
	cout<<"Train number: "<<trainNumber<<endl;
	cout<<"Train departure time: "<<departureTime<<endl;
	cout<<"origin station: "<<origin<<endl;
	cout<<"Destination station: "<<destination<<endl;
	cout<<"available tickets: "<<endl;
}
void train:: add_sl_ticket(coach* ch)
{
	ticket* t;
	for(int i = 1; i <= 72; i++)
    {
        switch (i % 8)
        {
        	case 1:
            case 4:
				t = new ticket(i,trainName,ch->names,"lower",trainType,origin,destination);
         	    ch->list.emplace_back(i,t);
                break;
           	case 2:
           	case 5:	
				t = new ticket(i,trainName,ch->names,"middle",trainType,origin,destination);
   	 		    ch->list.emplace_back(i,t);
                break;
            case 3:
            case 6:
				t = new ticket(i,trainName,ch->names,"upper",trainType,origin,destination);
				ch->list.emplace_back(i,t);
                break;
           	case 7:
				t = new ticket(i,trainName,ch->names,"sidelower",trainType,origin,destination);	
                ch->list.emplace_back(i,t);
                break;
           	case 0:
				t = new ticket(i,trainName,ch->names,"sideupper",trainType,origin,destination);
                ch->list.emplace_back(i,t);
                break;
        }
    }
}
void train:: add_2s_ticket(coach* ch)
{
	ticket* t;
    for(int i = 1; i <= 108; i++)
    {
    	switch (i % 6)
        {
        	case 1:
			case 0:
            	t = new ticket(i,trainName,ch->names,"window",trainType,origin,destination);
               	ch->list.emplace_back(i,t);
                break;
           	case 2:
            case 5:
                t = new ticket(i,trainName,ch->names,"middle",trainType,origin,destination);
                ch->list.emplace_back(i,t);
                break;
            case 3:
            case 4:
                t = new ticket(i,trainName,ch->names,"side",trainType,origin,destination);
                ch->list.emplace_back(i,t);
                break;
		}
	}
}
void train::add_coach()
{
	int counts;
	string name;
	cout<<"Enter coach details: "<<endl;
	cout<<"Enter sleeper coach count: "<<endl;
	cin>>counts;
	coach* ch;
	for(int i=1;i<=counts;i++)
	{
		name="sl"+to_string(i);
        ch = new coach(name);
        add_sl_ticket(ch);
		sl_coaches.push_back(ch);
	}
	sl_count = counts*72;
	cout<<"Enter sitting coach count: "<<endl;
    cin>>counts;
	for(int i=1;i<=counts;i++)
	{
		name="2s"+to_string(i);
		ch = new coach(name);
		add_2s_ticket(ch);
		s2_coaches.push_back(ch);
	}
	s2_count= counts * 108;
	getchar();
}
int train::add_stations()
{
	int n=1;
	float f;
	string name;
	string check;
	do
	{
		cout<<"Enter station name: "<<endl;
		getline(cin,name);
		cout<<"Enter distance from source: "<<endl;
		cin >> f;
		getchar();
		inter_stations.insert(make_pair(name,f));
		stations.insert(make_pair(name,++n));
		cout<<"ok to add stations !ok to finish "<<endl;
		getline(cin,check);
	}while(check=="ok");
	return n++;
}
void train:: show_tickets(string src,string dest,string cat)
{
    int count=0;
    ticket* temp = nullptr;
    if(cat=="2s")
    {
        goto s;
    }
    else if(cat=="sl")
    {
        goto sl;
    }
    s:

    for(auto& coach : s2_coaches)
    {
        for(vector<pair<int, ticket*>>::iterator ls = coach->list.begin(); ls != coach->list.end();)
        {
            if(ls->second)
            {
                temp = ls->second;
                while(temp)
                {
                    // cout << "stations[src] " << stations[src] << endl;
                    // cout << "stations[temp->from] " << stations[temp->from] << endl;
                    // cout << "stations[temp->to] " << stations[temp->to] << endl;
                    // cout << "stations[dest] " << stations[dest] << endl;
                    if(stations[src]>=stations[temp->from] && stations[dest]<=stations[temp->to])
                    {
                        // cout << "inside " << count << endl;
                        count++;
                        goto re1;
                    }
                    temp =temp->next;
                }
                // ls++;
            }
            re1:
            ls++;
        }
    }
    cout<<"2s tickets: "<<count<<endl;
    return;
    sl:
    count=0; // This will reset the count value to 0 before the next loop
    for(auto& coach : sl_coaches)
    {
        for(vector<pair<int, ticket*>>::iterator ls = coach->list.begin(); ls != coach->list.end();)
        {
            if(ls->second)
            {
                temp = ls->second;
                while(temp)
                {
                    if(stations[src]>=stations[temp->from] && stations[dest]<=stations[temp->to])
                    {   
                        count++;
                        goto re2;
                    }
                    temp=temp->next;
                }
                // ls++;
            }
            re2:
            ls++;
        }
    }
    cout<<"sl tickets: "<<count<<endl;
}