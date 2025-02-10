#include<iostream>
using namespace std;

class Planner{
	private:
	string tasks[12][31];
	
	public:
		Planner(){
			for(int i = 0; i < 12; i++){
				for(int j = 0; j < 31; j++){
					if(i == 1 && j > 27){
						tasks[i][j] = "Not Accessible!";
					}
					else{
					    tasks[i][j] = "No Task is Added!";
					}
				}
			}
		}
		
		void addtask(int month, int day, string task){
			int check = 0;
			if(day < 1 || day > 31 || month < 1 || month > 12){
				cout << "Invalid input! Please choose the correct month(1-12) and day(1-31)." << endl;
				check = 1;
			}
			if(month == 2 && day > 28){
					cout << "February has 28 days only!" << endl;
					check = 1;
			}
			if(check == 0){
			    if(tasks[month-1][day-1] != "No Task is Added!"){
				    cout << "Task has already been added." << endl;
			    }
			    else{
				    tasks[month-1][day-1] = task;
				    cout << "Task is added!" << endl;
			    }
			}
		}
		
		void removetask(int month, int day){
			int check = 0;
			if(day < 1 || day > 31 || month < 1 || month > 12){
				cout << "Invalid input! Please choose the correct month(1-12) and day(1-31)." << endl;
				check = 1;
			}
			if(month == 2 && day > 28){
				check = 1;
			}
			if(check == 0){
			    if(tasks[month-1][day-1] != "No Task is Added!"){
				    tasks[month-1][day-1] = "No Task is Added!";
				    cout << "Task is Removed." << endl;
			    }
			    else{
				    cout << "No task to remove." << endl;
			    } 
		    }
		}
		
		void update(int month,int day,string task){
			int invalid = 0;
			if(day < 1 || day > 31 || month < 1 || month > 12){
				cout << "Invalid input! Please choose the correct month(1-12) and day(1-31)." << endl;
				invalid = 1;
			}
			if(month == 2 && day > 28){
					cout << "February has 28 days only!" << endl;
					invalid = 1;
			}
			if(!invalid){
				tasks[month-1][day-1] = task;
				cout << "Task is updated!" << endl;
			}
		}
		
		void display(){
			for(int i = 0; i < 12; i++){
				for(int j = 0; j < 31; j++){
					if(i == 1 && j > 27){
					    continue;
					}
					else if(tasks[i][j] != "No Task is Added!"){
						cout << "Month: " << i+1 << "\nDay: " << j+1 << "\nTask: " << tasks[i][j] << endl;
					}
				}
			}
			cout<<"All Added Tasks are Displayed."<<endl;
		}
};

int main(){
	Planner planner;
	int month;
	int day;
	int choice;
	string task;
	cout << "Welcome to the Planner!" << endl;
	while(1){
		cout << "\nMENU" << endl;
		cout << "1. Add Task" << endl;
		cout << "2. Remove Task" << endl;
		cout << "3. Update Task" << endl;
		cout << "4. Display Task" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter the month:";
				cin >> month;
				cout << "Enter the day:";
				cin >> day;
				cout << "Enter the task to be added:";
				cin.ignore();
				getline(cin, task);;
				planner.addtask(month, day, task);
				break;
				
			case 2:
				cout << "Enter the month:";
				cin >> month;
				cout << "Enter the day:";
				cin >> day;
				planner.removetask(month, day);
				break;
				
			case 3:
				cout << "Enter the month:";
				cin >> month;
				cout << "Enter the day:";
				cin >> day;
				cout << "Enter the task to be updated:";
				cin.ignore();
				getline(cin, task);
				planner.update(month, day, task);
				break;
				
			case 4:
				planner.display();
				break;
				
			case 5:
				cout << "Exiting......" << endl;
				return 0;
				break;
				
			default:
				cout << "Invalid choice!" << endl;
		}
	}
}