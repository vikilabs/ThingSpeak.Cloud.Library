/* ThingSpeak Cloud Library
 * Read data from ThingSpeak Cloud
 * Write data to ThingSpeak Cloud
 *
 *				Author: Viki (a) Vignesh Natarajan 
 *				Contact: viki@vikilabs.org
 */

#include <stdio.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <string.h>
#include "ThingSpeak.h"

int http_transmit(bool secured, http_tx_type_e type, char *url, char *data)
{
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		if(type == HTTP_POST){
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		}
 
		if(secured){
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		}

		res = curl_easy_perform(curl);

		if(res != CURLE_OK){
			fprintf(stderr, "[ failure ] curl_easy_perform() %s\n", curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
	return 0;
}

int http_post(char *url, char *data)
{
	//char *update_url_n_data = "https://api.thingspeak.com/update?api_key=MZ2YW4WKXJ1CFD05&field1=100";
	http_transmit(false, HTTP_POST, url, data);
	return 0;
}

int https_post(char *url, char *data)
{
	http_transmit(true, HTTP_POST, url, data);
	return 0;
}

int http_get(char *url)
{
	http_transmit(false, HTTP_GET, url, NULL);
	return 0;
}

int https_get(char *url)
{
	http_transmit(true, HTTP_GET, url, NULL);
	return 0;
}

/* channel_key : ThingSpeak Write Api Key
 * field : <1 to xx> (To write value to specific field)
 * value : value to assign for the field
 */
int ThingSpeak_ServerWrite(char *channel_key, char *field, char *value)
{
	//GET "https://api.thingspeak.com/update?api_key=MZ2YW4WKXJ1CFD05 &field1=100";
	char request_url[2048];
	strcpy(request_url, THINGSPEAK_HTTP_URL);
	strcat(request_url, "/update?api_key=");
	strcat(request_url, channel_key);
	strcat(request_url, "&field");
	strcat(request_url, field);
	strcat(request_url, "=");
	strcat(request_url, value);
	printf("[ URL ] [ %s ]\n", request_url);
	http_get(request_url);
	printf("\n");
	return 0;
}

/* channel_key : ThingSpeak Read Api Key
 * channel_id  : ThingSpeak Channel ID
 * field_index : 0 (To read all fields) [currently not supported] 
 *				 <1 to xx> (To read specific field)
 */
int ThingSpeak_ServerRead(char *channel_key, char *channel_id, char *field)
{

	//GET "https://api.thingspeak.com/channels/693391/fields/1.json?api_key=39DU1YUVZ97QVDZH&results=2";
	char request_url[2048];
	strcpy(request_url, THINGSPEAK_HTTP_URL);
	strcat(request_url, "/");
	strcat(request_url, "channels/");
	strcat(request_url, channel_id);
	strcat(request_url, "/fields/");
	strcat(request_url, field);
	strcat(request_url, ".json?api_key=");
	strcat(request_url, channel_key);
	strcat(request_url, "&results=2");
	printf("[ URL ] [ %s ]\n", request_url);
	http_get(request_url);
	printf("\n");
	return 0;
}



