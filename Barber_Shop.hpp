//
//  Barber_Shop.hpp
//  multithreadingg
//
//  Created by HIMANSHU KUMAR on 1/27/19.
//  Copyright © 2019 HIMANSHU KUMAR. All rights reserved.
//

#ifndef Barber_Shop_hpp
#define Barber_Shop_hpp
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdio.h>


class BarberShop
{
    std::mutex mtx;
    int chairs = 5;
    int num_of_customers;
    int seat_occupied =0;
    std::vector<int> waiting_customers;
public:
    
    void barber();
    void enterShop(int order_id);
    
};

#endif /* Barber_Shop_hpp */
