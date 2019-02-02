/* ThingSpeak Cloud Library
 * Read data from ThingSpeak Cloud
 * Write data to ThingSpeak Cloud
 *
 *				Author: Viki (a) Vignesh Natarajan 
 *				Contact: viki@vikilabs.org
 */

#ifndef THINGSPEAK_H
#define THINGSPEAK_H

#define THINGSPEAK_HTTP_URL "http://api.thingspeak.com"
#define THINGSPEAK_HTTPS_URL "https://api.thingspeak.com"

typedef enum{
	HTTP_GET=1,
	HTTP_POST
}http_tx_type_e;

extern int ThingSpeak_ServerWrite(char *channel_key, char *field, char *value);
extern int ThingSpeak_ServerRead(char *channel_key, char *channel_id, char *field);
#endif
