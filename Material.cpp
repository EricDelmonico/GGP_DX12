#include "Material.h"
#include "DX12Helper.h"

Material::Material(
    Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState,
    DirectX::XMFLOAT2 uvScale,
    DirectX::XMFLOAT2 uvOffset) :
    pipelineState(pipelineState),
    uvScale(uvScale),
    uvOffset(uvOffset),
    colorTint(DirectX::XMFLOAT3(1, 1, 1)),
    finalized(false),
    finalGPUHandleForSRVs({}),
    textureSRVsBySlot()
{
}

DirectX::XMFLOAT3 Material::GetColorTint()
{
    return colorTint;
}

DirectX::XMFLOAT2 Material::GetUVScale()
{
    return uvScale;
}

DirectX::XMFLOAT2 Material::GetUVOffset()
{
    return uvOffset;
}

Microsoft::WRL::ComPtr<ID3D12PipelineState> Material::GetPipelineState()
{
    return pipelineState;
}

D3D12_GPU_DESCRIPTOR_HANDLE Material::GetFinalGPUHandleForSRVs()
{
    return finalGPUHandleForSRVs;
}

void Material::SetColorTint(DirectX::XMFLOAT3 _colorTint)
{
    colorTint = _colorTint;
}

void Material::SetUVScale(DirectX::XMFLOAT2 uvScale)
{
    this->uvScale = uvScale;
}

void Material::SetUVOffset(DirectX::XMFLOAT2 uvOffset)
{
    this->uvOffset = uvOffset;
}

void Material::AddTexture(D3D12_CPU_DESCRIPTOR_HANDLE srv, int slot)
{
    textureSRVsBySlot[slot] = srv;
}

void Material::FinalizeMaterial()
{
    if (finalized) return;

    finalGPUHandleForSRVs = DX12Helper::GetInstance().CopySRVsToDescriptorHeapAndGetGPUDescriptorHandle(textureSRVsBySlot[0], 1);
    for (int i = 1; i < 4; i++) 
    {
        DX12Helper::GetInstance().CopySRVsToDescriptorHeapAndGetGPUDescriptorHandle(textureSRVsBySlot[i], 1);
    }
}
