//I got bored and wrote a very simple bank simulator application

#include <iostream>

class equityBank{
    private:
    int balance = 0;

    public:
    std::string bankName = R"(
┌───────────────────────────────────────────────┐
│ ___           _ _          ___            _   │
│| __|__ _ _  _(_) |_ _  _  | _ ) __ _ _ _ | |__│
│| _|/ _` | || | |  _| || | | _ \/ _` | ' \| / /│
│|___\__, |\_,_|_|\__|\_, | |___/\__,_|_||_|_\_\│
│       |_|           |__/                      │
└───────────────────────────────────────────────┘)";

    
    equityBank(){
        std::cout << bankName << std::endl;

        std::cout << "1. Check Balance\n2. Withdraw\n3. Deposit\n4. Exit\n";
    }


    void checkBalance(){
        std::cout << "Balance:\nKsh." <<balance <<std::endl;
    }

    int withdraw(){
        int amount;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;
        if(amount > balance){
            std::cout << "Insufficient funds! " << std::endl;
        }else if(amount < 0){
            std::cout << "Invalid amount!" << std::endl;
        }
        else{
            balance -= amount;
            std::cout << "Successfully withdrawn Ksh. " << amount << std::endl;
        }

        return balance;
    }

    int deposit(){
        int depo;
        std::cout << "Enter amount to deposit: ";
        std::cin >>  depo;
        if(depo < 0 ){
            std::cout << "Deposit amount can not be less than Ksh. 0" << std::endl;
        }
        else{
            balance += depo;
            std::cout << "Successfully deposited Ksh." << depo << std::endl;
        }

        return balance;
    }
    void bankOutro(){
        std::string outro1 = R"(
 _____ _                 _                        _ 
|_   _| |__   __ _ _ __ | | __  _   _  ___  _   _| |
  | | | '_ \ / _` | '_ \| |/ / | | | |/ _ \| | | | |
  | | | | | | (_| | | | |   <  | |_| | (_) | |_| |_|
  |_| |_| |_|\__,_|_| |_|_|\_\  \__, |\___/ \__,_(_)
                                |___/   
        )";

        std::string outro2 = R"(
  __            
 / _| ___  _ __ 
| |_ / _ \| '__|
|  _| (_) | |   
|_|  \___/|_|   
              
        )";
        std::string outro3 = R"(
       _     _ _   _                         _ 
__   _(_)___(_) |_(_)_ __   __ _   _   _ ___| |
\ \ / / / __| | __| | '_ \ / _` | | | | / __| |
 \ V /| \__ \ | |_| | | | | (_| | | |_| \__ \_|
  \_/ |_|___/_|\__|_|_| |_|\__, |  \__,_|___(_)
                           |___/
        )";
        std::cout << outro1 << std::endl;
        std::cout << outro2 << std::endl;
        std::cout << outro3 << std::endl;
    }
};

int main(){

    equityBank bank;
    int choice;    
    do{
        std::cout << std::endl;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;
        switch(choice){
            case 1:
                bank.checkBalance();
                break;
            case 2:
                bank.withdraw();
                break;
            case 3:
                bank.deposit();
                break;
            case 4:
                bank.bankOutro();
                break;
            default:
                std::cout << "Invalid choice! Please select 1-4\n";
                std::cin.clear();
                std::cin.ignore(100000, '\n');
        }
    }while(choice != 4);

}