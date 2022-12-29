#include "CanvasNonAtomicImpl.h"
#include <iostream>
#include <vector>

template <class T>
CanvasNonAtomicImpl<T>::CanvasNonAtomicImpl() : m_x_size(0), m_y_size(0){};

template <class T>
CanvasNonAtomicImpl<T>::CanvasNonAtomicImpl(const CanvasNonAtomicImpl &canvas) {
  std::copy(canvas.m_canvas.begin(), canvas.m_canvas.end(),
            back_inserter(m_canvas));
  m_x_size = canvas.m_x_size;
  m_y_size = canvas.m_y_size;
}

template <class T> void CanvasNonAtomicImpl<T>::Resize(int x_size, int y_size) {
  m_canvas.resize(y_size);
  for (int y = 0; y < y_size; ++y) {
    m_canvas.at(y).resize(x_size, 0);
  }
  m_x_size = x_size;
  m_y_size = y_size;
}

template <class T> T CanvasNonAtomicImpl<T>::GetColor(int x, int y) {
  return m_canvas.at(y).at(x);
};

template <class T>
void CanvasNonAtomicImpl<T>::SetColor(int x, int y, T color) {
  m_canvas.at(y).at(x) += color;
};

template <class T>
void CanvasNonAtomicImpl<T>::GetSize(int &x_size, int &y_size) {
  x_size = m_x_size;
  y_size = m_y_size;
};

template <class T> void CanvasNonAtomicImpl<T>::DrawCanvas() {
  for (int y = 0; y < m_y_size; ++y) {
    for (int x = 0; x < m_x_size; ++x) {
      std::cout << m_canvas.at(y).at(x);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

template <class T>
std::unique_ptr<CanvasImpl<T>> CanvasNonAtomicImpl<T>::Clone() {
  return std::make_unique<CanvasNonAtomicImpl>(*this);
}

template class CanvasNonAtomicImpl<int>;