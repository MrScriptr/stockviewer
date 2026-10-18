#include <ncurses.h>
#include "ui.h"
#include "portfolio.h"

void renderstock(stock *tracking, int y, int x) {
  mvprintw(y, x, "%s", tracking->ticker);
  mvprintw(y + 1, x, "%.2f", tracking->price);
}

void renderscreener(struct portfolio *tracking) {
  int stocksperrow = COLS / 6;

  for (int i = 0; i < tracking->length; i++) {
    int col = (i % stocksperrow);
    int row = (i / stocksperrow);
    renderstock(tracking->stocks[i], row * 3, col * 6);
  }
}
