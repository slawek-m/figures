#ifndef FIGUREPARAMS_H
#define FIGUREPARAMS_H

struct RectangleParams {
  int ulx;
  int uly;
  int lrx;
  int lry;
  int color;
};

struct CircleParams {
  int center_x;
  int center_y;
  int radius;
  int color;
};

struct TriangleParams {
  int vertex_x;
  int vertex_y;
  int height;
  int color;
};

#endif
