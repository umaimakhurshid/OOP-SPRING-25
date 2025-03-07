#include<iostream>
using namespace std;

class Employee{
	protected:
		string name;
		float salary;
	
	public:
		Employee(string n, float s) : name(n), salary(s){}
		virtual void displayDetails(){
		cout << "\nName: " << name << endl;
		cout << "Salary: $" << salary << endl;	
		}
};

class Manager : public Employee{
	private:
		float bonus;
	
	public:
		Manager(string n, float s, float b): Employee(n,s), bonus(b){}
		void displayDetails() override{
			Employee :: displayDetails();
			cout << "Bonus: $" << bonus << endl;
		}
};

int main(){
	string name;
	float salary;
	float bonus;
	
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the salary: $";
	cin >> salary;
	cout << "Enter the bonus: $";
	cin >> bonus;
	Manager m1(name,salary,bonus);
	cout << "Manager Details:";
	m1.displayDetails();
	return 0;
}
