/*
Q5: Design Event Management System in C++ to facilitate the organization of
events. The program should empower the user to seamlessly manage event
details, including the event name, date, venue, and organizer. Incorporate key
features such as the ability to add events, display comprehensive details of all
events, and perform event searches based on specific dates. To enhance
flexibility and scalability, leverage dynamic memory allocation for storing event
details.
1. Prompt the user to input the total number of events they wish to manage.
2. Dynamically allocate memory to store event details for the specified
number of events.
3. For each event, prompt the user to input:
 Event Name
 Date
 Venue
 Organizer
4. Display all events that match the provided date, including their complete
details.
5. Allow the user to search for events based on a specific date.
*/

#include <iostream>
using namespace std;

typedef struct{
    string name;
    string date;
    string venue;
    string organizer;
}event;

int initialise(event **p){
    int n;
    cout<<"Enter number of events: ";
    cin>>n;
    *p=new event[n];
    for (int i=0; i<n; i++){
        cout<<"\nEnter details for event "<< i+1<<endl;
        cout<<"Enter Event name: ";
        cin>>(*p)[i].name;
        cout<<"Enter date in format (dd/mm/yy): ";
        cin>>(*p)[i].date;
        cout<<"Enter Event venue: ";
        cin>>(*p)[i].venue;
        cout<<"Enter Event organizer: ";
        cin>>(*p)[i].organizer;
    }
    return n;
}

void display_record(event p){
    cout<<"\nEvent Name: "<< p.name;
    cout<<"\nDate: "<<p.date;
    cout<<"\nVenue: "<<p.venue;
    cout<<"\nOrganizer: "<<p.organizer;
}

void search_event(event *p, int num){
    string date;
    int found=0;
    cout << "Enter date in format (dd/mm/yy): ";
    cin >> date;
    for (int i=0; i<num; i++){
        if (p[i].date==date) {
            found=1;
            display_record(p[i]);
        }
    }
    if (found==0) cout<<"No record found";
}

void display_all(event *p, int num){
    for (int i=0; i<num; i++){
        cout << endl;
        display_record(p[i]);
    }
}

int add_record(event **p, int num){
    static event *c= new event[num+1];
    for (int i=0; i<num; i++){
        c[i]=(*p)[i];
    }
    cout<<"Enter Event name: ";
    cin>>c[num].name;
    cout<<"Enter date in format (dd/mm/yy): ";
    cin>>c[num].date;
    cout<<"Enter Event venue: ";
    cin>>c[num].venue;
    cout<<"Enter Event organizer: ";
    cin>>c[num].organizer;
    delete [](*p);
    *p=c;
    return num+1;
}

int menu(event *p, int num){
    while (true){
        cout << "\n-----Menu-----\n";
        cout << "Press 1 to add a new event\nPress 2 to display all events\nPress 3 to search for a event\n";
        int c;
        cin >> c;
        switch (c){
            case 1:
                num = add_record(&p, num); continue;;
            case 2:
                display_all(p, num); continue;
            case 3:
                search_event(p, num); continue;
            default:
                return num;
        }
    }
    
}

int main(){
    event *p=NULL;
    int num_of_events;
    num_of_events=initialise(&p);
    num_of_events=menu(p, num_of_events);
}