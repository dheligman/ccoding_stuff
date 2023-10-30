#include <cstdio>

static int rat_things_power = 200; //  defining the static integer rat_things_power and setting it to 200

void power_up_rat_thing(int nuclear_isotopes) { // defining the function power_up_rat_thing
    rat_things_power = rat_things_power + nuclear_isotopes; // adding nuclear isotopes to rat_things_power
    const auto waste_heat = rat_things_power * 20; // defining a constant value waste heat
    if (waste_heat > 10000) { // if waste_heat is greater than 10000 it will print whats below
        printf("Warning! Hot doggie!\n");
    }
}

int main() {
    printf("Rat-thing power: %d\n", rat_things_power);
    power_up_rat_thing(100);
    printf("Rat-thing power: %d\n", rat_things_power);
    power_up_rat_thing(500);
    printf("Rat-thing power: %d\n", rat_things_power);
}