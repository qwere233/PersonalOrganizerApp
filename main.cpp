#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct task{
	string Name;
	string Date;
	int Time;
	string Note;
	string Status;
	string Type;
	
};
task Tasks[100];
task Events[100];
int TaskCount = 0;
int EventCount = 0;
void clearScreen() {
    system("cls");}
void pauseAndClear() {
    cout << "\nPress Enter to continue...";
    cin.ignore(); 
    cin.get();    
    clearScreen();
}   // FUNCTIONS DECLAERATIONS
	void addTask() { // FUNCTION FOR ADDING TASK
		try {
		
    		if (TaskCount >= 100){
    			throw runtime_error("Limit Reached");
    		
		}
			cout<<"Enter Task\n";
			cout<<"Enter Your Name: \n";
			cin>>Tasks[TaskCount].Name;
				cout<<"Enter Date: \n";
			cin>>Tasks[TaskCount].Date;
				cout<<"Enter time: \n";
			cin>>Tasks[TaskCount].Time;
				cout<<"Enter Note(if any): \n";
			cin>>Tasks[TaskCount].Note;
			cout<<"Mark Task as completed/Pending\n";
			cin>>Tasks[TaskCount].Status;
			// USING FOR LOOP
			for (int i = 0; i < TaskCount; i++) {
    if (Tasks[i].Date == Tasks[TaskCount].Date && Tasks[i].Time == Tasks[TaskCount].Time) {
        cout << "??  Warning: You already have something at " << Tasks[TaskCount].Time << " on " << Tasks[TaskCount].Date << "!\n";
        break;
    }
}
			TaskCount++; // INCREMENTATION
		}catch(const exception& e) {
        cout << "? Error: " << e.what() << endl;
    }
		}
		void addEvent() { // MAKING ADDEVENT FUNCTION
		try {
		
    		if (EventCount >= 100){   // ERROR EXCEPTION HANDLING
    			throw runtime_error("Limit Reached");
    		
		}
			cout<<"Enter Event\n";
			cout<<" Enter Event Name: \n";
			cin>>Events[EventCount].Name;
				cout<<"Enter Date: \n";
			cin>>Events[EventCount].Date;
				cout<<"Enter Event Detail(if any): \n";
			cin>>Events[EventCount].Note;
			cout<<"Event Added Succesfully!";
			EventCount++;
		}catch(const exception& e) {
        cout << "? Error: " << e.what() << endl;
    }
		}
		void ViewTask(){ // MAKING VIEWTASK FUNCTION
			try{
			
			if (TaskCount >= 100){
    			throw runtime_error("No Task Available");
    		
		}
		string date;
				cout<<"Enter Date: \n";
			cin>>date;
		for (int i = 0; i < TaskCount; i++){
		
			if (Tasks[i].Date == date){
			
				cout<<"Detail of Task is  "<<"\nName: "<<Tasks[i].Name<<"\nDate: "<<Tasks[i].Date<<"\nTime: "<<Tasks[i].Time<<"\nNote: "<<Tasks[i].Note<<"\nStatus: "<<Tasks[i].Status<<endl;
			}
		}
		}catch (const exception& e) {
        cout << "? Error: " << e.what() << endl;
		}
}
	void ViewEvent(){   // MAKING VIEWEVENT FUNCTION 
			try{
			
			if (EventCount >= 100){
    			throw runtime_error("No Event Available");
    		
		}
		string date;
				cout<<"Enter Date: \n";
			cin>>date;
		for (int i = 0; i < EventCount; i++){
		
			if (Events[i].Date == date){
			
				cout<<"Detail of Event is  "<<"\nEvent: "<<Events[i].Name<<"\nDate: "<<Events[i].Date<<"\nNote: "<<Events[i].Note<<endl;
			}
		}
		}catch (const exception& e) {
        cout << "? Error: " << e.what() << endl;
		}
}
	void ShowDailyActivityPlan(){
		string AddDate;
		int hour;
		cout<<"Input Date to Show Daily Activity Plan\n";
		cout<<"Date: ";
		cin>>AddDate;
		cout<<"\nTime: ";
		cin>>hour;
	
			for(int i = 0;i <TaskCount;i++){
		if (Tasks[i].Date == AddDate && Tasks[i].Time == hour) {
            int h = hour / 100;

            if (h >= 5 && h < 12)
                cout << "Morning:\n";
            else if (h >= 12 && h < 17)
                cout << "Afternoon:\n";
            else if (h >= 17 && h < 21)
                cout << "Evening:\n";
            else
                cout << "    Night   \n";

            cout << "Detail of Task:\n"
                 << "Name: " << Tasks[i].Name
                 << "\nDate: " << Tasks[i].Date
                 << "\nTime: " << Tasks[i].Time
                 << "\nNote: " << Tasks[i].Note << "\n";
        }
			
		}
		
	}

	void MarkTaskAsCompleted(){
		string name,date;
		cout<<"enter Task Name:"<<endl;
		cin>>name;
		cout<<"enter Task Date: "<<endl;
		cin>>date;
		for (int i = 0; i <TaskCount; i++){
			if (Tasks[i].Name == name && Tasks[i].Date == date){
				 Tasks[i].Status = "Completed";
            cout << " Task marked as Completed!\n";
			}
		}
	}
int main(){
	
	int choice;
	while (true){
		  cout<<"======================================";
		  cout << "\n          Personal Organizer \n";
		  cout<<"======================================\n";
        cout << "1. Add Task\n";
        cout << "2. Add Event\n";
        cout << "3. View Tasks by Date\n";
        cout << "4. View Events by Date\n";
        cout << "5. Daily Activity Plan\n";
		cout << "6. Mark Task as Completed\n";
        
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    switch (choice){     // USING SWITCH CASES
	case 1:
    	addTask();
    	pauseAndClear();
    	break;
    case 2:
    	addEvent();
    	pauseAndClear();
    	break;
    case 3:
    	ViewTask();
    	pauseAndClear();
    	
    	break;
    case 4:
    	ViewEvent();
    	break;
    	case 5:
    		ShowDailyActivityPlan();
    		pauseAndClear();
    		break;
    case 6:
    	MarkTaskAsCompleted();
    	pauseAndClear();
    	break;
    case 7:
    	cout<<"GoodBye"<<endl;
    	return 0;
    	break;
    }
	}
	
}
