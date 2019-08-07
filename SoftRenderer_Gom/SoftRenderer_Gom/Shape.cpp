#include "pch.h"
#include "Shape.h"


void Shape::SetRenderer(Renderer* renderer)
{
	shaderRenderer = renderer;
}

Triangle::Triangle()
{
	Initialize();
	SetTriangle(
		Vertex{ Vector3{ -50.0f, -50.0f }, Vector3Int{ 255, 0, 0}, Vector2{0, 1} },
		Vertex{ Vector3{ 0.0f, 50.0f }, Vector3Int{ 0, 255, 0}, Vector2{0.5, 0} },
		Vertex{ Vector3{ 50.0f, -50.0f }, Vector3Int{ 0, 0, 255}, Vector2{1, 1} });
	SetRenderer(&BitmapRenderer::GetInstance());
}

Triangle::Triangle(const Vector3& p1, const Vector3& p2, const Vector3& p3)
{
	Initialize();
	SetTriangle(p1, p2, p3);
}

Triangle::Triangle(const Vertex& v1, const Vertex& v2, const Vertex& v3)
{
	Initialize();
	SetTriangle(v1, v2, v3);
}

void Triangle::SetTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3)
{
	vertices[0].pos = p1;
	vertices[1].pos = p2;
	vertices[2].pos = p3;
}

void Triangle::SetTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3)
{
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
}

void Triangle::Initialize()
{
	verticesSize = 3;
	indicesSize = 3;
	vertices = new Vertex[verticesSize];
	indices = new int[indicesSize]{ 0, 1, 2 };
	SetRenderer(&ColorRenderer::GetInstance());
}

Quad::Quad()
{
	Initialize();
	SetQuad(
		Vertex{ Vector3{-500,  500}, Vector3Int{255, 0, 0}, Vector2{0, 0} },
		Vertex{ Vector3{ 500,  500}, Vector3Int{0, 255, 0}, Vector2{1, 0} },
		Vertex{ Vector3{-500, -500}, Vector3Int{0, 0, 255}, Vector2{0, 1} },
		Vertex{ Vector3{ 500, -500}, Vector3Int{255, 255, 255}, Vector2{1, 1} }
	);
	SetRenderer(&BitmapRenderer::GetInstance());
}

Quad::Quad(const int& left, const int& top, const int& right, const int& bottom)
{
	Initialize();
	SetQuad(left, top, right, bottom);
}

Quad::Quad(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4)
{
	Initialize();
	SetQuad(p1, p2, p3, p4);
}

Quad::Quad(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4)
{
	SetQuad(v1, v2, v3, v4);
}

void Quad::SetQuad(const int & left, const int & top, const int & right, const int & bottom)
{
	vertices[0].pos = Vector3Int{ left, top };
	vertices[1].pos = Vector3Int{ right, top };
	vertices[2].pos = Vector3Int{ left, bottom };
	vertices[3].pos = Vector3Int{ right, bottom };
}

void Quad::SetQuad(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4)
{
	vertices[0].pos = p1;
	vertices[1].pos = p2;
	vertices[2].pos = p3;
	vertices[3].pos = p4;
}

void Quad::SetQuad(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4)
{
	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;
	vertices[3] = v4;
}

void Quad::Initialize()
{
	verticesSize = 4;
	indicesSize = 6;
	vertices = new Vertex[verticesSize];
	indices = new int[indicesSize] { 0, 1, 2, 1, 3, 2 };
	SetRenderer(&ColorRenderer::GetInstance());
}
