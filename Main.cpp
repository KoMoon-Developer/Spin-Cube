#include <Cube.hpp>
#include <chrono>

using std::cout;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void render(float *buffer) {
  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_QUADS);

  glVertex3f(buffer[0], buffer[1], buffer[2]);
  glVertex3f(buffer[3], buffer[4], buffer[5]);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(buffer[6], buffer[7], buffer[8]);
  glVertex3f(buffer[9], buffer[10], buffer[11]);

  glEnd();

  glFlush();
}

int main() {
  if (!glfwInit()) {
    cout << "Failed to initialize GLFW.\n";
    return 1;
  }

  GLVer version = {2, 1};

  vec3f top[4] = {0.2f,  0.2f, -0.2f, -0.2f, 0.2f, -0.2f,
                  -0.2f, 0.2f, 0.2f,  0.2f,  0.2f, 0.2f};

  vec3f right[4] = {0.2f, 0.2f,  -0.2f, 0.2f, 0.2f,  0.2f,
                    0.2f, -0.2f, 0.2f,  0.2f, -0.2f, -0.2f};

  vec3f left[4] = {-0.2f, 0.2f,  0.2f,  -0.2f, 0.2f,  -0.2f,
                   -0.2f, -0.2f, -0.2f, -0.2f, -0.2f, 0.2f};

  vec3f front[4] = {0.2f,  0.2f,  0.2f, -0.2f, 0.2f,  0.2f,
                    -0.2f, -0.2f, 0.2f, 0.2f,  -0.2f, 0.2f};

  vec3f bottom[4] = {0.2f,  -0.2f, 0.2f,  -0.2f, -0.2f, 0.2f,
                     -0.2f, -0.2f, -0.2f, 0.2f,  -0.2f, -0.2f};

  vec3f back[4] = {0.2f,  -0.2f, -0.2f, -0.2f, -0.2f, -0.2f,
                   -0.2f, 0.2f,  -0.2f, 0.2f,  0.2f,  -0.2f};

  CWindow window;
  window.initWindow(800, 600, "Cube in OpenGL", NULL, NULL, version);
  glfwMakeContextCurrent(window.getWindow());

  CShape3D<6, 4> quad;
  quad.setFace(0, vec3f({0, 0, 0}), top);
  quad.setFace(1, vec3f({0, 0, 0}), bottom);
  quad.setFace(2, vec3f({0, 0, 0}), front);
  quad.setFace(3, vec3f({0, 0, 0}), back);
  quad.setFace(4, vec3f({0, 0, 0.}), right);
  quad.setFace(5, vec3f({0, 0, 0}), left);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "Failed to initialize GLAD.\n";
    return 1;
  }

  glfwSetFramebufferSizeCallback(window.getWindow(), framebuffer_size_callback);

  float time = 0;
  vec3f quadPos({0, 0, 0});

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);

  while (!glfwWindowShouldClose(window.getWindow())) {

    auto start = std::chrono::high_resolution_clock::now();

    // Clear Screen
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (uint i = 0; i < 6; i++)
      render(quad.getFace(i));

    glfwSwapBuffers(window.getWindow());
    glfwPollEvents();

    if (time > 0.1f) {
      time = 0;
      glRotatef(5.0f, 1.0f, 1.0f, 0.0f);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    time = time + std::chrono::duration<float>(duration).count();
  }

  glfwTerminate();
  return 0;
}
