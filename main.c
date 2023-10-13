
/* Eksamensopgave 1: En regnemaskine på kommandolinjen */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>


// Tjekker om operator er binær
bool is_binary_operator(char operator) {
  return operator== '+' || operator== '-' || operator== '*' || operator== '/' ||
  operator== '^';
}

// Laver næste operation
void do_next_op(char operator, double operand, double *akkumulator) {
  if (operator== '+') {
    *akkumulator += operand;
  } else if (operator== '-') {
    *akkumulator -= operand;
  } else if (operator== '*') {
    *akkumulator *= operand;
  } else if (operator== '/') {
    if (operand != 0) {
      *akkumulator /= operand;
    } else {
      printf("Kan ikke dividere med 0\n");
    }
  } else if (operator== '^') {
    *akkumulator = pow(*akkumulator, operand);
  } else if (operator== '#') {
    *akkumulator = sqrt(*akkumulator);
  } else if (operator== '!') {
    *akkumulator = 1 / *akkumulator;
  } else if (operator== '%') {
    *akkumulator = *akkumulator * -1;
  }
}

// Scanner data fra user input
void scan_data(char *operator, double * operand) {
  printf("Indtast operator: \n");
  scanf(" %c", operator);

  if (is_binary_operator(*operator)) {
    printf("Indtast operand: \n");
    scanf(" %lf", operand);
  } else {
    *operand = 0.0;
  }
}

// Kører regnemaskinen
double run_calculator() {
  double akkumulator = 0.0;

  while (1) {
    char operator;
    double operand;

    scan_data(&operator, & operand);

    if (operator== 'q' || operator== 'Q') {
      break;
    }

    if (is_binary_operator(operator)) {
      do_next_op(operator, operand, &akkumulator);
    } else if(operator== '#' || operator== '!' || operator== '%') {
      do_next_op(operator, 0, &akkumulator);
    } else {
      printf("Ukendt operator: %c\n", operator);
    }

    printf("Result so far: %f\n", akkumulator);
  }

  return akkumulator;
}

int main() {
  double result = run_calculator();

  printf("Resultatet er: %f\n", result);
  return 0;
}