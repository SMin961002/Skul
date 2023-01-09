#include "stdafx.h"
#include "ImageManager.h"
#include <wrl.h>

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

	for (auto iter : m_structureImages)
	{
		SAFE_DELETE(iter.second);
	}
	m_structureImages.clear();

	m_brush->Release();
	tf->Release();

	for (auto iter : m_gimages)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_gimages.clear();

	for (auto iter : m_vImages)
	{
		SAFE_DELETE(iter);
	}
	m_vImages.clear();
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

	IDWriteFactory3* m_pDWriteFactory = nullptr;

	DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(m_pDWriteFactory),
		reinterpret_cast<IUnknown**>(&m_pDWriteFactory)
	);

	IDWriteFontFile* fontFileReference;

	m_pDWriteFactory->CreateFontFileReference(L"./Resources/Font/NotoSansKR-Black.otf", nullptr, &fontFileReference);

	IDWriteFontSetBuilder1* fontSetBuilder;
	m_pDWriteFactory->CreateFontSetBuilder(reinterpret_cast<IDWriteFontSetBuilder**>(&fontSetBuilder));

	fontSetBuilder->AddFontFile(fontFileReference);

	IDWriteFontSet* customFontSet;
	fontSetBuilder->CreateFontSet(&customFontSet);
	IDWriteFontCollection1* col;
	m_pDWriteFactory->CreateFontCollectionFromFontSet(
		customFontSet
		, &col
	);

	m_pDWriteFactory->CreateTextFormat(
		L"Noto Sans KR",                  // 폰트 패밀리 이름의 문자열
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

	IDWriteFontFamily* fontFamily;
	IDWriteLocalizedStrings* localizedFontName;
	WCHAR* c_styleFontName = new WCHAR[70];

	col->GetFontFamily(0, &fontFamily);
	fontFamily->GetFamilyNames(&localizedFontName);
	localizedFontName->GetString(0, c_styleFontName, 65);

	m_pDWriteFactory->Release();
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

CImage* ImageManager::AddObjectImage(std::string key, std::wstring path)
{
	UINT _width = 0, _height = 0;
	CImage* img = new CImage(AddBitmap(path, &_width, &_height), _width, _height);
	m_objectImages.insert(make_pair(key, img));
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

vImage* ImageManager::AddImageVectorCopy(const std::string key)
{
	auto find = m_vectorImageList.find(key);
	if (find != m_vectorImageList.end())
	{
		vImage* vimg = new vImage();
		for (auto iter : find->second->GetImages())
		{
			vimg->AddImage(iter);
		}
		return vimg;
	}
	return nullptr;
}

GImage* ImageManager::AddPixelmage(string strKey, const char* fileName, int width, int height)
{
	GImage* img;
	img = new GImage;
	img->init(fileName, width, height);
	m_gimages.insert(make_pair(strKey, img));
	return img;
}

GImage* ImageManager::FindPixelImage(string strKey)
{
	auto find = m_gimages.find(strKey);
	if (find == m_gimages.end())
	{
		return nullptr;
	}
	return find->second;
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
	color.a = 0.5f;
	color.r = 255;
	color.g = 255;

	D2D1_MATRIX_3X2_F mat;
	mat = D2D1::Matrix3x2F::Translation(x - width / 2 - camera.x, y - width / 2 - camera.y);
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
	mat = D2D1::Matrix3x2F::Translation(-camera.x, -camera.y);
	pRT->SetTransform(&mat);
	pRT->CreateSolidColorBrush(color, &m_brush);

	pRT->FillRectangle(D2D1_RECT_F{ (float)rt.left ,(float)rt.top,(float)rt.right,(float)rt.bottom }, (m_brush));
}

void ImageManager::DrawMapTile(vector<vector<int>> vec)
{
	int y1 = 0;
	int m_width = m_tileImages[0]->GetWidth();
	for (auto iter : vec)
	{
		int x = 0;
		for (auto _iter : iter)
		{
			if (_iter != -1)
				IMAGEMANAGER->Render(m_tileImages[_iter], x * (m_width - 1), y1 * (m_width - 1));
			x++;
		}
		y1++;
	}
}

void ImageManager::DrawMapStructureBack(vector<StructureData*> vec)
{
	for (auto iter : vec)
	{
		if (iter->isBack == true)
			IMAGEMANAGER->Render(m_structureImages[iter->key], iter->x, iter->y, 2, 2);
	}
}

void ImageManager::DrawMapStructureFoward(vector<StructureData*> vec)
{
	for (auto iter : vec)
	{
		if (iter->isBack == false)
			IMAGEMANAGER->Render(m_structureImages[iter->key], iter->x, iter->y, 2, 2);
	}
}

void ImageManager::DrawRectCenter(RECT rt, CImage* img)
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
	pRT->FillRectangle(D2D1_RECT_F{ (float)rt.left + img->GetWidth() / 2,(float)rt.top + img->GetHeight() / 2,(float)rt.right + img->GetWidth() / 2,(float)rt.bottom + img->GetHeight() / 2 }, m_brush);
}

void ImageManager::DrawMapTilePixel(vector<vector<int>> vec)
{
	int y1 = 0;
	int m_width = m_tileImages[0]->GetWidth() - 1;
	for (auto iter : vec)
	{
		int x = 0;
		for (auto _iter : iter)
		{
			if (_iter == 0 || _iter == 1 || _iter == 2 || _iter == 3 || _iter == 4 || _iter == 7 || _iter == 8 || _iter == 9 || _iter == 10 || _iter == 11 || _iter == 12 || _iter == 13 || _iter == 14 || _iter == 36 || _iter == 37 || _iter == 38 || _iter == 39 || _iter == 40 || _iter == 41)
			{
				IMAGEMANAGER->Render(FindImage("CollisionBox"), x * m_width, y1 * m_width);
			}
			else if (_iter == 19 || _iter == 18 || _iter == 17 || _iter == 16)
			{
				IMAGEMANAGER->Render(FindImage("CollisionPlatform"), x * m_width, y1 * m_width);
			}
			x++;
		}
		y1++;
	}
}

void ImageManager::DrawColorRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot, bool isReverse, D2D1_COLOR_F colr)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;

	if (isReverse == false)
	{
		matT = D2D1::Matrix3x2F::Translation((x - img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	}
	else
	{
		matT = D2D1::Matrix3x2F::Translation((x + img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.y,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(-sizeX, sizeY);
	}
	pRT->SetTransform((matS * matT * matR));
	ID2D1SolidColorBrush* color;
	pRT->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	pRT->CreateSolidColorBrush(colr, &color);

	pRT->FillOpacityMask(img->GetBitMap(), color, D2D1_OPACITY_MASK_CONTENT_GRAPHICS, D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()));

}

void ImageManager::D2dTextOut(wstring str, float x, float y, D2D1_COLOR_F color, float scale)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x, y);
	matS = D2D1::Matrix3x2F::Scale(scale, scale);

	D2D1_RECT_F fRect;
	fRect.left = 0;
	fRect.top = 0;
	fRect.right = 1080;
	fRect.bottom = 1920;

	pRT->SetTransform((matS * matT));

	m_brush->SetColor({ 1.f / 255 * color.r,1.f / 255 * color.g,1.f / 255 * color.b,255 });
	pRT->DrawTextA(str.c_str(), str.size(), tf, fRect, m_brush);
}

void ImageManager::Render(CImage* img, float x, float y, float sizeX, float sizeY, float rot, float alpha) // 카메라 O
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x - camera.x, y - camera.y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x + img->GetWidth() / 2,y + img->GetHeight() / 2 });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));

	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

void ImageManager::CenterRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot, bool isReverse, float alpha)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;

	if (isReverse == false)
	{
		matT = D2D1::Matrix3x2F::Translation((x - img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.x,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	}
	else
	{
		matT = D2D1::Matrix3x2F::Translation((x + img->GetWidth() * sizeX / 2) - camera.x, (y - img->GetHeight() * sizeY / 2) - camera.y);
		matR = D2D1::Matrix3x2F::Rotation(rot, { x - camera.x,y - camera.y });
		matS = D2D1::Matrix3x2F::Scale(-sizeX, sizeY);
	}
	pRT->SetTransform((matS * matT * matR));
	ID2D1BitmapBrush* color;
	pRT->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	pRT->CreateBitmapBrush(img->GetBitMap(), &color);

	color->SetBitmap(img->GetBitMap());
	color->SetOpacity(alpha);
	pRT->FillOpacityMask(img->GetBitMap(), color, D2D1_OPACITY_MASK_CONTENT_GRAPHICS, D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()));
	color->Release();
}

void ImageManager::UIRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot, float alpha) // 카메라 X
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation(x, y);
	matR = D2D1::Matrix3x2F::Rotation(rot, { x ,y });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);
	pRT->SetTransform((matS * matT * matR));

	ID2D1BitmapBrush* color;
	pRT->SetAntialiasMode(D2D1_ANTIALIAS_MODE_ALIASED);
	pRT->CreateBitmapBrush(img->GetBitMap(), &color);

	color->SetBitmap(img->GetBitMap());
	color->SetOpacity(alpha);
	pRT->FillOpacityMask(img->GetBitMap(), color, D2D1_OPACITY_MASK_CONTENT_GRAPHICS, D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()));
	color->Release();
}

void ImageManager::UICenterRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot)
{
	D2D1_MATRIX_3X2_F matT, matR, matS;
	matT = D2D1::Matrix3x2F::Translation((x - img->GetWidth() * sizeX / 2), (y - img->GetHeight() * sizeY / 2));
	matR = D2D1::Matrix3x2F::Rotation(rot, { x ,y });
	matS = D2D1::Matrix3x2F::Scale(sizeX, sizeY);

	pRT->SetTransform((matS * matT * matR));
	pRT->DrawBitmap(img->GetBitMap(), D2D1::RectF(0.0f, 0.0f, img->GetWidth(), img->GetHeight()), 1, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
}

HRESULT GImage::init(const char* fileName, float width, float height)
{
	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(hInst, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			pixel[i][j] = GetPixel(GetMemDC(), i, j);
		}
	}
	return S_OK;
}
