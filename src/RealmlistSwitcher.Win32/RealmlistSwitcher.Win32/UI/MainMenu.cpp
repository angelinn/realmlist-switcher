#include "MainMenu.h"

HMENU MainMenu::Create()
{
	HMENU menu = CreateMenu();
	HMENU subMenu = CreatePopupMenu();

	AppendMenu(subMenu, MF_STRING, IDM_ABOUT, L"About");
	AppendMenu(subMenu, MF_STRING, IDM_EXIT, L"Exit");

	AppendMenu(menu, MF_STRING | MF_POPUP, (UINT_PTR)subMenu, L"File");

	return menu;
}
