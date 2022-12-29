#ifndef BATCHPARALLEL_H
#define BATCHPARALLEL_H

#include <memory>
#include <vector>

#include "Batch.h"

template <class T> class BatchParallel : public Batch<T> {
public:
  BatchParallel(CanvasManager<T> &cm);
  ~BatchParallel() = default;

  BatchParallel &Execute() override;

private:
  unsigned int m_threads_num;
};

#endif
