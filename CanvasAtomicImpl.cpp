#include "CanvasAtomicImpl.h"
#include <iostream>
#include <vector>

template <class T>
CanvasAtomicImpl<T>::CanvasAtomicImpl() : m_x_size(0), m_y_size(0){};

template <class T>
CanvasAtomicImpl<T>::CanvasAtomicImpl(const CanvasAtomicImpl &canvas) {
  std::copy(canvas.m_canvas.begin(), canvas.m_canvas.end(),
            back_inserter(m_canvas));
  m_x_size = canvas.m_x_size;
  m_y_size = canvas.m_y_size;
}

template <class T> void CanvasAtomicImpl<T>::Resize(int x_size, int y_size) {
  m_canvas.resize(y_size);
  for (int y = 0; y < y_size; ++y) {
    m_canvas.at(y).resize(x_size);
    for (int x = 0; x < x_size; ++x) {
      m_canvas.at(y).at(x) = 0;
    }
  }
  m_x_size = x_size;
  m_y_size = y_size;
}

template <class T> T CanvasAtomicImpl<T>::GetColor(int x, int y) {
  return m_canvas.at(y).at(x).load();
};

template <class T> void CanvasAtomicImpl<T>::SetColor(int x, int y, T color) {
  m_canvas.at(y).at(x) += color;
};

template <class T> void CanvasAtomicImpl<T>::GetSize(int &x_size, int &y_size) {
  x_size = m_x_size;
  y_size = m_y_size;
};

template <class T> void CanvasAtomicImpl<T>::DrawCanvas() {
  for (int y = 0; y < m_y_size; ++y) {
    for (int x = 0; x < m_x_size; ++x) {
      std::cout << m_canvas.at(y).at(x).load();
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

template <class T> std::unique_ptr<CanvasImpl<T>> CanvasAtomicImpl<T>::Clone() {
  return std::make_unique<CanvasAtomicImpl>(*this);
}

template class CanvasAtomicImpl<int>;