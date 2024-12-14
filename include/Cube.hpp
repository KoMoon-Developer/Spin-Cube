#ifndef CUBE_HEADER
#define CUBE_HEADER

#include <glad/glad.h>
#include <string>

#include <GLFW/glfw3.h>
#include <iostream>

using std::cout;
using std::string;
using uint = unsigned int;
using GLVer = unsigned int[2];

namespace CB {

struct vec3f {
  float x;
  float y;
  float z;
};

template <typename VEC_T, uint vertexAmount> struct GLFace {
  VEC_T facePos;
  VEC_T vertex[vertexAmount];
};

} // namespace CB

namespace GL_COMPONENTS {

class CWindow final {
private:
  GLFWwindow *win = nullptr;

public:
  CWindow(int width, int height, string title, GLFWmonitor *monitor,
          GLFWwindow *share, GLVer version);
  CWindow();
  void initWindow(int width, int height, string title, GLFWmonitor *monitor,
                  GLFWwindow *share, GLVer version);
  void destroyWindow();
  ~CWindow();

  GLFWwindow *getWindow() const;
};

template <uint amount, uint vAmount> class CShape3D {
private:
  CB::GLFace<CB::vec3f, vAmount> faces[amount];
  float vertexs[amount][vAmount * 3];

public:
  void setVertexs();
  void setPos(uint index, CB::vec3f pos);
  float *getFace(uint index);
  void setFace(uint index, CB::vec3f pos, CB::vec3f data[vAmount]);
};

} // namespace GL_COMPONENTS

using CB::GLFace;
using CB::vec3f;
using GL_COMPONENTS::CShape3D;
using GL_COMPONENTS::CWindow;

#include <Cube.tpp>
#endif // !CUBE_HEADER
