#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"

void AnimationTraining();

void UpdateBluePosition(int &x2);

void UpdateRedPosition(int &x1);

void ClearOld(int oldX1, int y1, int r, int oldX2, int y2);

void DrawCircle(int color, int x2, int y2, int r);

#define SpeedFactor 10
#define FinishLineX 300
#define TimeDelay 50

/*
    SDP Training Minigame #1

    Make the shapes race across the screen.
    Change their colors when they reach the finish line.
*/
void AnimationTraining()
{
    int x1 = 50, y1 = 50;
    int x2 = 50, y2 = 100;
    int r = 10;
    int oldX1 = x1, oldX2 = x2;

    // Draw Racer 1
    DrawCircle(RED, x1, y1, r);

    // Draw Racer 2
    DrawCircle(BLUE, x2, y2, r);

    // Draw finish line
    LCD.SetFontColor(WHITE);
    LCD.DrawLine(FinishLineX, 0, FinishLineX, 239);

    LCD.Update();

    // 0 = no winner, 1 = red, 2 = blue
    int winner = 0;

    // Make racers move across the screen
    while (x1 < FinishLineX || x2 < FinishLineX)
    {
        oldX1 = x1;
        oldX2 = x2;

        // Clear previous racers by drawing black over them
        ClearOld(oldX1, y1, r, oldX2, y2);

        // Update red racer
        UpdateRedPosition(x1);
        // Update blue racer
        UpdateBluePosition(x2);
        // Check for winner
        if (winner == 0 && x1 >= FinishLineX - r)
        {
            winner = 1;
        }
        if (winner == 0 && x2 >= FinishLineX - r)
        {
            winner = 2;
        }

        // Redraw racers with different colors - don't forget to sleep!
        int firstColor = (winner == 1)
                             ? GREEN
                         : (winner == 2)
                             ? ORANGE
                             : RED;
        int secondColor = (winner == 2)
                              ? GREEN
                          : (winner == 1)
                              ? ORANGE
                              : BLUE;
        // Draw red racer
        DrawCircle(firstColor, x1, y1, r);
        // Draw blue racer
        DrawCircle(secondColor, x2, y2, r);

        LCD.Update();
        Sleep(TimeDelay);
    }
}

void UpdateBluePosition(int &x2)
{
    if (x2 > FinishLineX)
    {
        return;
    }
    int blueDistance = Random.RandInt() % SpeedFactor;
    x2 += blueDistance;
}

void UpdateRedPosition(int &x1)
{
    if (x1 > FinishLineX)
    {
        return;
    }
    int redDistance = Random.RandInt() % SpeedFactor;
    x1 += redDistance;
}

void ClearOld(int oldX1, int y1, int r, int oldX2, int y2)
{
    LCD.SetFontColor(BLACK);
    LCD.DrawCircle(oldX1, y1, r);
    LCD.FillCircle(oldX1, y1, r);
    LCD.DrawCircle(oldX2, y2, r);
    LCD.FillCircle(oldX2, y2, r);
}

void DrawCircle(int color, int x1, int y1, int r)
{
    LCD.SetFontColor(color);
    LCD.DrawCircle(x1, y1, r);
    LCD.FillCircle(x1, y1, r);
}

// int main()
// {
//     // Clear background
//     LCD.SetBackgroundColor(BLACK);
//     LCD.Clear();

//     AnimationTraining();

//     while (1)
//     {
//         LCD.Update();
//         // Never end
//     }
//     return 0;
// }
