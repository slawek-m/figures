#include "Factory.h"
#include <iostream>

int main() {
  {
    Factory<int, CanvasAtomicImpl> factory(80, 80);
    auto cm = factory.CreateCanvasManager();
    auto bt = factory.CreateBatch();

    RectangleParams r1{0, 0, 20, 20, 1};
    RectangleParams r2{30, 30, 50, 50, 2};

    bool res = bt->AddFigure(r1).AddFigure(r2).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm->ShowCanvas();

    res = bt->MoveFigure(1, 3, 3).MoveFigure(2, 3, 3).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm->ShowCanvas();
  }
  /*{
    auto cai = std::make_unique<CanvasAtomicImpl<int>>();
    auto bmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cai), 80, 80, bmtx);
    BatchParallel<int> bt(cm);

    RectangleParams r1{0, 0, 20, 20, 1};
    RectangleParams r2{30, 30, 50, 50, 2};

    bool res = bt.AddFigure(r1).AddFigure(r2).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();

    res = bt.MoveFigure(1, 3, 3).MoveFigure(2, 3, 3).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }*/

  {
    Factory<int, CanvasNonAtomicImpl> factory(16, 16);
    auto cm = factory.CreateCanvasManager();
    auto bt = factory.CreateBatch();

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{3, 3, 5, 5, 2};

    bool res = bt->AddFigure(r1)
                   .AddFigure(r2)
                   .RemoveFigure(1)
                   .MoveFigure(2, 1, 1)
                   .Execute()
                   .Validate();
    std::cout << "batch result: " << res << std::endl;
    cm->ShowCanvas();
  }
  /*{
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, fmtx);
    Batch<int> bt(cm);

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
  }*/

  {
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, std::move(fmtx));
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{0, 0, 2, 2, 2};

    bool res =
        bt.AddFigure(r1).AddFigure(r2).MoveFigure(2, 3, 3).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, std::move(fmtx));
    Batch bt(cm);

    RectangleParams r1{0, 0, 2, 2, 1};
    RectangleParams r2{0, 0, 2, 2, 2};

    bool res =
        bt.AddFigure(r1).AddFigure(r2).MoveFigure(2, 1, 1).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  {
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, std::move(fmtx));
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
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, std::move(fmtx));
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
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, std::move(fmtx));
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
    auto cnai = std::make_unique<CanvasNonAtomicImpl<int>>();
    auto fmtx = std::make_unique<MtxFree>();
    CanvasManager<int> cm(std::move(cnai), 16, 16, std::move(fmtx));
    Batch bt(cm);

    TriangleParams t1{1, 1, 4, 1};

    bool res = bt.AddFigure(t1).Execute().Validate();
    std::cout << "batch result: " << res << std::endl;
    cm.ShowCanvas();
  }

  return 0;
}
