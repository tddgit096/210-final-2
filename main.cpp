// Final Exam II | Toma Dimov | COMSC210
#include <iostream>
#include <list>
#include <deque>
#include <vector>
/*
Your code must run at each milestone and exercise the structures or programming you just wrote

If you paste in code from a previous assignment, you must:
 (1) write a nearby comment in your code with attribution; and 
 (2) do an immediate commit with a brief explanation in the commit comments
*/


using namespace std;
const int MAXDRINKS = 10, MAXNAMES = 10, MAXMUFFINS = 10;
const int ROUNDS = 10, INITIAL_CUSTOMER_COUNT = 3;
const int JOIN_PROB = 50;

const string drinks[MAXDRINKS] = {
    "Espresso",
    "Cappuccino",
    "Latte",
    "Americano",
    "Mocha",
    "Macchiato",
    "Flat White",
    "Cortado",
    "Cold Brew",
    "Affogato"
};
const string names[MAXNAMES] = {
    "Liam",
    "Olivia",
    "Noah",
    "Emma",
    "Oliver",
    "Ava",
    "Elijah",
    "Sophia",
    "Lucas",
    "Mia"
};
const string drinks[MAXMUFFINS] = {
    "Blueberry",
    "Applepie",
    "Birthday Cake",
    "Chocolate Chip",
    "Double Chocolate",
    "Red Velvet",
    "Pecan",
    "Sesame",
    "Cream Cheese",
    "Cinnamon"
};

const string booth_type

struct customer{
    string name;
    string order;
    customer(string name = "",string order = "", string booth_type){
        if(name=="")
            this->name = names[rand()%MAXNAMES];
        else
            this->name = name;
        if(order=="")
            this->order = drinks[rand()%MAXDRINKS];
        else
            this->order = order;
    }
};

void print(list<customer>);

int main(){
    srand(time(NULL));
    list<customer> coffee_line;
    deque<customer> muffin_line;

    for(int i=0;i<INITIAL_CUSTOMER_COUNT;i++){
        customer temp;
        line.push_back(temp);
    }
    print(line);
    for(int i = 0; i<ROUNDS;i++){
        if(!coffee_line.empty()){
            coffee_line.pop_front();
        }
        if(rand()%100 < JOIN_PROB){
            customer temp;
            coffee_line.push_back(temp);
        }
    print(line);
    }
    return 0;
}

void print(list<customer> L){
    if(L.empty()){
        cout<<"Line Empty.\n";
        return;
    }
    for(auto it : L){
        cout<<it.name<<" - "<<it.order<<endl;
    }
    cout<<endl;
}