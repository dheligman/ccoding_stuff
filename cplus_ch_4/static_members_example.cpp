#include <cstdio>

struct RatThing { // defining a RatThing class
    static int rat_things_power; // declaring a static int rat_things_power
    static void power_up_rat_thing(int nuclear_isotopes) { // declaring a static function
        rat_things_power = rat_things_power + nuclear_isotopes;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10000) {
            printf("Warning! Hot doggie!\n");
        }
        printf("Rat-thing power: %d\n", rat_things_power);
    }
};

int RatThing::rat_things_power = 200; // initializing the rat_things_power member in the class

int main() {
    RatThing::power_up_rat_thing(100); // calling the power_up_rat_thing_metho
    RatThing::power_up_rat_thing(500);
}