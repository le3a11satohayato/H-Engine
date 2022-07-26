#pragma once

#include <d3dx12.h>
#include <dxgi1_6.h>
#include <dinput.h>
#include <xstring>
#include <vector>
#include <wrl.h>
#include "WindowsAPI.h"
#include "Singleton.h"
#include <dxgi.h>
#include <Xinput.h>
#include <d3d12.h>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

using namespace std;
using namespace Microsoft::WRL;

class DirectXBase : public Singleton<DirectXBase> {
public:
	static WindowsAPI windowsAPI;						//WindowsAPIクラス
	static ComPtr<ID3D12Debug> debugController;
	static ComPtr<ID3D12Device5> dev;
	static ComPtr<IDXGIFactory6> dxgiFactory;
	static vector<ComPtr<IDXGIAdapter1>> adapters;		//アダプターの列挙用
	static ComPtr<IDXGIAdapter1> tmpAdapter;			//特定の名前を持つアダプターオブジェクトを入れる
	static vector<D3D_FEATURE_LEVEL> levels;			//対応レベルの配列
	static D3D_FEATURE_LEVEL featureLevel;
	static ComPtr<IDXGISwapChain4> swapchain;
	static ComPtr<ID3D12CommandAllocator> cmdAllocator;
	static ComPtr<ID3D12GraphicsCommandList4> cmdList;
	static ComPtr<ID3D12CommandQueue> cmdQueue;
	static ComPtr<ID3D12DescriptorHeap> rtvHeaps;
	static vector<ComPtr<ID3D12Resource>> backBuffers;
	static D3D12_DESCRIPTOR_HEAP_DESC heapDesc;
	static ComPtr<ID3D12Resource> depthBuffer;			//深度バッファ
	static ComPtr<ID3D12DescriptorHeap> dsvHeap;		//深度バッファ用ディスクリプタヒープ
	static ComPtr<ID3D12Fence> fence;
	static UINT64 fenceVal;
	static IDirectInput8* dinput;						//DirectInputオブジェクト
	static IDirectInputDevice8* devkeybord;				//キーボードオブジェクト
	static IDirectInputDevice8* devmouse;				//マウスオブジェクト


public:
	//コンストラクタ
	friend Singleton<DirectXBase>;
	DirectXBase();
	//初期化処理
	void Init();
	//毎フレーム処理(描画前処理)
	void BeforeDrawing();
	//毎フレーム処理(描画後処理)
	void AfterDrawing();

	//レンダーターゲットをセット
	void SetRenderTarget();
	//描画後のリソースバリア
	void ResourceBarrierAfter();

	//imgui用ヒープ生成
	ComPtr<ID3D12DescriptorHeap> CreateDescriptorHeaoForImgui();
};