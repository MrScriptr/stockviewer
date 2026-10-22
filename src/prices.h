#pragma once

#ifndef PRICES_H
#define PRICES_H

#include "portfolio.h"

void closewebsocket();
void updateprices(struct portfolio *updatelist);
void initwebsocket();

#endif
