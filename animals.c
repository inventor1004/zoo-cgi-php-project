#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // create the file pointer to get the animal discription txt file
    FILE *ifp;
    char line[100];

    char filePath[50];
    strcpy(filePath, "./theZoo/");

    if (ifp == NULL)
    {
      printf("<h1 class ='greeting' style='color:red'>Can not open the file.</h1>");
      return 1;
    }
    else
    {
      printf("<h1 class ='greeting'>Hi <u>%s</u>. You choose <u>%s</u>! Let me tell you about it!</h1>", name, animal);

      if (strcmp(animal, "dragon") == 0)
      {
        strcat(filePath, "dragon.txt");
      }
      else if (strcmp(animal, "unicorn") == 0)
      {
        strcat(filePath, "unicorn.txt");
      }
      else if (strcmp(animal, "pegasus") == 0)
      {
        strcat(filePath, "pegasus.txt");
      }
      else if (strcmp(animal, "hydra") == 0)
      {
        strcat(filePath, "hydra.txt");
      }
      else if (strcmp(animal, "cerberus") == 0)
      {
        strcat(filePath, "cerberus.txt");
      }
      else if (strcmp(animal, "drunk-friend") == 0)
      {
        strcat(filePath, "drunk-friend.txt");
      }

      ifp = fopen(filePath, "r");

      while (fgets(line, sizeof(line), ifp) != NULL)
      {
        printf("%s", line);
      }
      fclose(ifp);
    }
  }
  else
  {
    printf("<h1>Invalid Data!</h1>");
  }

  printf("</body></html>");
  return 0;
}