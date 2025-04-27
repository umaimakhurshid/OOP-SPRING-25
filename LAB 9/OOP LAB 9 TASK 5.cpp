#include<iostream>
using namespace std;

class Activity{
    public:
        virtual void calculateCaloriesBurned() = 0;
};

class Running : public Activity{
    private:
        double distance; 
        double time;   
    
	public:
        Running(double d, double t){
            distance = d;
            time = t;
        }
    
        void calculateCaloriesBurned(){
            double calories = distance * 60; 
            cout << "Running: You burned " << calories << " calories." << endl;
        }
};

class Cycling : public Activity{
    private:
        double speed; 
        double time;
    
	public:
        Cycling(double s, double t){
            speed = s;
            time = t;
        }
    
	    void calculateCaloriesBurned(){
            double calories = speed * time * 5; 
            cout << "Cycling: You burned " << calories << " calories." << endl;
        }
};

int main(){
    Running r(5.0, 30.0);  
    Cycling c(20.0, 1.0); 
    
    r.calculateCaloriesBurned();
    c.calculateCaloriesBurned();
    return 0;
}