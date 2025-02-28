#include<iostream>
#include<string>
using namespace std;

class Professor{
    private:
        string name;
        string department;

    public:
        Professor(string n, string dept){
        	name = n;
			department = dept;
		}

    void display(){
        cout << "Professor Name: " << name << endl;
		cout << "Department: " << department << endl;
    }
};

class University{
    private:
        string name;
        Professor** professors;
        int professorcount;

    public:
    University(string uniname){
    	name = uniname;
		professorcount = 0;
        professors = new Professor*[100];
    }

    void add(string profname, string department){
        professors[professorcount] = new Professor(profname, department);
        professorcount++;
    }

    void display(){
        cout << "University Name: " << name << endl;
        cout << "List of Professors" << endl;
        for(int i = 0; i < professorcount; i++){
            professors[i] -> display();
        }
    }

    ~University(){
        for(int i = 0; i < professorcount; i++){
            delete professors[i];
        }
        delete[] professors;
    }
};

int main(){
    University uni("FAST University");

    uni.add("Shehzad Mirza", "Computer Science");
    uni.add("Sara Alam", "AI");
    uni.add("Bakhtawar Jamil", "Software Engineering");

    uni.display();
    return 0;
}