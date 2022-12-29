#include "Canvas.h"
#include <iostream>

template <class T>
Canvas<T>::Canvas(std::unique_ptr<CanvasImpl<T>> impl)
    : m_impl(std::move(impl)), m_x_size(0), m_y_size(0){};

template <class T>
Canvas<T>::Canvas(std::unique_ptr<CanvasImpl<T>> impl, int x_size, int y_size)
    : m_impl(std::move(impl)), m_x_size(x_size), m_y_size(y_size) {
  m_impl->Resize(x_size, y_size);
};

template <class T>
Canvas<T>::Canvas(const Canvas &canvas)
    : m_impl(std::move(canvas.m_impl->Clone())), m_x_size(canvas.m_x_size),
      m_y_size(canvas.m_y_size) {}
// m_impl must be a pointer (not reference). If reference used this
// m_impl(std::move(canvas.m_impl->Clone())) doesn't work correctly some slicing
// happens

template <class T> T Canvas<T>::GetColor(int x, int y) {
  return m_impl->GetColor(x, y);
};

template <class T> void Canvas<T>::SetColor(int x, int y, T color) {
  m_impl->SetColor(x, y, color);
};

template <class T> void Canvas<T>::GetSize(int &x_size, int &y_size) {
  m_impl->GetSize(x_size, y_size);
};

template <class T> void Canvas<T>::DrawCanvas() { m_impl->DrawCanvas(); }

template <class T> std::unique_ptr<Canvas<T>> Canvas<T>::Clone() {
  return std::make_unique<Canvas>(*this);
}

template class Canvas<int>;
