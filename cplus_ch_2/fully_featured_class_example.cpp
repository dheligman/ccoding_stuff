#include <cstdio>

struct ClockOfTheLongNow {
    void add_year() {
        year++;
    }
    int year;
};

int main() {
    ClockOfTheLongNow clock;
    clock.year = 2017;
    clock.add_year();
    printf("year: %d\n", clock.year);
    clock.add_year();
    printf("year: %d\n", clock.year);

}
/*Here I define a simple class that has a year attribute and uses the add_year method to 
increment the year by one.*/