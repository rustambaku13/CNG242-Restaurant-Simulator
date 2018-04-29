#ifndef DEC_H
#define DEC_H
#include <iostream>
#include <cstring>
#include "food.h"
#include<iomanip>// I INCLUDED THIS LIBRARY BECAUSE OF SETW() FUNCTION TO MAKE PRINTING EASIER AND CLEANER 
using namespace std;



//HERE ARE THE FUNCTIONS ASSOCIATED WITH THE BINARY TREE 

class Food* insert(class Food* node1, class Food * node2)
{
    
    if(node1==NULL)return node2;
    if(node1->getfoodcost()<node2->getfoodcost()){
        node1->right = insert(node1->right, node2);
    }
    else{
        node1->left = insert(node1->left, node2);
    }
    return node1;

}

class Food * findlowest(Food* x){

    while((x->left)!=NULL && x!=NULL){
        x=x->left;
    }
    return x;


};

float findcost(Food *x){
    if(x==NULL)return 0;
    return x->getfoodcost() + findcost(x->left) + findcost(x->right);

}
float findcost(Food *x, enum type_of_food tag){
   if(x==NULL)return 0;
   if(x->gettypey()==tag)return x->getfoodcost() + findcost(x->left,tag)+findcost(x->right,tag);
   return findcost(x->left,tag)+findcost(x->right,tag);
}
void printBinaryTree(class Food *x){
    if ( x != NULL )
    {
        printBinaryTree(x->left);
        x->printall();
        printBinaryTree(x->right);
    }
}
void printBinaryTree(class Food *x, enum type_of_food tag){
    if ( x != NULL )
    {
        printBinaryTree(x->left,tag);
        if(x->gettypey()==tag){(x->printall());};
        printBinaryTree(x->right,tag);
    }
}

void deleteTree(class Food *x ){
    if(x!=NULL){
        deleteTree(x->left);
        deleteTree(x->right);

        delete(x);
    }

}

void searchTree (class Food *x,int id){
    if(x!=NULL){
        if(x->getfoodid()==id)x->printall();
        searchTree(x->right,id);
        searchTree(x->left,id);
    }

}











//FUNCTION DECLARATIONS FOR FOOD
Food::Food(enum type_of_food x):typey(x),left(NULL),right(NULL){
    unsigned temp;
    char tmp[100];
    cout << "FOOD ID:";
    cin >> food_id;
    cout <<endl;
    cout << "FOOD NAME:";
    cin >> tmp;
    food_name = new char [strlen(tmp)+1];
    strcpy(food_name,tmp);
    cout <<endl;
    cout << "PREP TIME:";
    cin >> prep_time;
    cout <<endl;
    cout << "CAL:";
    cin >> cal;
    cout <<endl;
    do{
        cout << "VEGETARIAN(0)/ NON_VEGETARIAN(1)";
        cin >> temp;
        diet = type_eater (temp);
        cout <<endl;
    }while(temp!=0 && temp!=1);
    cout <<"ORIGIN COUNTRY:";
    cin >> tmp;
    origin = new char [strlen(tmp)+1];
    strcpy(origin,tmp);
    cout <<endl;
    cout << "COST:";
    cin >> cost;
    cout <<endl;

}

Food::Food(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet, const char * origin, float cost,enum type_of_food x):typey(x),left(NULL),right(NULL){
    this->food_id=food_id;
    this->food_name = new char [strlen(food_name)+1];
    strcpy(this->food_name,food_name);
    this->prep_time = prep_time;
    this->cal=cal;
    this->diet=diet;
    this->origin = new char [strlen(origin)+1];
    strcpy(this->origin,origin);
    this->cost=cost;
}


Food::~Food(){

    delete (food_name);
    delete (origin);
    cout << "Dead";


};
void Food::setfoodid(int food_id) {
    this->food_id=food_id;
};

void Food::setfoodname(const char *food_name) {
    delete (this->food_name);
    this->food_name=new char [strlen(food_name)+1];
    strcpy(this->food_name,food_name);

};

void Food::setfoodpreptime(float prep_time) {
    this->prep_time=prep_time;
};
enum type_of_food Food::gettypey(){
    return typey;
}
void Food::setfoodcal(float cal) {
    this->cal=cal;
}
void Food::setfoodtypeeater(enum type_eater diet) {
    this->diet=diet;
}
void Food::setfoodorigin(const char *origin) {
    delete(this->origin);
    this->origin=new char [strlen(origin)+1];
    strcpy(this->origin,origin);
}

void Food::setfoodcost(float cost) {
    this->cost=cost;
}

int Food::getfoodid() {
    return food_id;
}

const char * Food::getfoodname() {
    return food_name;
}
float Food ::getfoodpreptime() {
    return prep_time;
}
float Food ::getfoodcal() {
    return cal;
}
enum type_eater  Food::getfoodtypeeater() {
    return diet;

}
const char * Food::getfoodorigin() {
    return origin;
}
float Food::getfoodcost() {
    return cost;
}

Food::Food(const Food &x){
    this->food_id = x.food_id;
    this->food_name = new char [strlen(x.food_name)+1];
    strcpy(this->food_name,x.food_name);
    this->prep_time=x.prep_time;
    this->cal=x.cal;
    this->diet = x.diet;
    this->origin  = new char [strlen(x.origin)+1];
    strcpy(this->origin,x.origin);
    this->cost = x.cost;
    this->typey = x.typey;


}
 Food & Food :: operator = (const Food &x ){
    if(this==&x)return *this;
     this->food_id = x.food_id;
     delete(this->food_name);
     this->food_name = new char [strlen(x.food_name)+1];
     strcpy(this->food_name,x.food_name);
     this->prep_time=x.prep_time;
     this->cal=x.cal;
     this->diet = x.diet;
     delete(this->origin);
     this->origin  = new char [strlen(x.origin)+1];
     strcpy(this->origin,x.origin);
     this->cost = x.cost;
     cout <<"Main dish opeartr"<<endl;
     return *this;
};



void Food::printall() {
    cout << "FOOD_ID \tFOOD_NAME\tPREP_TIME\tCAL\tDIET_PLAN\tORIGIN\tCOST"<<endl;
    cout <<food_id<<"\t"<<food_name<<"\t"<<prep_time<<"\t"<<cal<<"\t";
    if(diet==0)cout <<"Vegan"<<"\t";
    else cout <<"Non-Vegan"<<"\t";
    cout <<origin <<"\t"<<cost<<"\t";
    cout <<endl;

};



//MAIN _DISH DECLARATION

main_dish::main_dish(const main_dish &x):Food(Main_dish){
    this->type = x.type;
    this->portion=x.portion;

}
main_dish::main_dish():Food(Main_dish){
    int temp;
    char tmp[100];
   do{
       cout <<"Dish Type (0)Meat   (1)Chicken    (2)Fish    (3)Pasta (4) Wraps";
       cin >>temp;
       type = type_dish(temp);
       cout << endl;
   }while(temp!=0 && temp!=1 && temp!=2 && temp!=3 && temp!=4 );

    do {
        cout << "Portion size (0.75) (0.5) (1.5) (1)"<<endl;
        cin >> portion;
    }while(portion != 0.75 && portion!=0.5 && portion != 1.5 &&portion!=1);
    costcalc();
    cout <<endl;
};


main_dish :: main_dish(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost, enum type_dish type, float portion):Food(food_id,food_name,prep_time,cal,diet,origin,cost,Main_dish)
{
    this->type= type;
    this->portion= portion;
    costcalc();
}

 main_dish & main_dish ::operator = (const main_dish &x ){
    if(this==&x)return *this;
     this->food_id = x.food_id;
     delete(this->food_name);
     this->food_name = new char [strlen(x.food_name)+1];
     strcpy(this->food_name,x.food_name);
     this->prep_time=x.prep_time;
     this->cal=x.cal;
     this->diet = x.diet;
     delete(this->origin);
     this->origin  = new char [strlen(x.origin)+1];
     strcpy(this->origin,x.origin);
     this->cost = x.cost;
     this->type = x.type;
     this->portion=x.portion;
     this->typey = x.typey;
     return *this;
}

void main_dish ::printall() {
    cout << "FOOD_ID|" <<std::setw(15)<< "FOOD_NAME|"<<std::setw(15)<<"PREP_TIME|"<<std::setw(15)<< "CAL|"<<std::setw(15)<<"DIET_PLAN|"<<std::setw(15)<<"ORIGIN|"<<std::setw(15)<<"COST|"<<std::setw(15)<<"Type of Dish|"<<std::setw(15)<<"Portion Size|"<<endl;
    cout <<food_id<<std::setw(15)<<food_name<<std::setw(15)<<prep_time<<std::setw(15)<<cal<<std::setw(15);
    if(diet==0)cout <<"Vegan"<<std::setw(15);
    else cout <<"Non-Vegan"<<std::setw(15);
    cout <<origin <<std::setw(15)<<cost<<std::setw(15);
    if(type == meat )cout <<"Meat"<<std::setw(15);
    else if(type == chicken)cout <<"Chicken"<<std::setw(15);
    else if (type == fish)cout <<"Fish"<<std::setw(15);
    else if(type==pasta) cout <<"Pasta"<<std::setw(15);
    else cout <<"Wraps"<<std::setw(15);
    cout << portion <<endl;


}


void main_dish ::setfoodtype(enum type_dish type){
    this->type = type;
};
void main_dish ::setfoodportion(float portion){
    this->portion =portion;
};
enum type_dish main_dish :: getfoodtype(){
    return type;
};
float main_dish :: getfoodportion(){
return portion;
};

void main_dish ::costcalc() {
    cost = cost * portion;
}

//APPETISER DECLARATION
appetiser:: appetiser():Food(Appetiser){
int temp;
do{
    cout << "Enter the appetiser type (0)Soup (1) Other";
    cin >> temp;
    type = app_type(temp);
    cout << endl;
}while(temp!=0 && temp!=1);

do{
    cout << "Enter the promotion (1) (2) (3) (4)";
    cin >> temp;
    promocode = temp;
    cout <<endl;
}while(promocode<=0 || promocode>=4);
costcalc();


};
appetiser:: appetiser(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost, enum app_type type, int promocode):Food(food_id,food_name,prep_time,cal,diet,origin,cost,Appetiser){
    this->type = type;
    this->promocode=promocode;
    costcalc();
}

appetiser::appetiser(const appetiser& x):Food(x){
this->type= x.type;
this->promocode = x.promocode;

};
appetiser& appetiser:: operator = (const appetiser&x){
    if(this==&x)return *this;
    this->food_id = x.food_id;
    delete(this->food_name);
    this->food_name = new char [strlen(x.food_name)+1];
    strcpy(this->food_name,x.food_name);
    this->prep_time=x.prep_time;
    this->cal=x.cal;
    this->diet = x.diet;
    delete(this->origin);
    this->origin  = new char [strlen(x.origin)+1];
    strcpy(this->origin,x.origin);
    this->cost = x.cost;
    this->type = x.type;
    this->promocode = x.promocode;
    this->typey = x.typey;
    return *this;
};


void appetiser::setappetisertype(enum app_type type){
this->type = type;
};
void appetiser::setappetiserpromocode(int promocode){
    this->promocode = promocode;
};
enum app_type appetiser:: getappetisertype(){
    return type;
};
int appetiser::getappetiserpromocode(){
    return promocode;
};

void appetiser::costcalc(){
if(promocode == 1){
    if(type ==0 )setfoodcost(cost *0.9);
    else  setfoodcost(cost *0.95);
}
else if(promocode ==2){
    if(type==0)setfoodcost(cost *0.8);
    else setfoodcost(cost *0.9);
}
else if(promocode==3){
    if(type==0)setfoodcost(cost *0.7);
    else setfoodcost(cost *0.85);
}
    };

void appetiser:: printall(){
    cout << "FOOD_ID|" <<std::setw(15)<< "FOOD_NAME|"<<std::setw(15)<<"PREP_TIME|"<<std::setw(15)<< "CAL|"<<std::setw(15)<<"DIET_PLAN|"<<std::setw(15)<<"ORIGIN|"<<std::setw(15)<<"COST|"<<std::setw(15)<<"Type of Dish|"<<std::setw(15)<<"Promocode|"<<endl;
    cout <<food_id<<std::setw(15)<<food_name<<std::setw(15)<<prep_time<<std::setw(15)<<cal<<std::setw(15);
    if(diet==0)cout <<"Vegan"<<std::setw(15);
    else cout <<"Non-Vegan"<<std::setw(15);
    cout <<origin <<std::setw(15)<<cost<<std::setw(15);
    if(type == soup )cout <<"Soup"<<std::setw(15);
    else cout <<"Other"<<std::setw(15);
    cout << promocode <<endl;
}
//dessert Declarations

dessert::dessert():Food(Dessert){
int temp;
unsigned tmp;
do {
    cout << "Enter the type of dessert (0) Fruits (1) Ice-Cream";
    cin >> temp;
    type = dessert_type(temp);
    cout << endl;
}while(temp!=0 && temp!=1);
cout <<"Enter the number of servings";
cin >> tmp;
number_in_plate = tmp;
cout <<endl;
costcalc();


};
dessert::dessert(int food_id,const char * food_name, float prep_time, float cal, enum type_eater diet,const char *  origin, float cost,enum dessert_type type, unsigned number_in_plate):Food(food_id,food_name,prep_time,cal,diet,origin,cost,Dessert){
    this->type = type;
    this->number_in_plate = number_in_plate;
    costcalc();
}
dessert::dessert(const dessert &x):Food(x){
this->type = x.type;
this->number_in_plate = x.number_in_plate;

};
dessert & dessert::operator = (const dessert&x){
    if(this==&x)return *this;
    this->food_id = x.food_id;
    delete(this->food_name);
    this->food_name = new char [strlen(x.food_name)+1];
    strcpy(this->food_name,x.food_name);
    this->prep_time=x.prep_time;
    this->cal=x.cal;
    this->diet = x.diet;
    delete(this->origin);
    this->origin  = new char [strlen(x.origin)+1];
    strcpy(this->origin,x.origin);
    this->cost = x.cost;
    this->type = x.type;
    this->number_in_plate = x.number_in_plate;
    this->typey = x.typey;
    return *this;
};

void dessert::setdesserttype(enum dessert_type type){
    this->type = type;
};
void dessert::setdessertnumber_in_plate(unsigned number_in_plate){
    this->number_in_plate = number_in_plate;
};
enum dessert_type dessert::getdesserttype(){
    return type;
};
unsigned dessert::getdessertnumber_in_plate(){
    return number_in_plate;
};
void dessert:: costcalc(){
cost = cost * number_in_plate;
}

void dessert::printall() {
    cout << "FOOD_ID|" <<std::setw(15)<< "FOOD_NAME|"<<std::setw(15)<<"PREP_TIME|"<<std::setw(15)<< "CAL|"<<std::setw(15)<<"DIET_PLAN|"<<std::setw(15)<<"ORIGIN|"<<std::setw(15)<<"COST|"<<std::setw(15)<<"Type of Dish|"<<std::setw(15)<<"Number Of Servings|"<<endl;
    cout <<food_id<<""<<std::setw(15)<<food_name<<""<<std::setw(15)<<prep_time<<""<<std::setw(15)<<cal<<std::setw(15);
    if(diet==0)cout <<"Vegan"<<std::setw(15);
    else cout <<"Non-Vegan"<<std::setw(15);
    cout <<origin <<std::setw(15)<<cost<<std::setw(15);
    if(type == fruits )cout <<"Fruits"<<std::setw(15);
    else cout <<"Ice-Cream"<<std::setw(15);
    cout << number_in_plate<<endl;
}









// FUNCTION DECLARATION FOR ORDER


Order::Order(){

id= 0;
name =NULL;
promo_dish = NULL;
ordered_food = NULL;




}

Order::Order(unsigned id,  char *name){
    this->id= id;
    this->name = new char [strlen(name)+1];
    strcpy(this->name,name);
    promo_dish=NULL;
    ordered_food=NULL;
}
Order::~Order(){
    if(name!=NULL)delete(name);


    if(ordered_food!=NULL)deleteTree(ordered_food);


};

void Order ::Initialize(unsigned id, char *name) {
    this->id= id;
    this->name = new char [strlen(name)+1];
    strcpy(this->name,name);

};
void Order::setorderid(unsigned id) {
    this->id = id;
}
void Order::setordername(const char *name) {
    delete(this->name);
    this->name  = new char[strlen(name)+1];
    strcpy(this->name,name);
}
unsigned Order ::getorderid() {
    return id;
}
const char* Order ::getordername() {
    return name;
}

void Order ::addFood() {

Food * newFood;
char dish_type[50];
    cout <<"Enter the type of meal  MainDish  | Appetiser | Dessert ";
    cin >> dish_type;
    cout <<endl;
    if(!strcmp(dish_type,"MainDish"))newFood = new main_dish;
    else if(!strcmp(dish_type,"Appetiser"))newFood = new appetiser;
    else newFood = new dessert;
    ordered_food = insert(ordered_food, newFood);




}

void Order::printOrders() {
    printBinaryTree(ordered_food);
}

float Order::totalcost() {
float cost,promo;
    cost  = findcost(ordered_food);
    if(cost >100) {
        promo_dish = findlowest(ordered_food);
        cout << "The promotion dish is :"<<endl;
        promo_dish->printall();
         promo = promo_dish->getfoodcost();
            cost = cost -promo;
    }
    cout <<"Total cost is : "<<cost<<endl ;
    return cost;


}

float Order ::totalcost(enum type_of_food tag) {
   return findcost(ordered_food,tag);

}

void Order::printOrders(enum type_of_food tag) {
    printBinaryTree(ordered_food,tag);
}

void Order::printgroups(){
    cout <<" ORDER ID:  "<<id<<"       ORDER NAME:  "<<name<<endl;
    cout << "MAIN DISHES"<<endl;
    cout <<"------------------------------------------------------------------"<<endl;
    printOrders(Main_dish);
    cout <<endl<<"The total cost of main Dishes is:"<<totalcost(Main_dish)<<endl<<endl<<endl<<endl;
    cout << "APPETISERS"<<endl;
    cout <<"------------------------------------------------------------------"<<endl;
    printOrders(Appetiser);
    cout <<endl<<"The total cost of Appetisers is:"<<totalcost(Appetiser)<<endl<<endl<<endl<<endl;
    cout << "DESSERTS"<<endl;
    cout <<"------------------------------------------------------------------"<<endl;
    printOrders(Dessert);
    cout <<endl<<"The total cost of Desserts is:"<<totalcost(Dessert)<<endl<<endl<<endl<<endl;


}


void Order::SearchFood(unsigned id){
    searchTree(ordered_food,id);
}







//FUNCTION DECLARATION FOR RESTAURANT

Restaurant::Restaurant(){
    max_capacity =5;
    myorders= new Order[max_capacity];
    current_capacity=0;
}
Restaurant::~Restaurant() {

if(myorders!=NULL)delete [] myorders;
}
void Restaurant::AddOrder() {
    unsigned id;
    char name[100];
    cout << "Enter the ID Of the Order";
    cin >> id;
    cout << endl<< "Enter the name of the person";
    cin >> name;
    myorders[current_capacity].Initialize(id,name);
    char choise;
    cout << "We ae ready to take your order"<<endl <<"------------------------------------------"<<endl;
    do {
        myorders[current_capacity].addFood();
        cout << "Is the all your order? (Y/N)"<<endl;
        cin >> choise;
    }while(choise!='Y');
    current_capacity++;


}

void Restaurant::searchFood( unsigned id) {
    int b = current_capacity;
    int i;
    for(i=0;i<b;i++){
        myorders[i].SearchFood(id);
    }

}

void Restaurant::printall() {
    int b = current_capacity;
    int i;
    for(i=0;i<b;i++){
        myorders[i].printOrders();



    }

}

void Restaurant::totalcost(){
    int b = current_capacity;
    int i;
    int sum=0;
    int y;
    for(i=0;i<b;i++) {
        cout <<"For order "<<myorders[i].getorderid()<<" Of Mr/Ms "<<myorders[i].getordername()<<endl;

        y = myorders[i].totalcost();
        sum+=y;
        cout <<endl<<endl;

    }

    cout <<"The cost at the moment of all meals is: "<<sum<<endl;


}

void Restaurant::costorder(unsigned id) {
    int b = current_capacity;
    int i;
    for(i=0;i<b;i++){
        if(myorders[i].getorderid() == id){
           myorders[i].totalcost();
        }
    }


}

void Restaurant::printall(unsigned id){
    int b = current_capacity;
    int i;
    for(i=0;i<b;i++){
        if(myorders[i].getorderid() == id){
            myorders[i].printOrders();
        }
    }
};

void Restaurant::printorder(unsigned id){
    int b = current_capacity;
    int i;
    for(i=0;i<b;i++){
        if(myorders[i].getorderid() == id){
            myorders[i].printgroups();
        }
    }
};







#endif
