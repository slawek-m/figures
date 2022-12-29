#include <future>

#include "BatchParallel.h"

template <class T>
BatchParallel<T>::BatchParallel(CanvasManager<T> &cm) : Batch<T>(cm) {
  m_threads_num = std::thread::hardware_concurrency();
};

template <class T> BatchParallel<T> &BatchParallel<T>::Execute() {
  // use vector to store futures from std::async
  // if the futures were not stored, the std::async would run sequentially
  unsigned int n = Batch<T>::m_batch.size() / m_threads_num;
  unsigned int r = Batch<T>::m_batch.size() % m_threads_num;
  std::vector<std::future<void>> fv;
  unsigned int i;
  for (i = 0; i < n; ++i) {
    for (unsigned int j = 0; j < m_threads_num; ++j) {
      auto &ptr = Batch<T>::m_batch.at((i * m_threads_num) + j);
      fv.push_back(
          std::async(std::launch::async, &Command<T>::Execute, ptr.get()));
    }
  }

  for (unsigned int j = 0; j < r; ++j) {
    auto &ptr = Batch<T>::m_batch.at((i * m_threads_num) + j);
    fv.push_back(
        std::async(std::launch::async, &Command<T>::Execute, ptr.get()));
  }

  return *this;
};

template class BatchParallel<int>;
