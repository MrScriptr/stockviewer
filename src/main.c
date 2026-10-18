#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  char ticker[6];
  float price;
  float lastprice;
} stock;

struct portfolio {
  unsigned int length;
  stock **stocks;
};

void newstock(struct portfolio* tracking, char ticker[]) {
  stock *newstock = malloc(sizeof(stock));
  strcpy(newstock->ticker, ticker);

  tracking->length += 1;
  tracking->stocks = realloc(tracking->stocks, sizeof(stock) * tracking->length);
  tracking->stocks[tracking->length - 1] = newstock;
}

void renderscreener(struct portfolio *tracking) {
  for (int i = 0; i < tracking->length; i++) {
    printf("%s\n", tracking->stocks[i]);
  }
}

int main() {
  struct portfolio stocks;
  stocks.stocks = malloc(0);
  stocks.length = 0;

  newstock(&stocks, "AAPL");
  newstock(&stocks, "AMZN");
  newstock(&stocks, "NVDA");

  // ncurses init
  //initscr();
  //raw();
  //curs_set(0);
  //noecho();

  clear();
  renderscreener(&stocks);

  return 0;
}
