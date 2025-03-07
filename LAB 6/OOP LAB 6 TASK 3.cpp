#include<iostream>
using namespace std;

class Person{
	protected:
		string name;
		int age;
	
	public:
		Person(string n, int a) : name(n), age(a){}
		virtual void displayDetails(){
		cout << "\nName: " << name << endl;
		cout << "Age: " << age << endl;	
		}
};

class Teacher : virtual public Person{
	protected:
		string subject;
	
	public:
		Teacher(string n, int a, string s): Person(n,a), subject(s){}
		void displayDetails() override{
			Person :: displayDetails();
			cout << "Subject: " << subject << endl;
		}
};

class Researcher : virtual public Person{  
    private:
        string researchArea;
        
    public:
        Researcher(string n, int a, string rA) : Person(n, a), researchArea(rA){}
        void displayDetails() override{
            Person::displayDetails();
            cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher{  
    private:
        int publications;
        
    public:
        Professor(string n, int a, string s, string rA, int p) : Person(n, a), Teacher(n, a, s), Researcher(n, a, rA), publications(p){}
        void displayDetails() override{
            Teacher::displayDetails();
            cout << "Research Area: " << researchArea << endl;
            cout << "Publications: " << publications << endl;
    }
};

int main(){
    string name;
    int age;
	string subject;
	string researchArea;
	int publications;

    cout << "Enter the professor's name: ";
    cin >> name;
    cout << "Enter the age: ";
    cin >> age;
    cout << "Enter the subject: ";
    cin >> subject;
    cout << "Enter the research area: ";
    cin >> researchArea;
    cout << "Enter the number of publications: ";
    cin >> publications;

    Professor prof(name, age, subject, researchArea, publications);
    cout << "\nProfessor Details:";
    prof.displayDetails();
    return 0;
}
