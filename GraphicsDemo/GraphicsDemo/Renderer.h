#pragma once
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Dependencies/SDL2/include/SDL.h"
#include "Mesh.h"
#include <vector>

enum { TRIANGLE, QUAD, TOTAL_POLYGONS };

class Renderer
{
public:
	~Renderer();

	static Renderer& GetInstance()
	{
		static Renderer instance;
		return instance;
	}

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete;

	void Run();
	void RenderMeshes();
	void InitMesh(GLuint meshType, char* texId);
	SDL_Window* GetAppWindow() { return window; }

	Mesh& GetComponent(char* textureId);

private:
	void SetWindowAttribs();
	bool InitSDLAndOpenGL();
	SDL_Window* window;
	int m_screenWidth, m_screenHeight;

private:
	Renderer() {};
	std::vector<Mesh*> m_meshes;
};

#endif // !__RENDERER_H__