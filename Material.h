#pragma once
#include <d3d12.h>
#include <DirectXMath.h>
#include <wrl/client.h>

class Material
{
public:
    Material(Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState, DirectX::XMFLOAT2 uvScale, DirectX::XMFLOAT2 uvOffset);

    DirectX::XMFLOAT3 GetColorTint();
    DirectX::XMFLOAT2 GetUVScale();
    DirectX::XMFLOAT2 GetUVOffset();
    Microsoft::WRL::ComPtr<ID3D12PipelineState> GetPipelineState();
    D3D12_GPU_DESCRIPTOR_HANDLE GetFinalGPUHandleForSRVs();
    void SetColorTint(DirectX::XMFLOAT3 _colorTint);
    void SetUVScale(DirectX::XMFLOAT2 uvScale);
    void SetUVOffset(DirectX::XMFLOAT2 uvOffset);
    void AddTexture(D3D12_CPU_DESCRIPTOR_HANDLE srv, int slot);
    void FinalizeMaterial();

private:
    DirectX::XMFLOAT3 colorTint;
    DirectX::XMFLOAT2 uvScale;
    DirectX::XMFLOAT2 uvOffset;
    bool finalized;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
    D3D12_CPU_DESCRIPTOR_HANDLE textureSRVsBySlot[4];
    D3D12_GPU_DESCRIPTOR_HANDLE finalGPUHandleForSRVs;
};

