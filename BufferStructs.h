#pragma once
#include <DirectXMath.h>
#include "Lights.h"

struct VertexShaderExternalData
{
    DirectX::XMFLOAT4X4 world;
    DirectX::XMFLOAT4X4 worldInv;
    DirectX::XMFLOAT4X4 view;
    DirectX::XMFLOAT4X4 proj;
};

struct PixelShaderExternalData
{
    DirectX::XMFLOAT2 uvScale;
    DirectX::XMFLOAT2 uvOffset;
    DirectX::XMFLOAT3 cameraPosition;
    int lightCount;
    Light lights[MAX_LIGHTS];
    DirectX::XMFLOAT3 colorTint;
    float __padding;
};