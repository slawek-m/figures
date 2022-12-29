Main: Main.o BatchParallel.o Batch.o Commands.o CanvasManager.o Canvas.o CanvasAtomicImpl.o CanvasNonAtomicImpl.o Rectangle.o Circle.o Triangle.o
	g++ Main.o BatchParallel.o Batch.o Commands.o CanvasManager.o Canvas.o CanvasAtomicImpl.o CanvasNonAtomicImpl.o Rectangle.o Circle.o Triangle.o -o Main

BatchParallel.o: BatchParallel.cpp BatchParallel.h
	g++ -Wall -c BatchParallel.cpp -o BatchParallel.o

Batch.o: Batch.cpp Batch.h
	g++ -Wall -c Batch.cpp -o Batch.o

Commands.o: Commands.cpp Commands.h
	g++ -Wall -c Commands.cpp -o Commands.o

CanvasManager.o: CanvasManager.cpp CanvasManager.h
	g++ -Wall -c CanvasManager.cpp -o CanvasManager.o

Canvas.o: Canvas.cpp Canvas.h
	g++ -Wall -c Canvas.cpp -o Canvas.o

CanvasAtomicImpl.o: CanvasAtomicImpl.cpp CanvasAtomicImpl.h
	g++ -Wall -c CanvasAtomicImpl.cpp -o CanvasAtomicImpl.o

CanvasNonAtomicImpl.o: CanvasNonAtomicImpl.cpp CanvasNonAtomicImpl.h
	g++ -Wall -c CanvasNonAtomicImpl.cpp -o CanvasNonAtomicImpl.o

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -Wall -c Rectangle.cpp -o Rectangle.o

Circle.o: Circle.cpp Circle.h
	g++ -Wall -c Circle.cpp -o Circle.o

Triangle.o: Triangle.cpp Triangle.h
	g++ -Wall -c Triangle.cpp -o Triangle.o

clean:
	rm -f *.o Main

