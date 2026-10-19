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

  char viewlist[][6] = {"AAPL", "NVDA", "TSLA", "AVGO", "COST", "AMZN", "META", "MSFT"};

  int len = sizeof(viewlist) / sizeof(viewlist[0]);
  for (int i = 0; i < len; i++) {
    newstock(&stocks, viewlist[i]);
  }

  // ncurses init
  initscr();
  raw();
  curs_set(0);
  noecho();

  //colors
  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal doesnt support colors\n");

    return 1;
  }

  start_color();
  use_default_colors(); 
    
  init_pair(1, COLOR_GREEN, -1);
  init_pair(2, COLOR_RED, -1);

  int ch;

  renderscreener(&stocks);
  while ((ch = getch()) != 'q') {
    clear();
    renderscreener(&stocks);

    refresh();
  }

  endwin();

  return 0;
}
