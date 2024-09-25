# Makefile  
  
# 定义编译器  
CXX = g++  
  
# 定义编译选项  
CXXFLAGS = -Wall -std=c++11  
  
# 目标可执行文件  
TARGET = Chicken  
  
# 依赖的源文件  
SOURCES = Chicken.cpp  
  
# 默认目标  
all: $(TARGET)  
  
# 如何从源文件生成目标文件  
$(TARGET): $(SOURCES)  
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)  
  
# 清理编译生成的文件  
clean:  
	rm -f $(TARGET)  