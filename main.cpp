// Final Exam II | Toma Dimov | COMSC210
#include <iostream>
#include <list>
/*
Your code must run at each milestone and exercise the structures or programming you just wrote

If you paste in code from a previous assignment, you must:
 (1) write a nearby comment in your code with attribution; and 
 (2) do an immediate commit with a brief explanation in the commit comments
*/
using namespace std;
const int MAXDRINKS = 10, MAXCUSTOMERS = 10;

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
const string names[MAXDRINKS] = {
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

struct customer{
    string name;
    string order;
};

int main(){
    list<customer> line;
    return 0;
}
