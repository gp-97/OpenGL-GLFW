#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

int main() {
	GLFWwindow *window;

	if (!glfwInit()) {
		cout << "Couldn't initialize GLFW Init" << '\n';
		return 1;
	}

	window = glfwCreateWindow(800, 600, "Hello World",
                           nullptr, nullptr);

	if (!window) {
		cout << "No window" << '\n';
		return 1;
	}

	glfwMakeContextCurrent(window);

	auto data = new unsigned char[100 * 100 * 3];
	for (int x=0; x<100; ++x) {
	    for (int y=0; y<100; ++y) {
	        data[y * 100 * 3 + x * 3] = 0xff;
            data[y * 100 * 3 + x * 3 + 1] = 0x00;
            data[y * 100 * 3 + x * 3 + 2] = 0x00;
	    }
	}
	for (int x=25; x<75; ++x) {
	    for (int y=25; y<75; ++y) {
	        data[y * 100 * 3 + x * 3] = 0x00;
	        data[y * 100 * 3 + x * 3 + 1] = 0xff;
            data[y * 100 * 3 + x * 3 + 2] = 0x00;
	    }
	}

	// Set background color
	glClearColor(0.1, 0.5, 0.7, 1.0);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, data);
		glfwSwapBuffers(window);
		glfwWaitEvents();
	}

	return 0;
}
