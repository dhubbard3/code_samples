#include <iostream>
#include <ctime>      // for time
#include <cstdlib>   // for srand and rand

#include "Lemur.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"
#include "SunDevil.h"

int main() {
    Critter *critter;

    // seeds the random number generator
    // you can read more my typing "man srand"
    srand((unsigned)time(NULL));

    std::cout << "Lemur:" << std::endl;

    // create, print info, delete
    critter = new Lemur();
    critter->printBehavior();
    delete critter;

    // Below is code to construct and print behavior
    // for Lions, Tigers, Bears (oh my) and Sun Devils.
    // You should remove the comments as you start 
    // implementing each class, so that you can compile
    // and test!

    
    std::cout << "\nLion:" << std::endl;

    // create, print info, delete
    Feline *kitty;
    kitty = new Lion();
    kitty->printBehavior();
    delete kitty;
    

    
    std::cout << "\nTiger:" << std::endl;

    
    Feline *anotherKitty;
    anotherKitty = new Tiger();
    anotherKitty->printBehavior();
    delete anotherKitty;
    
    
    
    std::cout << "\nBear:" << std::endl;

    
    critter = new Bear();
    critter->printBehavior();
    delete critter;
    

    
    std::cout << "\nSun Devil:" << std::endl;

     
     critter = new SunDevil();
     critter->printBehavior();
     delete critter;
    

    return 0;
}
