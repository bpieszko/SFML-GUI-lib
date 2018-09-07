PACKAGE			= SFML-GUI-lib
VERSION			= 1.0.0

SRC_DIR			= src
BUILD_DIR		= build
INCLUDE_DIR		= include

CXX				= g++-7 -std=c++17
CXXFLAGS		= -I$(INCLUDE_DIR) -DVERSION=\"$(VERSION)\"

HEADERS			= $(wildcard include/*.hpp)
SOURCES			= $(wildcard src/*.cpp)
LIBS			= -lsfml-graphics -lsfml-window -lsfml-system
EXTRAS			= Makefile README.md
DISTRIBUTION	= $(HEADERS) $(SOURCES) $(EXTRAS)

.PHONY: all clean dist

all: $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

test: $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
	$(CXX) $(CXXFLAGS) -o app.e $^ main.cpp $(LIBS)

clean: 
	rm -f $(BUILD_DIR)/*.o $(PACKAGE)$(LIBEXT) app.e

dist:
	mkdir $(PACKAGE)-$(VERSION)
	mkdir $(PACKAGE)-$(VERSION)/$(BUILD_DIR)
	cp --parents $(DISTRIBUTION) $(PACKAGE)-$(VERSION)
	tar -zcvf $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE)-$(VERSION)
	rm -rf $(PACKAGE)-$(VERSION)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $<)