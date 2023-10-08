#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

int main()
{
  char *data = NULL;
  int dataSize = 0;

  char name[100] = "";

  printf("Content-type:text/html\r\n\r\n");
  printf("<html><head><title> User Name INPUT CGI (GET)</title></head>\n");
  printf("<body>\n");

  data = getenv("QUERY_STRING");

  if (sscanf(data, "name=%99s", name) == 1)
  {
    printf("<p>Hi %s. Nice to meet you!</p>", name);
    printf("<p>What kind of animal are you interested in?</p>");
  }
  else
  {
    printf("<p>Invalid Data!</p>");
  }

  printf("</body></html>");
  return 0;
}