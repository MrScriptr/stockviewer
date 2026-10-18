#include <ncurses.h>
#include "ui.h"
#include "portfolio.h"

void renderstock(stock *tracking, int y, int x) {
  mvprintw(y, x, "%s", tracking->ticker);
  mvprintw(y + 1, x, "%.2f", tracking->price);
}

void renderscreener(struct portfolio *tracking) {
  for (int i = 0; i < tracking->length; i++) {
    renderstock(tracking->stocks[i], 3 * i, 1);
  }
}
