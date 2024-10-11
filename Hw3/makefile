# 定义编译器  
CXX = g++  
# 定义编译选项，-g 添加调试信息，-Wall 开启所有警告  
CXXFLAGS = -g -Wall  
  
# 定义目标文件  
TARGET = main  
  
# 定义依赖的源文件  
SOURCES = main.cpp  
  
# 定义目标规则  
$(TARGET): $(SOURCES)  
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)  
  
# 伪目标，清理编译生成的文件  
clean:  
	rm -f $(TARGET) *.o  
  
# 声明伪目标，确保这些目标不会与文件名冲突  
.PHONY: clean  