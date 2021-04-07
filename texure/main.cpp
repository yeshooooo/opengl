#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <gl/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION//这行必须有，预处理器会修改头文件，让其只包含相关的函数定义源码，等于说将这个头文件变为一个cpp文件
#include <stb_image.h>//导入图片用的


void window_size_callback(GLFWwindow* window, int width, int height);

//设置窗口大小
const unsigned int	Window_width = 1600;
const unsigned int Window_height = 1200;

int main() {

	//实例化GLFW窗口
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//下面的条件宏为了适应苹果系统
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	//创建一个窗口，这个窗口对象存放了所有和窗口相关的数据，而且会被glfw的其他函数频繁的用到。
	//此处增加一个判断窗口是否创建成功的判断条件
	GLFWwindow* window = glfwCreateWindow(Window_width, Window_height, "LearnOpenGlAndImGui", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "建立GLFW窗口失败" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, window_size_callback);
	glfwSwapInterval(1);

	//初始化gl3w
	gl3wInit();
	//创建并绑定Imgui
	ImGui::CreateContext();


}



