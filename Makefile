# Email: nitzanwa@gmail.com

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/SquareMat.cpp
HEADERS = include/SquareMat.hpp

MAIN = Main.cpp
TEST = tests/test.cpp
DOCTEST = doctest.h  # רק אם הוא בתיקייה הראשית

MAIN_EXE = Main.out
TEST_EXE = test_exec

.PHONY: all Main test valgrind clean

# ברירת מחדל - קומפילציה והרצת Main
all: Main

# קמפול להרצת Main
Main: $(SRC) $(MAIN) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) $(MAIN) -o $(MAIN_EXE)
	./$(MAIN_EXE)

# קמפול והרצת הבדיקות
test: $(SRC) $(TEST) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST) -o $(TEST_EXE)
	./$(TEST_EXE)

# בדיקת זיכרון עם valgrind
valgrind: $(SRC) $(TEST) $(HEADERS)
	$(CXX) $(CXXFLAGS) -g $(SRC) $(TEST) -o $(TEST_EXE)
	valgrind --leak-check=full ./$(TEST_EXE)

# ניקוי קבצים בינאריים
clean:
	rm -f $(MAIN_EXE) $(TEST_EXE)
