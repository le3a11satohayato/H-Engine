#pragma once
#include "Object3DBase.h"


class Object3D : public Object3DBase {

public:

	// 生成処理
	void Generate(XMFLOAT3 centerPos, int projectionID, int piplineID, string directoryPath, string modelFileName, LPCWSTR textureFileName, bool isSmoothing);

	// 描画処理
	void Draw();

	// パイプラインを更新する処理
	void SetPiplineID(int piplineID);

	// インデックスサイズを取得する
	inline int GetIndexSize() { return index.size(); }

	// 頂点コンテナを取得する
	inline vector<Vertex> GetVertex() { return vertex; }

	// 頂点インデックスコンテナを取得する
	inline vector<unsigned short> GetIndex() { return index; }

	/*-- レイトレーシング実装時に臨時で実装したやつ --*/

	// 頂点バッファを取得する。
	inline Microsoft::WRL::ComPtr<ID3D12Resource> GetVertexBuff() { return vertBuff; }

};