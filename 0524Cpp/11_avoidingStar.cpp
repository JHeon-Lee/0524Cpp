#include <iostream>
#include <Windows.h>

using namespace std;

#define WIDTH 15
#define HEIGHT 20

struct Star
{
    int x;
    int y;
    bool isStar;
};

struct Player
{
    int x;
    int y;
};

void gotoxy(int x, int y)
{
    COORD pos = { x * 2, y };
    // 2 * x 인 이유는 1씩 이동하는것보다 2씩 이동하는게 더 자연스러워 보이기 때문
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    // GetStdHandle : 콘솔창 핸들
}

Star star[WIDTH];
Player player;

void initialize()
{
    for (int i = 0; i < WIDTH; i++)
    {
        star[i].isStar = false;
    }

    player.x = WIDTH / 2;
    player.y = HEIGHT;
}

void createStar()
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (star[i].isStar == false)
        {
            star[i].x = rand() % WIDTH;
            star[i].y = 0;
            star[i].isStar = true;
            break;
        }
    }
}

void moveStar()
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (star[i].isStar)
        {
            star[i].y++;
        }
    }
}

int score = 0;

void destroyStar()
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (star[i].isStar && star[i].y > HEIGHT)
        {
            star[i].isStar = false;
            score += 100;
            printf("\n점수 : %d\n", score);
        }
    }
}

bool collidPlayer()
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (star[i].isStar && star[i].y == player.y
            && star[i].x == player.x)
        {
            printf("\n");
            printf("점수 : %d\n", score);
            return true;
        }
    }
    return false;
}

int isKeyDown(int key)
{
    return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

void movePlayer()
{
    if (isKeyDown(VK_LEFT))
        player.x--;
    if (isKeyDown(VK_RIGHT))
        player.x++;
    if (isKeyDown(VK_UP))
        player.y--;
    if (isKeyDown(VK_DOWN))
        player.y++;

    if (player.x < 1)
        player.x = 1;
    if(player.x > WIDTH  - 1)
        player.x = WIDTH - 1;
    if (player.y < 1)
        player.y = 1;
    if (player.y > HEIGHT)
        player.y = HEIGHT;
}

void PrintGame()
{
    system("cls");

    for (int i = 0; i < WIDTH; i++)
    {
        if (star[i].isStar)
        {
            gotoxy(star[i].x, star[i].y);
            printf("☆");
        }
    }

    gotoxy(player.x, player.y);
    printf("△");

    for (int i = 0; i < WIDTH + 1; i++)
    {
        gotoxy(i, 0);
        printf("■");

        for (int j = 0; j < HEIGHT + 1; j++)
        {
            gotoxy(i, j);
            if (i == 0 || i == WIDTH)
                printf("■");
        }
        gotoxy(i, HEIGHT + 1);
        printf("■");
    }
}

int main()
{
    initialize();

    srand((unsigned int)time(NULL));
    Sleep(10);

    while (!(collidPlayer()))
    {
        createStar();
        moveStar();
        destroyStar();

        movePlayer();
        PrintGame();

        Sleep(30);
    }

    return 0;
}