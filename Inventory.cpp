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
	IMAGEMANAGER->Render(image, 100, 100, 2, 2);
}

void Inventory::Release()
{
}
