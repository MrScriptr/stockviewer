#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "portfolio.h"
#include "prices.h"

static void getapikey(char *key, size_t size) {
  FILE *keyfile;
  keyfile = fopen("apikey.txt", "r");
  if (keyfile == NULL) {
    printf("Error opening file\n");
  }

  fgets(key, size, keyfile);

  fclose(keyfile);
}

void closewebsocket() {
  //curl_global_cleanup();
}

void updateprices(struct portfolio *updating) {
  return;
}

int initwebsocket() {
  CURL *curl;

  CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
  if(result != CURLE_OK) { return (int)result; }

  curl = curl_easy_init();

  //gets api key and makes url
  char key[500];
  getapikey(key, sizeof(key));

  if (key[0] == '\0') {
    printf("Please put a Finnhub api key in the apikey.txt file!\n");
    return 1;
  }

  char url[100] = "wss://ws.finnhub.io?token=";
  strcat(url, key);

  curl_global_cleanup();
}


