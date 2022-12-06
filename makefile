CPP=g++
CPPFLAGS= -g -std=c++17

SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.h)
BIN=bin
PROG=stockMarketGame

.PHONY: all clean
all: $(BIN)/$(PROG)

$(BIN)/$(PROG): $(OBJS) $(OBJ) $(BIN)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS) $(OBJ) $(BIN)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ):
	mkdir $(OBJ)

$(BIN):
	mkdir $(BIN)

clean:
	$(RM) -r $(OBJ) $(BIN)