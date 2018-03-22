PROGRAM = wol
OBJS = wolcommand.o WakeOnLan.o

CXXFLAGS = -Wall -O2

.SUFFIXES: .cpp .o

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $^

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)

