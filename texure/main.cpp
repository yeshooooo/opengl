#include <gl/glew.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <iostream>
//#define STB_IMAGE_IMPLEMENTATION//这行必须有，预处理器会修改头文件，让其只包含相关的函数定义源码，等于说将这个头文件变为一个cpp文件
//#include <stb_image.h>//导入图片用的


void window_size_callback(GLFWwindow* window, int width, int height);

//设置窗口大小
const unsigned int	Window_width = 1600;
const unsigned int Window_height = 1200;

int main() {

	//实例化GLFW窗口
	glfwInit();
	const char* glsl_version = "#version 330";
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
	glfwSwapInterval(1);
	//初始化glew
	glewInit();




	

	//创建并绑定Imgui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	//设置渲染后端
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version); 

	//设置字体部分
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\simhei.ttf", 15.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
	
	//初始化各种状态信息，后面用，暂时不用封装起来
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


	//渲染循环
	while (!glfwWindowShouldClose(window))
	{
		//事件处理部分
		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.//不要将鼠标输入数据发送到主应用程序 dispatch 发送，派遣
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.不要将键盘输入数据发送到主应用程序
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.//将所有输入传送到imgui，将他们隐藏通过这讲个标志隐藏
		glfwPollEvents();

		//启动imgui
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		//用Begin和End来创建一个窗口
		{
			ImGui::Begin(u8"设置");
			ImGui::ColorEdit4(u8"背景颜色", (float*)&clear_color);
			ImGui::End();

		}



		//渲染窗口颜色
		ImGui::Render();
		int view_width, view_height;
		glfwGetFramebufferSize(window, &view_width, &view_height);
		glViewport(0, 0, view_width, view_height);
		glClearColor(clear_color.x*clear_color.w, clear_color.y*clear_color.w, clear_color.z* clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);


		//
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);//交换双缓存







	}

	//释放内存
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;



}




