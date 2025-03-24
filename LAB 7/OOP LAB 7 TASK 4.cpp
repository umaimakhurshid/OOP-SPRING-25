#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
        string name;
		string id;
		string address;
		string phoneNumber;
		string email;
		
    public:
        Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e){}

        virtual void displayInfo(){
            cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
			cout << "Phone: " << phoneNumber << endl;
			cout << "Email: " << email << endl;
        }
        
        string getName(){
        	return name;
		}
		
		void updateInfo(){
            cout << "\nUpdating Info for: " << name << endl;
            cout << "Enter new address: ";
            cin.ignore();
            getline(cin, address);
            cout << "Enter new phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter new email: ";
            getline(cin, email);
            cout << "Information updated successfully!";
    }
    
    virtual ~Person(){}

};

class Student : public Person{
    private:
        string coursesEnrolled;
        double GPA;
        int enrollmentYear;
        
    public:
        Student(string n, string i, string a, string p, string e, string c, double g, int y) : Person(n, i, a, p, e), coursesEnrolled(c), GPA(g), enrollmentYear(y){}

        void displayInfo() override{
            Person :: displayInfo();
            cout << "Courses Enrolled: " << coursesEnrolled << endl;
			cout << "GPA: " << GPA << endl;
			cout << "Enrollment Year: " << enrollmentYear << endl;
        }
};

class Professor : public Person{
    private:
        string department;
        string coursesTaught;
        double salary;
        
    public:
        Professor(string n, string i, string a, string p, string e, string d, string c, double s) : Person(n, i, a, p, e), department(d), coursesTaught(c), salary(s){}

        void displayInfo() override{
            Person :: displayInfo();
            cout << "Department: " << department << endl;
			cout << "Courses Taught: " << coursesTaught << endl;
			cout << "Salary: $" << salary << endl;
        }
};

class Staff : public Person{
    private:
        string department;
        string position;
        double salary;
        
    public:
        Staff(string n, string i, string a, string p, string e, string d, string pos, double s) : Person(n, i, a, p, e), department(d), position(pos), salary(s){}

        void displayInfo() override{
            Person :: displayInfo();
            cout << "Department: " << department << endl;
			cout << "Position: " << position << endl;
			cout << "Salary: $" << salary << endl;
        }
};

class Course{
    private:
        string courseId;
		string courseName;
		string instructor;
		string schedule;
        int credits;
        
    public:
        Course(string id, string name, int cr, string inst, string sch) : courseId(id), courseName(name), credits(cr), instructor(inst), schedule(sch){}

        void registerStudent(Student* student){
            cout << student -> getName() << " has been registered for " << courseName << " (" << courseId << ")" << endl;
        }

        void calculateGrades(){
            cout << "Calculating grades for " << courseName << endl;
        }
};

int main(){
    Student* s1 = new Student("Sara", "S123", "123 Maple St", "555-1234", "sara@mail.com", "Math, Science", 3.8, 2023);
    Professor* p1 = new Professor("Dr. Saim", "P456", "456 Oak St", "555-5678", "saim@mail.com", "CS", "OOP, AI", 85000);
    Staff* staff1 = new Staff("Mr. Sarim", "ST789", "789 Pine St", "555-9012", "sarim@mail.com", "Admin", "Registrar", 60000);
    Course* c1 = new Course("C101", "Object-Oriented Programming", 3, "Dr. John", "MWF 10AM");

    cout << "Student Info" << endl;
    s1 -> displayInfo();  

    cout << "\nProfessor Info" << endl;
    p1 -> displayInfo();

    cout << "\nStaff Info" << endl;
    staff1 -> displayInfo();
    
    s1->updateInfo();

    cout << "\nStudent Info After Update" << endl;
    s1->displayInfo();

    cout << "\nCourse Registration" << endl;
    c1 -> registerStudent(s1);
    c1 -> calculateGrades();

    delete s1;
    delete p1;
    delete staff1;
    delete c1;
    return 0;
}