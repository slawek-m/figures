#ifndef CANVASNONATOMICIMPL_H
#define CANVASNONATOMICIMPL_H

#include "CanvasImpl.h"
#include <vector>

template <class T> class CanvasNonAtomicImpl : public CanvasImpl<T> {
public:
  CanvasNonAtomicImpl();
  CanvasNonAtomicImpl(const CanvasNonAtomicImpl &canvas);
  ~CanvasNonAtomicImpl() = default;
  void Resize(int x_size, int y_size) final;
  T GetColor(int x, int y) final;
  void SetColor(int x, int y, T color) final;
  void GetSize(int &x_size, int &y_size) final;
  void DrawCanvas() final;
  std::unique_ptr<CanvasImpl<T>> Clone() final;

private:
  int m_x_size;
  int m_y_size;
  std::vector<std::vector<T>> m_canvas;
};

#endif
