#include "pch.h"
#include "Renderer.h"
#include "GDIHelper.h"
#include "Asset.h"


void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + x + ScreenWidth * -y;
	*(dest + offset) = GetGDI().currentColor;
}

void PutPixel(int x, int y, const Vector3 & color)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + x + ScreenWidth * -y;
	*(dest + offset) = RGB(color.z, color.y, color.x);
}

void DrawLine(const Vector3& start, const Vector3& dir, const int& length)
{
	for (int i = 0; i <= length; i++) {
		Vector3 v = start + i * dir;
		PutPixel(v.x, v.y);
	}
}

void DrawLine(const Vector3& p1, const Vector3& p2)
{
	Vector3 dir = p2 - p1;
	float length = Max(Abs(dir.x), Abs(dir.y));
	dir /= length;
	DrawLine(p1, dir, length);
}

void Renderer::Render(Matrix3x3 matrix, Texture* texture)
{
	resource = texture;
	
	Vertex* vertices = new Vertex[texture->verticesCount];
	for (int i = 0; i < texture->verticesCount; i++) {
		vertices[i].pos = texture->vertices[i].pos * matrix;
		vertices[i].color = texture->vertices[i].color;
		vertices[i].normal = texture->vertices[i].normal;
	}
	for (int i = 0; i < texture->indicesCount; i += 3) {
		DrawTriangle(
			vertices[texture->indices[i]], 
			vertices[texture->indices[i + 1]], 
			vertices[texture->indices[i + 2]]);
	}

	delete[] vertices;
}

template <typename T>
const int sign(const T& val)
{
	return (T(0) < val) - (val < T(0));
}

void Renderer::DrawTriangle(Vertex v1, Vertex v2, Vertex v3) {
	if (v1.pos.y < v2.pos.y) {
		Swap(v1, v2);
	}
	if (v1.pos.y < v3.pos.y) {
		Swap(v1, v3);
	}
	if (v2.pos.y < v3.pos.y) {
		Swap(v2, v3);
	}

	Vector3 d1 = v2.pos - v1.pos;
	Vector3 d2 = v3.pos - v1.pos;
	Vector3 d3 = v3.pos - v2.pos;

	Vector3 u = d1;
	Vector3 v = d2;

	int d1Len = Abs(d1.y);
	int d2Len = Abs(d2.y);
	int d3Len = Abs(d3.y);

	if (d1Len != 0) {
		d1.x /= d1Len;
		d1.y = -1.0f;
	}
	if (d2Len != 0) {
		d2.x /= d2Len;
		d2.y = -1.0f;
	}
	if (d3Len != 0) {
		d3.x /= d3Len;
		d3.y = -1.0f;
	}

	float div = 1 / (Dot(u, u) * Dot(v, v) - Dot(u, v) * Dot(v, u));

	int y = v1.pos.y;

	for (int i = 0; i <= d1Len; i++, y--) {
		Vector3Int start{ v1.pos + d1 * i };
		Vector3Int end{ v1.pos + d2 * i };
		if (start.x > end.x) {
			Swap(start.x, end.x);
		}
		for (int j = start.x; j <= end.x; j++) {
			Vector3 w = Vector2Int(j, y) - v1.pos;
			float s = (Dot(w, u) * Dot(v, v) - Dot(w, v) * Dot(v, u)) * div;
			float t = (Dot(w, v) * Dot(u, u) - Dot(w, u) * Dot(u, v)) * div;
			Vertex pixel{ Vector2Int(j, y),
			   (1 - s - t) * v1.color + s * v2.color + t * v3.color,
			   (1 - s - t) * v1.normal + s * v2.normal + t * v3.normal };
			PutPixel(pixel);
		}
	}
	for (int i = 0; i <= d3Len; i++, y--) {
		Vector3Int start{ v1.pos + d1 * Max(d1Len, 1) + d3 * i };
		Vector3Int end{ v1.pos + d2 * (d1Len + i) };
		if (start.x > end.x) {
			Swap(start.x, end.x);
		}
		for (int j = start.x; j <= end.x; j++) {
			Vector3 w = Vector2Int(j, y) - v1.pos;
			float s = (Dot(w, u) * Dot(v, v) - Dot(w, v) * Dot(v, u)) * div;
			float t = (Dot(w, v) * Dot(u, u) - Dot(w, u) * Dot(u, v)) * div;
			Vertex pixel{ Vector2Int(j, y),
			   (1 - s - t) * v1.color + s * v2.color + t * v3.color,
			   (1 - s - t) * v1.normal + s * v2.normal + t * v3.normal };
			PutPixel(pixel);
		}
	}
}


//void Renderer::DrawTriangle(Vertex _v1, Vertex _v2, Vertex _v3)
//{
//	Vertex vts[3]{ _v1,_v2,_v3 };
//	std::sort(vts, vts + 3, [&](const Vertex& a, const Vertex& b) {return a.pos.y > b.pos.y; });
//
//	auto& v1 = vts[0];
//	auto& v2 = vts[1];
//	auto& v3 = vts[2];
//
//	if (v1.pos.y == v3.pos.y)
//	{
//		DrawFlatSideTriangle(v1, v2, v3);
//	}
//	else if (v1.pos.y == v2.pos.y)
//	{
//		DrawFlatSideTriangle(v3, v1, v2);
//	}
//	else
//	{
//		float x = v1.pos.x - (v1.pos.y - v2.pos.y) * (v1.pos.x - v3.pos.x) / (v1.pos.y - v3.pos.y);
//		Vertex v4(Vector2(round(x), v2.pos.y), Vector3(1, 1, 1));
//		DrawFlatSideTriangle(v1, v2, v4); // up-side
//		DrawFlatSideTriangle(v3, v2, v4); // down-side
//	}
//}

void Renderer::DrawFlatSideTriangle(Vertex v1, Vertex v2, Vertex v3)
{
	Vector2 vt1 = v1.pos;
	Vector2 vt2 = v1.pos;

	Vector2Int d1 = v2.pos - v1.pos;
	Vector2Int d2 = v3.pos - v1.pos;
	Vector2Int sign1{ Clamp(d1.x, -1.0f, 1.0f) , Clamp(d1.y, -1.0f, 1.0f) };
	Vector2Int sign2{ Clamp(d2.x, -1.0f, 1.0f) , Clamp(d2.y, -1.0f, 1.0f) };

	d1.x = Abs(d1.x);
	d1.y = Abs(d1.y);
	d2.x = Abs(d2.x);
	d2.y = Abs(d2.y);

	const bool isChanged1 = d1.y > d1.x;
	const bool isChanged2 = d2.y > d2.x;

	if (isChanged1)
	{
		Swap(d1.x, d1.y);
	}

	if (isChanged2)
	{
		Swap(d2.x, d2.y);
	}

	Vector3 u = v2.pos - v1.pos;
	Vector3 v = v3.pos - v1.pos;
	float div = 1 / (Dot(u, u) * Dot(v, v) - Dot(u, v) * Dot(v, u));

	int e1 = 2 * d1.y - d1.x;
	int e2 = 2 * d2.y - d2.x;

	for (int i = 0; i <= d1.x; ++i)
	{
		//edge 1
		while (e1 >= 0)
		{
			if (isChanged1)
				vt1.x += sign1.x;
			else
				vt1.y += sign1.y;
			e1 -= 2 * d1.x;
		}

		if (isChanged1)
			vt1.y += sign1.y;
		else
			vt1.x += sign1.x;

		e1 += 2 * d1.y;

		//edge 2
		while (vt2.y != vt1.y)
		{
			while (e2 >= 0)
			{
				if (isChanged2)
					vt2.x += sign2.x;
				else
					vt2.y += sign2.y;
				e2 -= 2 * d2.x;
			}

			if (isChanged2)
				vt2.y += sign2.y;
			else
				vt2.x += sign2.x;

			e2 += 2 * d2.y;
		}

		{

			int dx = abs(vt2.x - vt1.x);
			int dy = abs(vt2.y - vt1.y);

			const int signx = sign(vt2.x - vt1.x);
			const int signy = sign(vt2.y - vt1.y);

			const bool isChanged = dy > dx;

			if (isChanged)
			{
				Swap(dx, dy);
			}

			Vector2Int current = vt1;

			int e = 2 * dy - dx;
			for (int i = 0; i <= dx; ++i)
			{
				//PutPixel
				Vector3 w = current - v1.pos;
				float s = (Dot(w, u) * Dot(v, v) - Dot(w, v) * Dot(v, u)) * div;
				float t = (Dot(w, v) * Dot(u, u) - Dot(w, u) * Dot(u, v)) * div;
				Vertex pixel{ current,
				   (1 - s - t) * v1.color + s * v2.color + t * v3.color,
				   (1 - s - t) * v1.normal + s * v2.normal + t * v3.normal };
				PutPixel(pixel);

				if (e >= 0)
				{
					if (isChanged)
						current.x += signx;
					else
						current.y += signy;

					e -= 2 * dx;
				}

				if (isChanged)
					current.y += signy;
				else
					current.x += signx;

				e += 2 * dy;
			}
		}
	}
}

void ColorRenderer::PutPixel(const Vertex& v)
{
	if (!IsInRange(v.pos.x, v.pos.y)) return;

	static ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenOffset + v.pos.x + ScreenWidth * v.pos.y;
	*(dest + offset) = RGB(Clamp(v.color.z, 0, 255), Clamp(v.color.y, 0, 255), Clamp(v.color.x, 0, 255));
}

void BitmapRenderer::PutPixel(const Vertex& v)
{
	if (!IsInRange(v.pos.x, v.pos.y)) return;

	static ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenOffset + v.pos.x + ScreenWidth * v.pos.y;
	DWORD target = *(dest + offset);
	DWORD source = ((Texture*)resource)->GetPixelUV(Clamp(v.normal.x, 0.0f, 1.0f), Clamp(v.normal.y, 0.0f, 1.0f));
	double sourceAlpha = (source >> 24) * 0.003921568627451;
	*(dest + offset) = source * sourceAlpha + target * (1 - sourceAlpha);
}
