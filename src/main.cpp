#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

int main() {
	GLFWwindow *window;

	if (!glfwInit()) {
		cout << "Couldn't initialize GLFW Init" << '\n';
		return 1;
	}

	window = glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);

	if (!window) {
		cout << "No window" << '\n';
		return 1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glfwWaitEvents();
	}

	return 0;
}
