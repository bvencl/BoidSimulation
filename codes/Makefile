
ifeq ($(OS),Windows_NT)
	SFML_ROOT = C:\Users\venib\vcpkg\buildtrees\sfml\src
	MUSICF = C:\\git\\HAZI\\codes\\zenejo.ogg
	MUSIC_FILE_PATH_DEF = -DMUSIC_FILE_PATH="\"$(MUSICF)\""
	# LDFLAGS += $(SFML_ROOT)/bin
	# CXXFLAGS += -I$(SFML_ROOT)/include
else
	MUSICF = /home/vncl/git/VBW5N9_nagy_hazi_feladat/codes/zenejo.ogg
	MUSIC_FILE_PATH_DEF = -DMUSIC_FILE_PATH=\"$(MUSICF)\"
endif

CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic -fdiagnostics-color=always
CXXFLAGS += -DMEMTRACE #itt van a gond alapvetően :/
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCFLAGS = -I$(INCDIR)

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = includes

CXXFLAGS += $(MUSIC_FILE_PATH_DEF)

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
ifeq ($(OS),Windows_NT)
	-del $(OBJDIR)\*.o $(OBJDIR)\*.d $(BINDIR)\main.exe /Q
else
	rm -f  $(OBJDIR)/*.o $(OBJDIR)/*.d $(BINDIR)/main
endif