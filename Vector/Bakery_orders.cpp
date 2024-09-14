#include <iostream>
#include "Bakery_orders.hpp"

BakeryOrder::BakeryOrder(int _id, const std::string& _name, const std::unordered_map<std::string,int>& _items, double _price)
    : order_id(_id), customer_name(_name), items(_items), total_price(_price), status(Status::PENDING)
{

}

std::string BakeryOrder::statuaToString(Status status)const{
    switch(status){
        case Status::PENDING: return "Pending";
        case Status::INPROGRESS: return "In Progress";
        case Status::COMPLETED: return "Completed";
        default: return "Unkown";
    }
}
//Display the order
void BakeryOrder::printOrder() const{
    std::cout<<"Order ID: "<<order_id<<std::endl;
    std::cout<<"Customer Name: "<<customer_name<<std::endl;
    for(auto& item : items){
        std::cout<<" "<<item.first<<" : "<<item.second<<std::endl;
    }
    std::cout<<"Total Price: $"<<std::fixed<<std::setprecision(2)<<total_price<<std::endl;
    std::cout<<"Status: "<<statuaToString(status)<<std::endl;
}
//Add Item to the order
void BakeryOrder::addItem(const std::string& item_name,int quantity,double item_price){
    items[item_name] += quantity;
    total_price += quantity * item_price;
}
//Remove Item
void BakeryOrder::removeItem(const std::string& item_name,int quantity,double item_price){
    auto it = items.find(item_name);
    if(it != items.end()){
        if(quantity >= it->second){
            total_price -= it->second * item_price;
            items.erase(it);
        }else{
            it->second -= quantity;
            total_price -= quantity * item_price;
        }
    }else{
        std::cout<<item_name<<"not included in the order"<<std::endl;
    }
}
void BakeryOrder::updateItemQuantity(const std::string& item_name, int updated_quantity,double item_price){
    auto it = items.find(item_name);
    if(it != items.end()){
        total_price += (updated_quantity - it->second) * item_price;
        it->second = updated_quantity;
        
    }else{
        std::cout<<item_name<<" not found."<<std::endl;
    }
}

double BakeryOrder::getTotalPrice() const{
    return total_price;
}

void BakeryOrder::setStatus(Status _status){
    status = _status;
}
Status BakeryOrder::getStatus(){
    return status;
}