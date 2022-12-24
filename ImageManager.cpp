#include "stdafx.h"
#include "ImageManager.h"

ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
	for (auto iter : m_vectorImageList)
	{
		for (auto _iter : iter.second->GetImages())
		{
			SAFE_DELETE(_iter);
		}
		SAFE_DELETE(iter.second);
	}
	m_vectorImageList.clear();

	for (auto iter : m_tileImages)
	{
		SAFE_DELETE(iter);
	}
	m_tileImages.clear();

	for (auto iter : m_imageList)
	{
		SAFE_DELETE(iter.second);
	}
	m_imageList.clear();

	m_brush->Release();
	tf->Release();
}

void ImageManager::Init()
{
	factory = nullptr;
	RECT rc;
	GetClientRect(_hWnd, &rc);

	camera.x = 0;
	camera.y = 0;

	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory);
	pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(_hWnd, D2D1::SizeU(WINSIZE_X, WINSIZE_Y)), &pRT);

	CoInitialize(0);
	CoCreateInstance(CLSID_WICImagingFactory, 0, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory));

	IDWriteFactory* m_pDWriteFactory = nullptr;

	DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_pDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
	);

	m_pDWriteFactory->CreateTextFormat(
		L"맑음 고딕",                  // 폰트 패밀리 이름의 문자열
		NULL,                        // 폰트 컬렉션 객체, NULL=시스템 폰트 컬렉션
		DWRITE_FONT_WEIGHT_NORMAL,   // 폰트 굵기. LIGHT, NORMAL, BOLD 등.
		DWRITE_FONT_STYLE_NORMAL,    // 폰트 스타일. NORMAL, OBLIQUE, ITALIC.
		DWRITE_FONT_STRETCH_NORMAL,  // 폰트 간격. CONDENSED, NORMAL, MEDIUM, EXTEXDED 등.
		30,                          // 폰트 크기.
		L"ko",                         // 로케일을 문자열로 명시.  영어-미국=L"en-us", 한국어-한국=L"ko-kr"
		&tf
	);

	D2D1_COLOR_F color;
	color.a = 1;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pRT->CreateSolidColorBrush(color, &m_brush);

	m_pDWriteFactory->Release();
}

void ImageManager::LoadImages()
{
	//맵툴 UI 이미지
	AddImage("newFile", L"./MapFile/newFile.png");

	//예시 이미지
	AddImage("Frame_1SKill", L"./Resources/Frame_1SKill.png");
	AddImageVector("Ex_Idle", L"./Resources/Png/Idle/", 1, 6);

	//타일 이미지
	AddTileImage(L"./Resources/Tile/4Stage/01.png");
	AddTileImage(L"./Resources/Tile/4Stage/02.png");
	AddTileImage(L"./Resources/Tile/4Stage/03.png");
	AddTileImage(L"./Resources/Tile/4Stage/04.png");
	AddTileImage(L"./Resources/Tile/4Stage/05.png");
	AddTileImage(L"./Resources/Tile/4Stage/06.png");
	AddTileImage(L"./Resources/Tile/4Stage/07.png");
	AddTileImage(L"./Resources/Tile/4Stage/08.png");
	AddTileImage(L"./Resources/Tile/4Stage/09.png");
	AddTileImage(L"./Resources/Tile/4Stage/10.png");
	AddTileImage(L"./Resources/Tile/4Stage/11.png");
	AddTileImage(L"./Resources/Tile/4Stage/12.png");
	AddTileImage(L"./Resources/Tile/4Stage/13.png");
	AddTileImage(L"./Resources/Tile/4Stage/14.png");
	AddTileImage(L"./Resources/Tile/4Stage/15.png");
	AddTileImage(L"./Resources/Tile/4Stage/16.png");
	AddTileImage(L"./Resources/Tile/4Stage/17.png");
	AddTileImage(L"./Resources/Tile/4Stage/18.png");
	AddTileImage(L"./Resources/Tile/4Stage/19.png");
	AddTileImage(L"./Resources/Tile/4Stage/20.png");
	AddTileImage(L"./Resources/Tile/4Stage/21.png");
	AddTileImage(L"./Resources/Tile/4Stage/22.png");
	AddTileImage(L"./Resources/Tile/4Stage/23.png");
	AddTileImage(L"./Resources/Tile/4Stage/24.png");
	AddTileImage(L"./Resources/Tile/4Stage/25.png");
	AddTileImage(L"./Resources/Tile/4Stage/26.png");
	AddTileImage(L"./Resources/Tile/4Stage/27.png");
	AddTileImage(L"./Resources/Tile/4Stage/28.png");
	AddTileImage(L"./Resources/Tile/4Stage/29.png");
	AddTileImage(L"./Resources/Tile/4Stage/30.png");
	AddTileImage(L"./Resources/Tile/4Stage/31.png");
	AddTileImage(L"./Resources/Tile/4Stage/32.png");
	AddTileImage(L"./Resources/Tile/4Stage/33.png");
	AddTileImage(L"./Resources/Tile/4Stage/34.png");
	AddTileImage(L"./Resources/Tile/4Stage/35.png");
	AddTileImage(L"./Resources/Tile/4Stage/36.png");

	//배경 이미지
	AddImage("Moon", L"./Resources/BackGround/Boss_Stage_Moon.png");
	AddImage("Building", L"./Resources/BackGround/Boss_Stage_Building.png");
	AddImage("Lion", L"./Resources/BackGround/Boss_Stage_Lion.png");

	//보스 이미지
	AddImageVector("Boss", L"./Resources/Saint_Joanna/Phase_1/Casting/Boss/Ready/Casting_Ready_", 1, 7);

	// 맵 구조물 이미지
	AddStructureImage("statue", L"./Resources/Tile/4Stage/Structure/statue.png");
	AddStructureImage("arch1", L"./Resources/Tile/4Stage/Structure/arch1.png");
	AddStructureImage("arch2", L"./Resources/Tile/4Stage/Structure/arch2.png");
}

ID2D1Bitmap* ImageManager::AddBitmap(std::wstring path, UINT* Width, UINT* Height)
{
	ID2D1Bitmap* bitmap;
	IWICBitmapDecoder* decoder = nullptr;
	factory->CreateDecoderFromFilename(path.c_str(), 0, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &decoder);

	IWICBitmapFrameDecode* frameDecode = nullptr;
	decoder->GetFrame(0, &frameDecode);

	IWICFormatConverter* converter = nullptr;
	factory->CreateFormatConverter(&converter);

	converter->Initialize(frameDecode, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, 0, 0.0, WICBitmapPaletteTypeCustom);
	pRT->CreateBitmapFromWicBitmap(converter, 0, &bitmap);
	converter->GetSize(Width, Height);
	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return bitmap;
}

CImage* ImageManager::AddImage(const std::string key, std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_imageList.insert(std::make_pair(key, img));
	return img;
}

CImage* ImageManager::AddTileImage(std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_tileImages.push_back(img);
	return img;
}

CImage* ImageManager::AddStructureImage(std::string key, std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_structureImages.insert(make_pair(key, img));
	return nullptr;
}

CImage* ImageManager::FindImage(const std::string key)
{
	auto find = m_imageList.find(key);
	if (find != m_imageList.end())
	{
		return find->second;
	}
	cout << "이미지 key 없음 : " << key << "\n";
	return nullptr;
}

vImage* ImageManager::AddImageVector(const std::string key, std::wstring path, int startIndex, int endIndex)
{
	auto find = m_vectorImageList.find(key);

	if (find == m_vectorImageList.end())
	{
		vImage* imgs = new vImage();
		for (int i = startIndex; i <= endIndex; i++)
		{
			UINT _width = 0, _height = 0;
			std::wstring _path;
			if (i < 10)
			{
				_path = path + L"0" + std::to_wstring(i).c_str() + L".png";
			}
			else
			{
				_path = path + std::to_wstring(i).c_str() + L".png";
			}

			CImage* cImage = new CImage(AddBitmap(_path, &_width, &_height), _width, _height);
			imgs->AddImage(cImage);
		}
		m_vectorImageList.insert(std::make_pair(key, imgs));
		return imgs;
	}
	return nullptr;
}

vImage* ImageManager::FindImageVector(const std::string key)
{
	auto find = m_vectorImageList.find(key);
	if (find != m_vectorImageList.end())
	{
		return find->second;
	}
	cout << "애니메이션 key 없음 : " << key << "\n";
	return nullptr;
}

void ImageManager::DrawCircle(float x, float y, float width)
{
	D2D1_ELLIPSE ellipse;
	ellipse.radiusX = width;
	ellipse.radiusY = width;
	ellipse.point.x = 0;
	ellipse.point.y = 0;
	D2D1_COLOR_F color;
	color.b = 255;
	color.a = 255;
	color.r = 255;
	color.g = 255;

	D2D1_MATRIX_3X2_F mat;
	mat = D2D1::Matrix3x2F::Translation(x - width / 2, y - width / 2);
	pRT->SetTransform(&mat);
	pRT->CreateSolidColorBrush(color, &m_brush);

	pRT->FillEllipse(ellipse, (m_brush));
}

void ImageManager::DrawRect(RECT rt)
{
	D2D1_COLOR_F color;
	color.b = 255;
	color.a = 255;
	color.r = 255;
	color.g = 255;

	D2D1_MATRIX_3X2_F mat;
	mat = D2D1::Matrix3x2F::Translation(0, 0);
	pRT->SetTransform(&mat);
	pRT->CreateSolidColorBrush(color, &m_brush);

	pRT->FillRectangle(D2D1_RECT_F{ (float)rt.left ,(float)rt.top,(float)rt.right,(float)rt.bottom }, (m_brush));
}

void ImageManager::D2dTextOut(wstring str, float x, float y)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x, y);

	pRT->SetTransform((matT));
	D2D1_RECT_F fRect;
	fRect.left = x;
	fRect.top = y;
	fRect.right = x + 1080;
	fRect.bottom = y + 1920;
	pRT->DrawTextA(str.c_str(), str.size(), tf, fRect, m_brush);
}

void ImageManager::Render(CImage* img, float x, float y, float sizeX, float sizeY, float rot) // 카메라 O
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x - camera.x, y - camera.y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x + img->GetWidth() / 2,y + img->GetHeight() / 2 });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

void ImageManager::CenterRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;

	matT = D2D1::Matrix3x2F::Translation((x - img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

void ImageManager::UIRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot) // 카메라 X
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x, y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x ,y });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}
