#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::Init()
{
	image = IMAGEMANAGER->FindImage("Inventory_Frame");
}

void Inventory::Update()
{
}

void Inventory::Render()
{
	IMAGEMANAGER->UICenterRender(image, WINSIZE_X/2, WINSIZE_Y/2, 1.4, 1.4);
}

void Inventory::Release()
{
}
