#ifndef BAKERY_ORDERS
#define BAKERY_ORDERS

#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

enum class Status{
    PENDING,
    INPROGRESS,
    COMPLETED
};
class BakeryOrder{
    private:
        int order_id;
        std::string customer_name;
        std::unordered_map<std::string,int>items;
        double total_price;
        Status status;
        std::string statuaToString(Status status)const;

    public:
        BakeryOrder() = default;
        BakeryOrder(int _id, const std::string& _name, const std::unordered_map<std::string,int>& _items, double _price);
        void printOrder() const;
        void addItem(const std::string& item_name,int quantity,double item_price);
        void removeItem(const std::string& item_name,int quantity,double item_price);
        void updateItemQuantity(const std::string& item_name, int updated_quantity,double item_price);
        double getTotalPrice()const;
        void setStatus(Status _status);
        Status getStatus();
};


#endif