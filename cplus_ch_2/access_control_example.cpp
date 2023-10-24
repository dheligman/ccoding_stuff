#include <cstdio>

struct ClockOfTheLongNow {
    void add_year() {
        year++;
    }
    bool set_year(int new_year) {
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }
    int get_year() {
        return year;
    }
    private:
        int year;
};

int main() {
    ClockOfTheLongNow clock;
    if(!clock.set_year(2018)) {
        clock.set_year(2019);
    }
    clock.add_year();
    printf("year: %d", clock.get_year());
}
/*in this example, I set year to be private so that the year member can not be accessed outside 
the class itself. In order to initialize the year member you must use the set_year method. To 
access the year member, you must use the get_year method.*/