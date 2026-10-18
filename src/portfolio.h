#pragma once

typedef struct {
  char ticker[6];
  float price;
  float lastprice;
} stock;

struct portfolio {
  unsigned int length;
  stock **stocks;
};

void newstock(struct portfolio* tracking, char ticker[]);

