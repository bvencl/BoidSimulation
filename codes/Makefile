CXX = g++
CXXFLAGS = -Wall -g -DMEMTRACE
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = includes

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CXXFLAGS += -I$(INCDIR)
    MUSICF = /home/vncl/git/VBW5N9_nagy_hazi_feladat/codes/zenejo.ogg
    LDFLAGS =
else ifeq ($(OS),Windows_NT)
    CXXFLAGS += -IC:\msys64\mingw64\include
    MUSICF = C:/path/to/your/music.ogg
    LDFLAGS = -LC:\msys64\mingw64\lib
endif

CXXFLAGS += -DMUSIC_FILE_PATH=\"$(MUSICF)\"

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJECTS:.o=.d)

HEADERS = $(wildcard $(INCDIR)/*.h)
UML_OUTPUT = $(BINDIR)/output.puml

$(BINDIR)/main: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -MMD -c $< -o $@

uml: $(HEADERS)
	hpp2plantuml -i "$(INCDIR)/*.h" -o $(UML_OUTPUT)

clean:
	$(RM) $(OBJDIR)/*.o $(OBJDIR)/*.d $(BINDIR)/main

debug: CXXFLAGS += -DDEBUG
debug: $(BINDIR)/main
