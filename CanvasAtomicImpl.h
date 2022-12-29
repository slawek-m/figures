#ifndef CANVASATOMICIMPL_H
#define CANVASATOMICIMPL_H

#include "CanvasImpl.h"
#include <atomic>
#include <vector>

template <typename T> struct atomwrapper {
  std::atomic<T> m_a;

  atomwrapper() : m_a(){};
  atomwrapper(const std::atomic<T> &a) : m_a(a.load()){};
  atomwrapper(const atomwrapper &other) : m_a(other.m_a.load()) {}

  atomwrapper &operator=(const atomwrapper &other) {
    m_a.store(other.m_a.load());
  }

  T load() { return m_a.load(); }

  atomwrapper &operator=(T val) {
    m_a.store(val);
    return *this;
  }

  atomwrapper &operator+=(T val) {
    m_a += val;
    return *this;
  }
};

template <class T> class CanvasAtomicImpl : public CanvasImpl<T> {
public:
  CanvasAtomicImpl();
  CanvasAtomicImpl(const CanvasAtomicImpl &canvas);
  ~CanvasAtomicImpl() = default;
  void Resize(int x_size, int y_size) final;
  T GetColor(int x, int y) final;
  void SetColor(int x, int y, T color) final;
  void GetSize(int &x_size, int &y_size) final;
  void DrawCanvas() final;
  std::unique_ptr<CanvasImpl<T>> Clone() final;

private:
  int m_x_size;
  int m_y_size;
  std::vector<std::vector<atomwrapper<T>>> m_canvas;
};

#endif
