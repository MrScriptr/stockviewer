#include <ncurses.h>
#include "ui.h"
#include "portfolio.h"

int initncurses() {
  initscr();
  raw();
  curs_set(0);
  noecho();

  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal doesnt support colors\n");

    return -1;
  }

  start_color();
  use_default_colors(); 
    
  init_pair(1, COLOR_GREEN, -1);
  init_pair(2, COLOR_RED, -1);
  init_pair(3, COLOR_BLUE, -1);
}

void renderstock(stock *tracking, int y, int x) {
  attron(COLOR_PAIR(1));
  mvprintw(y, x, "%s", tracking->ticker);
  mvprintw(y + 1, x, "%.2f", tracking->price[0]);
  attroff(COLOR_PAIR(1));
}

void renderscreener(struct portfolio *tracking) {
  int stocksperrow = COLS / 6;

  for (int i = 0; i < tracking->length; i++) {
    int col = (i % stocksperrow);
    int row = (i / stocksperrow);
    renderstock(tracking->stocks[i], row * 3, col * 6);
  }
}
