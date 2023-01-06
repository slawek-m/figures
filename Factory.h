#ifndef FACTORY_H
#define FACTORY_H

#include "Batch.h"
#include "BatchParallel.h"
#include "CanvasAtomicImpl.h"
#include "CanvasManager.h"
#include "CanvasNonAtomicImpl.h"
#include <memory>

/*template <class T, template <class R> class U> class Factory {
public:
  Factory(int size_x, int size_y)
      : m_canvas_impl(std::make_unique<U<T>>()), m_size_x(size_x),
        m_size_y(size_y){};
  std::shared_ptr<CanvasManager<T>> CreateCanvasManager() {
    m_canvas_manager = std::make_shared<CanvasManager<T>>(
        std::move(m_canvas_impl), m_size_x, m_size_y);
    return m_canvas_manager;
  };
  std::unique_ptr<Batch<T>> CreateBatch() {
    return std::make_unique<BatchParallel<T>>(*m_canvas_manager);
  };

private:
  std::unique_ptr<U<T>> m_canvas_impl;
  int m_size_x;
  int m_size_y;
  std::shared_ptr<CanvasManager<T>> m_canvas_manager;
};*/

template <class T, template <class R> class U> class Factory {};

template <class T> class Factory<T, CanvasAtomicImpl> {
public:
  Factory(int size_x, int size_y)
      : m_canvas_impl(std::make_unique<CanvasAtomicImpl<T>>()),
        m_size_x(size_x), m_size_y(size_y){};
  std::shared_ptr<CanvasManager<T>> CreateCanvasManager() {
    m_canvas_manager = std::make_shared<CanvasManager<T>>(
        std::move(m_canvas_impl), m_size_x, m_size_y);
    return m_canvas_manager;
  };
  std::unique_ptr<Batch<T>> CreateBatch() {
    return std::make_unique<BatchParallel<T>>(*m_canvas_manager);
  };

private:
  std::unique_ptr<CanvasAtomicImpl<T>> m_canvas_impl;
  int m_size_x;
  int m_size_y;
  std::shared_ptr<CanvasManager<T>> m_canvas_manager;
};

template <class T> class Factory<T, CanvasNonAtomicImpl> {
public:
  Factory(int size_x, int size_y)
      : m_canvas_impl(std::make_unique<CanvasNonAtomicImpl<T>>()),
        m_size_x(size_x), m_size_y(size_y){};
  std::shared_ptr<CanvasManager<T>> CreateCanvasManager() {
    m_canvas_manager = std::make_shared<CanvasManager<T>>(
        std::move(m_canvas_impl), m_size_x, m_size_y);
    return m_canvas_manager;
  };
  std::unique_ptr<Batch<T>> CreateBatch() {
    return std::make_unique<Batch<T>>(*m_canvas_manager);
  };

private:
  std::unique_ptr<CanvasNonAtomicImpl<T>> m_canvas_impl;
  int m_size_x;
  int m_size_y;
  std::shared_ptr<CanvasManager<T>> m_canvas_manager;
};

#endif
