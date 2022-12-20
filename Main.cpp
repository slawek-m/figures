#include "Batch.h"
#include <iostream>

int main() {
  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{3, 3, 5, 5, 2};

    bool res = bt.AddFigure(r1)
                   .AddFigure(r2)
                   .RemoveFigure(1)
                   .MoveFigure(2, 1, 1)
                   .Execute()
                   .Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{0, 0, 2, 2, 2};

    bool res =
        bt.AddFigure(r1).AddFigure(r2).MoveFigure(2, 3, 3).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{0, 0, 2, 2, 2};

    bool res =
        bt.AddFigure(r1).AddFigure(r2).MoveFigure(2, 1, 1).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{3, 3, 5, 5, 2};

    bool res = bt.AddFigure(r1).AddFigure(r2).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();

    auto clone = cm.CloneCanvas();
    CanvasManager cm2(*clone);
    // cm2.ShowCanvas();

    res = bt.MoveFigure(2, -3, -3).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    if (res) {
      cm.ShowCanvas();
    } else {
      std::cout << "recovering canvas: " << std::endl;
      cm2.ShowCanvas();
    }
  }

  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{3, 3, 5, 5, 2};

    bool res = bt.AddFigure(r1).AddFigure(r2).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();

    res = bt.ColorFigure(2, 4).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    CircleParams c1{6, 6, 4, 1};

    bool res = bt.AddFigure(c1).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();

    res = bt.MoveFigure(1, 1, 1).ColorFigure(1, 4).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    CanvasManager cm(16, 16);
    Batch bt(cm);

    TriangleParams t1{1, 1, 4, 1};

    bool res = bt.AddFigure(t1).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  return 0;
}
