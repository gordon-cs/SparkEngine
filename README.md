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

### A few things to note
- All header files need to be put into the include directory next to the src directory
- When creating a new .cpp file, you must add the path of the new file to CMakeLists.txt in the ```set(SOURCE)``` block, exactly like it is currently structured.
- To contribute, please make changes on a new branch and create a pull request to merge into develop

- Good documentation for OpenGL can be found [here](docs.gl)
