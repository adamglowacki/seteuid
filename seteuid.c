#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int usage(char *app);

int main(int argc, char **argv) {
  if (argc < 1)
    return 1;
  char *app = argv[0];
  if (argc < 3)
    return usage(app);

  uid_t uid = 0;
  if (sscanf(argv[1], "%d", &uid) != 1)
    return usage(app);
  if (seteuid(uid) != 0) {
    perror("seteuid");
    return 1;
  }

  execvp(argv[2], argv + 2);
  perror("execvp");
  return 1;
}

static int usage(char *app) {
  fprintf(stderr, "Usage: %s <UID> ...\n", app);
  return 1;
}
