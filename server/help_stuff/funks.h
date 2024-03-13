#include <string.h>
#include <malloc.h>

char *join(char** list, const char* sep, int start, int count);

int sentence_length(char*);

char **parse_request(char*);