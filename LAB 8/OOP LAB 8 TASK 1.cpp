#include<iostream>
using namespace std;

class Humidity;

class Temperature{
	private:
        float temp;
        
    public:
        Temperature(float t){
            temp = t;
    }
    
    friend float calculateHeatIndex(Temperature, Humidity);
};

class Humidity{
	private:
    
	    float humidity;
    public:
        Humidity(float h){
            humidity = h;
    }
    
    friend float calculateHeatIndex(Temperature, Humidity);
};

float calculateHeatIndex(Temperature t, Humidity h){
    return t.temp + 0.1 * h.humidity;
}

int main(){
    Temperature t(25);
    Humidity h(57);
    float heatindex = calculateHeatIndex(t, h);
    cout << "Heat Index: " << heatindex << endl;
    return 0;
}