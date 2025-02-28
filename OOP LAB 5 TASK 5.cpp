#include<iostream>
using namespace std;

class TourGuide{
    private:
        string name;
        int yearsofexperience;
        string specialization;

    public:
        TourGuide(string guidename, int experience, string spec){
        	name = guidename;
			yearsofexperience = experience;
			specialization = spec;
		}

    void display() const{
        cout << "Name: " << name << endl;
        cout << "Experience: " << yearsofexperience << " years" << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class TravelAgency{
    private:
        string agencyname;
        TourGuide** guides;  
        int guidecount;
        int capacity;

    public:
        TravelAgency(string name, int maxguides){
        	agencyname = name;
			guidecount = 0;
			capacity = maxguides;
            guides = new TourGuide*[capacity];  
    }

    void hire(TourGuide* guide){
        if(guidecount < capacity){
            guides[guidecount++] = guide;
        } 
		else{
            cout << "Cannot hire more guides. Capacity reached!" << endl;
        }
    }

    void display() const{
        cout << "Travel Agency: " << agencyname << endl;
        cout << "Hired Tour Guides" << endl;
        for(int i = 0; i < guidecount; i++){
            guides[i] -> display();
        }
    }

    ~TravelAgency(){
        delete[] guides;
    }
};

int main(){
    TourGuide* guide1 = new TourGuide("Sarim", 5, "Historical Tours");
    TourGuide* guide2 = new TourGuide("Sara", 3, "Adventure Tours");
    TourGuide* guide3 = new TourGuide("Saif", 7, "Wildlife Safaris");

    TravelAgency agency("Explore The World", 5);

    agency.hire(guide1);
    agency.hire(guide2);
    agency.hire(guide3);
    agency.display();

    delete guide1;
    delete guide2;
    delete guide3;
    return 0;
}