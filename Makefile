CXXFLAGS = -g -Wall -Werror -std=c++17
LDLIBS =

PRGM  = project
SRCS := $(wildcard *.cc)
OBJS := $(SRCS:.cc=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean test

all: $(PRGM)

$(PRGM): $(OBJS)
	$(CXX) $(OBJS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

test: $(PRGM)
	./$<
	make clean

clean:
	rm -rf $(OBJS) $(DEPS) $(PRGM)

-include $(DEPS)
