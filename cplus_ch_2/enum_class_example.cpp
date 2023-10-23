#include <cstdio>

enum class Race {
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan
};

int main() {
    Race longobard_race = Race::Aidan;
    printf("%d", (int)longobard_race);
}
/*Here I define an enum class type and printed out the enumeration associated with
the race Aidan.*/