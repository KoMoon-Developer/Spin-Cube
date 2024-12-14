#include <Cube.hpp>
#include <cstring>

// CWindow class

void GL_COMPONENTS::CWindow::initWindow(int width, int height, string title,
                                        GLFWmonitor *monitor, GLFWwindow *share,
                                        GLVer version) {
  if (win == nullptr) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version[0]);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version[1]);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

    GLFWwindow *createWin;
    createWin = glfwCreateWindow(width, height, title.data(), monitor, share);
    if (createWin == NULL) {
      cout << "Falha na criacao da janela GLFW" << '\n';
    }
    win = createWin;
  }
}

GL_COMPONENTS::CWindow::CWindow() {};

GL_COMPONENTS::CWindow::CWindow(int width, int height, string title,
                                GLFWmonitor *monitor, GLFWwindow *share,
                                GLVer version) {
  initWindow(width, height, title, monitor, share, version);
}

void GL_COMPONENTS::CWindow::destroyWindow() {
  if (win != nullptr) {
    glfwDestroyWindow(win);
    cout << "janela foi destruida" << '\n';
  }
}

GL_COMPONENTS::CWindow::~CWindow() { destroyWindow(); }

GLFWwindow *GL_COMPONENTS::CWindow::getWindow() const { return win; }
