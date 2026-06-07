CXX = g++
CXXFLAGS = -Wall -std=gnu++11
SRCS = $(wildcard *.cpp)

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
OBJ_DIR := obj
BIN_DIR := bin

all: WeightedGraph

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

$(BIN_DIR)/WeightedGraph: $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o bin\WeightedGraph $(OBJS)
	
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

WeightedGraph: $(BIN_DIR)/WeightedGraph

clean:
	rm -f $(OBJS) $(TARGET)