#pragma once
#include "IBattleScene.h"
class CBattleItem :
    public IBattleScene
{
public:
    CBattleItem();
    virtual ~CBattleItem();

public:
    // IBattleScene��(��) ���� ��ӵ�
    virtual void Initialize(void) override;
    virtual void Update(void) override;
    virtual void Late_Update(void) override;
    virtual void Render(HDC hDC) override;
    virtual void Release(void) override;

};

