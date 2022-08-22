# CMake 示例程序

## 01HelloWorld

HelloWorld 入门示例

## 02Header

演示如何给项目添加 Header


## 03Lib
演示如何添加库

## 04Sublib
演示库作为一个单独项目引入主项目


## PUBLIC，PRIVATE，INTERFACE

以target_link_libraries(A B)命令为例，从理解的角度解释：

* PRIVATE 依赖项B仅链接到目标A，若有C链接了目标A，C不链接依赖项B
* INTERFACE 依赖项B并不链接到目标A，若有C链接了目标A，C会链接依赖项B
* PUBLIC 依赖项B链接到目标A，若有C链接了目标A，C也会链接依赖项B
从使用的角度解释，若有C链接了目标A：

* 如果依赖项B仅用于目标A的实现，且不在头文件中提供给C使用，使用 PRIVATE
* 如果依赖项B不用于目标A的实现，仅在头文件中作为接口提供给C使用，使用 INTERFACE
* 如果依赖项B不仅用于目标A的实现，而且在头文件提供给C使用，使用 PUBLIC


## 常用的变量

* PROJECT_SOURCE_DIR
* PROJECT_BINARY_DIR