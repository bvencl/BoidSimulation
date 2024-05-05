CXX = g++
CXXFLAGS = -Wall -g 
CXXFLAGS += -IC:\msys64\mingw64\include
LDFLAGS = -LC:\msys64\mingw64\lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJECTS:.o=.d)

HEADERS = vector.h point.h basicboid.h rule.h logger.h flock.h
UML_OUTPUT = $(BINDIR)/output.puml

$(BINDIR)/main: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

uml: $(HEADERS)
	hpp2plantuml -i $(HEADERS) -o $(UML_OUTPUT)

clean:
	del $(OBJDIR)\*.o $(OBJDIR)\*.d $(BINDIR)\main.exe /Q

debug: CXXFLAGS += -DDEBUG
debug: $(BINDIR)/main