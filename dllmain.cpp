#include <iostream>
#include "includes.h"
#include "menu.h"
#include "FNTool.h"
#include "spoof_call.h"
AFortPawn* AcknowledgedPawn;



auto redcol = ue::FLinearColor(1.f, 1.f, 1.f, 1.f);
auto bluecol = ue::FLinearColor(1.f, 1.f, 0.f, 1.f);
auto redcol2 = ue::FLinearColor(1.f, 0.8f, 0.f, 1.f);
auto bluecol2 = ue::FLinearColor(1.f, 0.f, 0.f, 1.f);
auto bluecol3 = ue::FLinearColor(0, 1, 1, 1);
auto chams = ue::FLinearColor(1.f, 0.f, 1.f, 1.f);
auto chams2 = ue::FLinearColor(0.f, 1.f, 1.f, 1.f);
auto col = ue::FLinearColor(1.f, 0.f, 0.f, 1.f);
auto FOVCOL = ue::FLinearColor(0.6f, 0.6f, 0.6f, 0.6f);
void DrawMenu() {
	ZeroGUI::SetupCanvas(static_canvas);
	ZeroGUI::Input::Handle();




	static Vector2 pos = Vector2(300, 300);
	if (ZeroGUI::Window(xorstr("Abble ceet [crip checked]"), &pos, Vector2{ 600, 475 }, ShowMenu))
	{
		static bool text_check = false;
		static int tab = 1;
		ZeroGUI::Text(xorstr(" "));
		ZeroGUI::NextColumn(10.0f);
		if (ZeroGUI::ButtonTab(xorstr("Hack uno"), Vector2{ 135, 25 }, tab == 1)) tab = 1;
		ZeroGUI::NextColumn(155.0f);
		if (ZeroGUI::ButtonTab(xorstr("Hack dos"), Vector2{ 135, 25 }, tab == 2)) tab = 2;
		ZeroGUI::NextColumn(300.0f);
		if (ZeroGUI::ButtonTab(xorstr("mod"), Vector2{ 135, 25 }, tab == 3)) tab = 3;
		ZeroGUI::NextColumn(445.0f);
		if (ZeroGUI::ButtonTab(xorstr("Nigga"), Vector2{ 135, 25 }, tab == 4)) tab = 4;

		if (tab == 1)
		{
			ZeroGUI::NextColumn(18.0f);
			ZeroGUI::Text(xorstr(" "));
			ZeroGUI::Text(xorstr("Aimbot mode (ENTER)"));
			ZeroGUI::Checkbox("Mouse aim", &Settings::mouseaim);
			ZeroGUI::Checkbox("Memory aim", &Settings::MemoryAim);
			ZeroGUI::Checkbox("Silent Aim", &Settings::SilentAim);
			ZeroGUI::SliderFloat("FOV:", &FovSize, 5.0f, 500.f);
			ZeroGUI::slidermouse("MouseAim Smooth:", &Settings::mousesmooth, 2.f, 15.f);

			ZeroGUI::NextColumn(200);
			ZeroGUI::Text(xorstr(" "));
			ZeroGUI::Text(xorstr("Aimbot Settings: "));
			ZeroGUI::Checkbox("Head", &Settings::head);
			ZeroGUI::Checkbox("Neck", &Settings::neck);
			ZeroGUI::Checkbox("Chest", &Settings::chest);
			ZeroGUI::Checkbox("Pelvis", &Settings::pelvis);
		}
		if (tab == 2)
		{
			ZeroGUI::NextColumn(18.0f);
			ZeroGUI::Text(xorstr(" "));
			ZeroGUI::Text(xorstr("Player ESP: "));
			ZeroGUI::Checkbox("Box", &Settings::box);
			ZeroGUI::Checkbox("Skeleton", &Settings::SkeletonESP);
			ZeroGUI::Checkbox("Snaplines", &Settings::LinesESP);
			ZeroGUI::Checkbox("Name", &Settings::PlayerNameESP);
			ZeroGUI::Checkbox("Chams", &Settings::Chams);
			ZeroGUI::Checkbox("Player Distance", &Settings::DistanceESP);
			ZeroGUI::Checkbox("Weapon/Active item", &Settings::EnemyWeaponESP);
			ZeroGUI::Text(xorstr(" "));
			ZeroGUI::Text(xorstr("ESP Settings: "));
			ZeroGUI::Checkbox("Bottom Line ESP", &Settings::BottomLineESP);
			ZeroGUI::Checkbox("Center Line ESP", &Settings::CenterLineESP);
			ZeroGUI::Checkbox("Top Line ESP", &Settings::TopLineESP);

			ZeroGUI::NextColumn(200);
			ZeroGUI::Text(xorstr(" "));
			ZeroGUI::Text(xorstr("World ESP: "));
			ZeroGUI::Checkbox("Chests", &Settings::chestesp);
			ZeroGUI::Checkbox("Vehicles", &Settings::vehicleespnerds);
			ZeroGUI::Checkbox("AmmoBox", &Settings::ammobox);			
			ZeroGUI::Text(xorstr("ESP Color: "));
			ZeroGUI::ColorPicker("Snapline ESP", &bluecol);
			ZeroGUI::ColorPicker("Box ESP", &col);
			ZeroGUI::ColorPicker("Skeleton ESP", &bluecol2);
			ZeroGUI::ColorPicker("Chams", &chams);
			ZeroGUI::ColorPicker("Team Chams", &chams2);
			ZeroGUI::ColorPicker("Fov Circle", &FOVCOL);
		}
		if (tab == 3)
		{
			ZeroGUI::NextColumn(18.0f);
			ZeroGUI::Text(xorstr(" "));
			ZeroGUI::Text(xorstr("Exploits (Could Be Risky): "));
			ZeroGUI::Checkbox("Bullet TP (Snipers)", &Settings::SniperTp);
			ZeroGUI::Checkbox("Aim While Jumping", &Settings::AimWhileJumping);
			ZeroGUI::Checkbox("Fov Changer", &Settings::FovChanger);
			ZeroGUI::slidermouse("Fov Amount:", &Settings::FovChanger_Value, 25.0f, 175.0f);
			ZeroGUI::Checkbox("Rapid Fire", &Settings::RapidFire);
			ZeroGUI::Checkbox("Tp To Player (Space)", &Settings::CarTpToPlayer);
			ZeroGUI::Checkbox("Vehicle Fly", &Settings::CarFly);
			ZeroGUI::slidermouse("Vehicle Fly Speed", &Settings::VehicleFlySpeed, 0.1f, 1000.0f);
			ZeroGUI::Checkbox("Vehicle TP To Player", &Settings::VehicleTP);
			ZeroGUI::Checkbox("Sync Camera Rotation", &Settings::SyncCameraRotation);
			ZeroGUI::Checkbox("Spin Bot", &Settings::g_spinbot);

		}	
		if (tab == 4)
		{
		
		}
	}
	ZeroGUI::Render();
}




static BOOL IsNotInScreen(int SizeX, int SizeY, Vector2 Pos) {
	if (((Pos.x <= 0 or Pos.x > SizeX) and (Pos.y <= 0 or Pos.y > SizeY)) or ((Pos.x <= 0 or Pos.x > SizeX) or (Pos.y <= 0 or Pos.y > SizeY))) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

AFortPawn* TargetPawno;
AFortPawn* LocalPawno;
APlayerCameraManager* PlayerCameraManagero;
Vector3 o_CamRot;
Vector3 o_CamLoc;
uintptr_t GlobalPlayerState;
bool initspeed = true;
bool Debuggytest = true;
ue::FString playeraname;
void __forceinline AnsiToWide(char* inAnsi, wchar_t* outWide)
{
	int i = 0;
	for (; inAnsi[i] != '\0'; i++)
		outWide[i] = (wchar_t)(inAnsi)[i];
	outWide[i] = L'\0';
}
#include <cmath>
float color_red;
float color_blue;
float color_green;
float color_speed = -10.0;
static ue::FLinearColor FromHSB(float hue, float saturation, float brightness)
{
	float h = hue == 1.0f ? 0 : hue * 6.0f;
	float f = h - (int)h;
	float p = brightness * (1.0f - saturation);
	float q = brightness * (1.0f - saturation * f);
	float t = brightness * (1.0f - (saturation * (1.0f - f)));

	if (h < 1)
	{
		return ue::FLinearColor(
			(float)(brightness),
			(float)(t),
			(float)(p),
			(float)(0.7f)
		);
	}
	else if (h < 2)
	{
		return ue::FLinearColor(
			(float)(q),
			(float)(brightness),
			(float)(p),
			(float)(0.7f)
		);
	}
	else if (h < 3)
	{
		return ue::FLinearColor(
			(float)(p),
			(float)(brightness),
			(float)(t),
			(float)(0.7f)
		);
	}
	else if (h < 4)
	{
		return ue::FLinearColor(
			(float)(p),
			(float)(q),
			(float)(brightness),
			(float)(0.7f)
		);
	}
	else if (h < 5)
	{
		return ue::FLinearColor(
			(float)(t),
			(float)(p),
			(float)(brightness),
			(float)(0.7f)
		);
	}
	else
	{
		return ue::FLinearColor(
			(float)(brightness),
			(float)(p),
			(float)(q),
			(float)(0.7f)
		);
	}
}
ue::FLinearColor GetItemColor(EFortItemTier tier)
{
	if (tier == EFortItemTier::I)
		return ue::FLinearColor(123 / 255.0f, 123 / 255.0f, 123 / 255.0f, 0.95f);
	else if (tier == EFortItemTier::II)
		return ue::FLinearColor(58 / 255.0f, 121 / 255.0f, 19 / 255.0f, 0.95f);
	else if (tier == EFortItemTier::III)
		return ue::FLinearColor(18 / 255.0f, 88 / 255.0f, 162 / 255.0f, 0.95f);
	else if (tier == EFortItemTier::IV)
		return ue::FLinearColor(189 / 255.0f, 63 / 255.0f, 250 / 255.0f, 0.95f);
	else if (tier == EFortItemTier::V)
		return ue::FLinearColor(255 / 255.0f, 118 / 255.0f, 5 / 255.0f, 0.95f);
	else if (tier == EFortItemTier::VI)
		return ue::FLinearColor(220 / 255.0f, 160 / 255.0f, 30 / 255.0f, 0.95f);
	else if (tier == EFortItemTier::VII)
		return ue::FLinearColor(0 / 255.0f, 225 / 255.0f, 252 / 255.0f, 0.95f);

	return ue::FLinearColor(123, 123, 123, 0.95f);
}

EFortItemTier GetItemEFortTier(float tier)
{
	int tierI = (int)tier;
	switch (tierI)
	{
	case 1:
		return EFortItemTier::I;
	case 2:
		return EFortItemTier::II;
	case 3:
		return EFortItemTier::III;
	case 4:
		return EFortItemTier::IV;
	case 5:
		return EFortItemTier::V;
	case 6:
		return EFortItemTier::VI;
	case 7:
		return EFortItemTier::VII;
	default:
		return EFortItemTier::I;
	}
}

std::string GetItemTierName(EFortItemTier tier)
{
	switch (tier)
	{
	case EFortItemTier::I:
		return xorstr("Common");
	case EFortItemTier::II:
		return xorstr("Uncommon");
	case EFortItemTier::III:
		return xorstr("Rare");
	case EFortItemTier::IV:
		return xorstr("Epic");
	case EFortItemTier::V:
		return xorstr("Legendary");
	case EFortItemTier::VI:
		return xorstr("Mythic");
	case EFortItemTier::VII:
		return xorstr("Exotic");
	default:
		return xorstr("Common");
	}
}

static void freenamenerds(__int64 address)
{
	auto func = reinterpret_cast<__int64(__fastcall*)(__int64 a1)>(ue::cached::signatures::FreeFn);

	(func, address);
}

static const char* getwierdnames(uintptr_t Object)
{
	if (Object == NULL)
		return ("");

	auto fGetObjName = reinterpret_cast<ue::FString * (__fastcall*)(int* index, ue::FString * res)>(ue::cached::signatures::GetNameByIndex);

	int index = *(int*)(Object + 0x18);

	ue::FString result;
	(fGetObjName, &index, &result);

	if (result.c_str() == NULL)
		return ("");

	auto result_str = result.ToString();

	if (result.c_str() != NULL)
		freenamenerds((__int64)result.c_str());

	return result_str.c_str();
}


void DrawFilledRect(UCanvas* pCanvas, Vector2 initial_pos, float width, float height, ue::FLinearColor color)
{
	for (float i = 0.0f; i < height; i += 1.0f)
		pCanvas->K2_DrawLine(Vector2(initial_pos.x, initial_pos.y + i), Vector2(initial_pos.x + width, initial_pos.y + i), 1.0f, color);

}
#define mpe 3.14159265358979323846264338327950288419716939937510582f

void DrawCircle(UCanvas* canvas, int x, int y, int radius, int numsides, ue::FLinearColor color)
{
	float Step = mpe * 2.0 / numsides;
	int Count = 0;
	Vector2 V[128];
	for (float a = 0; a < mpe * 2.0; a += Step)
	{
		float X1 = radius * sdkUssage->STATIC_Cos(a) + x;
		float Y1 = radius * sdkUssage->STATIC_Sin(a) + y;
		float X2 = radius * sdkUssage->STATIC_Cos(a + Step) + x;
		float Y2 = radius * sdkUssage->STATIC_Sin(a + Step) + y;
		V[Count].x = X1;
		V[Count].y = Y1;
		V[Count + 1].x = X2;
		V[Count + 1].y = Y2;
		canvas->K2_DrawLine(Vector2({ V[Count].x, V[Count].y }), Vector2({ X2, Y2 }), 1.5f, color);
	}
}

void DrawTriangle(UCanvas* pCanvas, const Vector2& point1, const Vector2& point2, const Vector2& point3, const ue::FLinearColor& color, bool isFilled)
{
	pCanvas->K2_DrawLine(point1, point2, 1.0f, color);
	pCanvas->K2_DrawLine(point1, point3, 1.0f, color);
	pCanvas->K2_DrawLine(point2, point3, 1.0f, color);
	// Fill it
	if (isFilled) {
		float addX = 0.5f;
		float addY = 1;
		for (float i = point1.y; i < point3.y; i++) {
			// draw line
			pCanvas->K2_DrawLine(Vector2(point1.x + addX, point1.y + addY), Vector2(point2.x - addX, point2.y + addY), 1.0f, color);
			addY++;
			addX += 0.5f;
		}
	}
}
ue::FLinearColor getColorFromTier(BYTE Tier) {
	ue::FLinearColor color = { 255.f, 255.f, 255.f, 1 };

	if (Tier == 1)
		color = { 255.f, 255.f, 255.f, 1 };
	else if (Tier == 2)
		color = { 0.0f, 255.f, 0.0f, 1 };
	else if (Tier == 3)
		color = { 0.f, 1.f, 1.f, 1 };
	else if (Tier == 4)
		color = { 0.8f, 0.f, 0.8f, 1.f };
	else if (Tier == 5)
		color = { 1.f, 1.f, 0.f, 1 };

	return color;
}
void DrawLine(UCanvas* Canvas, Vector2 position1, Vector2 position2, ue::FLinearColor color, int thickness = 1, bool screenCheck = false)
{
		Canvas->K2_DrawLine(position1, position2, thickness, color);
}

void DrawCorneredBox(UCanvas* Canvas, Vector2 position, Vector2 size, int thickness, ue::FLinearColor colora) {

	float lineW = (size.x / 4);
	float lineH = (size.y / 4);

	//corners
	DrawLine(Canvas, Vector2(position.x, position.y), Vector2(position.x, position.y + lineH), colora, 2);
	DrawLine(Canvas, Vector2(position.x, position.y), Vector2(position.x + lineW, position.y), colora, 2);
	DrawLine(Canvas, Vector2(position.x + size.x - lineW, position.y), Vector2(position.x + size.x, position.y), colora, 2);
	DrawLine(Canvas, Vector2(position.x + size.x, position.y), Vector2(position.x + size.x, position.y + lineH), colora, 2);
	DrawLine(Canvas, Vector2(position.x, position.y + size.y - lineH), Vector2(position.x, position.y + size.y), colora, 2);
	DrawLine(Canvas, Vector2(position.x, position.y + size.y), Vector2(position.x + lineW, position.y + size.y), colora, 2);
	DrawLine(Canvas, Vector2(position.x + size.x - lineW, position.y + size.y), Vector2(position.x + size.x, position.y + size.y), colora, 2);
	DrawLine(Canvas, Vector2(position.x + size.x, position.y + size.y - lineH), Vector2(position.x + size.x, position.y + size.y), colora, 2);
}



auto gold = ue::FLinearColor(1.000000000f, 0.843137324f, 0.000000000f, 1.000000000f);
auto lightgreen = ue::FLinearColor(0.564705908f, 0.933333397f, 0.564705908f, 1.000000000f);

void SetMouseAbsPosition(DWORD x, DWORD y)
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	input.mi.dx = x;
	input.mi.dy = y;
	SendInput(1, &input, sizeof(input));
}
void aimbot(float x, float y)
{
	float ScreenCenterX = (width / 2);
	float ScreenCenterY = (height / 2);
	int AimSpeed = Settings::mousesmooth;
	float TargetX = 0;
	float TargetY = 0;

	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}

	SetMouseAbsPosition(TargetX, TargetY);

	return;
}


void actorloop() {
	AFortPawn* targetpawn = nullptr;
	float closestTocenter = FLT_MAX;
	width = static_canvas->SizeX();
	height = static_canvas->SizeY();
	auto gworld = ((GWorld*)(*(uintptr_t*)(ue::cached::signatures::GWorld)));
	auto OwningGameInstance = gworld->OwningGameInstance();
	PlayerController = OwningGameInstance->LocalPlayers()->LocalPlayer()->PlayerController();
	auto PlayerCameraManager = PlayerController->PlayerCameraManager();
	auto LocalPawn = (AFortPawn*)PlayerController->LocalPawn();
	auto levels = gworld->Levels();
	auto CurrentVehicle = (AFortPawn*)LocalPawn->GetVehicle();

	for (int a = 0; a < levels.Num(); a++) {
		auto level = levels[a];
		if (!level) continue;
		auto actors = levels[a]->ActorArray();
		for (int i = 0; i < actors.Num(); i++) {
			auto actor = actors[i];
			if (!actor || actor == LocalPawn)
				continue;

			if (targetpawn)
			{
				Vector3 rahrah = targetpawn->GetBone(68);
				if (actor->IsA(ue::cached::objects::FortProjectileBase) && Settings::SniperTp)
				{
					actor->K2_SetActorLocation(rahrah, false, false); //68			
				}
			}
	

			if (Settings::chestesp)
			{
				if (wcsstr(actor->ObjectName(), xorstr(L"Tiered_Chest")))
				{
					int dist = actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100;


					static char distanceesp[128];
					static wchar_t wdistanceesp[128];
					sprintf(distanceesp, xorstr("Chest [.fm]"), (int)(actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100));
					AnsiToWide(distanceesp, wdistanceesp);


					auto ItemPos = PlayerController->WorldToScreen(actor->RootComponent()->RelativeLocation());
					static_canvas->K2_DrawText(ItemPos, gold, wdistanceesp, true, true);
				}
			}

			if (Settings::vehicleespnerds)
			{
				if (wcsstr(actor->ObjectName(), xorstr(L"Vehicle")))
				{
					int dist = actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100;


					static char distanceesp[128];
					static wchar_t wdistanceesp[128];
					sprintf(distanceesp, xorstr("Vehicle [.fm]"), (int)(actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100));
					AnsiToWide(distanceesp, wdistanceesp);


					auto ItemPos = PlayerController->WorldToScreen(actor->RootComponent()->RelativeLocation());
					static_canvas->K2_DrawText(ItemPos, bluecol, wdistanceesp, true, true);
				}
			}

			if (Settings::ammobox)
			{
				if (wcsstr(actor->ObjectName(), xorstr(L"Tiered_Ammo_Athena")))
				{
					int dist = actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100;

					static char distanceesp[128];
					static wchar_t wdistanceesp[128];
					sprintf(distanceesp, xorstr("AmmoBox [.fm]"), (int)(actor->RootComponent()->RelativeLocation().DistanceFrom(o_CamLoc) / 100));
					AnsiToWide(distanceesp, wdistanceesp);


					auto ItemPos = PlayerController->WorldToScreen(actor->RootComponent()->RelativeLocation());
					static_canvas->K2_DrawText(ItemPos, lightgreen, wdistanceesp, true, true);
				}
			}

			if (actor->IsA(ue::cached::objects::actor::FortPlayerPawnAthena)) {



				Vector3 head = actor->GetBone(6);
				Vector2 head_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, head);
				
				
				if (actor != LocalPawn) {

					auto dx = head_w2s.x - (width / 2);
					auto dy = head_w2s.y - (height / 2);
					auto dist = crt::sqrtf(dx * dx + dy * dy);

					if (dist < FovSize && dist < closestTocenter) {
						closestTocenter = dist;
						targetpawn = actor;
					}
					else if (!dist < FovSize && !dist < closestTocenter) {
						TargetPawno = 0;
					}

				}
				TargetPawno = targetpawn;
				LocalPawno = LocalPawn;
				PlayerCameraManagero = PlayerCameraManager;

				if (Settings::AimWhileJumping)
				{
					LocalPawn->AimWhileJumping(true);
				}
				if (Settings::CarTpToPlayer)
				{
					if (GetAsyncKeyState(VK_SPACE))
					{
						//LocalPawn->K2_TeleportTo(TargetPawno->GetBone(68), TargetPawno->GetBone(68));
						LocalPawn->K2_SetActorLocation(targetpawn->GetBone(68), true, true);
					}
				}

				if (Settings::g_spinbot)
				{
					if (GetAsyncKeyState(VK_LBUTTON))
					{
						LocalPawn->PlayerController()->ClientSetRotation(Vector3(360, 1, -180), false);						
					}
				}

				if (Settings::VehicleTP)
				{
					if (CurrentVehicle)
					{
						if (GetAsyncKeyState(VK_LSHIFT))
						{
							if (targetpawn)
							{
								CurrentVehicle->K2_SetActorLocation(targetpawn->GetBone(2), false, true);
							}
						}
					}
				}

				if (Settings::RapidFire)
				{
					LocalPawn->CurrentWeapon()->RapidFire();
				}

				if (Settings::FovChanger == true)
				{
					PlayerController->Fov(Settings::FovChanger_Value);
				}

				if (Settings::InfiniteAmmo)
				{
					if (GetAsyncKeyState(VK_LBUTTON))
					{
						Vector3 camrotation = PlayerCameraManager->GetCameraRotation();

						CurrentVehicle->K2_TeleportTo(Settings::Location, camrotation);
					}
				}

				if (Settings::CarFly)
				{
					if (CurrentVehicle)
					{
						if (Settings::VehicleTP)
						{
							if (!GetAsyncKeyState(VK_LSHIFT))
							{
								if (Settings::SyncCameraRotation)
								{
									Vector3 camrotation = PlayerCameraManager->GetCameraRotation();

									CurrentVehicle->K2_TeleportTo(Settings::Location, camrotation);
								}
								else
								{
									CurrentVehicle->K2_TeleportTo(Settings::Location, Vector3(NULL, NULL, NULL));
								}

								if (GetAsyncKeyState(0x57)) //w
								{
									Settings::Location.x += Settings::VehicleFlySpeed;
								}

								if (GetAsyncKeyState(0x53)) //s
								{
									Settings::Location.x -= Settings::VehicleFlySpeed;
								}

								if (GetAsyncKeyState(0x41)) //a
								{
									Settings::Location.y -= Settings::VehicleFlySpeed;
								}

								if (GetAsyncKeyState(0x44)) //d
								{
									Settings::Location.y += Settings::VehicleFlySpeed;
								}

								if (GetAsyncKeyState(VK_SPACE))
								{
									Settings::Location.z += Settings::VehicleFlySpeed;
								}
							}

							if (GetAsyncKeyState(VK_LSHIFT))
							{
								Settings::Location.z -= Settings::VehicleFlySpeed;
							}
						}
						else
						{
							if (Settings::SyncCameraRotation)
							{
								Vector3 camrotation = PlayerCameraManager->GetCameraRotation();

								CurrentVehicle->K2_TeleportTo(Settings::Location, camrotation);
							}
							else
							{
								CurrentVehicle->K2_TeleportTo(Settings::Location, Vector3(NULL, NULL, NULL));
							}

							if (GetAsyncKeyState(0x57)) //w
							{
								Settings::Location.x += Settings::VehicleFlySpeed;
							}

							if (GetAsyncKeyState(0x53)) //s
							{
								Settings::Location.x -= Settings::VehicleFlySpeed;
							}

							if (GetAsyncKeyState(0x41)) //a
							{
								Settings::Location.y -= Settings::VehicleFlySpeed;
							}

							if (GetAsyncKeyState(0x44)) //d
							{
								Settings::Location.y += Settings::VehicleFlySpeed;
							}

							if (GetAsyncKeyState(VK_SPACE))
							{
								Settings::Location.z += Settings::VehicleFlySpeed;
							}

							if (GetAsyncKeyState(VK_LSHIFT))
							{
								Settings::Location.z -= Settings::VehicleFlySpeed;
							}
						}

						if (GetAsyncKeyState(VK_RSHIFT))
						{
							Settings::Location = Vector3(5100, 2800, -85);
						}
					}
				}

				if (Settings::Chams)
				{
					LocalPawn->ApplyPawnHighlight(chams2, chams2);
					PlayerController->LocalPawn()->ApplyPawnHighlight(chams2, chams2);
					targetpawn->ApplyPawnHighlight(chams, chams);
				}
				if (Settings::mouseaim and targetpawn and (safe_call(GetAsyncKeyState)(VK_RBUTTON)))
				{
					Vector3 headmarket = targetpawn->GetBone(68);
					Vector2 headlarketn = PlayerController->WorldToScreen(headmarket);
					aimbot(headlarketn.x, headlarketn.y);
				}
				
				if (Settings::MemoryAim and targetpawn and (safe_call(GetAsyncKeyState)(VK_RBUTTON))) {
					if (Settings::head)
					{
						Vector3 head = actor->GetBone(6);
						Vector2 headtarget_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, head);
						auto camloc = PlayerCameraManager->GetCameraLocation();
						auto NewRotation = galgan(camloc, head);
						PlayerController->ClientSetRotation(NewRotation, false);
					}
					if (Settings::chest)
					{
						Vector3 headtarget = targetpawn->GetBone(37);
						Vector2 headtarget_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, headtarget);
						auto camloc = PlayerCameraManager->GetCameraLocation();
						auto NewRotation = galgan(camloc, headtarget);
						PlayerController->ClientSetRotation(NewRotation, false);
					}
					if (Settings::neck)
					{
						Vector3 headtarget = targetpawn->GetBone(66);
						Vector2 headtarget_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, headtarget);
						auto camloc = PlayerCameraManager->GetCameraLocation();
						auto NewRotation = galgan(camloc, headtarget);
						PlayerController->ClientSetRotation(NewRotation, false);
					}
					if (Settings::pelvis)
					{
						Vector3 headtarget = targetpawn->GetBone(2);
						Vector2 headtarget_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, headtarget);
						auto camloc = PlayerCameraManager->GetCameraLocation();
						auto NewRotation = galgan(camloc, headtarget);
						PlayerController->ClientSetRotation(NewRotation, false);
					}
				}
	
				Vector2 head2_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, { head.x, head.y, head.z + 20 });
				Vector3 bottom = actor->GetBone(0);
				Vector2 bottom_w2s = PlayerCameraManager->ProjectWorldLocationToScreen(width, height, { bottom.x, bottom.y, bottom.z });
				float TextOffset_Top;
				auto WorldHead = actor->GetBone(68);
				auto Head = PlayerController->WorldToScreen(WorldHead);
				Vector2 Top;
				Top = PlayerController->WorldToScreen({ WorldHead.x, WorldHead.y, WorldHead.z + 20 });
				auto Bottom = PlayerController->WorldToScreen(actor->GetBone(0));
				TextOffset_Top = Top.y;
				float TextOffset_Bottom = Bottom.y;

				if (IsNotInScreen(width, height, head_w2s)) continue;
				float BoxHeight = (float)(bottom_w2s.y - head2_w2s.y);
				float BoxWidth = BoxHeight * 0.50f;

				float BottomLeftX = (float)head2_w2s.x - BoxWidth / 2;
				float BottomLeftY = (float)bottom_w2s.y;

				float BottomRightX = (float)head2_w2s.x + BoxWidth / 2;
				float BottomRightY = (float)bottom_w2s.y;

				float TopRightX = (float)head2_w2s.x + BoxWidth / 2;
				float TopRightY = (float)head2_w2s.y;

				float TopLeftX = (float)head2_w2s.x - BoxWidth / 2;
				float TopLeftY = (float)head2_w2s.y;

				if (Settings::BoxESP) {
					static_canvas->K2_DrawLine(Vector2(BottomLeftX, BottomLeftY), Vector2(BottomRightX, BottomRightY), 2.f, col);
					static_canvas->K2_DrawLine(Vector2(BottomRightX, BottomRightY), Vector2(TopRightX, TopRightY), 2.f, col);
					static_canvas->K2_DrawLine(Vector2(TopRightX, TopRightY), Vector2(TopLeftX, TopLeftY), 2.f, col);
					static_canvas->K2_DrawLine(Vector2(TopLeftX, TopLeftY), Vector2(BottomLeftX, BottomLeftY), 2.f, col);
				}
				if (Settings::box)
				{
					float Height = Bottom.y - Top.y;
					float Width = Height * 0.50;
					Vector2 min;
					min.x = Bottom.x + Width / 2;
					min.y = Bottom.y;
					Vector2 max;
					max.x = Top.x - Width / 2;
					max.y = Top.y;
					Vector2 size;
					size.x = min.x - max.x;
					size.y = min.y - max.y;
					DrawCorneredBox(static_canvas, max, size, 1.f, col);
				}

				float TextOffset_Y = head2_w2s.y;
				float TextOffset_X = TopRightX + 5;
				Vector2 calculation;
				if (!IsNotInScreen(1920, 1080, head2_w2s)) {
					if (Settings::PlayerNameESP)
					{
						int ifespison = 30;
						if (sdkUssage->isValidPointer((uintptr_t)LocalPawn))
						{
							if (Settings::EnemyWeaponESP)
							{
								int ifespison = 15;
							}
						}

						auto PlayerState = actor->PlayerState();
						if (PlayerState)
						{
							TextOffset_Top -= static_canvas->K2_TextSize(PlayerState->GetPlayerName()).y + ifespison - 28;
							Vector2 calculation = Vector2(Top.x, TextOffset_Top);
							static_canvas->K2_DrawText(calculation, redcol2, PlayerState->GetPlayerName().c_str(), true, false);
						}
					}

					if (Settings::DistanceESP)
					{
						int dist = PlayerCameraManager->GetCameraLocation().Distance(actor->RootComponent()->RelativeLocation()) / 100;
						static char distanceesp[128];
						static wchar_t wdistanceesp[128];
						sprintf(distanceesp, xorstr("%d m"), dist);
						AnsiToWide(distanceesp, wdistanceesp);
						TextOffset_Y += static_canvas->K2_TextSize(ue::FString(wdistanceesp)).y + 10;
						Vector2 calculation = Vector2(Top.x, TextOffset_Top - 12);
						static_canvas->K2_DrawText(calculation, bluecol, wdistanceesp, true, false);
					}

					if (Settings::PlatformESP and LocalPawn) {
						auto platform = actor->PlayerState()->GetPlatform();
						if (!platform.IsValid()) continue;
						auto platform_name = platform.c_str();
						TextOffset_Top += static_canvas->K2_TextSize(ue::FString(platform_name)).y + 10;
						Vector2 calculation = Vector2(Top.x - 25, TextOffset_Top);

						if (math::custom_wcsstr(platform_name, xorstr(L"PSN"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"PlayStation"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"XBL"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"Xbox"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"XSX"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"Xbox Series S"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"WIN"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"Windows"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"MAC"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"MacOS"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"LNX"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"Linux"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"IOS"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"Ios"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"AND"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"Android"), false, false);
						}
						else if (math::custom_wcsstr(platform_name, xorstr(L"SWT"))) {
							static_canvas->K2_DrawText(calculation, redcol2, xorstr(L"NintendoSwitch"), false, false);
						}
						else {
							static_canvas->K2_DrawText(calculation, redcol2, platform_name, false, false);
						}
					}
				}
				
				
				

				Vector2 ChestAtLeft = PlayerController->WorldToScreen(actor->GetBone(37));
				Vector2 ChestAtRight = PlayerController->WorldToScreen(actor->GetBone(8));
				Vector2 Chest = { ChestAtLeft.x + (ChestAtRight.x - ChestAtLeft.x) / 2, ChestAtLeft.y };
				ue::FLinearColor Color = ue::FLinearColor(1.f, 1.f, 0.f, 1.f);
				if (Settings::SkeletonESP) {
					Vector2 Neck = PlayerController->WorldToScreen(actor->GetBone(66));

					Vector2 LeftShoulder = PlayerController->WorldToScreen(actor->GetBone(64));
					Vector2 RightShoulder = PlayerController->WorldToScreen(actor->GetBone(35));
					Vector2 LeftElbow = PlayerController->WorldToScreen(actor->GetBone(39));
					Vector2 RightElbow = PlayerController->WorldToScreen(actor->GetBone(10));
					Vector2 LeftHand = PlayerController->WorldToScreen(actor->GetBone(40));
					Vector2 RightHand = PlayerController->WorldToScreen(actor->GetBone(11));
					Vector2 LeftLeg = PlayerController->WorldToScreen(actor->GetBone(78));
					Vector2 RightLeg = PlayerController->WorldToScreen(actor->GetBone(71));
					Vector2 LeftThigh = PlayerController->WorldToScreen(actor->GetBone(84));
					Vector2 RightThigh = PlayerController->WorldToScreen(actor->GetBone(77));
					Vector2 LeftFoot = PlayerController->WorldToScreen(actor->GetBone(80));
					Vector2 RightFoot = PlayerController->WorldToScreen(actor->GetBone(73));
					Vector2 LeftFeet = PlayerController->WorldToScreen(actor->GetBone(82));
					Vector2 RightFeet = PlayerController->WorldToScreen(actor->GetBone(86));
					Vector2 LeftFeetFinger = PlayerController->WorldToScreen(actor->GetBone(83));
					Vector2 RightFeetFinger = PlayerController->WorldToScreen(actor->GetBone(76));
					Vector2 Bottom = PlayerController->WorldToScreen(actor->GetBone(0));
					Vector2 Pelvis = PlayerController->WorldToScreen(actor->GetBone(2));


					static_canvas->K2_DrawLine(head_w2s, Neck, 2, bluecol2);
					static_canvas->K2_DrawLine(Neck, Chest, 2, bluecol2);
					static_canvas->K2_DrawLine(Chest, Pelvis, 2, bluecol2);
					static_canvas->K2_DrawLine(Chest, LeftShoulder, 2, bluecol2);
					static_canvas->K2_DrawLine(Chest, RightShoulder, 2, bluecol2);
					static_canvas->K2_DrawLine(LeftShoulder, LeftElbow, 2, bluecol2);
					static_canvas->K2_DrawLine(RightShoulder, RightElbow, 2, bluecol2);
					static_canvas->K2_DrawLine(LeftElbow, LeftHand, 2, bluecol2);
					static_canvas->K2_DrawLine(RightElbow, RightHand, 2, bluecol2);
					static_canvas->K2_DrawLine(Pelvis, LeftLeg, 2, bluecol2);
					static_canvas->K2_DrawLine(Pelvis, RightLeg, 2, bluecol2);
					static_canvas->K2_DrawLine(LeftLeg, LeftThigh, 2, bluecol2);
					static_canvas->K2_DrawLine(RightLeg, RightThigh, 2, bluecol2);
					static_canvas->K2_DrawLine(LeftThigh, LeftFoot, 2, bluecol2);
					static_canvas->K2_DrawLine(RightThigh, RightFoot, 2, bluecol2);
					static_canvas->K2_DrawLine(LeftFoot, LeftFeet, 2, bluecol2);
					static_canvas->K2_DrawLine(RightFoot, RightFeet, 2, bluecol2);
					static_canvas->K2_DrawLine(LeftFeet, LeftFeetFinger, 2, bluecol2);
					static_canvas->K2_DrawLine(RightFeet, RightFeetFinger, 2, bluecol2);

				}

				if (Settings::EnemyWeaponESP and LocalPawn)
				{
					if (actor->CurrentWeapon()->WeaponData()) {
						auto weaponname = actor->CurrentWeapon()->WeaponData()->DisplayName().Get();
						if (weaponname) {
							TextOffset_Y += static_canvas->K2_TextSize(weaponname).y + 10;
							calculation = Vector2(Bottom.x, Bottom.y + 8);
							static_canvas->K2_DrawText(calculation, bluecol, weaponname, true, false);
						}
					}
				}

				if (Settings::LinesESP) 
				{
					if (Settings::BottomLineESP)
					{
						Settings::TopLineESP = false;
						Settings::CenterLineESP = false;
						static_canvas->K2_DrawLine(Vector2(width / 2, height), Head, 2, bluecol);
					}

					if (Settings::CenterLineESP)
					{
						Settings::BottomLineESP = false;
						Settings::TopLineESP = false;
						static_canvas->K2_DrawLine(Vector2(width / 2 - 0, height / 2 + 0), Head, 2, bluecol);
					}

					if (Settings::TopLineESP)
					{
						Settings::BottomLineESP = false;
						Settings::CenterLineESP = false;
						static_canvas->K2_DrawLine(Vector2(width / 2, height / 1080), Head, 2, bluecol);
					}
				}

			}
		}

	}
}
Vector3 OriginalLocation;
Vector3 OriginalRotation;
bool once = true;
bool once2 = true;
Vector3 rot;

void(*o_GetViewPoint)(uintptr_t, ue::FMinimalViewInfo*, BYTE) = nullptr;
void hk_GetViewPoint(uintptr_t this_LocalPlayer, ue::FMinimalViewInfo* OutViewInfo, BYTE StereoPass)
{
	o_GetViewPoint(this_LocalPlayer, OutViewInfo, StereoPass);

	if (sdkUssage->isValidPointer(uintptr_t(LocalPawno)))
	{
		if (Settings::SilentAim)
		{
			if ((safe_call(GetAsyncKeyState)(VK_RBUTTON)))
			{
				OutViewInfo->Rotation = OriginalRotation;
				OutViewInfo->Location = OriginalLocation;
			}
		}
	}
}
void(*o_GetPlayerViewPoint)(uintptr_t, Vector3*, Vector3*) = nullptr;
void hk_GetPlayerViewPoint(uintptr_t this_PlayerController, Vector3* Location, Vector3* Rotation) {
	
	o_GetPlayerViewPoint(this_PlayerController, Location, Rotation);
	OriginalLocation = *Location;
	OriginalRotation = *Rotation;
	if (sdkUssage->isValidPointer(uintptr_t(LocalPawno)))
	{
		if (Settings::SilentAim)
		{
			if ((safe_call(GetAsyncKeyState)(VK_RBUTTON)))
			{
				auto rootHead = TargetPawno->GetBone(2);
				Vector3 camloc = *Location;
				Vector3 VectorPos;
				VectorPos.x = rootHead.x - camloc.x;
				VectorPos.y = rootHead.y - camloc.y;
				VectorPos.z = rootHead.z - camloc.z;
				float distance = (double)(sqrtf(VectorPos.x * VectorPos.x + VectorPos.y * VectorPos.y + VectorPos.z * VectorPos.z));

				rot.x = -((acosf(VectorPos.z / distance) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510)) - 90.f);
				rot.y = atan2f(VectorPos.y, VectorPos.x) * (float)(180.0f / 3.14159265358979323846264338327950288419716939937510);
				rot.z = 0;
				*Rotation = rot;
			}
		}
	}
}
float(*CalculateReloadSpeedOriginal)(AWeapon*, float*) = nullptr;
auto CalculateReloadSpeedHook(AWeapon* Weapon, float* a2) //__m128 __fastcall sub_7FF660B36E80(__int64 a1)
{
	return FLT_MAX;
	return CalculateReloadSpeedOriginal(Weapon, a2);
}
bool oncee = false;
bool onceee = false;
bool temponce = false;
bool initudhooker = true;


static uintptr_t storedPController;
static uintptr_t storedPCurrentWeapon;
static uintptr_t storedPLocalPlayer;
bool hookplayanama = false;
bool calcc = false;
bool hookgetactorrotation = true;
bool hookdis = true;
bool hookdiss = true;
bool hookdisss = true;
bool hookdissss = true;
void VirtualTableFunctionSwap(void* VTable, void* FunctionToSwap, void** pOriginal, int Index)
{
	DWORD Old;

	void* pVTableFunction = (void*)((uint64_t)VTable + Index);
	*pOriginal = *(PVOID*)(pVTableFunction);

	VirtualProtectEx((HANDLE)-1, pVTableFunction, 8, PAGE_EXECUTE_READWRITE, &Old);
	*(PVOID*)pVTableFunction = FunctionToSwap;
	VirtualProtectEx((HANDLE)-1, pVTableFunction, 8, Old, &Old);
}
void DrawTransition(uintptr_t this_, uintptr_t Canvas) {
	if (!Canvas) {
		return DrawTransition(this_, Canvas);
	}
	static_canvas = (UCanvas*)Canvas;

	actorloop();

	auto uworld = ((GWorld*)(*(uintptr_t*)(ue::cached::signatures::GWorld)));
	auto LocalPlayer = uworld->OwningGameInstance()->LocalPlayers()->LocalPlayer();
	
	if (storedPLocalPlayer != (uintptr_t)LocalPlayer)
	{
		storedPLocalPlayer = (uintptr_t)LocalPlayer;
		hookdisss = true;

	}
	if (storedPLocalPlayer == (uintptr_t)LocalPlayer && hookdisss) {

		if (LocalPlayer) {
			void** LocalPlayer_VTable = *(void***)(LocalPlayer);
			DWORD OldProtection;
			safe_call(VirtualProtect)(&LocalPlayer_VTable[87], 8, PAGE_EXECUTE_READWRITE, &OldProtection);
			o_GetViewPoint = decltype(o_GetViewPoint)(LocalPlayer_VTable[87]);
			LocalPlayer_VTable[87] = &hk_GetViewPoint;
			safe_call(VirtualProtect)(&LocalPlayer_VTable[87], 8, OldProtection, &OldProtection);
		}
		hookdisss = false;
	}

	//GetPlayerViewpoint
	if (storedPController != (uintptr_t)LocalPlayer->PlayerController())
	{

		storedPController = (uintptr_t)LocalPlayer->PlayerController();
		//std::cout << "ud\n";
		hookdis = true;

	}

	if (Settings::SilentAim && storedPController == (uintptr_t)LocalPlayer->PlayerController() && hookdis) {
		
		void** PlayerController_VTable = *(void***)(LocalPlayer->PlayerController());
		DWORD OldProtection;
		safe_call(VirtualProtect)(&PlayerController_VTable[246], 8, PAGE_EXECUTE_READWRITE, &OldProtection);
		o_GetPlayerViewPoint = decltype(o_GetPlayerViewPoint)(PlayerController_VTable[246]);
		PlayerController_VTable[246] = &hk_GetPlayerViewPoint;
		safe_call(VirtualProtect)(&PlayerController_VTable[246], 8, OldProtection, &OldProtection);
		hookdis = false;
	}

	if ((safe_call(GetAsyncKeyState)(VK_INSERT)) & 1)
	{
		ShowMenu = !ShowMenu;
	}

	static_canvas->K2_DrawLine(Vector2(width / 2 + 5, height / 2), Vector2(width / 2 + 10.f, height / 2), 3, { 0.6f, 0.6f, 0.6f, 0.6f });
	static_canvas->K2_DrawLine(Vector2(width / 2 - 5, height / 2), Vector2(width / 2 - 10.f, height / 2), 3, { 0.6f, 0.6f, 0.6f, 0.6f });
	static_canvas->K2_DrawLine(Vector2(width / 2, height / 2 + 5), Vector2(width / 2, height / 2 + 10.f), 3, { 0.6f, 0.6f, 0.6f, 0.6f });
	static_canvas->K2_DrawLine(Vector2(width / 2, height / 2 - 5), Vector2(width / 2, height / 2 - 10.f), 3, { 0.6f, 0.6f, 0.6f, 0.6f });

	Pasted_CircleOutline(Vector2(width / 2, height / 2), FovSize, FOVCOL);
	DrawCircle(static_canvas, width / 2, height / 2, FovSize, 1450, ue::FLinearColor(0,0,1,1));

	if (ShowMenu) 
	{
		DrawMenu();
	}


	return DrawTransitionOriginal(this_, Canvas);
}
VOID Main()
{

		ue::cached::Base = sdkUssage->GetGameBase();

		ue::cached::signatures::GWorld = sdkUssage->PatternScan(ue::cached::Base, xorstr("48 89 05 ? ? ? ? 48 8B 4B 78"), 7, true); if (!ue::cached::signatures::GWorld) safe_call(MessageBox)(0, xorstr(L"Failed to find UWorld"), 0, 0);
		ue::cached::signatures::GetBoneMatrix = sdkUssage->PatternScan(ue::cached::Base, xorstr("E8 ? ? ? ? 0F 10 40 68"), 5, true); if (!ue::cached::signatures::GetBoneMatrix) safe_call(MessageBox)(0, xorstr(L"Failed to find GetBoneMatrix"), 0, 0);
		ue::cached::signatures::ProjectWorldToScreen = sdkUssage->PatternScan(ue::cached::Base, xorstr("40 53 55 56 57 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 33 DB 45 8A F1"), 5, false); if (!ue::cached::signatures::ProjectWorldToScreen) safe_call(MessageBox)(0, xorstr(L"Failed to find w2s"), 0, 0); //true -> false xD
		ue::cached::signatures::FreeFn = sdkUssage->PatternScan(ue::cached::Base, xorstr("48 85 C9 0F 84 ? ? ? ? 53 48 83 EC 20 48 89 7C 24 30 48 8B D9 48 8B 3D ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 48 8B 07 4C 8B 40 30 48 8D 05 ? ? ? ? 4C 3B C0"), 0, false); if (!ue::cached::signatures::FreeFn) safe_call(MessageBox)(0, xorstr(L"Failed to find FreeFn"), 0, 0);
		ue::cached::signatures::GetNameByIndex = sdkUssage->PatternScan(ue::cached::Base, xorstr("48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 8B"), 0, false); if (!ue::cached::signatures::GetNameByIndex) safe_call(MessageBox)(0, xorstr(L"Failed to find GetNameByIndex"), 0, 0); //48 89 ? ? ? 48 89 ? ? ? 48 89 ? ? ? 41 ? 48 81 EC ? ? ? ? 48 8B ? ? ? ? ? 48 33 ? 48 89 ? ? ? ? ? ? 8B 01
		ue::classes::objects = (ue::classes::GObjects*)sdkUssage->PatternScan(ue::cached::Base, xorstr("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1"), 7, true); if (!ue::classes::objects) safe_call(MessageBox)(0, xorstr(L"Failed to find GObjects"), 0, 0);

		ue::cached::objects::camera::GetCameraLocation = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerCameraManager.GetCameraLocation")); if (!ue::cached::objects::camera::GetCameraLocation) return;
		ue::cached::objects::camera::GetCameraRotation = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerCameraManager.GetCameraRotation")); if (!ue::cached::objects::camera::GetCameraRotation) return;
		ue::cached::objects::camera::GetFOVAngle = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerCameraManager.GetFOVAngle")); if (!ue::cached::objects::camera::GetCameraRotation) return;

		ue::cached::objects::render::Font = (ue::classes::UObject*)find::FindObject(xorstr(L"/Engine/EngineFonts/Roboto.Roboto")); if (!ue::cached::objects::render::Font) return;
		ue::cached::objects::render::K2_DrawLine = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Canvas.K2_DrawLine")); if (!ue::cached::objects::render::K2_DrawLine) return;
		ue::cached::objects::render::K2_DrawBox = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Canvas.K2_DrawBox")); if (!ue::cached::objects::render::K2_DrawBox) return;
		ue::cached::objects::render::K2_DrawText = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Canvas.K2_DrawText")); if (!ue::cached::objects::render::K2_DrawText) return;
		ue::cached::objects::render::K2_TextSize = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Canvas.K2_TextSize")); if (!ue::cached::objects::render::K2_DrawBox) return;


		ue::cached::objects::actor::FortPlayerPawnAthena = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortPlayerPawnAthena")); if (!ue::cached::objects::actor::FortPlayerPawnAthena) return;
		ue::cached::objects::actor::ClientSetRotation = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Controller.ClientSetRotation")); if (!ue::cached::objects::actor::ClientSetRotation) return;
		ue::cached::objects::actor::GetPlayerName = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerState.GetPlayerName")); if (!ue::cached::objects::actor::GetPlayerName) return;
		ue::cached::objects::actor::ApplyPawnHighlight = (ue::classes::UObject*)find::FindObject(xorstr(L"PlayerPawn_Athena.PlayerPawn_Athena_C.ApplyPawnHighlight")); if (!ue::cached::objects::actor::ApplyPawnHighlight) return;
		ue::cached::objects::actor::Fov = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerController.FOV")); if (!ue::cached::objects::actor::Fov) return;
		ue::cached::objects::actor::SetMouseLocation = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerController.SetMouseLocation")); if (!ue::cached::objects::actor::SetMouseLocation) return;
		ue::cached::objects::FortProjectileBase = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortProjectileBase")); if (!ue::cached::objects::FortProjectileBase) return;
		ue::cached::objects::AFortAthenaZipline = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortAthenaZipline")); if (!ue::cached::objects::AFortAthenaZipline) return;
		ue::cached::objects::FortRangedWeaponStats = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortRangedWeaponStats")); if (!ue::cached::objects::FortRangedWeaponStats) return;



		// What???

		ue::cached::objects::K2_GetActorRotation = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Actor.K2_GetActorRotation")); if (!ue::cached::objects::K2_GetActorRotation) return;

		//ue::cached::objects::actor::isHiddingInProp = (ue::classes::UObject*)find::FindObject(xorstr(L"PlayerPawn_Athena.PlayerPawn_Athena_C.isHiddingInProp")); if (!ue::cached::objects::actor::isHiddingInProp) return;
		//ue::cached::objects::actor::SetCharacterBodyVisibilityForPossession = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortPlayerPawnAthena.SetCharacterBodyVisibilityForPossession")); if (!ue::cached::objects::actor::SetCharacterBodyVisibilityForPossession) return;
		//ue::cached::FortKismetLibrary = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortKismetLibrary")); if (!ue::cached::FortKismetLibrary) return;
		//ue::cached::KismetStringLibrary = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.KismetStringLibrary")); if (!ue::cached::KismetStringLibrary) return;
		//ue::cached::KismetMathLibrary = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.KismetMathLibrary")); if (!ue::cached::KismetMathLibrary) return;
		//ue::cached::Conv_StringToName = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.KismetStringLibrary.Conv_StringToName")); if (!ue::cached::Conv_StringToName) return;
		//ue::cached::Cos = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.KismetMathLibrary.Cos")); if (!ue::cached::Cos) return;
		//ue::cached::Sin = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.KismetMathLibrary.Sin")); if (!ue::cached::Sin) return;

		ue::cached::objects::actor::K2_PayBuildingResourceCost = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortKismetLibrary.K2_PayBuildingResourceCost")); if (!ue::cached::objects::actor::K2_PayBuildingResourceCost) return;
		ue::cached::objects::actor::GetVehicle = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortPlayerPawn.GetVehicle")); if (!ue::cached::objects::actor::GetVehicle) return;
		//ue::cached::objects::actor::IsInVehicle = (ue::classes::UObject*)find::FindObject(xorstr(L"FortniteGame.FortPlayerPawn.IsInVehicle")); if (!ue::cached::objects::actor::IsInVehicle) return;
		ue::cached::objects::K2_TeleportTo = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Actor.K2_TeleportTo")); if (!ue::cached::objects::K2_TeleportTo) return;
		//ue::cached::objects::SetMouseLoc = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.PlayerController.SetMouseLocation")); if (!ue::cached::objects::SetMouseLoc) return;
		ue::cached::objects::K2_SetActorLocation = (ue::classes::UObject*)find::FindObject(xorstr(L"Engine.Actor.K2_SetActorLocation")); if (!ue::cached::objects::K2_SetActorLocation) return;

		//InsertKey = ue::FKey{ ue::FName{ sdkUssage->Conv_StringToName(xorstr(L"Insert")) }, 0 };
		//LBKey = ue::FKey{ ue::FName{ sdkUssage->Conv_StringToName(xorstr(L"LeftMouseButton")) }, 0 };
		//RBKey = ue::FKey{ ue::FName{ sdkUssage->Conv_StringToName(xorstr(L"RightMouseButton")) }, 0 };
		//F7Key = ue::FKey{ ue::FName{ sdkUssage->Conv_StringToName(xorstr(L"F7")) }, 0 };



		FNTool* sdk = new FNTool();
		sdk->Initialize((uintptr_t)ue::classes::objects, ue::cached::signatures::GetNameByIndex, ue::cached::signatures::FreeFn);

		ue::cached::offsets::OwningGameInstance = sdk->FindOffset("World", "OwningGameInstance");
		//ue::cached::offsets::WorldSettings = sdk->FindOffset("Level", "WorldSettings");
		ue::cached::offsets::Levels = sdk->FindOffset("World", "Levels");
		ue::cached::offsets::AcknowledgedPawn = sdk->FindOffset("PlayerController", "AcknowledgedPawn");
		ue::cached::offsets::PlayerCameraManager = sdk->FindOffset("PlayerController", "PlayerCameraManager");
		ue::cached::offsets::PlayerState = sdk->FindOffset("Pawn", "PlayerState");
		ue::cached::offsets::bADSWhileNotOnGround = sdk->FindOffset("FortPlayerPawnAthena", "bADSWhileNotOnGround");
		ue::cached::offsets::CurrentWeapon = sdk->FindOffset("FortPawn", "CurrentWeapon");
		ue::cached::offsets::TeamIndex = sdk->FindOffset("FortPlayerStateAthena", "TeamIndex");
		ue::cached::offsets::WeaponData = sdk->FindOffset("FortWeapon", "WeaponData");
		ue::cached::offsets::DisplayName = sdk->FindOffset("FortItemDefinition", "DisplayName");
		ue::cached::offsets::Mesh = sdk->FindOffset("Character", "Mesh");
		ue::cached::offsets::RootComponent = sdk->FindOffset("Actor", "RootComponent");
		ue::cached::offsets::RelativeLocation = sdk->FindOffset("SceneComponent", "RelativeLocation");
		ue::cached::offsets::LastFireTime = sdk->FindOffset("FortWeapon", "LastFireTime");
		ue::cached::offsets::AmmoCount = sdk->FindOffset("FortWeapon", "AmmoCount");
		ue::cached::offsets::LastFireTimeVerified = sdk->FindOffset("FortWeapon", "LastFireTimeVerified");
		ue::cached::offsets::Tier = sdk->FindOffset("FortItemDefinition", "Tier");

		Beep(500, 500);

		auto UViewportClient = ((GWorld*)(*(uintptr_t*)(ue::cached::signatures::GWorld)))->OwningGameInstance()->LocalPlayers()->LocalPlayer()->ViewportClient();


		void** DrawTransition_VTable = *(void***)(UViewportClient);
		DWORD OldProtection;
		safe_call(VirtualProtect)(&DrawTransition_VTable[0x6E], 8, PAGE_EXECUTE_READWRITE, &OldProtection);
		DrawTransitionOriginal = decltype(DrawTransitionOriginal)(DrawTransition_VTable[0x6E]);
		DrawTransition_VTable[0x6E] = &DrawTransition;
		safe_call(VirtualProtect)(&DrawTransition_VTable[0x6E], 8, OldProtection, &OldProtection);
}
// Ask him
BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
	if (reason != DLL_PROCESS_ATTACH) return FALSE;
	// IK how to lol
	system("start https://discord.gg/saturncc");
	Main();

	return TRUE;
}
