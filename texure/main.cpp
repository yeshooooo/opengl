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


	//��ʼ������״̬��Ϣ�������ã���ʱ���÷�װ����
	ImVec4 clear_color = ImVec4(0.45f, 0.55f,0.60f, 1.00f);

	

	//��������Imgui
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	//ImGui_ImplOpenGL3_Init(glsl_version); ������ɫ���汾����һ���Ǳ��룬��shader�ļ�����д����

	//�������岿��
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 15.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
	



	//��Ⱦѭ��
	while (!glfwWindowShouldClose(window))
	{
		//�¼�������
		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.//��Ҫ������������ݷ��͵���Ӧ�ó��� dispatch ���ͣ���ǲ
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.��Ҫ�������������ݷ��͵���Ӧ�ó���
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.//���������봫�͵�imgui������������ͨ���⽲����־����
		glfwPollEvents();

		//����imgui
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		//��Begin��End������һ������
		{
			ImGui::Begin(u8"����");
			ImGui::ColorEdit4(u8"��Ⱦ������ɫ", (float*)&clear_color);
			ImGui::End();

		}



		//��Ⱦ������ɫ
		int view_width, view_height;
		glfwGetFramebufferSize(window, &view_width, &view_height);
		glViewport(0, 0, view_width, view_height);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);


		//
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);//����˫����







	}

	//�ͷ��ڴ�
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;



}



