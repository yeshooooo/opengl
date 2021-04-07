#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <gl/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION//���б����У�Ԥ���������޸�ͷ�ļ�������ֻ������صĺ�������Դ�룬����˵�����ͷ�ļ���Ϊһ��cpp�ļ�
#include <stb_image.h>//����ͼƬ�õ�


void window_size_callback(GLFWwindow* window, int width, int height);

//���ô��ڴ�С
const unsigned int	Window_width = 1600;
const unsigned int Window_height = 1200;

int main() {

	//ʵ����GLFW����
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//�����������Ϊ����Ӧƻ��ϵͳ
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	//����һ�����ڣ�������ڶ����������кʹ�����ص����ݣ����һᱻglfw����������Ƶ�����õ���
	//�˴�����һ���жϴ����Ƿ񴴽��ɹ����ж�����
	GLFWwindow* window = glfwCreateWindow(Window_width, Window_height, "LearnOpenGlAndImGui", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "����GLFW����ʧ��" << std::endl;
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, window_size_callback);
	glfwSwapInterval(1);

	//��ʼ��gl3w
	gl3wInit();
	//��������Imgui
	ImGui::CreateContext();


}



