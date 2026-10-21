#pragma once

typedef struct {
  char ticker[6];
  float price[10];
} stock;

struct portfolio {
  unsigned int length;
  stock **stocks;
};

void newstock(struct portfolio* tracking, char ticker[]);

