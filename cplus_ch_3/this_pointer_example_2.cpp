#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow(int year_in) {
    if(!set_year(year_in)) {
      year = 2019;
    }
  }
  ClockOfTheLongNow() {
    year = 2019;
  }
  void add_year() {
    year++;
  }
  bool set_year(int year) { // in this example, I replaced new_year with year
    if(year < 2019)
      return false;
    this->year = year; // need to use this->year otherwise it will only treat the local variable year
    return true;
  }
  int get_year() {
    return year;
  }

  private:
  int year;
};

void add_year(ClockOfTheLongNow& clock) {
    clock.set_year(clock.get_year() + 1); // No deref operator needed
}

int main() {
    ClockOfTheLongNow clock;
    printf("The year is %d. \n", clock.get_year());
    add_year(clock);
    printf("The year is %d.", clock.get_year());
}
