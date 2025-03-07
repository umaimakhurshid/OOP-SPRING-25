#include<iostream>
using namespace std;

class Movie{
    private:
        string title;
        string director;
        int duration;
		 
    public:
        Movie(){} 
        Movie(string t, string d, int dur) : title(t), director(d), duration(dur){}

        void display() const{
            cout << "Movie: " << title << endl;
			cout << "Director: " << director << endl; 
            cout << "Duration: " << duration << " minutes" << endl;
        }
};

class CinemaHall{
    private:
        string name;
        Movie movies[10]; 
        int moviecount;   

    public:
        CinemaHall(string n) : name(n), moviecount(0){}

        void addmovie(const Movie& movie){
            if(moviecount < 10){
                movies[moviecount] = movie;
                moviecount++;
            } 
			else{
                cout << "Cannot add more movies. Maximum limit reached!" << endl;
            }
        }

        void displaydetails() const{
            cout << "Cinema Hall: " << name << endl;
            cout << "Movies Currently Screening: " << endl;
            for(int i = 0; i < moviecount; i++){
                movies[i].display();
            }
        }
};

int main(){
    CinemaHall hall("Old Cinema");

    hall.addmovie(Movie("Inception", "Christopher Nolan", 148));
    hall.addmovie(Movie("Interstellar", "Christopher Nolan", 169));
    hall.addmovie(Movie("The Matrix", "Lana & Lilly Wachowski", 136));

    hall.displaydetails();
    return 0;
}
