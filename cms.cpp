#include<iostream>
using namespace std;
class Contact{
    private:
        string name;
        string phoneNo;
        string email;
    public:
        Contact(string n, string p, string e){
            name = n;
            phoneNo = p;
            email = e;
        }
        string getPhone(){
            return phoneNo;
        }
        string getName(){
            return name;
        }
        void display(){
            cout<<"\nNAME: "<<name<<endl;
            cout<<"PHONE NUMBER: "<<phoneNo<<endl;
            cout<<"EMAIL: "<<email<<endl;
        }
};
int main(){
    Contact* contacts[50];
    int count = 0, choice;
    
    do{
        cout<<"\n---Contact List---\n";
        cout<<"1. Add contact\n";
        cout<<"2. View all contacts\n";
        cout<<"3. Search by name\n";
        cout<<"4. Delete contact\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
            case 1:
            {
               string name;
               string phone;
               string email;
               if(count < 50){
                cout<<"Enter the name: ";
                getline(cin, name);
                cout<<"Enter phone number: ";
                getline(cin, phone);
                cout<<"Enter email: ";
                getline(cin, email);
                contacts[count]= new Contact(name, phone, email);
                count++;
               }
               break;
            }

            case 2:
            {
                if(count == 0){
                    cout<<"No contacts available.\n";
                }
                else{
                    for(int i=0;i<count;i++){
                        contacts[i]->display();
                    }
                }
               break;
            }

            case 3:
            {
                string name;
                bool found = false;
                cout<<"Enter name to search: ";
                getline(cin, name);
                for(int i=0; i<count; i++){
                    if(contacts[i]->getName() == name){
                        cout<<"\nName found at "<<i+1;
                        found = true;
                        break;
                    }
                }
                if(found == false){
                    cout<<"NOT FOUND!";
                }
                break;
            }

            case 4:
            {
                string phone;
                bool found = false;
                cout<<"Enter phone number to delete: ";
                getline(cin, phone);
                for(int i = 0; i < count; i++){
                    if(contacts[i]->getPhone() == phone){
                        delete contacts[i];
                        for(int j = i; j<count-1; j++){
                            contacts[j] = contacts[j+1];
                        }
                        count--;
                        found = true;
                        break;
                    }
                }
                if(found == false){
                    cout<<"Phone number is not found to delete";
                }
                break;
            }

            case 5:
                break;
        }
    } while (choice != 5);

    // To free memory space
    for(int i = 0; i < count; i++){
        delete contacts[i];
    } 
    return 0;
}