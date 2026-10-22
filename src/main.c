#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "portfolio.h"
#include "ui.h"
#include "prices.h"

int main() {
  struct portfolio stocks;
  stocks.stocks = malloc(0);
  stocks.length = 0;

  char viewlist[][6] = {"AAPL", "NVDA", "TSLA", "AVGO", "COST", "AMZN", "META", "MSFT"};

  int len = sizeof(viewlist) / sizeof(viewlist[0]);
  for (int i = 0; i < len; i++) {
    newstock(&stocks, viewlist[i]);
  }
  
  //checking for colors
  if (initncurses() == -1) {
    return 1;
  }

  int ch;

  //initwebsocket();
  //updateprices(&stocks);
  renderscreener(&stocks);
  while ((ch = getch()) != 'q') {
    clear();

    //updateprices(&stocks);
    renderscreener(&stocks);

    refresh();
  }

  //closewebsocket();
  endwin();

  return 0;
}
