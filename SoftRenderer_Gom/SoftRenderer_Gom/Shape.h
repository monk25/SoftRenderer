#pragma once
#include "Renderer.h"

class Shape
{
public:
	Shape() : vertices(nullptr), indices(nullptr), shaderRenderer(nullptr) {}
	virtual ~Shape() {
		if (vertices)
			delete[] vertices;
		if (indices)
			delete[] indices;
	}

public:
	void SetRenderer(Renderer* renderer);
	virtual void Render() {
		shaderRenderer->Render(vertices, indices, indicesSize);
	}

protected:
	Vertex* vertices;
	int verticesSize;
	int* indices;
	int indicesSize;

private:
	Renderer* shaderRenderer;
};

class Triangle :
	public Shape
{
public:
	Triangle();
	Triangle(const Vector3& p1, const Vector3& p2, const Vector3& p3);
	Triangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);
	~Triangle() {}

public:
	void SetTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3);
	void SetTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);

private:
	void Initialize();
};

class Quad :
	public Shape
{
public:
	Quad();
	Quad(const int& left, const int& top, const int& right, const int& bottom);
	Quad(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4);
	Quad(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4);
	~Quad() {}

public:
	void SetQuad(const int& left, const int& top, const int& right, const int& bottom);
	void SetQuad(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4);
	void SetQuad(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4);

private:
	void Initialize();
};