#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "portfolio.h"

void newstock(struct portfolio* tracking, char ticker[]) {
  stock *newstock = malloc(sizeof(stock));
  strcpy(newstock->ticker, ticker);
  newstock->price = 0;
  newstock->lastprice = 0;

  tracking->length += 1;
  tracking->stocks = realloc(tracking->stocks, sizeof(stock) * tracking->length);
  tracking->stocks[tracking->length - 1] = newstock;
}

