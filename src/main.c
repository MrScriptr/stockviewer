#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "portfolio.h"
#include "ui.h"

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
