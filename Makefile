TARGET = libImageEditor.so
CXX = g++

CORE_DIR = ./src
HEADER_DIR = ./include
LIB_DIR = ./lib

CXXFLAGS = -I$(HEADER_DIR) --shared -fPIC -lpng

SRC = $(wildcard $(CORE_DIR)/*.cpp) $(wildcard $(CORE_DIR)/ImagePNG/*.cpp) $(wildcard $(CORE_DIR)/ImageBMP/*.cpp)

all : create_lib_folder $(TARGET)

$(TARGET) : $(SRC)
	g++ $^ $(CXXFLAGS) -o $(LIB_DIR)/$@

install_required_soft : 
	user sudo apt-get install libpng-dev -y

create_lib_folder :
	@mkdir -p $(LIB_DIR)

clean :
	@rm -rf $(LIB_DIR)

test :
	