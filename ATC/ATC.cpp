#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
//Algorithms
//1.landing
//2.take off
//3.when take off and landing occur at the same time
// {
//
//    if(arrival time ==depature time and take off flight has emergency and landing  flight has no emergency)
//  	{
//      take off
//      after 5 sec
//      landing
//		}
//    else
//		{
//	    landing
//	    after 5 sec
//	    takeoff
//		}
//	}
//3.display
//4.exit

struct flight{
	string fl_no;
	string fl_nm;
	float arrival_tm;
	float departure_tm;
	bool emergency;
	flight(string flight_no,string flight_name,float arrival_time,float departure_time,bool emer){
		fl_no=flight_no;
		fl_nm=flight_name;
		arrival_tm=arrival_time;
		departure_tm=departure_time;
		emergency=emer;
	}
};
struct cmp{
	bool operator()(flight  * p1, flight  *p2)
	{
		if(p1->departure_tm!=p2->departure_tm)
		  return p1->departure_tm>p2->departure_tm;
		return p1->emergency<p2->emergency;
	}
};
priority_queue<flight *, vector<flight*>,cmp> q;

void landing(){
	string flight_no,flight_name;
	float arrival_time,departure_time;
	bool emergency;
	cout<<" Enter flight no,flight name,arrival time,departure time:\n";
	cin>>flight_no>>flight_name>>arrival_time>>departure_time;
	cout<<" Is there any priority or not: ";
	cin>>emergency;
	flight *f=new flight(flight_no,flight_name,arrival_time,departure_time,emergency);
	
	cout<<"flight landed successfully\n";
	q.push(f);
 }

void take_off(){
	bool z;
	cout<<"Do u want to take off new flight<1:Yes/0:No>: ";
	cin>>z;
	if(z==1){
		string flight_no,flight_name;
		float arrival_time,departure_time;
		bool emergency;
		cout<<" Enter flight no,flight name,arrival time,departure time:\n";
		cin>>flight_no>>flight_name>>arrival_time>>departure_time;
		cout<<" Is there any priority or not: ";
		cin>>emergency;
		flight *f=new flight(flight_no,flight_name,arrival_time,departure_time,emergency);
		flight *x=q.top();
		if(f->arrival_tm==x->departure_tm){
			
			if(f->emergency==0 && x->emergency==1){
			  q.pop();
		      cout<<"flight takeoff successfully\n";
		      Sleep(5000);
		      
		      q.push(f);
			  cout<<"flight landed successfully\n";	
			}
			else{
			  q.push(f);
			  cout<<"flight landed successfully\n";
	
		      q.pop();
		      Sleep(5000);
		      cout<<"flight takeoff successfully\n";
			}
		}
		else{
		q.push(f);
		cout<<"flight takeoff successfully\n";
		q.pop();
		}
	}
	else{
	cout<<"flight takeoff successfully\n";
	q.pop();
    }
}

void display(){
	priority_queue<flight *, vector<flight*>,cmp> q1;
	cout<<"flight_no\t\tflight_name\t\tarrival_time\t\tdeparture_time\t\temergency\n";
	while(!q.empty()){
		flight *temp=q.top();
		cout<<temp->fl_no<<"\t\t\t"<<temp->fl_nm<<"\t\t\t"<<temp->arrival_tm<<"\t\t\t"<<temp->departure_tm<<"\t\t\t"<<temp->emergency<<"\n";
		q.pop();
		q1.push(temp);
	}
	swap(q1,q);	
}

int main(){
	cout<<"Flight operation\n  1. Landing flight\n  2. Take off flight\n  3. Print\n  4. Exit\n";
	while(1){
		int n;
		cout<<"Enter your choice: ";
		cin>>n;
		switch(n){
			case 1:
				landing();   // landing
				break;
			case 2:
				take_off();   // take off
				break;
			case 3:
				display();   // display
				break;
			case 4:
				exit(0);   // exit
				break;
			default:
				cout<<"Choose appropriate choice\n";
				break;	
		}
	}
	return 0;
}

