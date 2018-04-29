


#include "food.cpp"
// FOOD_ID FOOD_NAME PREP_TIME CAL DIET ORIGIN COST
int main() {
Restaurant Rustams;
   int c;
   unsigned id;
   
   cout <<"WELCOME TO RESTAURANT SIMULATOR\n";
   cout << "Please Avoid using Strings with Spaces\n ";

   do{
        cout<< " 1. Create an order\n"
             "    2. Search a food by ID\n"
             "    3. List all foods ordered in the restaurant\n"
             "    4. Show total cost orders for the restaurants\n"
             "    5. List all food in a given order\n"
             "    6. List all food of a given order grouped as appetisers, main dishes, and desserts with total cost of each group.\n"
             "    7. Show total cost of a given order\n"
             "    8. Exit\n";
        cin >> c;

        switch(c){
            fflush(stdin);
            case 1 : Rustams.AddOrder();break;
            case 2 : cout <<"Enter The ID:"<<endl;
                     cin >>id;
                     Rustams.searchFood(id);
                     break;
            case 3: Rustams.printall();break;
            case 4: Rustams.totalcost();break;
            case 5: cout <<"Enter The ID:"<<endl;
                    cin >>id;
                    Rustams.printall(id);
                    break;
            case 6: cout <<"Enter The ID:"<<endl;
                    cin >>id;
                    Rustams.printorder(id);
                    break;
            case 7: cout <<"Enter The ID:"<<endl;
                    cin >>id;
                    Rustams.costorder(id);
                    break;
            default: break;



        }

   }while(c!=8);














    return 0;
}
