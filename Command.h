#ifndef COMMAND_H
#define COMMAND_H

#include "CanvasManager.h"

template <class T> class Command {
public:
  Command(CanvasManager<T> &cm) : m_cm(cm){};
  virtual ~Command() = default;
  virtual void Execute() = 0;
  virtual bool Validate(int &id) = 0;

protected:
  CanvasManager<T> &m_cm;
};

#endif
