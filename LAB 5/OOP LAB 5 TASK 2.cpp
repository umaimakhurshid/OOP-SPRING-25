#include<iostream>
#include<string>
using namespace std;

class Patient{
    private:
        int id;
        string name;
        int* testresults;
        int numtests;

    public:
        Patient(int patientID, string patientname, int tests[], int num){
        id = patientID;
        name = patientname;
        numtests = num;

        testresults = new int[numtests];
        for(int i = 0; i < numtests; i++){
            testresults[i] = tests[i];
        }
    }

    Patient(const Patient &patient){
        id = patient.id;
        name = patient.name;
        numtests = patient.numtests;
        
        testresults = new int[numtests];
        for(int i = 0; i < numtests; i++){
            testresults[i] = patient.testresults[i];
        }
    }

    void display(){
        cout << "Patient ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Test Results: ";
        
        for(int i = 0; i < numtests; i++){
            cout << testresults[i] << " ";
        }
    }

    ~Patient(){
        delete[] testresults;
    }
};

int main(){
    int tests[] = {47, 62, 85, 23, 91};
    int numtests = 5;

    Patient patient1(046, "Sarim Imran", tests, numtests);
    cout << "Original Patient Details" << endl;
    patient1.display();

    Patient patient2(patient1);
    cout << "\nCopied Patient Details" << endl;
    patient2.display();
    return 0;
}