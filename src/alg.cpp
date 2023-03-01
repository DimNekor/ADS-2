// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double osn = value;
  if (n == 0)
    return 1;
  else if (n == 1)
    return value;
  while (n > 1) {
    value *= osn;
    n -= 1;
  }
  return value;
}

uint64_t fact(uint16_t n) {
  uint64_t res = n;
  while (n > 1) {
    res = res * (n - 1);
    n -= 1;
  }
  return res;
}

double calcItem(double x, uint16_t n) { return pown(x, n) / fact(n); }

double expn(double x, uint16_t count) {
  double sum = 1;
  for (int i = 1; i < count + 1; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  int osn = 3;
  int counter = 2;
  double sum = x;
  for (int i = 3; i < (count - 1) * 2 + osn; i += 2) {
    sum += pown(-1, counter - 1) * pown(x, i) / fact(i);
    counter++;
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  int osn = 2;
  int counter = 2;
  double sum = 1;
  for (int i = 2; i < (count - 1) * 2 + osn; i += 2) {
    sum += pown(-1, counter - 1) * pown(x, i) / fact(i);
    counter++;
  }
  return sum;
}
