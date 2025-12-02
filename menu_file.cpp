#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"

void CreateMenuplay()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(50, 50, 200, 30); // Draw menu box
    LCD.SetFontScale(1.5);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}void riteplay()
{
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Play Game", 100, 60);
}
//This function should handle the process of clicking play and starting up the game.
/*Previous code    int x, y;
    bool clicked = LCD.Touch(&x, &y, true);
    if (clicked)
    {
        if (x >= 50 && x <= 250 && y >= 50 && y <= 80)*/
void leftclickplay()

{
// New click code
float x, y;
    while (true)
    {   
        //Set the x and y value equal to the box size of the menu buttons
        if(LCD.Touch(&x, &y, true))
        {
            // Check if the touch is within the "Play Game" button area
            if (x >= 50 && x <= 250 && y >= 50 && y <= 80)
        

        {
            // Play Game button clicked
            LCD.Clear(BLACK);
            Sleep(500); // Pause to show highlight
            LCD.SetFontColor(WHITE);
            LCD.SetFontScale(1.0);  
            LCD.WriteAt("Starting ", 80, 120);
            Sleep(550);
            LCD.WriteAt("         Game", 80, 120);
            Sleep(600);
            LCD.WriteAt("              .", 80, 120);
             Sleep(650);
            LCD.WriteAt("              ..", 80, 120);
             Sleep(700);
            LCD.WriteAt("              ...", 80, 120);
             Sleep(750);
            LCD.Update();
            Sleep(1000); // Pause before starting the game
            // Here you can add code to start the game
        }
    }
}
}

/*void CreateMenu()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(50, 50, 200, 30); // Draw menu box
    LCD.SetFontScale(1.5);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}*/
void CreateMenustats()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(60, 80, 180, 28); // Draw menu box
    LCD.SetFontScale(1.0);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}
void CreateMenuinfo()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(60, 110, 180, 28); // Draw menu box
    LCD.SetFontScale(1.0);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}
void CreateMenucredits()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(60, 140, 180, 28); // Draw menu box
    LCD.SetFontScale(1.0);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}
void decalline()
{
    LCD.SetFontColor(WHITE);
    LCD.DrawLine(0, 200, 319, 200); // Draw line across screen
}
void decalline2()
{
    LCD.SetFontColor(WHITE);
    LCD.DrawLine(0, 210, 319, 210); // Draw line across screen
}
void decalline3()
{
    LCD.SetFontColor(WHITE);
    LCD.DrawLine(0, 20, 319, 20); // Draw line across screen
}
void decalline4()
{
    LCD.SetFontColor(WHITE);
    LCD.DrawLine(0, 30, 319, 30); // Draw line across screen
}
int main()
{
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    CreateMenuplay();
    CreateMenuinfo();
    CreateMenucredits();
    CreateMenustats();
    decalline();
    decalline2();
    decalline3();
    decalline4();
    riteplay();
    leftclickplay();

    
    while (1)
    {
        LCD.Update();
        // Never end
    }
    return 0;
}
