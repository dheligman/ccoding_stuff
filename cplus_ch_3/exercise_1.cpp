#include <cstdio>

void read_from(const char* word, int index, size_t length) {
    if (index >= 0 && index < length-1) {
        printf("%c", word[index]);
    }
}

void write_to(char* word, int index, char element, size_t length) {
    if (index >= 0 && index < length-1) {
        word[index] = element;
    }
}

int main() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  size_t length_lower = sizeof(lower)/sizeof(char);
  size_t length_upper = sizeof(upper)/sizeof(char);

  char* upper_ptr = upper; // Equivalent: &upper[0]

  lower[3] = 'd'; // lower now contains a b c d e \0
  upper_ptr[3] = 'D'; // upper now contains A B C D E \0

  char letter_d = lower[3]; // letter_d equals 'd'
  char letter_D = upper_ptr[3]; // letter_D equals 'D'

  printf("lower: %s\nupper: %s\n", lower, upper);
  

  read_from(lower, 4, length_lower);

  printf("\n");

  write_to(upper, 3, 'F', length_upper);

  read_from(upper, 1, length_upper);

  //lower[7] = 'g'; // Super bad. You must never do this.
}
