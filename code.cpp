// DEVELOP AN FULLY FUNCTIONAL ATM INTERFACE USING C++
    

#include <bits/stdc++.h>
using namespace std;

class Account{
    private :
        long int acc_number ;
        int pin;
        double balance;
    public:
        Account(long int acc_num , int pinNum , double bal){
            this->acc_number = acc_num;
            this->pin = pinNum;
            this->balance = bal;
        }
        
        long int getAccountNumber(){
            return this->acc_number;
        }
        int getPin(){
            return this->pin;
        }
        double getBalance(){
            return this->balance;
        }
        
        void deposit(int dep){
            this->balance += dep;
            cout << "You Have Successfully Deposited of Rupees" << dep << "in your Account " << endl; 
        }
        
        void withdraw(int with){
            if(with > this->balance){
                cout << "You have Insuffcient funds in your Account"<<endl;
                
            }
            else{
                this->balance -= with;
                cout<<"You have Successfully Withdrawed Rupees" << with <<"From your Account" << endl; 
            }
        }
        
        void checkBalance(){
            cout << "Your Current Balance is " << this->balance << endl;
        }
    
};

class Atm{
    private:
        vector<Account> accounts;
        Account *loggedinUser ;
    public:
        Atm(){
            loggedinUser = NULL;
            accounts.push_back(Account(1000200030004000 , 1234 , 3000.00));
            accounts.push_back(Account(5000600070008000 , 1234 , 3000.00));
            accounts.push_back(Account(1000200030004000 , 1234 , 3000.00));
            
        }
        
        bool Authenticate(){
            long int enteredAcc;
            long int enteredPass;
            cout<<"Enter Account Number"<<endl;
            cin>>enteredAcc;
            cout<<"Enter Four Digit Pin Number"<<endl;
            cin>>enteredPass;
            
            for(auto& acc : accounts){
                if(acc.getAccountNumber() == enteredAcc && acc.getPin() == enteredPass){
                    cout << "Logged in Successfully" <<endl;
                    loggedinUser = &acc;
                    return true;
                }
                
                
            }
            cout<<"The Entered Details are Incorrect !! Please Try Again" << endl;
                return false;
        }
        
        void menu(){
            int choice;
            do{
                cout<<"----- ATM Menu -----"<<endl;
                cout<<"1. Check Balance" <<endl;
                cout<<"2. Depost Money" <<endl;
                cout<<"3. Withdraw Money" <<endl;
                cout<<"4. Logout" <<endl;
                cout<<"Enter Your Choice" << endl;
                cin>> choice;
                
                
                switch(choice){
                    case 1 : 
                        loggedinUser->checkBalance();
                        break;
                    case 2 :
                        depositMenu();
                        break;
                        
                    case 3:
                        withdrawMenu();
                        break;
                    case 4 : 
                        cout <<"Logging Out.."<<endl;
                        loggedinUser=NULL;
                        break;
                    default :
                        cout << "Invalid Details entered"<<endl;
                        break;
                }
            }while(choice != 4);
            
            
        }
        void depositMenu(){
                double amount;
                cout <<"Enter the Amount :" <<endl;
                cin>>amount;
                if(amount>0){
                loggedinUser->deposit(amount);
                }
                else{
                    cout<<"Invalid Amount entered" <<endl;
                }
            }
            
            void withdrawMenu(){
                int amount ;
                cout <<"Enter the amount to Withdraw"<<endl;
                cin>>amount;
                
                if(amount>0){
                    loggedinUser->withdraw(amount);
                }
                else{
                    cout<<"Invalid Amount Entered" <<endl;
                }
            }
            
            void run(){
                cout << "Welcome to ATM " << endl;
                if(Authenticate()){
                    cout <<"Login Successfull"<<endl;
                    menu();
                }
            }
    
};

int main()
{
    Atm City;
    City.run();
    return 0;
}
