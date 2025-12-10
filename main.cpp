// Final Exam II | Toma Dimov | COMSC210
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <map>
/*
Your code must run at each milestone and exercise the structures or programming you just wrote

If you paste in code from a previous assignment, you must:
 (1) write a nearby comment in your code with attribution; and 
 (2) do an immediate commit with a brief explanation in the commit comments
*/


using namespace std;
const int TOTALBOOTHS = 4, MAXDRINKS = 10, MAXNAMES = 10, MAXMUFFINS = 10,MAXBRACELETS = 12, MAXBALLOONS = 10;
const int ROUNDS = 10, INITIAL_CUSTOMER_COUNT = 3;
const int JOIN_PROB = 50;

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
const string muffins[MAXMUFFINS] = {
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
const string bracelets[MAXBRACELETS] = {
    "Beaded Bracelet",
    "Charm Bracelet",
    "Bangle Bracelet",
    "Cuff Bracelet",
    "Chain Bracelet",
    "Anklet (ankle bracelet)",
    "Stretch Bracelet",
    "Knot Bracelet",
    "Hemp Bracelet",
    "Leather Bracelet",
    "Silk Thread Bracelet",
    "Pearl Bracelet",
};
const string balloons[MAXBALLOONS] = {
    "Balloon Dog",
    "Balloon Swan",
    "Balloon Giraffe",
    "Balloon Monkey",
    "Balloon Elephant",
    "Balloon Sword",
    "Balloon Hat",
    "Balloon Flower",
    "Balloon Heart",
    "Balloon Octopus"
};

enum BOOTHTYPE {
    COFFEE = 1,
    MUFFIN = 2,
    BRACELET = 3,
    BALLOON = 4
};

struct customer{
    string name;
    string order;
    customer(string name = "",string order = "", int booth = 0){
        if(name=="")
            this->name = names[rand()%MAXNAMES];
        else
            this->name = name;
        if(order=="")
            switch (booth){
            case COFFEE:
                this->order = drinks[rand()%MAXDRINKS];
                break;
            case MUFFIN:
                this->order = muffins[rand()%MAXDRINKS];
                break;
            case BRACELET:
                this->order = drinks[rand()%MAXDRINKS];
                break;  
            case BALLOON:
                this->order = drinks[rand()%MAXDRINKS];
                break;
            };     
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