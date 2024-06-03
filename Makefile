TARGET = libImageEditor.so
CXX = g++

SRC_DIR = ./src
INCLUDE_DIR = ./include
LIB_DIR = ./lib

CXXFLAGS = -I$(INCLUDE_DIR) --shared -fPIC
LDFLAGS = -lpng

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRC_DIR),*.cpp)

all : create_lib_dir $(TARGET)

$(TARGET) : $(SRC)
	g++ $^ $(CXXFLAGS) $(LDFLAGS) -o $(LIB_DIR)/$@

install_required_soft : 
	sudo apt-get install libpng-dev -y

remove_src_dir :
	# @rm -rf $(SRC_DIR)

create_lib_dir :
	@mkdir -p $(LIB_DIR)

clean :
	@rm -rf $(LIB_DIR)

test :
	@echo There are no tests yet :\(