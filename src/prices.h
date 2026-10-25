#pragma once

#ifndef PRICES_H
#define PRICES_H

#include <curl/curl.h>
#include "portfolio.h"

void closewebsocket(CURL *curl);
void updateprices(struct portfolio *updating);
int initwebsocket(CURL *curl);

#endif
