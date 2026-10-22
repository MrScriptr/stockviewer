#pragma once

#ifndef UI_H
#define UI_H

#include "portfolio.h"

int initncurses();
void renderstock(stock *tracking, int x, int y);
void renderscreener(struct portfolio *tracking);

#endif
