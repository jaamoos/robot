#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#define COMMAND_STOP 0
#define COMMAND_RUN 1
#define COMMAND_CLOSE 500

struct Request {
  int command;
};

#endif
