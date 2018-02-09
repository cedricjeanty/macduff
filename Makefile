CXXFLAGS += $(shell pkg-config --cflags opencv) -I. -g
LDFLAGS += $(shell pkg-config --libs opencv)


all: main.cpp macduff.cpp macduff.h
	g++ $(CXXFLAGS) macduff.cpp main.cpp $(LDFLAGS) -o macduff

clean:
		rm -f macduff
