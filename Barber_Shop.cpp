//
//  Barber_Shop.cpp
//  multithreadingg
//
//  Created by HIMANSHU KUMAR on 1/27/19.
//  Copyright © 2019 HIMANSHU KUMAR. All rights reserved.
//

#include "Barber_Shop.hpp"
void BarberShop::barber()
{
    do {
        
        while (waiting_customers.size()!=0)
            
        {   // Barber start working on the first customer in the queue
            printf("\n\nBarber cutting the hair of customer: %d",waiting_customers[0]);
            waiting_customers.erase(std::remove(waiting_customers.begin(), waiting_customers.end(), waiting_customers[0]),waiting_customers.end());
            // printing customers waiting
            printf("\n Waiting room");
            for(int i=0;i< waiting_customers.size();i++)
            {printf(" %d ",waiting_customers[i]);}
            // random delay between 4 and 5 seconds
            usleep((rand()%5+4)*1000000);
            seat_occupied =0;
        }
        
    }while(1);
}



void BarberShop::enterShop(int order_id)
{
    mtx.lock(); // critical section locking for one thread at a time
    //condition 1 : when barber is not doing anything
    if(waiting_customers.size()<= chairs && seat_occupied==0)
    {
        waiting_customers.push_back(order_id+1);
        seat_occupied=1;
        mtx.unlock();
    }
    //condition 2 : when barber is working on some other customer and waiting room seats are empty
    else if(waiting_customers.size() <= chairs && seat_occupied==1)
    {
        waiting_customers.push_back(order_id+1);
        mtx.unlock();
    }
    //condition 3 : when barber is working on some other customer and waiting room seats are not empty
    else if (waiting_customers.size() > chairs && seat_occupied==1)
    {
        printf("\n customer :%d leaving",order_id+1);
        mtx.unlock();
    }
    
    
    }
