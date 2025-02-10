#include<iostream>
using namespace std;

class GroceryStore{
	private:
	string itemname[20];
	float itemprice[20];
	int count;
	
	public:
		GroceryStore(){
			count = 0;
		}
		
		void additem(string name,int price){
			if(count >= 50){
				return;
			}
			
			int found = 0;
			
			for(int i = 0; i < count; i++){
				if(name == itemname[i]){
					cout << "Item is already existed." << endl;
					found = 1;
					return;
				}
			}
			if(!found){
				itemname[count] = name;
				itemprice[count] = price;
				cout << "Item is added to the list." << endl;
				count ++;
				if(count == 50){
					cout << "List capacity is full." << endl;
				}
			}
		}
		
		void viewinventory(){
			cout<<"Inventory Management System"<<endl;
			for(int i = 0; i < count; i++){
				cout << "Item " << i+1 << endl;
				cout << "Name: " << itemname[i] << endl;
				cout << "Item " << i+1 << endl;
				cout << "Price: " << itemprice[i] << endl;	
			}	
		}
		
		void updateprice(string name, int newprice){
			int found = 0;
			for(int i = 0; i < count; i++){
				if(itemname[i] == name){
					itemprice[i] = newprice;
					cout << "Item price is update!" << endl;
					found = 1;
					break;
				}
			}
			if(!found){
				cout << "Item is not found." << endl;
			}
		}
		
		void receipt(int quantity){
			int found;
			int total;
			float Tsum = 0;
			string name;
			cin.ignore();
			for(int i = 1; i <= quantity; i++){
				found = 0;
				cout << "Enter the name of item:";
				getline(cin,name);
				cout<<"Enter the quantity of item:";
				cin>>total;
				cin.ignore();
				for(int j = 0;j < this -> count; j++){
					if(itemname[j] == name){
						float sum = 0;
						sum += itemprice[j] * total;
						Tsum += sum;
						found = 1;
						cout << itemname[j] << " x " << total << " = " << sum << " PKR" << endl;
                		found = 1;
                		break;
					}
				}
				if(!found){
					cout << "Item is not found." << endl;
				}
			}
		cout<<"RECEIPT"<<endl;
        cout<<"Total Bill: "<< Tsum << " PKR" << endl;
		}
		
};

int main(){
	GroceryStore gclist;
	int price;
	int choice;
	string name;
	cout<<"Welcome to the Grocery Shop List!"<<endl;
	while(1){
		cout << "\nMENU" << endl;
		cout << "1. Add item" << endl;
		cout << "2. Update price" << endl;
		cout << "3. Display items" << endl;
		cout << "4. Generate receipt" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter the choice:";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Enter the name of item:";
				cin.ignore();
				getline(cin,name);
				cout << "Enter the price of item:";
				cin >> price;
				gclist.additem(name,price);
				break;
				
			case 2:
				cout << "Enter the name of item:";
				cin.ignore();
				getline(cin,name);
				cout << "Enter the new price of item:";
				cin >> price;
				gclist.updateprice(name, price);
				break;
				
			case 3:
				gclist.viewinventory();
				break;
				
			case 4:
				int quantity;
				cout << "Enter the quantity of different things to buy:";
				cin >> quantity;
				if(quantity <= 50){
					gclist.receipt(quantity);
				}
				else{
					cout << "Please enter valid quantity." << endl;
				}
				break;
				
			case 5:
				cout << "Exiting......" << endl;
				return 0;
				break;
				
			default:
				cout << "Invalid choice!" << endl;
		}
	}
}