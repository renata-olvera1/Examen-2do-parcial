#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[]) {
    std::string reset_position;
    int frame = 0;
    auto posX = 0;
    bool explotar = false;

    while (true) {
        auto can = Canvas(100, 100);  

        auto ColorSupport = vbox({
            Terminal::ColorSupport() >= Terminal::Color::Palette16
                ? text(" 16 color palette support : Yes")
                : text(" 16 color palette support : No"),
            Terminal::ColorSupport() >= Terminal::Color::Palette256
                ? text("256 color palette support : Yes")
                : text("256 color palette support : No"),
            Terminal::ColorSupport() >= Terminal::Color::TrueColor
                ? text("       True color support : Yes")
                : text("       True color palette support : No"),
        });

        can.DrawPointLine(posX + 15, 50, posX + 35, 50); 
        can.DrawPointCircle(posX + 40, 50, 4);
        can.DrawPointCircle(posX + 10, 50, 4);
        can.DrawPointLine(posX + 2, 50, posX + 4, 50); 
        can.DrawPointLine(posX + 2, 50, posX + 2, 42);
        can.DrawPointLine(posX + 2, 40, posX + 10, 40);
        can.DrawPointLine(posX + 10, 40, posX + 10, 33);
        can.DrawPointLine(posX + 10, 33, posX + 30, 33);
        can.DrawPointLine(posX + 30, 33, posX + 30, 40);
        can.DrawPointLine(posX + 30, 40, posX + 50, 40);
        can.DrawPointLine(posX + 50, 50, posX + 50, 40);
        can.DrawPointLine(posX + 50, 50, posX + 35, 50);

        if (explotar) {
            can.DrawPoint(78, 20, true);
            can.DrawPoint(82, 32, true);
            can.DrawPoint(74, 32, true);
            can.DrawPoint(76, 45, true);
            can.DrawPoint(80, 45, true);
        } else {
            can.DrawPointLine(80, 45, 80, 35);
            can.DrawPointLine(75, 38, 80, 40);
            can.DrawPointLine(75, 35, 80, 40);
            can.DrawPointCircle(78, 30, 3);
            can.DrawPointLine(75, 54, 80, 40);
        }

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element personaje = spinner(20, frame);
        Element lienzo = bgcolor(Color::Red, border(vbox(ColorSupport, personaje, canvas(&can))));
        Element lienzo2 = bgcolor(Color::Red, border(vbox(canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);

        if (posX < 65) {
            posX++;
        } else {
            explotar = true;
        }

        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}