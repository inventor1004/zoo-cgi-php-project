#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

int main()
{
  char *data = NULL;
  int dataSize = 0;

  char name[100] = "";
  char animal[100] = "";

  printf("Content-type:text/html\r\n\r\n");
  printf("<html><head>");
  printf("<title> User Name INPUT CGI (GET)</title>");
  printf("<link href= 'style.css' rel='stylesheet'/>");
  printf("</head>\n");

  printf("<body>\n");
  data = getenv("QUERY_STRING");

  if (sscanf(data, "name=%99[^&]&animal=%99s", name, animal) == 2)
  {
    printf("<h1 class ='greeting'>Hi %s. You choose %s Nice to meet you!</h1>", name, animal);
    printf("<table>");
    printf("<td>What kind of animal are you interested in?</td>");
    printf("</table>");
  }
  else
  {
    printf("<p>Invalid Data!</p>");
  }

  printf("</body></html>");
  return 0;
}