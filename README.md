# Spark Engine - An engine built with C++ and OpenGL

## Building and running locally (Note  - This was tested in a Linux environment)

- You will need the following: 
  - cmake
  - The dependencies mentioned [here](https://www.glfw.org/docs/3.3/compile_guide.html#compile_deps_x11)

- run ```git clone --recursive git@github.com:Kindlewing/SparkEngine.git```
- ```cd {clone-directory}/SparkEngine/Spark```
- ```cmake -S . -B build/```
- ```cd build/```
- ```make```
- finally - ```./Spark``` to run
