#include<iostream>
#include<string>
using namespace std;

class FileException{
    public:
        virtual const char* what() const{
            return "FileException";
        }
        
		virtual ~FileException(){}
};

class FileNotFoundException : public FileException{
    public:
        const char* what() const override{
            return "File not found!";
        }
};

class PermissionDeniedException : public FileException{
    public:
        const char* what() const override{
            return "PermissionDeniedException - Access denied!";
        }
};

void readFile(const string& filename){
    if(filename == "missing.txt"){
        throw FileNotFoundException();
    } 
	else if(filename == "secret.txt"){
        throw PermissionDeniedException();
    } 
	else{
        cout << "Reading '" << filename << "' successful!" << endl;
    }
}

int main(){
    string filenames[] = {"data.txt", "missing.txt", "secret.txt"};

    for(const string& file : filenames){
        try{
            readFile(file);
        } 
		catch(const FileException& e){
            cout << "Reading '" << file << "': " << e.what() << endl;
        }
    }
    return 0;
}