#include <iostream>
#include <vector>
#include <string>


class Sandwitch{
    public: 
        static Sandwitch *make_sandwitch(std::string choice);

        virtual void meatChoice() = 0;

        virtual ~Sandwitch() = default;

};

class Ham: public Sandwitch{
    public:
    void meatChoice(){
        std::cout << "a perfectly made ham sandwhich.\n";
    }

};

class Turkey: public Sandwitch{
    public:
    void meatChoice(){
        std::cout << "a loveable turkey sandwhich.\n";
    }

};


class Tofu: public Sandwitch{
    public:
    void meatChoice(){
        std::cout << "a disguting tofu sandwhich.\n";
    }

};

class Empty: public Sandwitch{
    public:
    void meatChoice(){
        std::cout << " a beautiful handcrafted bread sandwitch.\n";
    }

};


//Factory
Sandwitch *Sandwitch::make_sandwitch(std::string choice){
    if(choice == "Ham")
        return new Ham;
    else if (choice == "Turkey")
        return new Turkey;
    else if (choice == "Tofu")
        return new Tofu;
    else
    {
        return new Empty;
    }
    
}



int main(int argc, char* argv[]){
    if(argc < 2){
        std::cerr << "Usage: " << argv[0] << " PARAMETER " << "\n";
        return 1;
    }
  
    std::vector<Sandwitch*> meats;
    std::string choice;
    for(int i = 1; i < argc; i++){
      choice = argv[i];
      meats.push_back(Sandwitch::make_sandwitch(choice));
    }
    
    

    for(int i = 0; i <meats.size(); i++){
        std::cout << "Wow what a choice! Here I made you ";
        meats[i]->meatChoice();
    }

    for(int i = 0; i <meats.size(); i++){
        delete meats[i];
    }
    

    return 0;
}
