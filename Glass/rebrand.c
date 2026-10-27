#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
void process(const char *path) {
    FILE *f = fopen(path, "r+");
    if (!f) return;
    fseek(f, 0, SEEK_END); long len = ftell(f); fseek(f, 0, SEEK_SET);
    char *buf = malloc(len+1); fread(buf, 1, len, f); buf[len]=0; fclose(f);
    for (int i=0; buf[i]; i++) if (strncmp(&buf[i],"ReactOS",7)==0) memcpy(&buf[i],"Glass(OS)",9);
    f = fopen(path, "w"); fwrite(buf, 1, len, f); fclose(f); free(buf);
}
int main() {
    DIR *d = opendir("."); struct dirent *e; while ((e=readdir(d))!=NULL) { process(e->d_name); }
    printf("Replaced ALL files in current dir\n"); return 0;
}
