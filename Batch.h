#ifndef BATCH_H
#define BATCH_H

#include <memory>
#include <vector>

#include "Commands.h"

class Batch {
public:
  Batch(CanvasManager &cm);
  ~Batch() = default;

  Batch &AddFigure(const RectangleParams &params);
  Batch &AddFigure(const CircleParams &params);
  Batch &AddFigure(const TriangleParams &params);
  Batch &RemoveFigure(int id);
  Batch &MoveFigure(int id, int offset_x, int offset_y);
  Batch &ColorFigure(int id, int color);

  Batch &Execute();
  bool Validate();

private:
  CanvasManager &m_cm;
  std::vector<std::unique_ptr<Command>> m_batch;
};

#endif
