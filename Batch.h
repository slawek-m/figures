#ifndef BATCH_H
#define BATCH_H

#include <memory>
#include <vector>

#include "Commands.h"

template <class T> class Batch {
public:
  Batch(CanvasManager<T> &cm);
  ~Batch() = default;

  Batch &AddFigure(const RectangleParams &params);
  Batch &AddFigure(const CircleParams &params);
  Batch &AddFigure(const TriangleParams &params);
  Batch &RemoveFigure(int id);
  Batch &MoveFigure(int id, int offset_x, int offset_y);
  Batch &ColorFigure(int id, int color);

  Batch &Execute();
  Batch &ExecuteParallel();
  bool Validate();

private:
  CanvasManager<T> &m_cm;
  std::vector<std::unique_ptr<Command<T>>> m_batch;
  unsigned int m_threads_num;
};

#endif
