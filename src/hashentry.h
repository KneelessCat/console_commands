#ifndef CONSOLE_COMMANDS_HASHENTRY_H
#define CONSOLE_COMMANDS_HASHENTRY_H

struct commandFunct;

struct bucket;

void setBucket(struct bucket *b, char *k, const struct commandFunct cf);

#endif