
CC = g++ -std=c++17

EXECUTABLE = run.exe

SOURCES = main.cpp   \
	  avl_tree\avl_tree.cpp \
	  testing\generator\random_tree_generator.cpp \
	  testing\utilities\middle_result.cpp \
	  testing\insert_tester.cpp \
	  testing\custom\custom_insert_tester.cpp \
	  testing\find_tester.cpp \
	  testing\best_case\insert.cpp \
	  testing\best_case\find.cpp \
	  testing\middle_case\insert.cpp \
	  testing\middle_case\find.cpp \
	  testing\worst_case\insert.cpp \
	  testing\worst_case\find.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ 

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	del $(OBJECTS)
	del ${EXECUTABLE}