#include<iostream>
#include<string>
using namespace std;

class Media{
    protected:
        string title;
        string publicationDate;
        string uniqueID;
        string publisher;

    public:
        Media(string t, string pubdate, string id, string pub): title(t), publicationDate(pubdate), uniqueID(id), publisher(pub){}

        virtual void displayInfo(){
            cout << "Title: " << title << endl;
			cout << "Publication Date: " << publicationDate << endl;
            cout << "Unique ID: " << uniqueID << endl;
			cout << "Publisher: " << publisher << endl;
        }

        virtual void checkOut(){
            cout << "Checking out: " << title << endl;
        }

        virtual void returnItem(){
            cout << "Returning: " << title << endl;
        }

        string getTitle(){ 
		return title; 
		}
		
        string getPublicationDate(){ 
		return publicationDate; 
		}
};

class Book : public Media{
    private:
        string author;
        string ISBN;
        int numberOfPages;

    public:
        Book(string t, string pubdate, string id, string pub, string auth, string isbn, int pages): Media(t, pubdate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages){}

        void displayInfo() override{
            Media :: displayInfo();
            cout << "Author: " << author << endl;
			cout << "ISBN: " << ISBN << endl;
			cout << "Pages: " << numberOfPages << endl;;
        }
};

class DVD : public Media{
    private:
        string director;
        int duration;
        double rating;

    public:
        DVD(string t, string pubdate, string id, string pub, string dir, int dur, double rate) : Media(t, pubdate, id, pub), director(dir), duration(dur), rating(rate){}

        void displayInfo() override{
            Media :: displayInfo();
            cout << "Director: " << director << endl;
			cout << "Duration: " << duration << " minutes" << endl;
			cout << "Rating: " << rating << "/10" << endl;
        }
};

class CD : public Media{
    private:
        string artist;
        int numberOfTracks;
        string genre;

    public:
        CD(string t, string pubdate, string id, string pub, string art, int tracks, string gen) : Media(t, pubdate, id, pub), artist(art), numberOfTracks(tracks), genre(gen){}

        void displayInfo() override{
            Media :: displayInfo();
            cout << "Artist: " << artist << endl;
			cout << "Tracks: " << numberOfTracks << endl;
			cout << "Genre: " << genre << endl;
        }
};

void searchMedia(Media* media, string searchTitle){
    if(media -> getTitle() == searchTitle){
        cout << "Media found:";
        media -> displayInfo();
    } 
	else{
        cout << "No media found with title: " << searchTitle << endl;
    }
}

void searchMedia(Media* media, string searchAuthor, bool isBook){
    if (isBook){
    	Book* book = (Book*)media;
        cout << "Book found:" << endl;
        book->displayInfo();
    } 
	else{
        cout << "No book found with author: " << searchAuthor << endl;
    }
}

int main() {
    Book book("C++ Programming", "2020", "B123", "TechPub", "John Doe", "978-1234567890", 450);
    DVD dvd("Inception", "2010", "D456", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd("Thriller", "1982", "C789", "Epic Records", "Michael Jackson", 9, "Pop");

    book.displayInfo();
    dvd.displayInfo();
    cd.displayInfo();

    searchMedia(&book, "C++ Programming");
    searchMedia(&dvd, "Unknown Title");
    searchMedia(&book, "John Doe", true);
    return 0;
}