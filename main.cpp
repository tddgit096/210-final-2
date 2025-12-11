// Final Exam II | Toma Dimov | COMSC210
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <map>
#include <set>

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
    customer(int booth){
        this->name = names[rand()%MAXNAMES];
        switch (booth){
        case COFFEE:
            this->order = drinks[rand()%MAXDRINKS];
            break;
        case MUFFIN:
            this->order = muffins[rand()%MAXMUFFINS];
            break;
        case BRACELET:
            this->order = bracelets[rand()%MAXBRACELETS];
            break;  
        case BALLOON:
            this->order = balloons[rand()%MAXBALLOONS];
            break;
        }
    }

    bool operator<(const customer& that)const  { //organize the line by order name, alphabetically.
        return order < that.order;
    }  
};

void coffee_initiate(list<customer>&);
void muffin_initiate(deque<customer>&);
void bracelet_initiate(vector<customer>&);
//void balloon_initiate(set<customer>&);

void print_coffee(list<customer>);
void print_muffin(deque<customer>);
void print_bracelet(vector<customer>);
//void print_balloon(set<customer>);

void coffee_round(list<customer>&);
void muffin_round(deque<customer>&);
void bracelet_round(vector<customer>&);
//void balloon_round(set<customer>&);

int main(){
    srand(time(NULL));
    list<customer> coffee_line;
    deque<customer> muffin_line;
    vector<customer> bracelet_line;
    set<customer> balloon_line;

    coffee_initiate(coffee_line);
    muffin_initiate(muffin_line);
    bracelet_initiate(bracelet_line);
    //balloon_round(balloon_line);

    for(int i = 0; i<ROUNDS;i++){
        cout<<"====================ROUND "<<i+1<<"====================\n";
        coffee_round(coffee_line);
        muffin_round(muffin_line);
        bracelet_round(bracelet_line);
        //balloon_round(balloon_line);
    }
    return 0;
}

void coffee_initiate(list<customer>& L){
    for(int i=0;i<INITIAL_CUSTOMER_COUNT;i++){
        customer temp_coffee(COFFEE);
        L.push_back(temp_coffee);
    }
    print_coffee(L);
}

void muffin_initiate(deque<customer>& L){
    for(int i=0;i<INITIAL_CUSTOMER_COUNT;i++){
        customer temp_muffin(MUFFIN);
        L.push_back(temp_muffin);
    }
    print_muffin(L);
}

void bracelet_initiate(vector<customer>& L){
    for(int i=0;i<INITIAL_CUSTOMER_COUNT;i++){
        customer temp(BRACELET);
        L.push_back(temp);
    }
    print_bracelet(L);
}
/*
void balloon_initiate(set<customer>& L){
    for(int i=0;i<INITIAL_CUSTOMER_COUNT;i++){
        customer temp(BALLOON);
        L.insert(temp);
    }
    print_balloon(L);
}*/

void coffee_round(list<customer>& L){
    if(!L.empty())
        L.pop_front();
    if(rand()%100 < JOIN_PROB){
        customer temp(COFFEE);
        L.push_back(temp);
    }
    print_coffee(L);
}

void muffin_round(deque<customer>& L){
    if(!L.empty())
        L.pop_front();
    if(rand()%100 < JOIN_PROB){
        customer temp(MUFFIN);
        L.push_back(temp);
    }
    print_muffin(L);
}

void bracelet_round(vector<customer>& L){
    if(!L.empty())
        L.erase(L.begin());
    if(rand()%100 < JOIN_PROB){
        customer temp(BRACELET);
        L.push_back(temp);
    }
    print_bracelet(L);
}
/*
void balloon_round(set<customer>& L){
    if(!L.empty())
        L.erase(L.begin());
    if(rand()%100 < JOIN_PROB){
        customer temp(BRACELET);
        L.insert(temp);
    }
    print_balloon(L);
}
*/
void print_coffee(list<customer> L){
    cout<<"===Coffee line===\n";
    if(L.empty()){
        cout<<"Line Empty.\n\n";
        return;
    }
    for(auto it : L){
        cout<<it.name<<" - "<<it.order<<endl;
    }
    cout<<endl;
}

void print_muffin(deque<customer> L){
    cout<<"===Muffin line===\n";
    if(L.empty()){
        cout<<"Line Empty.\n\n";
        return;
    }
    for(auto it : L){
        cout<<it.name<<" - "<<it.order<<endl;
    }
    cout<<endl;
}

void print_bracelet(vector<customer> L){
    cout<<"===Bracelet line===\n";
    if(L.empty()){
        cout<<"Line Empty.\n\n";
        return;
    }
    for(auto it : L){
        cout<<it.name<<" - "<<it.order<<endl;
    }
    cout<<endl;
}

/*
void print_balloon(set<customer> L){


    cout<<"===Bracelet line===\n";
    if(L.empty()){
        cout<<"Line Empty.\n\n";
        return;
    }
    for(auto it : L){
        cout<<it.name<<" - "<<it.order<<endl;
    }
    cout<<endl;
}
*/