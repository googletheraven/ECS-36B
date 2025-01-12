CXXFLAGS=-Wall
CXX=g++
all: testPoint testShape checkpack

checkpack: checkpack.o Shape.o Point.o Domain.o
	$(CXX) -o $@ $^

testPoint: testPoint.o Point.o
	$(CXX) -o $@ $^

testShape: testShape.o Point.o Shape.o
	$(CXX) -o $@ $^

clean:
	rm -f checkpack testPoint testShape *.o