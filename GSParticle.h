#pragma once
#include "GSParticleBase.h"
#include <vector>

class GSParticle : public GSParticleBase {

private:

	// 共通の生成処理
	void CommonGenerate(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int pipelineID, int instanceCount = 1);

public:

	// 生成処理
	void GenerateForTexture(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID, LPCWSTR fileName, int instanceCount = 1);
	void GenerateForColor(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID, XMFLOAT4 color, int instanceCount = 1);
	void GenerateSpecifyTextureID(XMFLOAT3 centerPos, XMFLOAT2 size, int projectionID, int piplineID, int textureID, int instanceCount = 1);

	// 描画処理
	void Draw();
	void DrawInstance(vector<GSConstBufferDataB0> instanceData);

	// 色を変える処理
	inline void ChangeColor(const XMFLOAT4& color) {

		constBufferDataB0.color = color;

	}
	// 色を取得する処理
	inline XMFLOAT4 GetColor() { return constBufferDataB0.color; }

};