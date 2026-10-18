#include <ncurses.h>
#include "ui.h"
#include "portfolio.h"

void renderscreener(struct portfolio *tracking) {
  for (int i = 0; i < tracking->length; i++) {
    printf("%s\n", tracking->stocks[i]);
  }
}
