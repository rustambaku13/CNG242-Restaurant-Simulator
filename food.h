//
// Created by Rustam Quliyev on 23/04/18.
//
#include <iostream>
#include <cstring>
#ifndef ASS2_DEF_H
#define ASS2_DEF_H
using namespace std;
enum type_eater { vegan, non_vegan};
enum type_dish {meat,chicken, fish, pasta,wraps};
enum app_type {soup, other};
enum dessert_type {fruits,ice_cream};
enum type_of_food{Main_dish,Appetiser, Dessert};
//My enum types 
//NOTE : TYPE_OF_FOOD is a tag associated with each food so we can distinguish them later on 
class Food {
private:
protected:
    int food_id;
    char *food_name;
    float prep_time;
    float cal;
    enum type_eater diet;
    char * origin;
    float cost;
    enum type_of_food typey;
public:
    Food *left;
    Food *right;
    //MY FOODS ARE ORDANIZED IN A BINARY TREE. I DID SO MAINLY BECAUSE OF 3 REASONS
    //1) SEARCHING THE FOOD WITH LEAST COST, WILL TAKE LESS TIME
    //2) WANTED TO REVISE THE DATA_STRUCTURES A BIT
    //3) I LIKE DATA_STRUCTURES :)
    Food(enum type_of_food);
     Food & operator = (const Food &);
    Food(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost,enum type_of_food);
    Food(const Food &x);
    ~Food();
     void setfoodid(int food_id);
     void setfoodname(const char* food_name);
     void setfoodpreptime(float prep_time);
     void setfoodcal(float cal);
     void setfoodtypeeater(enum type_eater diet);
     void setfoodorigin(const char* origin);
     void setfoodcost(float cost);
     int getfoodid();
     const char * getfoodname();
     float getfoodpreptime();
     float getfoodcal();
     enum type_eater getfoodtypeeater();
     const char* getfoodorigin();
     float getfoodcost();
    virtual void printall();
     enum type_of_food gettypey();
};

class main_dish : public Food {
private:
enum type_dish type;
float portion;
public:
main_dish();
main_dish(const main_dish &x);
 main_dish& operator = (const main_dish &x);
main_dish(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost, enum type_dish type, float portion);
void printall();
void setfoodtype(enum type_dish);
void setfoodportion(float portion);
enum type_dish getfoodtype();
float  getfoodportion();
void costcalc();

};

class appetiser: public Food {
private:
    enum app_type type;
    int promocode;
public:
    appetiser();
    appetiser(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost, enum app_type type, int promocode);
    appetiser(const appetiser&);
    appetiser& operator = (const appetiser&x);
    void setappetisertype(enum app_type);
    void setappetiserpromocode(int);
    enum app_type getappetisertype();
    int getappetiserpromocode();
    void costcalc();
    void printall();
};

class dessert :public Food{
private:
    enum dessert_type type;
    unsigned number_in_plate;
public :
dessert();
dessert(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost,enum dessert_type type, unsigned number_in_plate);
dessert(const dessert &);
dessert & operator = (const dessert&);
void setdesserttype(enum dessert_type);
void setdessertnumber_in_plate(unsigned );
enum dessert_type getdesserttype();
unsigned getdessertnumber_in_plate();
void costcalc();
void printall();


};




//END OF FOOODDD



//ORDER



class Order {
private:
    unsigned id;
    char *name;
    Food *promo_dish;
    Food * ordered_food;


public :

    Order();
    Order(unsigned, char *);
    ~Order();
    void Initialize(unsigned,char *);
    void setorderid(unsigned);
    void setordername(const char *);
    unsigned getorderid();
    const char * getordername();
    void addFood ();
    void printOrders();
    void printOrders(enum type_of_food tag);
    float totalcost (enum type_of_food tag);
    float totalcost();//Total cost of the entire order
    void printgroups();
    void SearchFood(unsigned);

};


//END OF ORDER



//RESTARUANT



class Restaurant {
private:
    int max_capacity;
     int current_capacity;


public:
    Order * myorders;
Restaurant();
~Restaurant();
void AddOrder();
void searchFood(unsigned);
void printall();
void totalcost();
void costorder(unsigned);
void printall(unsigned);
void printorder(unsigned);
};
#endif //ASS2_DEF_H
