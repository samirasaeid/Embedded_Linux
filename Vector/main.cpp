#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>
#include "Bakery_orders.hpp"


int main(){
    std::unordered_map<std::string,int>p1_items;
    p1_items["Bread"] = 1;
    BakeryOrder order1(1,"Person",p1_items,50.0);
    BakeryOrder order2(2,"Customer_name",{{"Cake",3}},71.5);

    //Create an empty vector to represent today's orders.
    std::vector<BakeryOrder>today_Orders;

    //Use a fill constructor to create a vector of pre-prepared items.
    std::vector<BakeryOrder>prepaid_Items(5,order1);

    //Initialize a vector with a customer's order using braced initialization.
    std::vector<BakeryOrder>customer_order{order2};

    //Copy the customer's order into the main order list.
    std::vector<BakeryOrder>main_order_list{customer_order};

    //Print the first, last, and third orders using appropriate vector functions.
    if(!prepaid_Items.empty()){
        prepaid_Items.front().printOrder();
        prepaid_Items.back().printOrder();
        if(prepaid_Items.size() >= 3){
            prepaid_Items[2].printOrder();
        }else{
            std::cout<<"Order not found"<<std::endl;
        }
    }

    //Add new orders to the end of the list.
    BakeryOrder person_2_order(3,"Person_2",{{"Pizza",2}},56);
    BakeryOrder person_3_order(3,"Person_3",{{"shami_Bread",6}},85.23);
    main_order_list.push_back(person_2_order);
    main_order_list.push_back(person_3_order);

    //Find and remove a specific order.
    auto it = std::find_if(main_order_list.begin(),main_order_list.end(),[](const BakeryOrder& a){
        return a.getTotalPrice() == 56;
    });

    if(it != main_order_list.end()){
        main_order_list.erase(it);
    }

    //Insert pre-prepared items at the beginning of the order list.
    main_order_list.insert(main_order_list.begin(),prepaid_Items.begin(),prepaid_Items.end());

    //Add a large catering order, resizing the vector if necessary.
    BakeryOrder larg_order(4,"person_4",{{"cookies",50}},300.0);
    main_order_list.resize(main_order_list.size()+1);
    main_order_list.back() = larg_order;

    //Print the capacity and size before shrinking
    std::cout<<"main_order_list capacity: "<<main_order_list.capacity()<<std::endl;
    std::cout<<"main_order_list size: "<<main_order_list.size()<<std::endl;

    //Optimize the vector's storage after completing some orders.
    main_order_list.shrink_to_fit();
    
    //Print the current size, capacity, and maximum possible size of the vector.
    std::cout<<"main_order_list capacity: "<<main_order_list.capacity()<<std::endl;
    std::cout<<"main_order_list size: "<<main_order_list.size()<<std::endl;
    std::cout<<"Max_Size: "<<main_order_list.max_size()<<std::endl;

    //Find and print the least and most complex items in the order list,
    //assuming you have a way to compare their complexity.
    auto min_max_order = std::minmax_element(main_order_list.begin(),main_order_list.end(),[](const BakeryOrder& a, const BakeryOrder& b){
        return a.getTotalPrice() < b.getTotalPrice();
    });

    min_max_order.first->printOrder();
    min_max_order.second->printOrder();

    /*******************Iterators*****************************/
    //Normal Iterator
    std::cout<<"****************Normal Iterator*****************"<<std::endl;
    for(auto it = main_order_list.begin(); it != main_order_list.end();it++){
            it->printOrder();
    }

    //Reverse Iterator
    std::cout<<"****************Reverse Iterator*****************"<<std::endl;
    for(auto it = main_order_list.rbegin(); it != main_order_list.rend();it++){
            it->printOrder();
    }

    //Const Iterator
    std::cout<<"****************Constant Iterator*****************"<<std::endl;
    for(auto it = main_order_list.cbegin(); it != main_order_list.cend();it++){
            it->printOrder();
    }

    std::cout<<"****************Auto Iterator*****************"<<std::endl;
    for(auto& it : main_order_list){
            it.printOrder();
    }

    //Clear all orders at the end of the day.
    main_order_list.clear();
    //Check if the vector is empty
    if(main_order_list.empty()){
        std::cout<<"Empty List"<<std::endl;
    }

    return 0;
}