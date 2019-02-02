#include "ThingSpeak.h"
int main(void)
{
  char *read_key = "39DU1YUVZ97QVDZH";
  char *channel_id = "693391";
  char *write_key = "MZ2YW4WKXJ1CFD05";
  char *value = "10";
  ThingSpeak_ServerRead(read_key, channel_id, "1");
  ThingSpeak_ServerWrite(write_key,"1", value);
  return 0;
}
