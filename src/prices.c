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

void closewebsocket(CURL *curl) {
  curl_easy_cleanup(curl);
  curl_global_cleanup();
}

int addstock(stock *addingstock) {
  // format request
  char req[50];
  snprintf(req, sizeof(req), "{\"type\":\"subscribe\",\"symbol\":\"%s\"}", addingstock->ticker);

  CURLcode result = CURLE_OK;
  const char *buf = &req;
  size_t sent, blen = strlen(send_payload);

  // sending ping
  while(blen) {
    result = curl_ws_send(curl, buf, blen, &sent, 0, CURLWS_TEXT);

    if(result == CURLE_OK) {
      buf += sent;
      blen -= sent;
    } else if(result == CURLE_AGAIN) {
      sleep(1);
    } else
      break;
  }

  if(result == CURLE_OK)
    return 0;
}

int updateprices(struct portfolio *updating) {
  size_t rlen = 0;
  const struct curl_ws_frame *meta;
  char buffer[256];
  CURLcode result = curl_ws_recv(curl, buffer, sizeof(buffer), &rlen, &meta);

  if (result == CURLE_OK) {
    // updating logic coming soon
    return 0;
  }
}

int initwebsocket(CURL *curl) {
  CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
  if(result != CURLE_OK) { return (int)result; }

  curl = curl_easy_init();

  //gets api key and makes url
  char key[100];
  getapikey(key, sizeof(key));
  if (key[0] == '\0') {
    printf("Please put a Finnhub api key in the apikey.txt file!\n");
    return 1;
  }

  key[strcspn(key, "\n")] = '\0';
  char url[200] = "wss://ws.finnhub.io?token=";
  strcat(url, key);
  
  //connecting to websocket
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 2l);

  result = curl_easy_perform(curl);

  if (result != CURLE_OK) {
    printf("Curl error: %s\n", curl_easy_strerror(result));
    return 1;
  }
}

