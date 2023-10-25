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
  bool set_year(int new_year) {
    if(new_year < 2019)
      return false;
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
    ClockOfTheLongNow clock; // declaring an instance of ClockOfTheLongNow class as clock 
    ClockOfTheLongNow* clock_ptr = &clock; // declaring a ClockOfTheLongNow pointer clock_ptr and point it to clock
    clock_ptr->set_year(2020); // setting the year of clock via the clock_ptr using the -> operator
    printf("Address of clock: %p\n", clock_ptr); // printing clock_ptr
    printf("Value of clock's year: %d", clock_ptr->get_year()); // printing the current year using the get_year method viar -> operator
    printf("\nValue of clock's year: %d", (*clock_ptr).get_year()); // equivalent to the previous line
}