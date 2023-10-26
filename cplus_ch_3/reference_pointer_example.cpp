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

void add_year(ClockOfTheLongNow& clock) {
    clock.set_year(clock.get_year() + 1); // No deref operator needed
}

int main() {
    ClockOfTheLongNow clock;
    printf("The year is %d. \n", clock.get_year());
    add_year(clock);
    printf("The year is %d.", clock.get_year());
}

/*The reason I think that you need to use a reference instead of a pointer is because if you 
did not declare it a reference it would treat whatever you input as a local variable, thus it 
would not change the value globally. You input the address of the objects memory, you will 
manipulate the memory at that location and thus globally.*/