#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("/output/index.html", "w");
    if (file == NULL) {
        return 1;
    }

    char hostname[128];
    gethostname(hostname, sizeof(hostname));

    fprintf(file, "<html><body>");
    fprintf(file, "<h1>Serwer HTTP na Nginx</h1>");
    fprintf(file, "<p>IP Serwera: (pobierane dynamicznie przez przeglądarkę)</p>");
    fprintf(file, "<p>Nazwa hosta: %s</p>", hostname);
    fprintf(file, "<p>Wersja aplikacji: %s</p>", getenv("VERSION") ? getenv("VERSION") : "brak");
    fprintf(file, "</body></html>");

    fclose(file);
    return 0;
}
