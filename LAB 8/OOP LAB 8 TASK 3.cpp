#include<iostream>
using namespace std;

class Teacher;

class Student{
	private:
        string name;
        int grades[3];

    public:
        Student(string n, int g1, int g2, int g3){
            name = n;
            grades[0] = g1;
            grades[1] = g2;
            grades[2] = g3;
        }
        
    friend class Teacher;
    friend float calculateAverageGrade(Student s);
};

class Teacher{
    public:
        void updategrade(Student &s, int index, int newgrade){
            if(index >= 0 && index < 3){
                    s.grades[index] = newgrade;
            }
		}

        void displaygrades(Student s){
            cout << "Grades: ";
            for(int i = 0; i < 3; i++){
                cout << s.grades[i] << " ";
            }
            cout << endl;
        }
};

float calculateAverageGrade(Student s){
    float sum = 0;
    for(int i = 0; i < 3; i++){
        sum += s.grades[i];
    }
    return sum / 3.0;
}

int main(){
    Student s("Sara", 94, 82, 73);
    Teacher t;
    t.displaygrades(s);
    cout << "Average: " << calculateAverageGrade(s) << endl;
    
    cout << "After Upgrade:" << endl;
	t.updategrade(s, 1, 91);
    t.displaygrades(s);
    cout << "New Average: " << calculateAverageGrade(s) << endl;
    return 0;
}