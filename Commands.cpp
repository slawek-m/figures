#include "Commands.h"
#include <iostream>

AddFigureCmd::AddFigureCmd(CanvasManager &cm, const RectangleParams &params)
    : Command(cm) {
  m_id = m_cm.AddRectangle(params.ulx, params.uly, params.lrx, params.lry,
                           params.color);
};

AddFigureCmd::AddFigureCmd(CanvasManager &cm, const CircleParams &params)
    : Command(cm) {
  m_id = m_cm.AddCircle(params.center_x, params.center_y, params.radius,
                        params.color);
};

AddFigureCmd::AddFigureCmd(CanvasManager &cm, const TriangleParams &params)
    : Command(cm) {
  m_id = m_cm.AddTriangle(params.vertex_x, params.vertex_y, params.height,
                          params.color);
};

void AddFigureCmd::Execute() {
  m_cm.DrawFigure(m_id);
  std::cout << "added figure id: " << m_id << std::endl;
};

bool AddFigureCmd::Validate(int &id) {
  id = m_id;
  return m_cm.Validate(m_id);
};

int AddFigureCmd::GetId() const { return m_id; }

RemoveFigureCmd::RemoveFigureCmd(CanvasManager &cm, int id)
    : Command(cm), m_id(id){};

void RemoveFigureCmd::Execute() {
  m_cm.RemoveFigure(m_id);
  std::cout << "removed figure id: " << m_id << std::endl;
};

bool RemoveFigureCmd::Validate(int &id) {
  id = m_id;
  return m_cm.Validate(m_id);
};

MoveFigureCmd::MoveFigureCmd(CanvasManager &cm, int id, int offset_x,
                             int offset_y)
    : Command(cm), m_id(id), m_offset_x(offset_x), m_offset_y(offset_y){};

void MoveFigureCmd::Execute() {
  m_cm.MoveFigure(m_id, m_offset_x, m_offset_y);
  std::cout << "moved figure id: " << m_id << std::endl;
};

bool MoveFigureCmd::Validate(int &id) {
  id = m_id;
  return m_cm.Validate(m_id);
};

ColorFigureCmd::ColorFigureCmd(CanvasManager &cm, int id, int color)
    : Command(cm), m_id(id), m_color(color){};

void ColorFigureCmd::Execute() {
  m_cm.ColorFigure(m_id, m_color);
  std::cout << "color figure id: " << m_id << std::endl;
};

bool ColorFigureCmd::Validate(int &id) {
  id = m_id;
  return m_cm.Validate(m_id);
};
