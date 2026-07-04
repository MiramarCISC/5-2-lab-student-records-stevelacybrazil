CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

APP_TARGET = main
TEST_TARGET = test_student_records

APP_SOURCES = src/main.cpp src/student_records.cpp
TEST_SOURCES = tests/test_student_records.cpp src/student_records.cpp

.PHONY: all test clean run

all: $(APP_TARGET)

$(APP_TARGET): $(APP_SOURCES)
	$(CXX) $(CXXFLAGS) $(APP_SOURCES) -o $(APP_TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

run: $(APP_TARGET)
	./$(APP_TARGET)

clean:
	rm -f $(APP_TARGET) $(TEST_TARGET)
