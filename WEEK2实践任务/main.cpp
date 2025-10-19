#include "Caesar.hpp"
int main(){
    Menu menu;
    menu.show();
    int choice;
    std::cin>>choice;
    std::cin.ignore();
    menu.Run(choice);
    return 0;
}