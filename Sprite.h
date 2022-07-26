#pragma once
#include "SpriteBase.h"

class Sprite : public SpriteBase {

private:

	// 共通の生成処理
	void CommonGenerate(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID);

public:

	// 生成処理
	void GenerateForTexture(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID, LPCWSTR fileName);
	void GenerateForColor(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID, XMFLOAT4 color);
	void GenerateSpecifyTextureID(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID, int textureID);

	// 描画処理
	void Draw();

	// 色を変える処理
	inline void SetColor(const XMFLOAT4& color) { constBufferDataB0.color = color; }

};