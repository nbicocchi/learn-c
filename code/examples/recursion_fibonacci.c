#include <stdio.h>
#include <time.h>

// implementazione fibonacci iterativa
unsigned int fibonacci(unsigned int n) {
  int x = 0, y = 1, z = 0;
  for (int i = 0; i < n - 1; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  return z;
}

// implementazione fibonacci ricorsiva
unsigned int fibonaccir(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return (fibonaccir(n-1) + fibonaccir(n-2));
}

int main() {
  unsigned int n = 40;
  clock_t start;
  clock_t end;
  double duration;

  // iterative benchmark
  start = clock();
  printf("iterative benchmark: %ud\n", fibonacci(n));
  end = clock();

  duration = (double) (end - start) / CLOCKS_PER_SEC;
  printf("%.5lf seconds\n", duration);

  // recursive benchmark
  start = clock();
  printf("recursive benchmark: %ud\n", fibonaccir(n));
  end = clock();

  duration = (double) (end - start) / CLOCKS_PER_SEC;
  printf("%.3lf seconds\n", duration);
}