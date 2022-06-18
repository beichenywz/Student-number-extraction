#include <graphics.h>
#include <time.h>
#include <stdio.h>

using namespace std;


int asp = 1;


char* Random()
{
	int x = 0, a = 0, b = 0, c = 0;
	static char s[2];
	s[1] = '\0';
	while (1) {
		x = rand() % 43 + 1;
		if (x != a && x != b && x != c) break;
	}
	if (x < 10)
		s[0] = x + '0';
	else {
		s[0] = x / 10 + '0';
		s[1] = x % 10 + '0';
	}
	return s;
}


void show(int x, int y, char* msg)
{
	int tx = x - textwidth(msg) / 2;
	int ty = y - textheight(msg) / 2;
	outtextxy(tx, ty, msg);
}


void show(int x, int y, const char* msg)
{
	int tx = x - textwidth(msg) / 2;
	int ty = y - textheight(msg) / 2;
	outtextxy(tx, ty, msg);
}


void Show()
{
	int sp = 500;
	while (sp > 3) {
		clearrectangle(10 * asp, 10 * asp, 140 * asp, 50 * asp);
		show(75 * asp, 30 * asp, Random());
		Sleep(sp);
		sp -= sp / 3;
	}
	show(30 * asp, 30 * asp, "!!!");
	show(120 * asp, 30 * asp, "!!!");
}


void initialization()
{
	unsigned seed = time(0);
	srand(seed);

	initgraph(150 * asp, 100 * asp, NOMINIMIZE);
	HWND hnd = GetHWnd();
	SetWindowText(hnd, "Ñ§ºÅ³éÈ¡");
	hnd = GetForegroundWindow();
	SetWindowPos(hnd, HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE);
	setbkcolor(WHITE);
	cleardevice();
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2 * asp);
	settextstyle(30 * asp, 0, "Î¢ÈíÑÅºÚ");
}


void button()
{
	int x = 20 * asp, y = 55 * asp, w = 110 * asp, h = 35 * asp;
	const char msg[9] = "³éÈ¡Ñ§ºÅ";
	fillroundrect(x, y, x + w, y + h, 20 * asp, 20 * asp);
	int tx = x + (w - textwidth(msg)) / 2;
	int ty = y + (h - textheight(msg)) / 2;
	outtextxy(tx, ty, msg);
}


void extract()
{
	settextstyle(50 * asp, 0, "Î¢ÈíÑÅºÚ");
	ExMessage msg;
	while (true) {
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 25 * asp && msg.x <= (25 + 100) * asp && msg.y >= 55 * asp && msg.y <= (55 + 35) * asp)
					Show();
				break;
			default:
				break;
			}
		}
	}

}

int main()
{
	//cin >> asp;

	initialization();

	button();

	extract();
	
	getchar();
	closegraph();
	return 0;
}