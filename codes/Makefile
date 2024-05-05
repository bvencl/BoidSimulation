TARGET = main
CXX = g++
CXXFLAGS = -g -Wall -pedantic
LDFLAGS = -L"C:/Users/venib/vcpkg/installed/x64-windows/lib"
CPPFLAGS = -I"C:/Users/venib/vcpkg/installed/x64-windows/include"

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(SRCDIR)/*.h)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.d)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $(CXXFLAGS) -MMD $<

include $(DEPS)

$(DEPS): ;

debug: CXXFLAGS += -DDEBUG
debug: $(BINDIR)/$(TARGET)

.PHONY: clean
clean:
	del obj\*.* bin\*.* /s

.PHONY: doc
doc: $(SOURCES) $(HEADERS)
	doxygen