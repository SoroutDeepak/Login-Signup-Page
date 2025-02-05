#include<iostream>
#include<fstream>
#include<string>
using namespace std;


    class temp{
        string userName, Email, password;
        string searchName,searchPass,searchEmail;
        fstream file;
        public:
        void login();
        void signUP();
        void forgot();

    }obj;


int main() {
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sign-up";
    cout<<"\n3- Forgot Password";
    cout<<"\n4- Exit";
    cout<<"\nEnter Your Choice :: ";
    cin>>choice;

    

    switch(choice){
        case '1':
            cin.ignore();
            obj.login();
        break;
        case '2':
            cin.ignore();
            obj.signUP();
        break;
        case '3':
            cin.ignore();
            obj.forgot();
        break;
        case '4':
            return 0;
        break;
        defualt:
            cout<<"Invalid Selection...!";
    }
}

void temp :: signUP() {
    cout<<"\nEnter the user name: ";
    getline(cin,userName);
    cout<<"Enter your Email Address :: ";
    getline(cin,Email);
    cout<<"Enter Your Password :: ";
    getline(cin,password);

    file.open("LoginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp :: login() {
    
    cout<<"---------Login------"<<endl;
    cout<<"Enter User Name :: "<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin,searchPass);


    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');

    while(!file.eof()){
        if(userName==searchName){
            if(password == searchPass){
                cout<<"\nAccount login Successfully ...!";
                cout<<"\nUsername::"<<userName<<endl;
                cout<<"\nEmail::"<<Email<<endl;  
            }
            else{
                cout<<"Password is Incorrect...!"<<endl;
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
    }
    file.close();
    
}

void temp :: forgot(){
    cout<<"\nEnter Your UserName :: ";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName == searchName){
            if(Email == searchEmail){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password :: "<<password<<endl;
            }else{
                cout<<"Not found...!\n";
            }
        }else{
            cout<<"\nNot fount...!\n";
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
    file.close();
}