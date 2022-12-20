#ifndef COMMAND_H
#define COMMAND_H

#include "CanvasManager.h"

class Command {
public:
  Command(CanvasManager &cm) : m_cm(cm){};
  virtual ~Command() = default;
  virtual void Execute() = 0;
  virtual bool Validate(int &id) = 0;

protected:
  CanvasManager &m_cm;
};

#endif
