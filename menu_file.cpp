#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"
#include "menu_file.h"

void CreateMenuplay()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(50, 45, 200, 30); // Draw menu box
    LCD.SetFontScale(1.5);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}
void writeplay()
{
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Play Game", 100, 50);
}

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
// This is refusing to write to screen, it is assumed that is is being covered in some way.
// Display the text stats to screen
void writestats()
{
    Sleep(10);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Stats", 120, 85);
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
void writeInstruct()
{
    Sleep(10);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Instructions", 80, 115);
}
void createMenuCredits()
{
    // Example function to create a menu on the FEHLCD
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(60, 140, 180, 28); // Draw menu box
    LCD.SetFontScale(1.0);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(60, 60); // Draw menu item
    // Add more menu items as needed
}
void writecredits()
{
    Sleep(10);
    LCD.SetFontColor(WHITE);
    LCD.SetFontScale(1.0);
    LCD.WriteAt("Credits", 100, 145);
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

// Touch function
void testTouch()
{
    // New click code
    float x, y;
    while (true)
    {
        // Set the x and y value equal to the box size of the menu buttons
        if (LCD.Touch(&x, &y, true))
        {
            // Check if the touch is within the "Play Game" button area
            if (GoToPlay(x, y) || GoToStats(x, y) || GoToInstruct(x, y) || GoToCredits(x, y))
            {
                break;
            }
        }
    }
}
// Function to handle "play" button click
bool GoToStats(float x, float y)
{
    if (x >= 50 && x <= 220 && y >= 40 && y <= 80)
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
        LCD.SetFontColor(RED);
        LCD.WriteAt("Click to EXIT", 80, 200);
        Sleep(750);
        LCD.Update();
        Sleep(1000); // Pause before starting the game
        // Here you can add code to start the game
        return true;
    }
    return false;
}
// Function to handle "stats" button click
bool GoToPlay(float x, float y)
{
    if (x >= 60 && x <= 200 && y >= 80 && y <= 100)
    {
        // Play Game button clicked
        // Please note that the error values are place holders and will need to be remove and remade.
        LCD.Clear(BLACK);
        LCD.DrawHorizontalLine(30, 0, 319); // Draw line across screen
        Sleep(500);                         // Pause to show highlight
        LCD.SetFontColor(WHITE);
        LCD.SetFontScale(1.0);
        LCD.WriteAt("Stats: ", 10, 10);
        Sleep(550);
        LCD.WriteAt("Wood:", 10, 50);
        Sleep(600);
        LCD.WriteAt("Metal:", 10, 70);
        LCD.SetFontColor(RED);
        LCD.WriteAt("ERROR", 80, 50);
        LCD.SetFontColor(WHITE);
        Sleep(650);
        LCD.WriteAt("Food:", 10, 90);
        LCD.SetFontColor(RED);
        LCD.WriteAt("ERROR", 80, 70);
        LCD.SetFontColor(WHITE);
        Sleep(700);
        LCD.WriteAt("Total score...", 10, 180);
        LCD.SetFontColor(RED);
        LCD.WriteAt("ERROR", 80, 90);
        Sleep(750);
        LCD.SetFontColor(RED);
        LCD.WriteAt("ERROR", 180, 180);
        Sleep(750);
        LCD.SetFontColor(RED);
        LCD.WriteAt("Click to EXIT", 80, 200);
        LCD.Update();
        Sleep(1000); // Pause before starting the game
        // Here you can add code to start the game
        return true;
    }
    return false;
}
// Activates on clicking instructions
bool GoToInstruct(float x, float y)
{
    if (x >= 60 && x <= 200 && y >= 100 && y <= 140)
    {
        // Play Game button clicked
        // Please note that the error values are place holders and will need to be remove and remade.
        LCD.Clear(BLACK);
        LCD.DrawHorizontalLine(30, 0, 319); // Draw line across screen
        Sleep(100);                         // Pause to show highlight
        LCD.SetFontColor(WHITE);
        LCD.SetFontScale(1.0);
        LCD.WriteAt("Info: ", 10, 10);
        LCD.SetFontScale(.5);
        Sleep(1000);
        LCD.WriteAt("Hello and welcome to your new", 10, 50);
        Sleep(950);
        LCD.WriteAt("simulated Village and hopefully town.", 10, 60);
        Sleep(900);
        LCD.WriteAt("In this village you will learn", 10, 70);
        Sleep(850);
        LCD.WriteAt("The value of resource management", 10, 80);
        Sleep(800);
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Through the lens of a small village", 10, 90);
        Sleep(750);
        LCD.WriteAt("You will need to gather three different resources", 10, 100);
        Sleep(700);
        LCD.WriteAt("-Wood  -Metal  -Food", 10, 110);
        Sleep(650);
        LCD.WriteAt("Each will have its own purpose and limitation", 10, 120);
        Sleep(600);
        LCD.WriteAt("And you will need to carefully balance them.", 10, 130);
        Sleep(550);
        LCD.WriteAt("Do to how you will be forced to spend time", 10, 140);
        Sleep(500);
        LCD.WriteAt("collecting each, and during these times", 10, 150);
        Sleep(450);
        LCD.WriteAt("other resources may deplete or be lost.", 10, 160);
        Sleep(400);
        LCD.WriteAt("So always be careful of what you have", 10, 170);
        Sleep(350);
        LCD.WriteAt("or else.", 10, 180);
        Sleep(1000);
        LCD.SetFontColor(RED);
        LCD.WriteAt("Good Luck", 10, 200);
        Sleep(750);
        LCD.SetFontColor(RED);
        LCD.WriteAt("Click to EXIT", 100, 200);
        LCD.Update();
        Sleep(1000);
        // Pause before starting the game
        // Here you can add code to start the game
        return true;
    }
    return false;
}
// Function to handle "Credits" button click
bool GoToCredits(float x, float y)
{
    if (x >= 50 && x <= 200 && y >= 140 && y <= 180)
    {
        // Play Game button clicked
        LCD.Clear(BLACK);
        LCD.DrawHorizontalLine(30, 0, 319); // Draw line across screen
        Sleep(100);                         // Pause to show highlight
        LCD.SetFontColor(WHITE);
        LCD.SetFontScale(1.0);
        LCD.WriteAt("Credits: ", 10, 10);
        LCD.SetFontScale(0.5);
        Sleep(750);
        LCD.WriteAt("Code by: ", 10, 50);
        Sleep(750);
        LCD.WriteAt("Brayden Hass, and Glenn Busch", 10, 70);
        Sleep(750);
        LCD.WriteAt("Made within:", 10, 90);
        Sleep(750);
        LCD.WriteAt("Visual Studio", 10, 110);
        Sleep(750);
        LCD.WriteAt("References:", 10, 130);
        Sleep(750);
        LCD.WriteAt("Paul Clingen, Taylor Hamilton, Rahul Sanghvi", 10, 150);
        Sleep(750);
        LCD.WriteAt("And a special thanks to ", 10, 170);
        LCD.SetFontColor(RED);
        LCD.WriteAt("                       you", 10, 170);
        Sleep(750);
        LCD.SetFontColor(RED);
        LCD.WriteAt("Click to EXIT", 100, 200);
        LCD.Update();
        Sleep(1000); // Pause before starting the game
        // Here you can add code to start the game
        return true;
    }
    return false;
}



int main()
{
    //Call for reset of menu, this function will trigger the while loop the resets back to menu
float x, y;
    while (true)
    if(LCD.Touch(&x, &y, true))
    {
        // Clear background
        LCD.SetBackgroundColor(BLACK);
        LCD.Clear();

        CreateMenuplay();
        CreateMenuinfo();
        createMenuCredits();
        CreateMenustats();
        decalline();
        decalline2();
        decalline3();
        decalline4();
        writeplay();
        writeInstruct();
        writestats();
        writecredits();
        testTouch();
    }
    
    while (1)
    {
        LCD.Update();
        // Never end
    }
    return 0;
}
