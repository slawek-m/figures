#include <algorithm>

#include "Batch.h"

Batch::Batch(CanvasManager &cm) : m_cm(cm){};

Batch &Batch::AddFigure(const RectangleParams &params) {
  m_batch.push_back(std::make_unique<AddFigureCmd>(m_cm, params));
  return *this;
};

Batch &Batch::AddFigure(const CircleParams &params) {
  m_batch.push_back(std::make_unique<AddFigureCmd>(m_cm, params));
  return *this;
};

Batch &Batch::AddFigure(const TriangleParams &params) {
  m_batch.push_back(std::make_unique<AddFigureCmd>(m_cm, params));
  return *this;
};

Batch &Batch::RemoveFigure(int id) {
  m_batch.push_back(std::make_unique<RemoveFigureCmd>(m_cm, id));
  return *this;
};

Batch &Batch::MoveFigure(int id, int offset_x, int offset_y) {
  m_batch.push_back(
      std::make_unique<MoveFigureCmd>(m_cm, id, offset_x, offset_y));
  return *this;
};

Batch &Batch::ColorFigure(int id, int color) {
  m_batch.push_back(std::make_unique<ColorFigureCmd>(m_cm, id, color));
  return *this;
};

Batch &Batch::Execute() {
  std::for_each(m_batch.begin(), m_batch.end(),
                [](auto &ptr) { ptr->Execute(); });
  return *this;
};

bool Batch::Validate() {
  std::vector<std::pair<int, bool>> overlap_status;
  std::for_each(m_batch.begin(), m_batch.end(), [&overlap_status](auto &ptr) {
    int id;
    bool res = ptr->Validate(id);
    overlap_status.push_back(std::make_pair(id, res));
  });

  bool res = true;
  if (std::find_if(overlap_status.begin(), overlap_status.end(),
                   [](const auto &pair) { return pair.second == false; }) !=
      overlap_status.end())
    res = false;

  m_batch.clear();

  return res;
}
