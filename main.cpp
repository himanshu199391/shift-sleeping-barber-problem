//
//  main.cpp
//  finalthreads
//
//  Created by HIMANSHU KUMAR on 1/26/19.
//  Copyright © 2019 HIMANSHU KUMAR. All rights reserved.
//


#include <iostream>
#include <stdlib.h>
#include "Barber_Shop.hpp"
#include <thread>

BarberShop b;

void barbers ()
{
    b.barber();
}
void goToShop(int order)
{
    b.enterShop(order);
}
void customers(int num)
{
    printf("\n Generating %d customers",num);
    std::thread barber_shop[num];
    for (int order = 0; order < num; order++){
        barber_shop[order] = std::thread(goToShop, order);
        usleep(3000000);
    }
    for (int order = 0; order < num; order++) {
        barber_shop[order].join();
    }
    
}


int main ()
{
    std::thread barber(barbers);
    
    std::thread customer(customers,30);
    
    barber.join();
    
    customer.join();

    
    
   
    return 0;
}

